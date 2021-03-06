#include "nmpp.h"
#include "time.h"
#include <stdio.h>
#include "demo3d_common.h"

#define SIZE 1024

SECTION(".data_imu2") float flags[SIZE+2];
SECTION(".data_imu3") float src[SIZE+2];
SECTION(".data_imu4") float dst[SIZE+2];
	
	
extern "C" void ternaryLt0_AddC_AddC_32f(nm32f* srcFlags, nm32f* srcVec, float valueLeft, float valueRight, float* dstVec, int size);

int main()
{
	clock_t t0,t1;
	unsigned crc =0;
	for(int i=0;i < SIZE + 2; i++){
		if(i%2){
			flags[i] = 0;
		} else {
			flags[i] = -1;
		}
		src[i] = 5;
		dst[i] = 0;
	}
	for(int size = 0; size <= SIZE; size += 2){
		t0 = clock();
		ternaryLt0_AddC_AddC_32f(flags, src, 0, 2, dst, size);
		t1 = clock();
		nmppsCrcAcc_32s((nm32s*)dst, size + 2, &crc);
	}
	for(int i=0;i< 64;i++){
		printf("%d - %f\n", i, dst[i]);
	}

	printf("crc=0x%x\n",crc);
	//printf("time0x%x\n",crc);
	return t1-t0;
}
