#include "hal_target.h"
#include "hal.h"
#include <time.h>
#include <nmpp.h>
#include "demo3d_nm0.h"
#include "cache.h"
#include "ringbuffer.h"
#include "nmprofiler.h"

#include "nmgl.h"


#define CHECK_EXIT0 if(nmglSynchro->exit_nm==EXIT) {	break;	}

SECTION(".data_imu1")	float nmglBuffer0[12 * NMGL_SIZE];
SECTION(".data_imu2")	float nmglBuffer1[12 * NMGL_SIZE];
SECTION(".data_imu3")	float nmglBuffer2[12 * NMGL_SIZE];
SECTION(".data_imu4")	float nmglBuffer3[12 * NMGL_SIZE];


SECTION(".data_imu1")	float nmglx0[NMGL_SIZE];
SECTION(".data_imu2")	float nmgly0[NMGL_SIZE];
SECTION(".data_imu3")	float nmglx1[NMGL_SIZE];
SECTION(".data_imu4")	float nmgly1[NMGL_SIZE];
SECTION(".data_imu5")	float nmglx2[NMGL_SIZE];
SECTION(".data_imu6")	float nmgly2[NMGL_SIZE];
SECTION(".data_imu7")	int nmglz_int[NMGL_SIZE];
SECTION(".data_imu6")	v4nm32s nmgllightsValues[NMGL_SIZE];

SECTION(".data_imu7") int dividedMasksMemory[4][NMGL_SIZE / 32];

SECTION(".data_imu6") int masksBits[36][NMGL_SIZE / 32];

int counter = 0;

template<class T> inline T* myMallocT() {
	T* result = (T*)halMalloc32(sizeof32(T));
	if (result == 0) throw counter;
	counter++;
	return result;
}

template<class T> inline T* myMallocT(int count) {
	T* result = (T*)halMalloc32(count * sizeof32(T));
	if (result == 0) throw counter;
	counter++;
	return result;
}

SECTION(".data_imu0") NMGL_Context_NM0 *NMGL_Context_NM0::context;

SECTION(".text_nmglvs") int nmglvsNm0Init()
{
	halSetProcessorNo(0);
	halSleep(100);
	NMGLSynchroData* synchroData;
	NMGL_Context_NM0 *cntxt;
	try {
		int fromHost = halHostSync(0xC0DE0000);		// send handshake to host
		if (fromHost != 0xC0DE0086) {					// get  handshake from host
			return 1;
		}


		setHeap(8);
		synchroData = myMallocT<NMGLSynchroData>();
		synchroData->init();

		setHeap(7);
		NMGL_Context_NM0::create(synchroData);	
		cntxt = NMGL_Context_NM0::getContext();

		setHeap(10);
		cntxt->polygonsData = myMallocT<PolygonsArray>();
		cntxt->polygonsData->init();
		cntxt->init(synchroData);

		cntxt->beginEndInfo.vertex = myMallocT<v4nm32f>(BIG_NMGL_SIZE);
		cntxt->beginEndInfo.normal = myMallocT<v4nm32f>(BIG_NMGL_SIZE);
		cntxt->beginEndInfo.color = myMallocT<v4nm32f>(BIG_NMGL_SIZE);
		cntxt->beginEndInfo.maxSize = BIG_NMGL_SIZE;
	}
	catch (int& e) {
		halHostSync(0xDEADB00F);
		return e;
	}
	halHostSync(0x600DB00F);	// send ok to host
	
	cntxt->patterns = (PatternsArray*)halSyncAddr(synchroData, 1);
	halSyncAddr(cntxt->polygonsData, 1);

	halHostSync(0x600DB00F);	// send ok to host

	cntxt->trianInner.x0 = nmglx0;
	cntxt->trianInner.y0 = nmgly0;
	cntxt->trianInner.x1 = nmglx1;
	cntxt->trianInner.y1 = nmgly1;
	cntxt->trianInner.x2 = nmglx2;
	cntxt->trianInner.y2 = nmgly2;
	cntxt->trianInner.z = nmglz_int;
	cntxt->trianInner.colors = nmgllightsValues;
	cntxt->trianInner.maxSize = NMGL_SIZE;
	cntxt->trianInner.size = 0;

	cntxt->lineInner.x0 = nmglx0;
	cntxt->lineInner.y0 = nmgly0;
	cntxt->lineInner.x1 = nmglx1;
	cntxt->lineInner.y1 = nmgly1;
	cntxt->lineInner.z = nmglz_int;
	cntxt->lineInner.colors = nmgllightsValues;
	cntxt->lineInner.maxSize = NMGL_SIZE;
	cntxt->lineInner.size = 0;


	cntxt->buffer0 = nmglBuffer0;
	cntxt->buffer1 = nmglBuffer1;
	cntxt->buffer2 = nmglBuffer2;
	cntxt->buffer3 = nmglBuffer3;

	cntxt->dividedMasks[0].init((nm1*)dividedMasksMemory[0], (nm1*)dividedMasksMemory[1]);
	cntxt->dividedMasks[1].init((nm1*)dividedMasksMemory[2], (nm1*)dividedMasksMemory[3]);


	nmglViewport(0, 0, WIDTH_IMAGE, HEIGHT_IMAGE);
	int countSegs = cntxt->windowInfo.nColumns * cntxt->windowInfo.nRows;
	for (int i = 0; i < countSegs; i++) {
		cntxt->segmentMasks[i].init((nm1*)masksBits[i]);
	}
#ifdef __GNUC__
	halDmaInitC();
	halInstrCacheEnable();
#ifdef PROFILER0
	halProfilerEnable();
#endif // PROFILER0	
#endif // __GNUC__

	//sync4
	halHostSync((int)0x600d600d);
	nmglClearColor(0, 0, 0, 1.0f);
	nmglClearDepthf(1);

	return 0;
} 

