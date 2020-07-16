#include "demo3d_common.h"
#include "demo3d_nm1.h"
#include "nmgldef.h"
#include <nmpp.h>
#include <stdio.h>

#ifdef TEXTURE_ENABLED

#include "nmgltex_nm1.h"
#include "nmgltex_common.h"
//#include "textureTriangle.h"

extern "C" TexImage2D teximage_256_256;
extern "C" TexImage2D teximage_mytexture;
extern "C" TexImage2D teximage_128_128;
extern "C" TexImage2D teximage_64_64;
extern "C" TexImage2D teximage_32_32;
extern "C" TexImage2D teximage_16_16;
extern "C" TexImage2D teximage_8_8;
extern "C" TexImage2D teximage_4_4;
extern "C" TexImage2D teximage_2_2;
extern "C" TexImage2D teximage_1_1;

SECTION(".data_shmem1") TrianglesInfo triangles;

union intfloat_t
{
    float fl;
    unsigned int uinteg;
};

SECTION(".data_imu0") intfloat_t texdata;

#endif //TEXTURE_ENABLED

SECTION(".data_imu0") Rectangle windows[NMGL_SIZE];

#define PRIMITIVE_AMOUNT 12 
SECTION(".data_shmem1") float cntxt_x0[PRIMITIVE_AMOUNT] = { 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f };
SECTION(".data_shmem1") float cntxt_y0[PRIMITIVE_AMOUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
SECTION(".data_shmem1") float cntxt_x1[PRIMITIVE_AMOUNT] = { 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f };
SECTION(".data_shmem1") float cntxt_y1[PRIMITIVE_AMOUNT] = { 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f, 0.0f, 31.0f };
SECTION(".data_shmem1") float cntxt_x2[PRIMITIVE_AMOUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
SECTION(".data_shmem1") float cntxt_y2[PRIMITIVE_AMOUNT] = { 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f, 31.0f };
SECTION(".data_shmem1") float cntxt_s0[PRIMITIVE_AMOUNT] = { 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f };
SECTION(".data_shmem1") float cntxt_t0[PRIMITIVE_AMOUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
SECTION(".data_shmem1") float cntxt_s1[PRIMITIVE_AMOUNT] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
SECTION(".data_shmem1") float cntxt_t1[PRIMITIVE_AMOUNT] = { 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f };
SECTION(".data_shmem1") float cntxt_s2[PRIMITIVE_AMOUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
SECTION(".data_shmem1") float cntxt_t2[PRIMITIVE_AMOUNT] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
SECTION(".data_shmem1") float cntxt_zEye[PRIMITIVE_AMOUNT] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

SECTION(".text_demo3d") void drawTriangles(NMGL_Context_NM1* context) {
	PolygonsConnector connector(context->polygonsData);
	Polygons* poly = connector.ptrTail();
	getAddrPtrnsT(context, poly);
	printf(") ");
	nm32s* mulZ = context->buffer0;
	nm32s* mulC = context->buffer0;
	nm32s* texC = context->buffer0 + WIDTH_PTRN*HEIGHT_PTRN*SMALL_SIZE;
	nm32s* zMaskBuffer = context->buffer1;
#ifdef TEXTURE_ENABLED
    nm32s* texTri = context->buffer0;
#endif //TEXTURE_ENABLED
	// printf("%s %d \n",__func__, __LINE__);
	msdWaitDma(0);
	// printf("%s %d \n",__func__, __LINE__);
	merge_v4nm32s(context->offsetTrX,
		context->offsetTrY,
		context->widths, 
		context->heights, 
		(v4nm32s*)windows, 
		poly->count);

	int point = 0;

	msdWaitDma(1);
	int countTrangles = poly->count;
	(*connector.pTail)++;

	while (countTrangles > 0) {
		int localSize = MIN(countTrangles, SMALL_SIZE);
		int point_x3 = point * 3;
		int* widths = context->widths + point;
		int* heights = context->heights + point;
		int* offsetsX = context->offsetTrX + point;
		int* valuesC = context->valuesC + point;
		int* valuesZ = context->valuesZ + point;

		//копирование паттернов во внутреннюю память. Паттерны копируются
		//не полностью, чтобы сэкономить время на пересылку
		copyPacket_32s(context->ppSrcPackPtrns + point_x3, 
			context->ppDstPackPtrns + point_x3, 
			context->nSizePtrn32 + point_x3, 3 * localSize);

		//объединение паттернов сторон в паттерн треугольника
		//объединение происходит не полностью (только значимой части) для
		//оптимизации
		mAndVxN_32u((nm32u**)context->ppPtrns1_2s, 
			(nm32u**)context->ppPtrns2_2s, 
			(nm32u**)context->ppPtrnsCombined_2s, 
			context->nSizePtrn32 + point_x3, localSize);

		//проверка активирования теста глубины
		if (context->depthBuffer.enabled == NMGL_FALSE) {
			mMulCVxN_2s32s(
				context->polyImgTmp,
				windows + point,
				context->minusOne,
				zMaskBuffer,
				localSize);
		}
		else {
			//умножение бинарных масок на Z
			mMulCVxN_2s32s(
				context->polyImgTmp,
				windows + point,
				valuesZ,
				mulZ,
				localSize);

			//mulZ теперь хранит z-треугольники

			//функция теста глубины
			depthTest(context->zBuffPoints + point, WIDTH_SEG,
				(nm32s*)mulZ,
				(nm32s*)zMaskBuffer,
				heights,
				widths, localSize);
		}

		//color v4nm8s in imgOffset
		mMulCVxN_2s_RGB8888(
			context->polyImgTmp,
			windows + point,
			(v4nm8s*)valuesC,
			mulC,
			localSize);

		//mulBuffer теперь хранит цвет

#ifdef TEXTURE_ENABLED //for test
		//предварительная настройка контекста для выполнения текстурирования
		//ручная загрузка текстур и настройка параметров
		       
        context->texState->activeTexUnitIndex = 0;
        unsigned int activeTexUnitIndex = context->texState->activeTexUnitIndex;
    
        context->texState->texUnits[activeTexUnitIndex].boundTexObject = &context->texState->texObjects[0];
        TexObject* boundTexObject = context->texState->texUnits[activeTexUnitIndex].boundTexObject;
        
        // boundTexObject->texImages2D[0] = teximage_256_256;
         // boundTexObject->texImages2D[0] = teximage_mytexture;
        boundTexObject->texImages2D[0] = teximage_2_2;
        //boundTexObject->texImages2D[0] = teximage_32_32;
        boundTexObject->texImages2D[1] = teximage_128_128;
        boundTexObject->texImages2D[2] = teximage_64_64;
        boundTexObject->texImages2D[3] = teximage_32_32;
        boundTexObject->texImages2D[4] = teximage_16_16;
        boundTexObject->texImages2D[5] = teximage_8_8;
        boundTexObject->texImages2D[6] = teximage_4_4;
        boundTexObject->texImages2D[7] = teximage_2_2;
        boundTexObject->texImages2D[8] = teximage_1_1;

        boundTexObject->texMinFilter = NMGL_NEAREST; //default NEAREST_MIPMAP_LINEAR
        boundTexObject->texMagFilter = NMGL_NEAREST; //default LINEAR
        boundTexObject->texWrapS = NMGL_REPEAT; // default REPEAT
        boundTexObject->texWrapT = NMGL_REPEAT;// default REPEAT

        context->texState->texUnits[activeTexUnitIndex].texFunctionName = NMGL_REPLACE; //default = NMGL_MODULATE
        
        //default texEnvColor = (0.0f, 0.0f, 0.0f, 0.0f)
        context->texState->texUnits[activeTexUnitIndex].texEnvColor[0] = 0.0f;
        context->texState->texUnits[activeTexUnitIndex].texEnvColor[1] = 0.0f;
        context->texState->texUnits[activeTexUnitIndex].texEnvColor[2] = 0.0f;
        context->texState->texUnits[activeTexUnitIndex].texEnvColor[3] = 0.0f;

        context->texState->unpackAlignment = 4;
        // printPattern(patterns, pSrcTriangle, TRIANGLE_AMOUNT);
#endif //TEXTURE_ENABLED

#ifdef TEXTURE_ENABLED
		if (context->texState->textureEnabled){

			//значения для структуры triangles помещаются в контекст из статических массивов
			//вне функции getAddrPtrnsT
			context->x0 = cntxt_x0;
			context->y0 = cntxt_y0;
			context->x1 = cntxt_x1;
			context->y1 = cntxt_y1;
			context->x2 = cntxt_x2;
			context->y2 = cntxt_y2;
			context->texS0 = cntxt_s0;
			context->texS1 = cntxt_s1;
			context->texS2 = cntxt_s2;
			context->texT0 = cntxt_t0;
			context->texT1 = cntxt_t1;
			context->texT2 = cntxt_t2;
			context->zEye = cntxt_zEye;

			//заполняем стуктуру triangles
        	triangles.x0 = context->x0 + point;
        	triangles.y0 = context->y0 + point;
        	triangles.x1 = context->x1 + point;
        	triangles.y1 = context->y1 + point;
        	triangles.x2 = context->x2 + point;
        	triangles.y2 = context->y2 + point;
     
        	triangles.s0 = context->texS0 + point;
        	triangles.t0 = context->texT0 + point;
        	triangles.s1 = context->texS1 + point;
        	triangles.t1 = context->texT1 + point;
        	triangles.s2 = context->texS2 + point;
        	triangles.t2 = context->texT2 + point;
        	
        	triangles.z = context->zEye + point;
			
			//printf ("**********\n");
			//for (int trCnt = 0; trCnt < localSize; trCnt++){
   //            printf ("triangle %x\n", trCnt);
			//	// printf("trCnt = %x\n", trCnt);
			//	// printf("x0 = %f\n", ((nm32f*)triangles.x0)[trCnt]);
			//	// printf("y0 = %f\n", ((nm32f*)triangles.x0)[trCnt]);
			//	// printf("x1 = %f\n", ((nm32f*)triangles.x1)[trCnt]);
			//	// printf("y1 = %f\n", ((nm32f*)triangles.y1)[trCnt]);
			//	// printf("x2 = %x\n", ((nm32f*)triangles.x2)[trCnt]);
			//	// printf("y2 = %f\n", ((nm32f*)triangles.y2)[trCnt]);
			//	// printf("s0 = %f\n", ((nm32f*)triangles.s0)[trCnt]);
			//	texdata.fl = ((nm32f*)triangles.s0)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.t0)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.s1)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.t1)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.s2)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.t2)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
   //            
			//	texdata.fl = ((nm32f*)triangles.x0)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.y0)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.x1)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.y1)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.x2)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.y2)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	texdata.fl = ((nm32f*)triangles.z)[trCnt];
			//	printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);
			//	// printf ("%x\n",texdata.uinteg);				
			//	// printf("t0 = %f\n", ((nm32f*)triangles.t0)[trCnt]);
			//	// printf("s1 = %f\n", ((nm32f*)triangles.s1)[trCnt]);
			//	// printf("t1 = %f\n", ((nm32f*)triangles.t1)[trCnt]);
			//	// printf("s2 = %x\n", ((nm32f*)triangles.s2)[trCnt]);
			//	// printf("t2 = %x\n", ((nm32f*)triangles.t2)[trCnt]);
			//	// printf("z = %x\n", ((nm32f*)triangles.t2)[trCnt]);
			//}
			
			
        	textureTriangle(context->polyImgTmp, &triangles, 
        	                context->imagePoints + point, 
        	                windows + point, 
        	                mulC, 
        	                mulC, 
        	                localSize);
		}
#endif //TEXTURE_ENABLED

		//функция накладывает маску на буфер с цветами 
		//и копирует треугольник в изображение
		mMaskVxN_32s((nm32s*)mulC,
			(nm32s*)zMaskBuffer,
			context->imagePoints + point, WIDTH_SEG,
			heights, widths, localSize);

		countTrangles -= SMALL_SIZE;
		point += SMALL_SIZE;
	}
	// printf("%s %d \n",__func__, __LINE__);

	return;
}

