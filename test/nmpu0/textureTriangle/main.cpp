#include "nmtype.h"
#include "nmgldef.h"
#include <cstdio>
#include "nmgltex_common.h"
#include "nmgltex_nm0.h"
#include "demo3d_nm0.h"
#include <cstdlib>
#include "nmplv/vSupport.h"
#include "malloc32.h"
#include "time.h"

#ifndef __NM__
#include "bmp.h"
#include "image.h"
#endif

#ifdef __GNUC__
#define SECTION(sec) __attribute__((section(sec)))
#else
#define SECTION(sec)
#endif // __GNUC__

#define TRIANGLE_AMOUNT 2

//Массив текстур в виде структур типа image_t
#define TEXTURE_AMOUNT 9

extern "C" TexImage2D teximage_256_256;
extern "C" TexImage2D teximage_mytexture;
extern "C" TexImage2D teximage_mytexture_256_256;
extern "C" TexImage2D teximage_128_128;
extern "C" TexImage2D teximage_64_64;
extern "C" TexImage2D teximage_32_32;
extern "C" TexImage2D teximage_16_16;
extern "C" TexImage2D teximage_8_8;
extern "C" TexImage2D teximage_4_4;
extern "C" TexImage2D teximage_2_2;
extern "C" TexImage2D teximage_1_1;

#ifndef __NM__
//массив изображений после текстурирования
image_t result_images [TRIANGLE_AMOUNT]; 


/**
Функция rawToImage выполняет преобразование массива цветов пикселей в структуру типа image_t.

\param triangles [in] Массив цветов пикселей треугольников
\param windows [in] Массив с данными о треугольниках в массиве triangles
\param images [in] Массив структур типа image_t для сохранения информации о треугольниках
\param count [in] Количество треугольников 
*/
int rawToImage (nm32s* triangles, Rectangle* windows, image_t* images, int count);

#endif

/**
Функция printPattern выполняет вывод на экран паттерны для треугольников в виде псевдографики.

\param patterns [in] Массив паттернов треугольников
\param triangles [in] Массив цветов треугольников (не используется)
\param count [in] Количество паттернов
*/
void printPattern(Pattern* patterns, int count);

//Массив данных о треугольниках (координаты вершин, текстурные координаты и т.д.)
SECTION(".data_imu0") TrianglesInfo triangles;

// Паттерны треугольников. Паттерн представляет собой массив элементов из WIDTH_PTRN=32 строк и HEIGHT_PTRN=32 столбцов.
// Одна строка матрицы состоит из 32 элементов по 2 бита на элемент => каждая строка занимает 64 бита.
// Всего паттерн (WIDTH_PTRN * HEIGHT_PTRN / 16) intов на один треугольник
// 0-ой int - младшая половина 64-битной 0-ой строки паттерна
// 1-ой int - младшая половина 64-битной 0-ой строки паттерна
// 2-ой int - младшая половина 64-битной 1-ой строки паттерна
// 3-ой int - младшая половина 64-битной 2-ой строки паттерна
// 0-ая строка паттерна - верхняя строка
SECTION(".data_imu0") Pattern patterns [TRIANGLE_AMOUNT] = { 
    {0x50000000, 0x00000000, 
    0x54000000, 0x00000000, 
    0x54000000, 0x00000001, 
    0x55000000, 0x00000001, 
    0x55400000, 0x00000005, 
    0x55400000, 0x00000005, 
    0x55500000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55550000, 0x00000055, 
    0x55554000, 0x00000055, 
    0x55554000, 0x00000155, 
    0x55555000, 0x00000155, 
    0x55555400, 0x00000555, 
    0x55555400, 0x00000555, 
    0x55555500, 0x00001555, 
    0x55555500, 0x00001555, 
    0x55555540, 0x00001555, 
    0x55555550, 0x00005555, 
    0x55555550, 0x00005555, 
    0x55555555, 0x00015555, 
    0x55555540, 0x00015555, 
    0x55540000, 0x00055555, 
    0x50000000, 0x00055555, 
    0x00000000, 0x00055540, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000}, 
    
    {0x50000000, 0x00000000, 
    0x54000000, 0x00000000, 
    0x54000000, 0x00000001, 
    0x55000000, 0x00000001, 
    0x55400000, 0x00000005, 
    0x55400000, 0x00000005, 
    0x55500000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55540000, 0x00000015, 
    0x55550000, 0x00000055, 
    0x55554000, 0x00000055, 
    0x55554000, 0x00000155, 
    0x55555000, 0x00000155, 
    0x55555400, 0x00000555, 
    0x55555400, 0x00000555, 
    0x55555500, 0x00001555, 
    0x55555500, 0x00001555, 
    0x55555540, 0x00001555, 
    0x55555550, 0x00005555, 
    0x55555550, 0x00005555, 
    0x55555555, 0x00015555, 
    0x55555540, 0x00015555, 
    0x55540000, 0x00055555, 
    0x50000000, 0x00055555, 
    0x00000000, 0x00055540, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 
    0x00000000, 0x00000000},
};

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

unsigned int timeMod = 0;
unsigned int timeModf = 0;
unsigned int timeGetPixelValue = 0;
unsigned int timeLog2f = 0;
unsigned int timeDiv = 0;
unsigned int timeFmod = 0;
unsigned int timeMemAccess = 0;
unsigned int timeGetPixelLinear = 0;
unsigned int timeGetPixelNearest = 0;
unsigned int timeGetPixelLinear_interpolatePixels = 0;
unsigned int timeGetPixelLinear_floor = 0;
unsigned int timeGetPixelLinear_modf = 0;
unsigned int timeInterpolateMipmap = 0;
unsigned int timeInterpolateMipmap_modf = 0;
unsigned int timeInterpolateMipmap_interp = 0;
unsigned int timePerspectiveCorrect = 0;
unsigned int timePerspectiveCorrect_div = 0;
unsigned int timeSqrtf = 0;
unsigned int timeBuildFbPixel = 0;
unsigned int timeTexFunction = 0;
unsigned int timeGetPixelLinear_getPixel = 0;
unsigned int timeWrapCoord = 0;
unsigned int timeWrapCoord_div = 0;
unsigned int timeWrapCoord_repeat = 0;
unsigned int timeWrapCoord_clamp = 0;
unsigned int timeWrapCoord_calcMaxVal = 0;


void resetCounters() {
	timeMod = 0;
	timeModf = 0;
	timeGetPixelValue = 0;
	timeLog2f = 0;
	timeDiv = 0;
	timeFmod = 0;
	timeMemAccess = 0;
	timeGetPixelLinear = 0;
	timeGetPixelNearest = 0;
	timeGetPixelLinear_interpolatePixels = 0;
	timeGetPixelLinear_floor = 0;
	timeGetPixelLinear_modf = 0;
	timeGetPixelLinear_getPixel = 0; 
	timeInterpolateMipmap = 0;
	timeInterpolateMipmap_modf = 0;
	timeInterpolateMipmap_interp = 0;
	timePerspectiveCorrect = 0;
	timePerspectiveCorrect_div = 0;
	timeSqrtf = 0;
	timeTexFunction = 0;
	timeBuildFbPixel = 0;
	timeWrapCoord = 0;
	timeWrapCoord_div = 0;
	timeWrapCoord_repeat = 0;
	timeWrapCoord_clamp = 0;
	timeWrapCoord_calcMaxVal = 0;
};

void printCounters(unsigned int allTime) {
	
	printf("%u\t",(unsigned int)timeGetPixelValue); //timeGetPixelValue
	printf("%u\t",(unsigned int)timeGetPixelNearest); //timeGetPixelNearest
	printf("%u\t",(unsigned int)timeGetPixelLinear); //timeGetPixelLinear
	printf("%u\t",(unsigned int)timeGetPixelLinear_interpolatePixels); //timeGetPixelLinear_interpolatePixels
	printf("%u\t",(unsigned int)timeGetPixelLinear_floor); //timeGetPixelLinear_floor
	printf("%u\t",(unsigned int)timeGetPixelLinear_modf); //timeGetPixelLinear_modf
	printf("%u\t",(unsigned int)timeGetPixelLinear_getPixel); //timeGetPixelLinear_getPixel
	printf("%u\t",(unsigned int)timeLog2f); //timeLog2f
	printf("%u\t",(unsigned int)timeInterpolateMipmap); //timeInterpolateMipmap
	printf("%u\t",(unsigned int)timeInterpolateMipmap_modf); //timeInterpolateMipmap_modf
	printf("%u\t",(unsigned int)timeInterpolateMipmap_interp); //timeInterpolateMipmap_interp
	printf("%u\t",(unsigned int)timePerspectiveCorrect); //timePerspectiveCorrect
	printf("%u\t",(unsigned int)timePerspectiveCorrect_div); //timePerspectiveCorrect_div
	printf("%u\t",(unsigned int)timeSqrtf); //timeSqrtf
	printf("%u\t",(unsigned int)timeTexFunction); //timeTexFunction
	printf("%u\t",(unsigned int)timeBuildFbPixel); //timeBuildFbPixel
	printf("%u\t",(unsigned int)timeWrapCoord); //timeWrapCoord
	printf("%u\t",(unsigned int)timeWrapCoord_div); //timeWrapCoord_div
	printf("%u\t",(unsigned int)timeWrapCoord_repeat); //timeWrapCoord_repeat
	printf("%u\t",(unsigned int)timeWrapCoord_clamp); //timeWrapCoord_clamp
	printf("%u\t",(unsigned int)timeWrapCoord_calcMaxVal); //timeWrapCoord_calcMaxVal
	printf("\n\n");
	
	printf("timeGetPixelValue/allTime = %f\n",(float)timeGetPixelValue/allTime*100.0f); //timeGetPixelValue
	printf("timeGetPixelNearest/allTime = %f\n",(float)timeGetPixelNearest/allTime*100.0f); //timeGetPixelNearest
	printf("timeGetPixelLinear/allTime = %f\n",(float)timeGetPixelLinear/allTime*100.0f); //timeGetPixelLinear
	printf("timeGetPixelLinear_interpolatePixels/timeGetPixelLinear = %f\n",(float)timeGetPixelLinear_interpolatePixels/timeGetPixelLinear*100.0f); //timeGetPixelLinear_interpolatePixels
	printf("timeGetPixelLinear_floor/timeGetPixelLinear = %f\n",(float)timeGetPixelLinear_floor/timeGetPixelLinear*100.0f); //timeGetPixelLinear_floor
	printf("timeGetPixelLinear_modf/timeGetPixelLinear = %f\n",(float)timeGetPixelLinear_modf/timeGetPixelLinear*100.0f); //timeGetPixelLinear_modf
	printf("timeGetPixelLinear_getPixel/timeGetPixelLinear = %f\n",(float)timeGetPixelLinear_getPixel/timeGetPixelLinear*100.0f); //timeGetPixelLinear_getPixel
	printf("timeLog2f/allTime = %f\n",(float)timeLog2f/allTime*100.0f); //timeLog2f
	printf("timeInterpolateMipmap/allTime = %f\n",(float)timeInterpolateMipmap/allTime*100.0f); //timeInterpolateMipmap
	printf("timeInterpolateMipmap_modf/timeInterpolateMipmap = %f\n",(float)timeInterpolateMipmap_modf/timeInterpolateMipmap*100.0f); //timeInterpolateMipmap_modf
	printf("timeInterpolateMipmap_interp/timeInterpolateMipmap = %f\n",(float)timeInterpolateMipmap_interp/timeInterpolateMipmap*100.0f); //timeInterpolateMipmap_interp
	printf("timePerspectiveCorrect/allTime = %f\n",(float)timePerspectiveCorrect/allTime*100.0f); //timePerspectiveCorrect
	printf("timePerspectiveCorrect_div/timePerspectiveCorrect = %f\n",(float)timePerspectiveCorrect_div/timePerspectiveCorrect*100.0f); //timePerspectiveCorrect_div
	printf("timeSqrtf/allTime = %f\n",(float)timeSqrtf/allTime*100.0f); //timeSqrtf
	printf("timeTexFunction/allTime = %f\n",(float)timeTexFunction/allTime*100.0f); //timeTexFunction
	printf("timeBuildFbPixel/allTime = %f\n",(float)timeBuildFbPixel/allTime*100.0f); //timeBuildFbPixel
	printf("timeWrapCoord/allTime = %f\n",(float)timeWrapCoord/allTime*100.0f); //timeWrapCoord
	printf("timeWrapCoord/timeWrapCoord = %f\n",(float)timeWrapCoord/timeWrapCoord*100.0f); //timeWrapCoord
	printf("timeWrapCoord_div/timeWrapCoord = %f\n",(float)timeWrapCoord_div/timeWrapCoord*100.0f); //timeWrapCoord_div
	printf("timeWrapCoord_repeat/timeWrapCoord = %f\n",(float)timeWrapCoord_repeat/timeWrapCoord*100.0f); //timeWrapCoord_repeat
	printf("timeWrapCoord_clamp/timeWrapCoord = %f\n",(float)timeWrapCoord_clamp/timeWrapCoord*100.0f); //timeWrapCoord_clamp
	printf("timeWrapCoord_calcMaxVal/timeWrapCoord = %f\n",(float)timeWrapCoord_calcMaxVal/timeWrapCoord*100.0f); //timeWrapCoord_calcMaxVal
	printf("\n\n");
	
};

SECTION(".text_demo3d") 
int main ()
{
	
	NMGL_Context_NM0 *test_cntxt;
	NMGLSynchroData synchroData;
	synchroData.init();
	NMGL_Context_NM0::create(&synchroData);	
	test_cntxt = NMGL_Context_NM0::getContext();
	test_cntxt->init(&synchroData);
	
    //Массивы растеризованных и закрашенных треугольников
	nm32s pSrcTriangle[WIDTH_PTRN * HEIGHT_PTRN * TRIANGLE_AMOUNT];
	nm32s pDstTriangle [WIDTH_PTRN * HEIGHT_PTRN * TRIANGLE_AMOUNT]; 
    
    //Массив значений цветов для треугольников, один цвет на треугольник
    v4nm32s colors [TRIANGLE_AMOUNT];
	((nm32s*)colors)[0] = (nm32s)255;
	((nm32s*)colors)[1] = (nm32s)0;
	((nm32s*)colors)[2] = (nm32s)255;
	((nm32s*)colors)[3] = (nm32s)255;
    ((nm32s*)colors)[4] = (nm32s)255;
	((nm32s*)colors)[5] = (nm32s)255;
	((nm32s*)colors)[6] = (nm32s)0;
	((nm32s*)colors)[7] = (nm32s)255;
	
	//Информация о размещении видимой части треугольников в сегменте
    Rectangle windows [TRIANGLE_AMOUNT];
    
    int count = TRIANGLE_AMOUNT;
    int i = 0;
    int j = 0;
	
	clock_t clkStart=0;
	clock_t clkEnd=0;
	clock_t diff = 0;


	printf ("Start textureTriangle test...\n");

    windows[0].x = -1;
    windows[0].y = 0;
    windows[0].width = 32;
    windows[0].height = 32;
  
    windows[1].x = -1;
    windows[1].y = 0;
    windows[1].width = 32;
    windows[1].height = 32;

    //setup triangles parameters
    
     //float x0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
     //float y0[TRIANGLE_AMOUNT] = {10.0f, 10.0f};
     //float x1[TRIANGLE_AMOUNT] = {15.0f, 15.0f};
     //float y1[TRIANGLE_AMOUNT] = {30.0f, 30.0f};
     //float x2[TRIANGLE_AMOUNT] = {26.0f, 26.0f};
     //float y2[TRIANGLE_AMOUNT] = {5.0f, 5.0f};
   
    //float x0[TRIANGLE_AMOUNT] = {399.0f, 399.0f};
    //float y0[TRIANGLE_AMOUNT] = {354.0f, 354.0f};
    //float x1[TRIANGLE_AMOUNT] = {384.0f, 384.0f};
    //float y1[TRIANGLE_AMOUNT] = {374.0f, 374.0f};
    //float x2[TRIANGLE_AMOUNT] = {410.0f, 410.0f};
    //float y2[TRIANGLE_AMOUNT] = {379.0f, 379.0f};
    //
    //float s0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    //float t0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    //float s1[TRIANGLE_AMOUNT] = {0.5f, 0.5f};
    //float t1[TRIANGLE_AMOUNT] = {0.5f, 0.5f};
    //float s2[TRIANGLE_AMOUNT] = {0.5f, 0.5f};
    //float t2[TRIANGLE_AMOUNT] = {0.0f, 0.0f};

    float x0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float y0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float x1[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float y1[TRIANGLE_AMOUNT] = {31.0f, 31.0f};
    float x2[TRIANGLE_AMOUNT] = {31.0f, 31.0f};
    float y2[TRIANGLE_AMOUNT] = {31.0f, 31.0f};
    
    float s0[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float t0[TRIANGLE_AMOUNT] = {1.0f, 1.0f};
    float s1[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float t1[TRIANGLE_AMOUNT] = {0.0f, 0.0f};
    float s2[TRIANGLE_AMOUNT] = {1.0f, 1.0f};
    float t2[TRIANGLE_AMOUNT] = {0.0f, 0.0f};


    
    float z[TRIANGLE_AMOUNT] = {1.0f, 1.0f}; //minus (z in camera space)
    
	for (int counter = 0; counter < 1; counter++)
	{
		//printf ("%d\n", counter);
		triangles.x0 = x0;
		triangles.y0 = y0;
		triangles.x1 = x1;
		triangles.y1 = y1;
		triangles.x2 = x2;
		triangles.y2 = y2;
 
		triangles.s0 = s0;
		triangles.t0 = t0;
		triangles.s1 = s1;
		triangles.t1 = t1;
		triangles.s2 = s2;
		triangles.t2 = t2;
    
		triangles.z0 = z;
		triangles.z1 = z;
		triangles.z2 = z;
	
		triangles.colors = colors;
			
		//Активный текстурный модуль
		test_cntxt->texState.activeTexUnitIndex = 0;
		unsigned int activeTexUnitIndex = test_cntxt->texState.activeTexUnitIndex;
    
		//Текстурный объект, привязанный к активному текстурному модулю
		test_cntxt->texState.texUnits[activeTexUnitIndex].boundTexObject = &test_cntxt->texState.texObjects[0];
		TexObject* boundTexObject = test_cntxt->texState.texUnits[activeTexUnitIndex].boundTexObject;

		//boundTexObject->texImages2D[0] = teximage_mytexture;
		boundTexObject->texImages2D[0] = teximage_mytexture_256_256;
		boundTexObject->texImages2D[1] = teximage_128_128;
		boundTexObject->texImages2D[2] = teximage_64_64;
		boundTexObject->texImages2D[3] = teximage_32_32;
		boundTexObject->texImages2D[4] = teximage_16_16;
		boundTexObject->texImages2D[5] = teximage_8_8;
		boundTexObject->texImages2D[6] = teximage_4_4;
		boundTexObject->texImages2D[7] = teximage_2_2;
		boundTexObject->texImages2D[8] = teximage_1_1;

		//default texEnvColor = (0.0f, 0.0f, 0.0f, 0.0f)
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[0] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[1] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[2] = 0.0f;
		test_cntxt->texState.texUnits[activeTexUnitIndex].texEnvColor[3] = 0.0f;

		boundTexObject->texMagFilter = NMGL_NEAREST; //default LINEAR
		boundTexObject->texWrapS = NMGL_CLAMP_TO_EDGE; // default REPEAT
		boundTexObject->texWrapT = NMGL_CLAMP_TO_EDGE;// default REPEAT
		test_cntxt->texState.texUnits[activeTexUnitIndex].texFunctionName = NMGL_REPLACE; //default = NMGL_MODULATE
	
//texMinFilter = NMGL_NEAREST
		printf ("texMinFilter = NMGL_NEAREST\n");
		resetCounters();
		boundTexObject->texMinFilter = NMGL_NEAREST;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %u\n",(unsigned int)diff);
		printCounters(diff);
#if 0
//texMinFilter = NMGL_LINEAR
		printf ("texMinFilter = NMGL_LINEAR\n");
		resetCounters();
		boundTexObject->texMinFilter = NMGL_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %u\n",(unsigned int)diff);
		printCounters(diff);
	
//texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR
		printf ("texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR\n");
		resetCounters();
		boundTexObject->texMinFilter = NMGL_NEAREST_MIPMAP_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %u\n",(unsigned int)diff);
		printCounters(diff);
	
//texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR
		printf ("texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR\n");
		resetCounters();
		boundTexObject->texMinFilter = NMGL_LINEAR_MIPMAP_LINEAR;

		clkStart=clock();	
		textureTriangle(&triangles, pDstTriangle, count);
		clkEnd=clock();	
		diff = clkEnd - clkStart;
		printf("time = %u\n",(unsigned int)diff);
		printCounters(diff);		
		
#endif
		
}
	
#ifndef __NM__

    //convert result to image_t to compare with etalon    
    rawToImage(pDstTriangle, windows, result_images, count);

    char* fileNames [TRIANGLE_AMOUNT] = {"./result_1.bmp", "./result_2.bmp"};

    for (i = 0; i < count; i++)
    {
        saveToBmp (32, result_images[i], fileNames[i]);
    }
#endif //__NM__        

	printf ("End textureTriangle test...\n");
    return 0;
}

#ifndef __NM__
int rawToImage (nm32s* triangles, Rectangle* windows, image_t* images, int count)
{
    
    int i = 0;
    int srcRow = 0;
    int dstRow = 0;
    int col = 0;

    nm32s* triangle = triangles;
    
    for (i = 0; i < count; i++)
    {
        int width = windows[i].width;
        int height = windows[i].height;
        nm32s pixel_pos = 0;
        nm32s pixel_value = 0;
        
        images[i].width = width;
        images[i].height = height;
        images[i].format = RGBA;
        images[i].type = UNSIGNED_BYTE;
		images[i].alignment = 1;
        
        //copy pixels from triangles to image
        images[i].pixels = (unsigned char*) malloc(width*height*4); //TODO: nmc char type has size of 4 bytes. 
                                                                    //Perhaps it would be better to use UNSIGNED_INT_8_8_8_8
        for (srcRow = height-1, dstRow = 0; srcRow >= 0; srcRow--, dstRow++)
        {
            for (col = 0; col < width; col++)
            {
                pixel_pos = (dstRow*width + col)*4;
                pixel_value = triangle[srcRow*width + col];
				//0xARGB t0 0xRGBA
                ((unsigned char*)images[i].pixels)[pixel_pos] = (pixel_value & 0x00ff0000) >> 16;
                ((unsigned char*)images[i].pixels)[pixel_pos + 1] = (pixel_value & 0x0000ff00) >> 8;
                ((unsigned char*)images[i].pixels)[pixel_pos + 2] = (pixel_value & 0x000000ff);
                ((unsigned char*)images[i].pixels)[pixel_pos + 3] = (pixel_value & 0xff000000) >> 24;
            }
        }
        
        triangle += windows[i].height * windows[i].width;

        // for (dstRow = 0; dstRow < height; dstRow++)
        // {
            // for (col = 0; col < width; col++)
            // {
                // printf ("%08x ", ((int*)images[i].pixels)[dstRow*width + col]);
            // }
        // printf ("\n\n");            
        // }
  
        // printf ("\n\n");   
    }
    
    
    
    return 0;
}

void printPattern(Pattern* patterns, int count)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < count; i++)
    {
        for (int j = 0; j < 32; j++)
		{
			//sprintf("i = %d %x \n", i, context->ppSrcPackPtrns[0][i]);
			for (int k = 0; k < 32; k++)
				if (((nm64s*)patterns[i])[j] & ((nm64s)1 << (k * 2)))
					printf("1 ");
				else
					printf("0 ");
			// if (i & 1)
            printf("\n");
		}
    }
}

#endif //__NM__