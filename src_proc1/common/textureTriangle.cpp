#include "nmtype.h"
#include "demo3d_common.h"
#include "demo3d_nm1.h"
#include "nmgltex_nm1.h"
//#include "textureTriangle.h"
#include "nmgltex_common.h"
//#include <stdio.h>
#include <math.h>
#include <float.h> //TODO: only FLT_EPSILON is used from float.h
//#define FLT_EPSILON      1.192092896e-07F

#if 1 //variant_2
#define USE_BARYCENTRIC
// #define PERSPECTIVE_CORRECT
#define  TEXTURE_MIN_LOD   -1000
#define  TEXTURE_MAX_LOD    1000
#define  TEXTURE_BASE_LEVEL 0
#define  TEXTURE_MAX_LEVEL  1000	

union intfloat_t
{
	float fl;
	unsigned int uinteg;
};

typedef enum { MINIFICATION, MAGNIFICATION } lod_t;

typedef struct Vec2f {
	float x;
	float y;
} Vec2f;

typedef struct Vec3f {
	nm32f x;
	nm32f y;
	nm32f z;
} Vec3f;

typedef struct color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} color;

SECTION(".data_shmem1") Vec2f st;
SECTION(".data_shmem1") color pixelValue;
SECTION(".data_shmem1") Vec3f cv;
SECTION(".data_shmem1") Vec3f cs;
SECTION(".data_shmem1") Vec3f cc;
SECTION(".data_shmem1") Vec3f cf;
SECTION(".data_shmem1") Vec3f texEnvColor;
SECTION(".data_shmem1") intfloat_t texdata2[16];

//extern unsigned char pixels_2_2[16];

float c = 0.0; // minification vs. magnification switchover point, look glspec 1.3, chapter 3.8.8
volatile lod_t minMagFlag = MINIFICATION;
unsigned int borderWidth = 0; //TEXTURE BORDER - texture image's specified border width
int textureBaseLevel = 0;
int textureMaxLevel = 1000;
color borderColor;

extern NMGL_Context_NM1 cntxt;

#define TEXTURE_TRIANGLE_SECTION ".text_demo3d"

SECTION(TEXTURE_TRIANGLE_SECTION)
void edgeFunction(float x0, float y0, float x1, float y1, float x2, float y2, float* res)
{
	*res = (x2 - x0) * (y1 - y0) - (y2 - y0) * (x1 - x0);
}

SECTION(TEXTURE_TRIANGLE_SECTION)
int max(int a, int b)
{
	return (b > a) ? b : a;
}

SECTION(TEXTURE_TRIANGLE_SECTION)
int min(int a, int b)
{
	return (b < a) ? b : a;
}

SECTION(TEXTURE_TRIANGLE_SECTION)
float wrapCoord(NMGLint textureWrapMode, int texAxisSize, float texCoord)
{
	float min_coord_val = 1 / (float)texAxisSize*0.5; //CLAMP_TO_EDGE
													  //float min_s = 0.0f; //CLAMP
	float max_coord_val = 1.0f - min_coord_val;

	float resTexCoord = 0.0f;

	//Apply texture Wrap modes
	if (textureWrapMode == NMGL_REPEAT)
		resTexCoord = texCoord - floor(texCoord);
	else if (textureWrapMode == NMGL_CLAMP_TO_EDGE)
	{
		if (texCoord > max_coord_val) resTexCoord = max_coord_val;
		else if (texCoord < min_coord_val) resTexCoord = min_coord_val;
		else resTexCoord = texCoord;
	}
	else
	{
		printf("Unsupported textureWrapS or textureWrapT value. Exit.\n");
		getchar();
		return -1.0;
	}

	return resTexCoord;
}

SECTION(TEXTURE_TRIANGLE_SECTION) void textureTriangle(Pattern* patterns,
	TrianglesInfo* triangles,
	nm32s** pROI,
	Rectangle* windows,
	nm32s* pSrcTriangle,
	nm32s* pDstTriangle,
	int count)
{

	int image_num = 0;

	//Активный текстурный модуль
	cntxt.texState->activeTexUnitIndex = 0;
	unsigned int activeTexUnitIndex = cntxt.texState->activeTexUnitIndex;

	//Текстурный объект, привязанный к активному текстурному модулю
	cntxt.texState->texUnits[activeTexUnitIndex].boundTexObject = &cntxt.texState->texObjects[0];
	TexObject* boundTexObject = cntxt.texState->texUnits[activeTexUnitIndex].boundTexObject;

	float scaleFactor = 1.0;
	borderColor.r = (nm32f)0.0f;
	borderColor.g = (nm32f)0.0f;
	borderColor.b = (nm32f)0.0f;
	borderColor.a = (nm32f)0.0f;

	// color pixelValue; //moved to global scope 08072020
	pixelValue.r = (nm32f)0;
	pixelValue.g = (nm32f)0;
	pixelValue.b = (nm32f)0;

	//texEnvColor consists of rgb + alpha
	//Vec3f texEnvColor;//moved to gloabal scope 08072020
	float texEnvColorAlpha;
	texEnvColor.x = cntxt.texState->texUnits[activeTexUnitIndex].texEnvColor[0];
	texEnvColor.y = cntxt.texState->texUnits[activeTexUnitIndex].texEnvColor[1];
	texEnvColor.z = cntxt.texState->texUnits[activeTexUnitIndex].texEnvColor[2];
	texEnvColorAlpha = cntxt.texState->texUnits[activeTexUnitIndex].texEnvColor[3];

	//primitive color (glColor3f)
	Vec3f vertexRGB;
	vertexRGB.x = (nm32f)1.0;
	vertexRGB.y = (nm32f)1.0;
	vertexRGB.z = (nm32f)1.0;
	nm32f vertexAlpha = (nm32f)1.0;


	NMGLint textureMinFilter = boundTexObject->texMinFilter; //default NEAREST_MIPMAP_LINEAR
	NMGLint textureMagFilter = boundTexObject->texMagFilter; //default LINEAR
	NMGLint textureWrapS = boundTexObject->texWrapS; // default NMGL_REPEAT
	NMGLint textureWrapT = boundTexObject->texWrapT; // default NMGL_REPEAT

	NMGLint texEnvMode = cntxt.texState->texUnits[activeTexUnitIndex].texFunctionName; //default = NMGL_MODULATE

	NMGLint texBaseInternalFormat = boundTexObject->texImages2D[0].internalformat;//use level 0 texture format to select texture function

																				  //Calculate some parameters from OpenGL 1.3 spec
	int n = log2(boundTexObject->texImages2D[0].width);
	int m = log2(boundTexObject->texImages2D[0].height);
	int p = max(n, m) + TEXTURE_BASE_LEVEL; //p = max{n,m,l} + TEXTURE_BASE_LEVEL
	int q = min(p, TEXTURE_MAX_LEVEL);//min{p,TEXTURE_MAX_LEVEL} page 140, glspec 1.3

	unsigned long long int temp;
	nm32s* dst = pDstTriangle;
	nm32s* src = pSrcTriangle;
	int winX0 = 0;
	int winY0 = 0;

	for (int cnt = 0; cnt < count; cnt++) {
		nm64s* pattern = (nm64s*)(patterns + cnt);
		pattern += windows[cnt].y;

		int width = windows[cnt].width;

		if (windows[cnt].x < 0) {
			width += windows[cnt].x;
		}

#ifdef __NM__
		int winOffset = ((int)(pROI[cnt]) - (int)cntxt.smallColorBuff.data) /*>> 2*/;//>> 2 = divide by sizeof int = 4 bytes
#else //__NM__
		int winOffset = ((int)(pROI[cnt]) - (int)cntxt.smallColorBuff.data) >> 2;//>> 2 = divide by sizeof int = 4 bytes
#endif //__NM__

																				 //TODO:remove magic number 2
		winY0 = cntxt.texState->segY0 + (winOffset >> 7); //>> 7 = divide by segment width 
														 //TODO: remove magic number 7
		winX0 = cntxt.texState->segX0 + (winOffset & (cntxt.texState->segWidth - 1));//get reminder  of division by segment width

//start calculate pixel value for texturing
		float area = 0;
		float x0 = triangles->x0[cnt];
		float y0 = triangles->y0[cnt];
		float x1 = triangles->x1[cnt];
		float y1 = triangles->y1[cnt];
		float x2 = triangles->x2[cnt];
		float y2 = triangles->y2[cnt];

		float s0 = triangles->s0[cnt];
		float t0 = triangles->t0[cnt];
		float s1 = triangles->s1[cnt];
		float t1 = triangles->t1[cnt];
		float s2 = triangles->s2[cnt];
		float t2 = triangles->t2[cnt];

		float z0 = triangles->z[cnt];
		float z1 = triangles->z[cnt];
		float z2 = triangles->z[cnt];

		float oneOverTriSquare = 1.0 / ((x0 - x1)*(y2 - y1) - (y0 - y1)*(x2 - x1));

		float A0 = (float)(y2 - y1);
		float A1 = y0 - y2;
		volatile float A2 = (float)((float)384 - (float)353);

		float B0 = x1 - x2;
		float B1 = x2 - x0;
		float B2 = x0 - x1;

		float D0 = x2*y1 - y2*x1;
		float D1 = y2*x0 - x2*y0;
		float D2 = x1*y0 - x0*y1;

		volatile float A_s = oneOverTriSquare*(A0*s0 + A1*s1 + A2*s2);
		volatile float B_s = oneOverTriSquare*(B0*s0 + B1*s1 + B2*s2);
		volatile float D_s = oneOverTriSquare*(D0*s0 + D1*s1 + D2*s2);

		volatile float A_t = oneOverTriSquare*(A0*t0 + A1*t1 + A2*t2);
		volatile float B_t = oneOverTriSquare*(B0*t0 + B1*t1 + B2*t2);
		volatile float D_t = oneOverTriSquare*(D0*t0 + D1*t1 + D2*t2);


		// Area of triangle.
		// Part of calculation attribute values using barycentric coordinates.
		edgeFunction(x0, y0, x1, y1, x2, y2, &area);
		volatile float oneOverArea = 1.0 / area;
		int pixelCnt = 0;
		//printf("%x", area);

		for (int y = 0; y < windows[cnt].height; y++) {
			temp = pattern[y];
			nm32s* pDst = (nm32s*)(dst + y * windows[cnt].width);
			nm32s* pSrc = (nm32s*)(src + y * windows[cnt].width);
			if (windows[cnt].x < 0) {
				for (int i = 0; i > windows[cnt].x; i--) {
					pDst[0] = 0x00000000;
					pDst += 1;
					pSrc += 1;
				}
			}
			else {
				temp >>= (windows[cnt].x * 2);
			}

			for (int x = 0; x < width; x++) {
				int mul = temp & 0x3;

				if (mul > 0)//pixel belongs to triangle
				{

					//Calculate x and y of current pixel as float values
					//relative to triangle vertex coordinates inside segment
					volatile float xf = winX0 + x + 0.5f;
					volatile float yf = winY0 + y + 0.5f;//TODO: Барицентрические координаты не соответствуют растеризованной картинке,
												//то есть растеризованные по шаблону пиксели не должны быть растеризованы, 
												//если использовать барицентрические координаты.
												//Но так как они растеризованы, то для них вычисляются неверные барицентрические
												//координаты и неправильные значения текстурных координат
												//Нужно как-то соотнести алгоритм растеризации и вычисление текстурных координат
					float w0 = 0;
					float w1 = 0;
					float w2 = 0;
					//TODO: it works only for triangle in CW order
					edgeFunction(x1, y1, x2, y2, xf, yf, &w0);
					edgeFunction(x2, y2, x0, y0, xf, yf, &w1);
					edgeFunction(x0, y0, x1, y1, xf, yf, &w2);

					//*res = (x2 - x0) * (y1 - y0) - (y2 - y0) * (x1 - x0);

					w0 = w0*oneOverArea;
					w1 = w1*oneOverArea;
					w2 = w2*oneOverArea;

					float s = 0.0;
					float t = 0.0;

					s = s0 * w0 + s1 * w1 + s2 * w2;
					t = t0 * w0 + t1 * w1 + t2 * w2;

					// Vec2f st; //moved to global scope
					st.x = s;
					st.y = t;
#if 0
					/* Calculate minification vs. magnification switchover point */

					if ((textureMagFilter == NMGL_LINEAR) && ((textureMinFilter == NMGL_NEAREST_MIPMAP_NEAREST) || (textureMinFilter == NMGL_NEAREST_MIPMAP_LINEAR)))
						c = 0.5f;
					else
						c = 0.0f;

					/*************************************************************/

					/*Calculate partial derivative for u(x,y) and v(x,y). level 0 texture are using to calculate scale factor*/

#ifdef PERSPECTIVE_CORRECT
					float derivOneOverDenom = 1.0 / ((A2*x + B2*y + D2)*(A2*x + B2*y + D2));
					float dudx = (float)boundTexObject->texImages2D[0].width*((A1_s*B2 - A2*B1_s)*y + A1_s*D2 - A2*D1_s)*derivOneOverDenom;
					float dudy = (float)boundTexObject->texImages2D[0].width*((B1_s*A2 - B2*A1_s)*x + B1_s*D2 - B2*D1_s)*derivOneOverDenom;
					float dvdx = (float)boundTexObject->texImages2D[0].height*((A1_t*B2 - A2*B1_t)*y + A1_t*D2 - A2*D1_t)*derivOneOverDenom;
					float dvdy = (float)boundTexObject->texImages2D[0].height*((B1_t*A2 - B2*A1_t)*x + B1_t*D2 - B2*D1_t)*derivOneOverDenom;
#else //PERSPECTIVE_CORRECT  
					float dudx = (float)boundTexObject->texImages2D[0].width*A_s;
					float dudy = (float)boundTexObject->texImages2D[0].width*B_s;
					float dvdx = (float)boundTexObject->texImages2D[0].height*A_t;
					float dvdy = (float)boundTexObject->texImages2D[0].height*B_t;
#endif //PERSPECTIVE_CORRECT

					/*Calculate scale factor*/
#ifdef SCALE_FACTOR_IDEAL
					scaleFactor = fmax(sqrtf(dudx*dudx + dvdx*dvdx), sqrtf(dudy*dudy + dvdy*dvdy));
#else
					float mu = fmax(fabs(dudx), fabs(dudy));
					float mv = fmax(fabs(dvdx), fabs(dvdy));
					scaleFactor = fmax(mu, mv);
#endif
					//printf("Scale factor = %f\n", scaleFactor);

					/*Calculate level of detail*/

					float lod = 0.0;
					float lod_ = log2f(scaleFactor);

					if (TEXTURE_MIN_LOD > TEXTURE_MAX_LOD)
					{
						printf("Error. TEXTURE_MIN_LOD > TEXTURE_MAX_LOD. LOD is undefined. Exit\n");
						return;
					}
					else if (lod_ > TEXTURE_MAX_LOD)
						lod = TEXTURE_MAX_LOD;
					else if (lod_ < TEXTURE_MIN_LOD)
						lod = TEXTURE_MIN_LOD;
					else
						lod = lod_;

					//if ((lod < c) || (equalf(lod,c) == 1))
					if (lod <= c)
						minMagFlag = MAGNIFICATION;
					else
						minMagFlag = MINIFICATION;
#endif //0
					//printf("minmag = %x\n",minMagFlag);

#if 1					
					minMagFlag = MAGNIFICATION;
					unsigned int d = 0;
					unsigned int d1 = 0;
					unsigned int d2 = 0;

					if (((minMagFlag == MINIFICATION) && (textureMinFilter == NMGL_NEAREST)) ||
						((minMagFlag == MAGNIFICATION) && (textureMagFilter == NMGL_NEAREST)))
					{


						//Not mipmapping. So wrap texture coordinates for texture of level 0 
						//st.x = wrapCoord(textureWrapS, boundTexObject->texImages2D[0].width, st.x);
						//st.y = wrapCoord(textureWrapT, boundTexObject->texImages2D[0].height, st.y);

						//st.x = wrapCoord(textureWrapS, boundTexObject->texImages2D[0].width, st.x);
						float min_coord_val = 1.0f/(float)boundTexObject->texImages2D[0].width*0.5; //CLAMP_TO_EDGE
																		  //float min_s = 0.0f; //CLAMP
						float max_coord_val = 1.0f - min_coord_val;

						float resTexCoord = 0.0f;

//Apply texture Wrap modes to s texCoord
						if (textureWrapS == NMGL_REPEAT)
							resTexCoord = st.x - (float)floor(st.x);
						else if (textureWrapS == NMGL_CLAMP_TO_EDGE)
						{
							if (st.x > max_coord_val) resTexCoord = max_coord_val;
							else if (st.x < min_coord_val) resTexCoord = min_coord_val;
							else resTexCoord = st.x;
						}
						else
						{
							//printf("Unsupported textureWrapS or textureWrapT value. Exit.\n");
							resTexCoord = 999.0;
						}

						st.x = resTexCoord;

						//st.y = wrapCoord(textureWrapT, boundTexObject->texImages2D[0].height, st.y);
						min_coord_val = 1.0f / (float)boundTexObject->texImages2D[0].height*0.5; //CLAMP_TO_EDGE
																								   //float min_s = 0.0f; //CLAMP
						max_coord_val = 1.0f - min_coord_val;

						resTexCoord = 0.0f;

//Apply texture Wrap modes to t texCoord
						if (textureWrapT == NMGL_REPEAT)
							resTexCoord = st.y - (float)floor(st.y);
						else if (textureWrapT == NMGL_CLAMP_TO_EDGE)
						{
							if (st.y > max_coord_val) resTexCoord = max_coord_val;
							else if (st.y < min_coord_val) resTexCoord = min_coord_val;
							else resTexCoord = st.y;
						}
						else
						{
							//printf("Unsupported textureWrapS or textureWrapT value. Exit.\n");
							resTexCoord = 999.0;
						}

						st.y = resTexCoord;

						//pixelValue = getPixelNearest(st, boundTexObject->texImages2D[0]);
						//pixelValue = getPixelNearest(st, boundTexObject->texImages2D[0]);

						unsigned int texel_i = 0;
						unsigned int texel_j = 0;
						// //color pixelValue; //moved to global scope

						 //float u = boundTexObject->texImages2D[0].width*st.x; //2^n = textureWidth
						 //float v = boundTexObject->texImages2D[0].height*st.y; //2^m = textureHeight
						float u = (float)2.0*st.x; //2^n = textureWidth
						float v = (float)2.0*st.y; //2^m = textureHeight
						
						texel_i = (unsigned int)((st.x < (float)1.0f) ? (int)floor(u) : (boundTexObject->texImages2D[0].width - (int)1));
						texel_j = (unsigned int)((st.y < (float)1.0f) ? (int)floor(v) : (boundTexObject->texImages2D[0].height - (int)1));

						//if ((x == 0) && (y == 0))
						//{
						//	// texdata2.fl = s;
						//	// printf ("%x\n", texdata2.uinteg);

						//	// texdata2.fl = t;
						//	// printf("%x\n", texdata2.uinteg);

						//	// printf("%f %f \n", st.x, st.y);
						//	// printf("%d\n", winX0);
						//	printf("%f %f %f\n", w0, w1, w2);
						//	// printf("%x %x\n", winOffset, (int)cntxt.smallColorBuff.data);
						//}
						unsigned int texel_x = (unsigned int)texel_i;
						unsigned int texel_y = (unsigned int)texel_j;
						 //unsigned int texel_x = x;
						 //unsigned int texel_y = y;

						/******************getPixel Value*****************************/
						unsigned int rowDataSize = (unsigned int)0;
						unsigned int rawDataSize = (unsigned int)0;
						unsigned int rowPadding = (unsigned int)0;
						unsigned int bmpFileSize = (unsigned int)0;
						unsigned int bitsInPixel = (unsigned int)24;
						unsigned int bytesInPixel = (unsigned int)0;

						unsigned int imgwidth = boundTexObject->texImages2D[0].width;
						unsigned int imgheight = boundTexObject->texImages2D[0].height;
						void * pixels = boundTexObject->texImages2D[0].pixels;
						NMGLint format = boundTexObject->texImages2D[0].internalformat;
						NMGLenum type = NMGL_UNSIGNED_BYTE;//TODO: if constant internal type then 'type' variable is unnecessary
						int alignment = cntxt.texState->unpackAlignment;

						switch (format)
						{
						case NMGL_RGB:
							bytesInPixel = (unsigned int)3;
							break;
#if 0	
						case NMGL_RGBA:
							bytesInPixel = (unsigned int)4;
							break;

						case NMGL_ALPHA:
						case NMGL_LUMINANCE:
							bytesInPixel = (unsigned int)1;
							break;

						case NMGL_LUMINANCE_ALPHA:
							bytesInPixel = (unsigned int)2;
							break;
#endif 
						default:
							bytesInPixel = (unsigned int)3;

							break;
						}

						int rowPaddingBytes = (int)((imgwidth * bytesInPixel) % alignment ? alignment - (imgwidth * bytesInPixel) % alignment : (int)0);
						unsigned int imageRowWidthBytes = (unsigned int)(imgwidth * bytesInPixel + rowPaddingBytes);

						

						unsigned int pixelPos = (unsigned int)(texel_y * imageRowWidthBytes + texel_x * bytesInPixel); //does not work
						//printf("%x ",imageRowWidthBytes);
#if 1
						if ((format == NMGL_RGB) && (type == NMGL_UNSIGNED_BYTE))
						{

							//pixelValue.r =((nm32s*)pixels_2_2)[pixelPos];
							pixelValue.r = ((nm32s*)pixels)[pixelPos];
/*								pixelValue.g =pixels[pixelPos + (unsigned int)1];
							pixelValue.b = (unsigned char)((unsigned char*)pixels)[pixelPos + (unsigned int)2];
							pixelValue.a = (unsigned char)255;*/
						}
#endif //0
#if 0
						else if (((format == NMGL_RGBA) && (type == NMGL_UNSIGNED_BYTE)))
						{
							//Чтение производится из массива данных изображения bmp с учетом наличия в нём 
							//дополнительных байтов для выравнивания по границе 4 байтов
							pixelValue.r = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.g = (unsigned char)((unsigned char*)pixels)[pixelPos + (unsigned int)1];
							pixelValue.b = (unsigned char)((unsigned char*)pixels)[pixelPos + (unsigned int)2];
							pixelValue.a = (unsigned char)255;
						}

						else if ((format == NMGL_ALPHA) && (type == NMGL_UNSIGNED_BYTE))
						{
							//Чтение производится из массива данных изображения bmp с учетом наличия в нём 
							//дополнительных байтов для выравнивания по границе 4 байтов
							pixelValue.r = (unsigned char)0;
							pixelValue.g = (unsigned char)0;
							pixelValue.b = (unsigned char)0;
							pixelValue.a = (unsigned char)((unsigned char*)pixels)[pixelPos];
						}
						else if ((format == NMGL_LUMINANCE) && (type == NMGL_UNSIGNED_BYTE))
						{
							//Чтение производится из массива данных изображения bmp с учетом наличия в нём 
							//дополнительных байтов для выравнивания по границе 4 байтов
							pixelValue.r = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.g = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.b = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.a = (unsigned char)255;
						}
						else if ((format == NMGL_LUMINANCE_ALPHA) && (type == NMGL_UNSIGNED_BYTE))
						{
							//Чтение производится из массива данных изображения bmp с учетом наличия в нём 
							//дополнительных байтов для выравнивания по границе 4 байтов
							pixelValue.r = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.g = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.b = (unsigned char)((unsigned char*)pixels)[pixelPos];
							pixelValue.a = (unsigned char)((unsigned char*)pixels)[pixelPos + (unsigned int)1];
						}
						else
						{
							//printf("Error: %s %s %d", __FILE__, __func__, __LINE__);
						}
#endif
						/***********getPixelValue**************/
					}// if minMagFlag == MINIFICATION
						//Apply texture finction
						//RGB value
#if 0
						Vec3f cf_; //primary color components of the incoming fragment (primary color of PRIMITIVE pixel OR fragment color from previous texture unit)
								   //Not framebuffer color.Framebuffer color can be used at another stage called Blending (glBlendFunc...)
						Vec3f cs_; //texture source color (color from texture array, one tex unit - one texture)
						Vec3f cc_; //texture environment color (unique for each texture unit)
						Vec3f cv_; //primary color components computed by the texture function (to another OpenGL stages or to next texture unit)
#endif //0

#if 0
								   //Alpha value
						nm32f af;
						nm32f as;
						nm32f ac;
						nm32f av;

						//(nm32s)pSrc[0] = 0xARGB
						vertexRGB.x = (nm32f)((pSrc[0] >> 16) & 0xff) / 255.0;//r
						vertexRGB.y = (nm32f)((pSrc[0] >> 8) & 0xff) / 255.0;//g
						vertexRGB.z = (nm32f)(pSrc[0] & 0xff) / 255.0;//b
						vertexAlpha = (nm32f)(((pSrc[0]) >> 24) & 0xff) / 255.0;//a

																				//TODO: extra assignment. name vertexRGB is umbiguous and unnecessary.
						cf.x = (nm32f)vertexRGB.x;
						cf.y = (nm32f)vertexRGB.y;
						cf.z = (nm32f)vertexRGB.z;

						cs.x = (nm32f)pixelValue.r / 255.0;
						cs.y = (nm32f)pixelValue.g / 255.0;
						cs.z = (nm32f)pixelValue.b / 255.0;

						cc.x = (nm32f)texEnvColor.x;
						cc.y = (nm32f)texEnvColor.y;
						cc.z = (nm32f)texEnvColor.z;

						cv.x = (nm32f)0.0;
						cv.y = (nm32f)0.0;
						cv.z = (nm32f)0.0;

						af = (nm32f)vertexAlpha;
						as = (nm32f)pixelValue.a / 255.0;
						ac = (nm32f)texEnvColorAlpha;
						av = (nm32f)0.0;

						switch (texBaseInternalFormat)
						{
						case NMGL_RGB:
							switch (texEnvMode)
							{
							case NMGL_REPLACE:
								cv.x = (nm32f)cs.x;
								cv.y = (nm32f)cs.y;
								cv.z = (nm32f)cs.z;
								av = (nm32f)af;
								break;

							case NMGL_MODULATE:
								cv.x = (nm32f)(cf.x * cs.x);
								cv.y = (nm32f)(cf.y * cs.y);
								cv.z = (nm32f)(cf.z * cs.z);
								av = (nm32f)af;
								break;

							case NMGL_DECAL:
								cv.x = (nm32f)cs.x;
								cv.y = (nm32f)cs.y;
								cv.z = (nm32f)cs.z;
								av = (nm32f)af;
								break;
							case NMGL_BLEND:
								cv.x = (nm32f)(cf.x * ((nm32f)1.0 - cs.x) + cc.x * cs.x);
								cv.y = (nm32f)(cf.y * ((nm32f)1.0 - cs.y) + cc.y * cs.y);
								cv.z = (nm32f)(cf.z * ((nm32f)1.0 - cs.z) + cc.z * cs.z);
								av = (nm32f)af;
								break;

							case NMGL_ADD:
								cv.x = (nm32f)(cf.x + cs.x);
								cv.y = (nm32f)(cf.y + cs.y);
								cv.z = (nm32f)(cf.z + cs.z);
								av = (nm32f)af;
								break;
							}
							break;

						default:
							printf("Unsupported internal format\n");
							break;
						}

						nm32s color = 0;
						//(nm32s)pDst[0] = 0xARGB
						color = color | (((nm32s)(av * 255) & 0xff) << 24);//a
						color = color | (((nm32s)(cv.x * 255) & 0xff) << 16); //r
						color = color | (((nm32s)(cv.y * 255) & 0xff) << 8);//g
						color = color | (((nm32s)(cv.z * 255) & 0xff));//b
																	   // pDst[0] = mul * pSrc[0];
						pDst[0] = mul * color;
#endif //0
#endif//0
						pDst[0] = mul * 0xff00ff00;
				} //mul > 0
				pDst += 1;
				pSrc += 1;
				temp >>= 2;
			} //x
		} //y

		src += windows[cnt].height * windows[cnt].width;
		dst += windows[cnt].height * windows[cnt].width;
	} //cnt triangle
}
#endif