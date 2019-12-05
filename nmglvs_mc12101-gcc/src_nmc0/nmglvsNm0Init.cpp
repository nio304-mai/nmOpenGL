#include "hal_target.h"
#include "hal.h"
#include <time.h>
#include <nmpp.h>
#include "demo3d_nm0.h"
#include "cache.h"
#include "ringbuffer.h"
#include "nmprofiler.h"

#include "nmgl.h"
#include "nmgl_data0.h"

#define CHECK_EXIT0 if(nmglSynchro->exit_nm==EXIT) {	break;	}

SECTION(".data_imu1")	float nmglBuffer0[12 * NMGL_SIZE];
SECTION(".data_imu2")	float nmglBuffer1[12 * NMGL_SIZE];
SECTION(".data_imu3")	float nmglBuffer2[12 * NMGL_SIZE];
SECTION(".data_imu4")	float nmglBuffer3[12 * NMGL_SIZE];


SECTION(".data_imu6")	float x0[NMGL_SIZE];
SECTION(".data_imu6")	float y0[NMGL_SIZE];
SECTION(".data_imu5")	float x1[NMGL_SIZE];
SECTION(".data_imu5")	float y1[NMGL_SIZE];
SECTION(".data_imu4")	float x2[NMGL_SIZE];
SECTION(".data_imu4")	float y2[NMGL_SIZE];
SECTION(".data_imu6")	int z_int[NMGL_SIZE];
SECTION(".data_imu6")	v4nm32s lightsValues[NMGL_SIZE];

/*SECTION(".data_shmem0")	HalRingBuffer mPolygonsRB;
SECTION(".data_shmem0")	NMGLSynchroData mSynchroData;
SECTION(".data_shared")	NMGLSynchro mSynchro(&mSynchroData);
SECTION(".data_shared")	float mDataDdr[11 * BIG_NMGL_SIZE];
SECTION(".data_shared")	Polygons mPolyArray[COUNT_POLYGONS_BUFFER];*/


template<class T> T* myMallocT(int size) {
	return (T*)halMalloc32(size * sizeof32(T));
}

template<class T> T* myMallocT() {
	return (T*)halMalloc32(sizeof32(T));
}

#pragma code_section ".text_demo3d"
int nmglvsNm0Init()
{
	halSetProcessorNo(0);
	int fromHost = halHostSync(0xC0DE0000);		// send handshake to host
	if (fromHost != 0xC0DE0086) {					// get  handshake from host
		return -1;
	}
	setHeap(8);
	NMGLSynchroData* synchroData = myMallocT<NMGLSynchroData>();
	setHeap(10);
	PolygonsArray* polygonsArray = myMallocT<PolygonsArray>();
	cntxt.init(synchroData, polygonsArray);

	cntxt.trianInner.x0 = x0;
	cntxt.trianInner.y0 = y0;
	cntxt.trianInner.x1 = x1;
	cntxt.trianInner.y1 = y1;
	cntxt.trianInner.x2 = x2;
	cntxt.trianInner.y2 = y2;
	cntxt.trianInner.z = z_int;
	cntxt.trianInner.colors = lightsValues;
	cntxt.trianInner.maxSize = NMGL_SIZE;
	cntxt.trianInner.size = 0;

	float* dataDdr = (float*)halMalloc32(11 * BIG_NMGL_SIZE);
	cntxt.trianDdr.x0 = dataDdr;
	cntxt.trianDdr.y0 = dataDdr + BIG_NMGL_SIZE;
	cntxt.trianDdr.x1 = dataDdr + 2 * BIG_NMGL_SIZE;
	cntxt.trianDdr.y1 = dataDdr + 3 * BIG_NMGL_SIZE;
	cntxt.trianDdr.x2 = dataDdr + 4 * BIG_NMGL_SIZE;
	cntxt.trianDdr.y2 = dataDdr + 5 * BIG_NMGL_SIZE;
	cntxt.trianDdr.z = (int*)(dataDdr + 6 * BIG_NMGL_SIZE);
	cntxt.trianDdr.colors = (v4nm32s*)(dataDdr + 7 * BIG_NMGL_SIZE);
	cntxt.trianDdr.maxSize = BIG_NMGL_SIZE;
	cntxt.trianDdr.size = 0;

#ifdef __GNUC__
	halDmaInit();
	halInstrCacheEnable();
#ifdef PROFILER0
	nmprofiler_init();
#endif // PROFILER0	
#endif // __GNUC__


	cntxt.buffer0 = nmglBuffer0;
	cntxt.buffer1 = nmglBuffer1;
	cntxt.buffer2 = nmglBuffer2;
	cntxt.buffer3 = nmglBuffer3;


	cntxt.patterns = (Patterns*)halSyncAddr((int*)synchroData, 1);
	halSyncAddr((int*)cntxt.polygonsData, 1);

	// Check memory allocation
	if (cntxt.polygonsData == 0 || synchroData == 0 || dataDdr == 0) {
		halHostSync(0xDEADB00F);	// send error to host
		return -1;
	}
	else {
		halHostSync(0x600DB00F);	// send ok to host
	}

	//sync4
	halHostSync((int)0x600d600d);

	nmglViewport(0, 0, WIDTH_IMAGE, HEIGHT_IMAGE);

} 

