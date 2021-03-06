#include "demo3d_nm0.h"
#include "nmgl.h"
#include "nmgl_data0.h"

#pragma code_section ".text_nmgl"

SECTION(".text_nmgl")
void nmglTranslatef(NMGLfloat x, NMGLfloat y, NMGLfloat z){
	mat4nm32f temp ={1,0,0,0,
					 0,1,0,0,
					 0,0,1,0,
					 0,0,0,1};
	temp.matr[12] = x;
	temp.matr[13] = y;
	temp.matr[14] = z;

	mat4nm32f* current = cntxt.currentMatrixStack->top();
	mul_mat4nm32f_v4nm32f(current, (v4nm32f*)&temp, (v4nm32f*)current, 4);
}
