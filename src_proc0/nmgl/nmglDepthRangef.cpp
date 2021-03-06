#include "demo3d_nm0.h"
#include "nmgl.h"
#include "nmblas.h"
#include "nmpp.h"
#include "ringbuffer.h"
#include "nmgl_data0.h"

#pragma code_section ".text_nmgl"

SECTION(".text_nmgl")
void nmglDepthRangef(NMGLclampf near,	NMGLclampf far) {
	cntxt.windowInfo.viewportMulZ = (far - near) * 0.5 * ZBUFF_MAX;
	cntxt.windowInfo.viewportAddZ = (far + near) * 0.5 * ZBUFF_MAX;
}
