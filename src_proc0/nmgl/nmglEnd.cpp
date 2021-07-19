#include "demo3d_nm0.h"
#include "nmgl.h"


#pragma code_section ".text_nmgl"

SECTION(".data_imu7") Array vertexArrayTmp;
SECTION(".data_imu7") Array normalArrayTmp;
SECTION(".data_imu7") Array colorArrayTmp;
//TEXTURING_PART
SECTION(".data_imu7") Array texcoordArrayTmp; //XXX: Only one texture unit is supported. So one tmpArray.
//TEXTURING_PART

SECTION(".text_nmgl")
void nmglEnd ()
{
	NMGL_Context_NM0 *cntxt = NMGL_Context_NM0::getContext();

	if (!cntxt->beginEndInfo.inBeginEnd) {
		cntxt->error = NMGL_INVALID_OPERATION;
		return;
	}
	cntxt->beginEndInfo.inBeginEnd = false;

	nmblas_scopy(sizeof32(Array), (float*)&cntxt->vertexArray, 1, (float*)&vertexArrayTmp, 1);
	nmblas_scopy(sizeof32(Array), (float*)&cntxt->normalArray, 1, (float*)&normalArrayTmp, 1);
	nmblas_scopy(sizeof32(Array), (float*)&cntxt->colorArray, 1, (float*)&colorArrayTmp, 1);
//TEXTURING_PART
	nmblas_scopy(sizeof32(Array), (float*)&cntxt->texState.texcoordArray[0], 1, (float*)&texcoordArrayTmp, 1); //XXX: Only one texture unit is supported.
	NMGLenum clientActiveTexUnitTmp = cntxt->texState.clientActiveTexUnit;
	unsigned int clientActiveTexUnitIndexTmp = cntxt->texState.clientActiveTexUnitIndex;
//TEXTURING_PART

	NMGLboolean arrayEnabled = cntxt->beginEndInfo.vertexCounter != 0;
	
	cntxt->vertexArray.enabled = arrayEnabled;
	nmglVertexPointer(4, NMGL_FLOAT, 0, cntxt->beginEndInfo.vertex);

	cntxt->normalArray.enabled = arrayEnabled;
	nmglNormalPointerNM(NMGL_FLOAT, 0, cntxt->beginEndInfo.normal);

	cntxt->colorArray.enabled = arrayEnabled;
	nmglColorPointer(4, NMGL_FLOAT, 0, cntxt->beginEndInfo.color);
	
//TEXTURING_PART
	//XXX: Only one texture unit is supported.
	cntxt->texState.clientActiveTexUnit = NMGL_TEXTURE0;
	cntxt->texState.clientActiveTexUnitIndex = 0;
	cntxt->texState.texcoordArray[0].enabled = cntxt->vertexArray.enabled = arrayEnabled;
	nmglTexCoordPointer(2, NMGL_FLOAT, 0, cntxt->beginEndInfo.texcoord);
	
//TEXTURING_PART
	
	//printf("vertexCounter=%d\n", cntxt->beginEndInfo.vertexCounter);
	nmglDrawArrays(cntxt->beginEndInfo.mode, 0, cntxt->beginEndInfo.vertexCounter);

	nmblas_scopy(sizeof32(Array), (float*)&vertexArrayTmp, 1, (float*)&cntxt->vertexArray, 1);
	nmblas_scopy(sizeof32(Array), (float*)&normalArrayTmp, 1, (float*)&cntxt->normalArray, 1);
	nmblas_scopy(sizeof32(Array), (float*)&colorArrayTmp, 1, (float*)&cntxt->colorArray, 1);
//TEXTURING_PART
	nmblas_scopy(sizeof32(Array), (float*)&texcoordArrayTmp, 1,(float*)&cntxt->texState.texcoordArray[0], 1); //XXX: Only one texture unit is supported.
	cntxt->texState.clientActiveTexUnit = clientActiveTexUnitTmp;
	cntxt->texState.clientActiveTexUnitIndex = clientActiveTexUnitIndexTmp;
//TEXTURING_PART
	//printf("end\n\n");
	
}
