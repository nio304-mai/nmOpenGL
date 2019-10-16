#include "nmgl.h"
#include "hal.h"
#include "nmglvs_nmc0.h"
#include "stdio.h"
#include "phillips.h"
#include "led.h"
#include "hal.h"
#include "float.h"

#include "nmpp.h"
#include <cstring>
#include <cmath>
#include "hal_target.h"
#include "dma.h"


#define			STR_SIZE			256
#define			COL_SIZE			256
#define			FRAME_SIZE			STR_SIZE * COL_SIZE

struct Vertex {
	float x;
	float y;
	float z;
	float w;
};

struct Triangle {
	Vertex a;
	Vertex b;
	Vertex c;
};

SECTION(".data_shared") float colorTriangles[4 * FRAME_SIZE];
SECTION(".data_imu0") NMGL_Context_NM0 context;

SECTION(".data_imu1") nm32fcr h0_sram[STR_SIZE];
SECTION(".data_imu1") nm32f   re_im_sram[COL_SIZE];

SECTION(".data_imu1") nm32f   omega_sram[STR_SIZE];
SECTION(".data_imu1") nm32fcr h0_conj_sram[STR_SIZE];

SECTION(".data_imu5") nm32f   re_exp_sram[STR_SIZE];
SECTION(".data_imu5") nm32fcr fft_sram1[COL_SIZE];

SECTION(".data_imu4") nm32f   im_exp_sram[STR_SIZE];
SECTION(".data_imu4") nm32fcr h_sram[STR_SIZE];

SECTION(".data_imu5") nm32fcr exp_sram[STR_SIZE];
SECTION(".data_imu5") nm32f   omegat_sram[STR_SIZE];

SECTION(".data_imu6") nm32fcr fft_sram0[COL_SIZE];
SECTION(".data_imu6") nm32f   result_sram[COL_SIZE];

#define COUNT_TRIANGLES 2 * (STR_SIZE-1) * (COL_SIZE-1) 

SECTION(".data_DDR") nm32f    dispersion_ddr[FRAME_SIZE];
SECTION(".data_DDR") Triangle triangles[COUNT_TRIANGLES];
SECTION(".data_DDR") nm32fcr  h0_ddr[FRAME_SIZE];
SECTION(".data_DDR") nm32fcr  h0_conj_ddr[FRAME_SIZE];
SECTION(".data_DDR") nm32fcr  fft_ddr[FRAME_SIZE];
SECTION(".data_DDR") float    result_ddr[FRAME_SIZE];
SECTION(".data_DDR") float    result_ddr_color[12 * COUNT_TRIANGLES];

extern "C" {
	void SumReImParts(const nm32fcr* complex_nums, nm32f* sum_re_im, int size);
}

void halCopy_32s(void* srcVec, void* dstVec, int size) {
	int* src = (int*)srcVec;
	int* dst = (int*)dstVec;
	for (int i = 0; i < size; i++) {
		dst[i] = src[i];
	}
}

#define DY 0

void FillXy(Triangle* triangles, int width, int height) {
	int index = 0;
	for (int i = 0; i < height - 1; i++) {
		for (int j = 0; j < width - 1; j++, index += 2) {
			triangles[index].a.x = j;
			triangles[index].a.y = i + DY;
			triangles[index].a.w = 1;

			triangles[index].b.x = j + 1;
			triangles[index].b.y = i + DY;
			triangles[index].b.w = 1;

			triangles[index].c.x = j;
			triangles[index].c.y = i + 1 + DY;
			triangles[index].c.w = 1;

			triangles[index + 1].a.x = j + 1;
			triangles[index + 1].a.y = i + DY;
			triangles[index + 1].a.w = 1;

			triangles[index + 1].b.x = j + 1;
			triangles[index + 1].b.y = i + 1 + DY;
			triangles[index + 1].b.w = 1;

			triangles[index + 1].c.x = j;
			triangles[index + 1].c.y = i + 1 + DY;
			triangles[index + 1].c.w = 1;
		}
	}
}


void FillZw(const float* z_mtr, Triangle* triangles, int width, int height)
{
	int index = 0;
	for (int i = 0; i < height - 1; i++) {
		for (int j = 0; j < width - 1; j++, index += 2) {
			triangles[index].a.z = z_mtr[i * height + j];
			//triangles[index].a.w = 1;

			triangles[index].b.z = z_mtr[i * height + j + 1];
			//triangles[index].b.w = 1;

			triangles[index].c.z = z_mtr[(i + 1) * height + j];
			//triangles[index].c.w = 1;

			triangles[index + 1].a.z = z_mtr[i * height + j + 1];
			//triangles[index + 1].a.w = 1;

			triangles[index + 1].b.z = z_mtr[(i + 1) * height + j + 1];
			//triangles[index + 1].b.w = 1;

			triangles[index + 1].c.z = z_mtr[(i + 1) * height + j];
			//triangles[index + 1].c.w = 1;
		}
	}
}


int main()
{
	nmglvsNm0Init();

	FillXy(triangles, STR_SIZE, COL_SIZE);
#ifdef __OPEN_GL__
	computeOmega(dispersion_ddr, STR_SIZE, COL_SIZE);
	computeH0(h0_ddr, h0_conj_ddr, STR_SIZE, COL_SIZE);
#else
	halHostSync((int)dispersion_ddr); 			// send a frame address in DDR to PC
	halHostSync((int)h0_ddr);
	halHostSync((int)h0_conj_ddr);

	halHostSync(0x12300123);
#endif
	NmppsFFTSpec_32fcr* fft_coeffs;					// FFT variable
	halLed(1);
	int fftIsInitialized = FFTFwdInitAlloc_32fcr(&fft_coeffs, STR_SIZE);
	halLed(255);
	if (fftIsInitialized == 0) {
		halHostSync(0x600D600D);
	}
	else {
		halHostSync(fftIsInitialized);
		return fftIsInitialized;
	}
	nmglClearColor(0, 0, 0.2f, 0.0f);

	nmglMatrixMode(NMGL_MODELVIEW);
	nmglTranslatef(-128, -128, 0);
	nmglRotatef(-60, 1, 0, 0);	
	nmglScalef(1, 1, 50);
	nmglTranslatef(0, 100, 0);

	//nmglRotatef(-60, 0, 1, 0);
	
	nmglMatrixMode(NMGL_PROJECTION);
	nmglOrthof(-128, 128, -128, 128, -200, 200);
	nmglViewport(0, 0, 768, 768);

	nmglEnable(NMGL_DEPTH_TEST);
	//nmglEnable(NMGL_LIGHTING);
	//nmglEnable(NMGL_LIGHT0);
	//nmglEnable(NMGL_NORMALIZE);
	//NMGLenum error = nmglGetError();

	nmglEnableClientState(NMGL_VERTEX_ARRAY);
	nmglEnableClientState(NMGL_COLOR_ARRAY);
	//nmglEnableClientState(NMGL_NORMAL_ARRAY);
	//nmglNormalPointer(NMGL_FLOAT, 0, nmglNormalArray);
	nmglVertexPointer(4, NMGL_FLOAT, 0, triangles);
	nmglColorPointer(4, NMGL_FLOAT, 0, result_ddr_color);


	float time = 0;
	float invmax = (1 / 4.8) * 0.5;

	while(nmglvsNm0Run()){
		nmglClear(NMGL_COLOR_BUFFER_BIT | NMGL_DEPTH_BUFFER_BIT);

		for (int i = 0, offset = 0; i < STR_SIZE; i++, offset += STR_SIZE) {
			//memcpy((void*)omega_sram, (void*)(dispersion_ddr + offset), STR_SIZE);
			halCopy_32s((void*)(dispersion_ddr + offset), (void*)omega_sram, STR_SIZE);
			
			nmppsMulC_32f(omega_sram, omegat_sram, time, STR_SIZE);

			nmppsCos_32f(omegat_sram, re_exp_sram, STR_SIZE);
			nmppsSin_32f(omegat_sram, im_exp_sram, STR_SIZE);

			halCopy_32s((void*)(h0_conj_ddr + offset), (void*)h0_conj_sram, STR_SIZE << 1);

			//memcpy((void*)h0_conj_sram, (void*)(h0_conj_ddr + offset), STR_SIZE << 1);

			halCopy_32s((void*)(h0_ddr + offset), (void*)h0_sram, STR_SIZE << 1);
			//memcpy((void*)h0_sram, (void*)(h0_ddr + offset), STR_SIZE << 1);

			nmppsMerge_32f(re_exp_sram, im_exp_sram, (float*)exp_sram, STR_SIZE);

			nmppsMul_ConjMul_Add_32fcr(h0_sram, exp_sram, h0_conj_sram, exp_sram, h_sram, STR_SIZE);

			FFTFwd_32fcr(h_sram, fft_sram0, fft_coeffs, STR_SIZE);

			halCopy_32s((void*)fft_sram0, (void*)(fft_ddr + offset), STR_SIZE << 1);
			
			//memcpy((void*)(fft_ddr + offset), (void*)(fft_sram0), STR_SIZE << 1);
		}

		int columns = 0;
		int offs = 0;
		nm32f* tmp_buffer_sram = im_exp_sram;
		while (columns < COL_SIZE) {
			for (int i = 0, stride = 0; i < COL_SIZE; i++, stride += STR_SIZE) {
				halCopy_32s((void*)(fft_ddr + stride + columns), (void*)(fft_sram0 + i), 2);
				//memcpy((void*)(fft_sram0 + i), (void*)(fft_ddr + stride + columns), 2);
			}

			FFTFwd_32fcr(fft_sram0, fft_sram0, fft_coeffs, COL_SIZE);
            
			// ���������� ����� �� ������������ z => |z| = sqrt(z.re^2 + z.im^2)
			nmppsMul_32f((nm32f*)fft_sram0, (nm32f*)fft_sram0, (nm32f*)fft_sram1, COL_SIZE << 1);
			SumReImParts(fft_sram1, re_im_sram, COL_SIZE << 1);
			nmppsSqrt_32f(re_im_sram, tmp_buffer_sram, result_sram, COL_SIZE);

			nmppsMulC_AddC_32f(tmp_buffer_sram, 0.1, 0.5, result_sram, COL_SIZE);
			halCopy_32s((void*)result_sram, (void*)(result_ddr + offs), COL_SIZE);
			//memcpy((void*)(result_ddr + offs), (void*)(result_sram), COL_SIZE);
			columns++;
			offs += COL_SIZE;
		}
		FillZw(result_ddr, triangles, STR_SIZE, COL_SIZE);
		time += 0.5;


		
		
		//if(0)
		for (int i = 0, k=0; i < COUNT_TRIANGLES; i++) {
			for (int j = 0; j < 3; j++, k++) {

					//result_ddr_color[4 * k + 0] = 0;
					//result_ddr_color[4 * k + 1] = 0;
					result_ddr_color[4 * k + 2] = (triangles[i].a.z);
					//result_ddr_color[4 * k + 3] = 0;
			}
			
		}

		//nmglDrawArrays(NMGL_TRIANGLES, 0, 8 * 3 * 2 * (COL_SIZE - 1));
		nmglDrawArrays(NMGL_TRIANGLES, 0, COUNT_TRIANGLES*3);
		//error = nmglGetError();
		nmglvsSwapBuffer();

	}

	nmglDisableClientState(NMGL_VERTEX_ARRAY);
	nmglDisableClientState(NMGL_COLOR_ARRAY);
	//nmglDisableClientState(NMGL_NORMAL_ARRAY);
	nmglvsExit_mc12101();
	return 0x600D600D;
}