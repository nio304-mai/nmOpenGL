#include "demo3d_nm0.h"
#include "nmgl.h"
#include "nmgl_data0.h"

#pragma code_section ".text_nmgl"

SECTION(".text_nmgl")
void nmglActiveTexture (NMGLenum texture)
{
	
	if ((texture < NMGL_TEXTURE0) || (texture >= NMGL_TEXTURE0 + NMGL_MAX_TEX_UNITS))
	{
		cntxt.error = NMGL_INVALID_ENUM;
		return;
	}

	cntxt.texState.activeTexUnit = texture;
	
	unsigned int activeTexUnitIndex = texture - NMGL_TEXTURE0;
	cntxt.texState.activeTexUnitIndex = activeTexUnitIndex;
	cntxt.synchro.writeInstr(1, NMC1_SET_ACTIVE_TEXTURE, (unsigned int)activeTexUnitIndex);
	
}
