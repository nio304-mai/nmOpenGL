#ifndef DEMO3D_NM1_H 
#define DEMO3D_NM1_H 

#include "nmtype.h"
#include "nmgl.h"
#include "demo3d_common.h"
#include "imagebuffer.h"
#include "myserverdma.h"
#include "nmgltex_nm1.h"

typedef void DepthCore(nm32s &buffZ, nm32s &trianSrcZ, nm32s &trianDstZ);


void selectPatterns(nm32s* dydxTable, nm32s* dX, nm32s* dY, nm32s* x0, nm32s* pPtrnPaintSide, nm32s** pSrcPack, int nSize, int* pTmp);

struct NMGL_Context_NM1 {
	Pattern polyImgTmp[SMALL_SIZE];
	
	PatternsArray* patterns;

	nm32s** ppSrcPackPtrns;
	nm32s** ppDstPackPtrns;
	nm32s* nSizePtrn32;

	int* buffer0;
	int* buffer1;
	clock_t t0, t1;

	NMGLSynchro synchro;
	ImageData* imagesData;
	PolygonsArray* polygonsData;

	DepthBuffer depthBuffer;
	ImageBuffer colorBuffer;
	ImageBuffer smallColorBuff;
	ImageBuffer smallDepthBuff;

	nm32s** zBuffPoints;
	nm32s** imagePoints;

	Pattern* ppPtrns1_2s[SMALL_SIZE];
	Pattern* ppPtrns2_2s[SMALL_SIZE];
	Pattern* ppPtrnsCombined_2s[SMALL_SIZE];
	nm32s minusOne[SMALL_SIZE];

	nm32s* offsetTrX;
	nm32s* offsetTrY;
	nm32s* widths;
	nm32s* heights;
	nm32s* valuesZ;
	nm32s* valuesC;

#ifdef TEXTURE_ENABLED
	nm32f* x0;
	nm32f* y0;
	nm32f* x1;
	nm32f* y1;
	nm32f* x2;
	nm32f* y2;

	nm32f* texS0;
	nm32f* texT0;
	nm32f* texS1;
	nm32f* texT1;
	nm32f* texS2;
	nm32f* texT2;

	nm32f* zEye;
	// int dummy[2];
#endif //TEXTURE_ENABLED
	
	NMGL_Context_NM1_Texture texState;

};


extern "C" {
	
	/**
	 *  \defgroup mMaskVxN mMaskVxN
	 *  \brief Функция маскирования пакетов треагольников
	 *  
	 *  \param pTriangles [in] Description for pTriangles
	 *  \param pMask [in] Description for pMask
	 *  \param pROI [in] Description for pROI
	 *  \param imageStride [in] Description for imageStride
	 *  \param pTriangsHeight [in] Description for pTriangsHeight
	 *  \param pTriangsWidth [in] Description for pTriangsWidth
	 *  \param count [in] Description for count
	 *  \retval Return description
	 *  
	 *  \par
	 *  \xmlonly
	 *      <testperf>
	 *          <param> pTriangles </param> <values>  </values>
	 *          <param> pMask </param> <values>  </values>
	 *          <param> pROI </param> <values>  </values>
	 *          <param> imageStride </param> <values>  </values>
	 *          <param> pTriangsHeight </param> <values>  </values>
	 *          <param> pTriangsWidth </param> <values>  </values>
	 *          <param> count </param> <values>  </values>
	 *      </testperf>
	 *  \endxmlonly
	 */
	 //! \{
	void mMaskVxN_32s(nm32s* pTriangles, nm32s* pMask, nm32s** pROI, int imageStride, int* pTriangsHeight, int* pTriangsWidth, int count);
	 //! \}
	
	void depthTest(nm32s** pROI, int imageStride, nm32s* pTriangles, nm32s* pDstMask, int* pTriangsHeight, int* pTriangsWidth, int count);
	

	void selectPaintSide(nm32s* pSrc, int X, int Y, nm32s* pDst, int nSize);
	
	void mMulCVxN_2s32s(Pattern* ppSrcTreangle_2s, Rectangle* window, int* valueC, nm32s* pDstTreangle_32s, int count);
	void mMulCVxN_2s_RGB8888(Pattern* ppSrcTreangle_2s, Rectangle* window, v4nm8s* valueC, nm32s* pDstTreangle_32s, int count);
	void mMulCVxN_2s16s(Pattern* ppSrcTreangle_2s, Rectangle* window, int* valueC, nm16s* pDstTreangle_32s, int count);
	void mMulCVxN_2s_RGB565(Pattern* ppSrcTreangle_2s, Rectangle* window, int* valueC, nm16s* pDstTreangle_32s, int count);
	
	
	void mAndVxN_32u(nm32u** pSrc1, nm32u** pSrc2, nm32u** pDst, int* size, int count);
	
	void copyPacket_32s(nm32s** ppSrc, nm32s** ppDst, int* size, int count);

	void mergePtrnsAddr3(nm32s** ppSrcCA, nm32s** ppSrcCB, nm32s** ppSrcBA, int step, nm32s** ppDst, int count);
	void mergePtrnsAddr2(nm32s** ppSrc1, nm32s** ppSrc2, int step, nm32s** ppDst, int count);

	/**
	 *  \defgroup selectColorChannel selectColorChannel
	 *  \brief Функция выборки канала из BGR_32(8-8-8-8) изображения
	 *  
	 *  \param srcImage [in] Входное изображение
	 *  \param channel [in] Канал ( 0 - blue, 1 - green, 2 -red)
	 *  \param dst [out] Выходной массив
	 *  \param size [in] Размер изображения в пикселях
	 *  \retval Return description
	 *  
	 *  \par
	 *  \xmlonly
	 *      <testperf>
	 *          <param> srcImage </param> <values>  </values>
	 *          <param> channel </param> <values>  </values>
	 *          <param> dst </param> <values>  </values>
	 *          <param> size </param> <values>  </values>
	 *      </testperf>
	 *  \endxmlonly
	 */
	void selectColorChannel(v4nm8s* srcImage, int channel, nm8s* dst, int size);

	void absIfNegElse0(int* src, int* dst, int size);

	int totalSum(nm32s* pVec, int size);

	void merge_v4nm32s(nm32s* src1, nm32s* src2, nm32s* src3, nm32s* src4, v4nm32s* dst, int size);
	
}

void drawTriangles(NMGL_Context_NM1* context);
void drawLines(NMGL_Context_NM1* context);
int getAddrPtrnsT(NMGL_Context_NM1* context, Polygons* poly);
int getAddrPtrnsL(NMGL_Context_NM1* context, Polygons* poly);

typedef struct TrianglesInfo {
	//Поля структуры для коммита 2fbdfcc0 nmOpenGLs
	float* x0; /**< Оконная координата x 0-ой вершины треугольника */
	float* y0; /**< Оконная координата y 0-ой вершины треугольника */
	float* x1; /**< Оконная координата x 1-ой вершины треугольника */
	float* y1; /**< Оконная координата y 1-ой вершины треугольника */
	float* x2; /**< Оконная координата x 2-ой вершины треугольника */
	float* y2; /**< Оконная координата y 2-ой вершины треугольника */
	float* z;  /**< Координата z треугольника (одна на три вершины)*/ //TODO: Needed float z in camera space, so float value
	v4nm32s* colors; /**< Цвет треугольника (один на три вершины) */
	int size;   /**< Количество треугольников */
	int maxSize; /**< Максимальное обрабатываемое количество треугольников */

				 //TODO: необходимо добавить в структуру Triangles (include\demo3d_nm0.h)
	float* s0; /**< Текстурная координата s 0-ой вершины треугольника */
	float* t0; /**< Текстурная координата t 0-ой вершины треугольника */
	float* s1; /**< Текстурная координата s 1-ой вершины треугольника */
	float* t1; /**< Текстурная координата t 1-ой вершины треугольника */
	float* s2; /**< Текстурная координата s 2-ой вершины треугольника */
	float* t2; /**< Текстурная координата t 2-ой вершины треугольника */
}TrianglesInfo;


typedef struct MyStruct {
	float x[5];
	float* x1;
	float* x2;
}MyStruct;

void textureTriangle(Pattern* patterns,
	TrianglesInfo* triangles,
	nm32s** pROI,
	Rectangle* windows,
	nm32s* pSrcTriangle,
	nm32s* pDstTriangle,
	int count);

/**
\brief Функция для вычисления значения edge-функции.

Функции edgeFunction вычисляет значение edge-функции для заданных точек.

\param triangles [in] Входной массив параметров треугольников
\param x0 [in] Координата x точки 0
\param y0 [in] Координата x точки 0
\param x1 [in] Координата x точки 1
\param y1 [in] Координата x точки 1
\param x2 [in] Координата x точки 2
\param y2 [in] Координата x точки 2
\param res [out] Результат вычисления функции
\retval void
*/
void edgeFunction(float x0, float y0, float x1, float y1, float x2, float y2, float* res);

void foo(
	Pattern* patterns,
	//TrianglesInfo* triangles,
	nm32s** pROI,
	MyStruct* a,
	Rectangle* windows
);

#endif
