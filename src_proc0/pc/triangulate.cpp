#include <cmath> // pow for NMC-SDK

#include "service.h"

static Buffer initBuf(void *data, int size)
{
	Buffer buf;
	buf.data = data;
	buf.back = size;
	buf.front = -1;
	buf.size = size;
	return buf;
}

static int bufIsFull(Buffer *buf)
{
	return ((buf->front + 1) == buf->back);	
}

static int bufIsEmpty(Buffer *buf)
{
	return (buf->back == buf->size);	
}

static int bufSize(Buffer *buf)
{
	return (buf->front + 1);	
}

static int bufSpace(Buffer *buf)
{
	return (buf->back - buf->front - 1);	
}

//      push here         
//          |
//          V
// |-|-|-|-|-|x|x|
// |-|-|-|-|-|x|x|
// |-|-|-|-|-|x|x|
static int pushBackVertices(Buffer *vbuf, Vertices *vert)
{
	if (bufIsFull(vbuf)){
		return -1;
	} else {
		vbuf->back -= 1;
		nm32f *dst = (nm32f *) vbuf->data; 
		for (int i = 0; i < 9; ++i){
			dst[i * vbuf->size + vbuf->back] = vert->v[i];
		}	
		return 0;
	}
}

//      push here         
//          |
//          V
// |x|x|x|x|-|-|-|
// |x|x|x|x|-|-|-|
// |x|x|x|x|-|-|-|
static int pushFrontVertices(Buffer *vbuf, Vertices *vert)
{
	if (bufIsFull(vbuf)){
		return -1;
	} else {
		vbuf->front += 1;
		nm32f *dst = (nm32f *) vbuf->data; 
		for (int i = 0; i < 9; ++i){
			dst[i * vbuf->size + vbuf->front] = vert->v[i];
		}	
		return 0;
	}
}

//   return this item         
//          |
//          V
// |-|-|-|-|x|x|x|
// |-|-|-|-|x|x|x|
// |-|-|-|-|x|x|x|
static int popBackVertices(Buffer *vbuf, Vertices *vert)
{
	if (bufIsEmpty(vbuf)){
		return -1;
	} else {
		nm32f *src = (nm32f *) vbuf->data; 
		for (int i = 0; i < 9; ++i){
			vert->v[i] = src[i * vbuf->size + vbuf->back];
		}	
		vbuf->back += 1;
		return 0;
	}
}

// 				|-|-|-|-|-|-|-|
// push here ->	|-|-|-|-|-|-|-|
// 				|x|x|x|x|x|x|x|
// 				|x|x|x|x|x|x|x|
static int pushBackColors(Buffer *cbuf, Colors *colors)
{
	if (bufIsFull(cbuf)){
		return -1;
	} else {
		cbuf->back -= 1;
		Colors *topColor = &((Colors *) cbuf->data)[cbuf->back];
		nm32f *dst = (nm32f *) topColor;
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 4; ++j){
				dst[i * 4 + j] = colors->c[i].vec[j];
			}
		}
		return 0;
	}
}

// 				|x|x|x|x|x|x|x|
// 				|x|x|x|x|x|x|x|
// push here ->	|-|-|-|-|-|-|-|
// 				|-|-|-|-|-|-|-|
static int pushFrontColors(Buffer *cbuf, Colors *colors)
{
	if (bufIsFull(cbuf)){
		return -1;
	} else {
		cbuf->front += 1;
		Colors *frontColor = &((Colors *) cbuf->data)[cbuf->front];
		nm32f *dst = (nm32f *) frontColor;
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 4; ++j){
				dst[i * 4 + j] = colors->c[i].vec[j];
			}
		}
		return 0;
	}
}

// 						|-|-|-|-|-|-|-|
// return this item ->	|x|x|x|x|x|x|x|
// 						|x|x|x|x|x|x|x|
// 						|x|x|x|x|x|x|x|
static int popBackColors(Buffer *cbuf, Colors *colors)
{
	if (bufIsEmpty(cbuf)){
		return -1;
	} else {
		Colors *topColor = &((Colors *) cbuf->data)[cbuf->back];
		nm32f *src = (nm32f *) topColor;
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 4; ++j){
				colors->c[i].vec[j] = src[i * 4 + j];
			}
		}
		cbuf->back += 1;
		return 0;
	}
}

int triangulate(const nm32f *srcVertex,
	const v4nm32f *srcColor,
	int srcCount,
	int maxWidth,
	int maxHeight,
	int maxDstSize,
	nm32f *dstVertex,
	v4nm32f *dstColor,
	int *srcTreatedCount)
{
	int currentDstSize = 0;

	Buffer verticesStack = initBuf((void *) dstVertex, maxDstSize);
	Buffer colorsStack = initBuf((void *) dstColor, maxDstSize);

	int i = 0; // make this iterator local to assign it later to srcTreatedCount
	for (i = 0; i < srcCount; ++i) {
		// Get the triangle from the source
		Point a;
		Point b;
		Point c;

		a.x = srcVertex[i];
		a.y = srcVertex[i + srcCount];
		a.z = srcVertex[i + 2 * srcCount];
		b.x = srcVertex[3 * srcCount + i];
		b.y = srcVertex[3 * srcCount + i + srcCount];
		b.z = srcVertex[3 * srcCount + i + 2 * srcCount];
		c.x = srcVertex[6 * srcCount + i];
		c.y = srcVertex[6 * srcCount + i + srcCount];
		c.z = srcVertex[6 * srcCount + i + 2 * srcCount];
		a.color = srcColor[3 * i];
		b.color = srcColor[3 * i + 1];
		c.color = srcColor[3 * i + 2];
		Triangle tr{a, b, c};

		// Try to triangulate the triangle
		int res = triangulateOneTriangle(tr, 
										(nm32f) maxWidth, 
										(nm32f) maxHeight, 
										&verticesStack, 
										&colorsStack);
		// If the number of smaller triangles is too big
		if (res == -1) {
			// Finish triangulation
			break;
		} else {
			// Update the number of the result output triangles
			// in case of successful split
			// (triangulateOneTriangle modifies output buffer, so
			// update result size only in case of successful split)
			currentDstSize = res;
		}
	}
	*srcTreatedCount = i;
	return currentDstSize;
}

static nm32f sum_of_arithmetic_progression(nm32f a1, nm32f an, nm32f n){
	return (n * (a1 + an) / 2);
}

void buildPoints(const Triangle &tr, int n, Point *points)
{
	struct Point a = tr.points[0];
	struct Point b = tr.points[1];
	struct Point c = tr.points[2];

	nm32f ab_dx = (b.x - a.x) / n;
	nm32f ab_dy = (b.y - a.y) / n;
	nm32f ac_dx = (c.x - a.x) / n;
	nm32f ac_dy = (c.y - a.y) / n;

	Point points[128][128];
	for (int i = 0; i < n; ++i){
		nm32f ab_x = a.x + i * ab_dx;
		nm32f ab_y = a.y + i * ab_dy;
		for (int j = 0; j < n + 1 - i; ++j){
			points[i][j].x = ab_x + j * ac_dx;
			points[i][j].y = ab_y + j * ac_dy;
		}
	}
	points[n][0].x = b.x;
	points[n][0].y = b.y;

	printf("GLfloat tr_set_1[%i] = {\n\r", (int) (6 * sum_of_arithmetic_progression(1, n, n)));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n - i; ++j){
			printf("%f,%f,%f,%f,%f,%f,\n\r", 
					points[i][j].x, points[i][j].y, 
					points[i + 1][j].x, points[i + 1][j].y,
					points[i][j + 1].x, points[i][j + 1].y);
		}
	}
	printf("};\n\r");
	printf("GLfloat tr_set_2[%i] = {\n\r", (int) (6 * sum_of_arithmetic_progression(1, n - 1, n - 1)));
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < n - i; ++j){
			printf("%f,%f,%f,%f,%f,%f,\n\r",
					points[i][j].x, points[i][j].y, 
					points[i][j + 1].x, points[i][j + 1].y,
					points[i - 1][j + 1].x, points[i - 1][j + 1].y);
		}
	}
	printf("};\n\r");
}

// Return:
// -1 - деление не удалось, в выходном буфере нет места
// n - текущее количество треугольников в выходном буфере
int triangulateOneTriangle(	const Triangle& tr, 
							nm32f maxWidth, 
							nm32f maxHeight, 
							Buffer *verticesStack, 
							Buffer *colorsStack)
{
	// Check the free space in output buffer
	// (at least for input triangle (if it is OK and don't be splitted))
	int vsize = bufSpace(verticesStack);
	if (vsize < 1){
		// No space in output buffer
		return -1;
	} else {
		// Do nothing here, just continue
	}

	// Process the triangle:
	// Check the size and split if it is necessary
	if (tr.isTooBig(maxWidth, maxHeight)){
		//Get the number of output triangles
		nm32f triangle_width = tr.GetWidth();
		nm32f triangle_height = tr.GetHeight();
		printf("Triangle width is %f\n\r", triangle_width);
		printf("Triangle height is %f\n\r", triangle_height);
		nm32f lengths[2] = {triangle_width, triangle_height};
		nm32f max_length = max_fabs_in_array(lengths, 2);
		nm32f sizes[2] = {maxWidth, maxHeight};
		nm32f max_size = min_fabs_in_array(sizes, 2);
		nm32f n = floor(max_length / max_size);
		printf("n = %f\n\r", n);
		nm32f n_of_triangles = sum_of_arithmetic_progression(1, 2 * n - 1, n);
		printf("Number of triangles is %f\n\r", n_of_triangles);
		if (n_of_triangles > vsize){
			//There are no more space in output buffer
		} else {
			// Get the points of triangle and push it to the output buffer
			buildPoints(tr, (int) n);
		}
	} else {
		// Triangle size is OK
		// Push the triangle to the output 
		Vertices trVertices = {
			tr.points[0].x, tr.points[0].y, tr.points[0].z,
			tr.points[1].x, tr.points[1].y, tr.points[1].z,
			tr.points[2].x, tr.points[2].y, tr.points[2].z
		};
		Colors trColors = {
			tr.points[0].color,
			tr.points[1].color,
			tr.points[2].color
		};
		pushFrontVertices(verticesStack, &trVertices);
		pushFrontColors(colorsStack, &trColors);
	}
	return bufSize(verticesStack);
}
