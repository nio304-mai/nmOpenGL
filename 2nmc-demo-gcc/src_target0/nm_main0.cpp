#include "hal_target.h"
#include "hal.h"
#include <time.h>
#include "stdio.h"
#include "nmpp.h"
#include "nmgl.h"
#include "nmglvs_nmc0.h"
	
//SECTION(".data_shared0") float vertices_DDR[2000 * 12];
//SECTION(".data_shared0") float normal_DDR[2000 * 9];
//SECTION(".data_shared0") float vertices_DDR2[2000 * 12];
//SECTION(".data_shared0") float normal_DDR2[2000 * 9];
SECTION(".data_shared0") float twoTriangles[24 * 4] = {
	110, 90, 0, 1,
	90, 110, 0, 1,
	90, 90, 0, 1,
	110, 110, 0, 1,

	110, 90, 0, 1,
	90, 90, 0, 1,
	110, 90, 0, 1,
	110, 110, 0, 1,

	110, 90, 0, 1,
	125, 95, 0, 1,
	90, 90, 0, 1,
	75, 95, 0, 1,

	90, 90, 0, 1,
	75, 95, 0, 1,
	90, 90, 0, 1,
	75, 95, 0, 1,
	110, 90, 0, 1,
	125, 95, 0, 1,
	110, 90, 0, 1,
	125, 95, 0, 1,
	110, 90, 0, 1,
	125, 95, 0, 1,
	110, 90, 0, 1,
	125, 95, 0, 1,
};

SECTION(".text_shared0") int main()
{
	nmglvsNm0Init();
	setHeap(10);
	float* vertices_DDR = (float*)halMalloc32(2000 * 12);
	float* normal_DDR = (float*)halMalloc32(2000 * 9);
	float* vertices_DDR2 = (float*)halMalloc32(2000 * 12);
	float* normal_DDR2 = (float*)halMalloc32(2000 * 9);
	
#ifdef __OPEN_GL__
	Models models;
	char* filePath = models.nm;

	FILE* fmodel = fopen(filePath, "r");
	if (fmodel == 0) {
		printf("File not opened\n");
		return 1;
	}
	int amount = get_amm_poligone(fmodel);
	fmodel = fopen(filePath, "r");
	createArrayVec4(fmodel, vertices_DDR, normal_DDR, 1);
	int amountPolygons = amount;

	filePath = models.two_sphere;
	fmodel = fopen(filePath, "r");
	amount = get_amm_poligone(fmodel);
	fmodel = fopen(filePath, "r");
	createArrayVec4(fmodel, vertices_DDR2, normal_DDR2, 0.5);
	


	int amountPolygons2 = amount;
	int ok;
#else
	int amountPolygons = halHostSync(0);

	//������ ������ ��������� (�� 4 ���������� �� �������)
	//sync1
	halHostSync((int)vertices_DDR);

	//sync2
	int ok = halHostSync((int)normal_DDR);

	int amountPolygons2 = halHostSync(0);
	halHostSync((int)vertices_DDR2);

	//sync2
	ok = halHostSync((int)normal_DDR2);
	ok = halHostSync((int)0x600D600D);
#endif
	
	nmglClearColor(0, 0, 0.4, 0.0f);
	//nmglClearColor(0.5, 0.5, 0.5, 1.0f);

	nmglEnable(NMGL_DEPTH_TEST);
	nmglEnable(NMGL_CULL_FACE);

	nmglMatrixMode(NMGL_MODELVIEW);
	nmglLoadIdentity();
	nmglMatrixMode(NMGL_PROJECTION);
	nmglOrthof(-384, 384, -384, 384, -384, 384);
	nmglMatrixMode(NMGL_MODELVIEW);

	nmglViewport(0, 0, 768, 768);

	nmglEnable(NMGL_LIGHTING);
	nmglEnable(NMGL_LIGHT0);
	float lightVector[4] = { 0, -0.707, 0.707, 0 };
	nmglLightfv(NMGL_LIGHT0, NMGL_POSITION, lightVector);
	float lightDiffuse[4] = { 1, 1, 1, 1 }; 
	nmglLightfv(NMGL_LIGHT0, NMGL_DIFFUSE, lightDiffuse);
	float materialSpec[4] = { 0,0,0,1 };
	float materialDiffuse[4] = { 0,0,0,1 };
	nmglMaterialf(NMGL_FRONT_AND_BACK, NMGL_SHININESS, 15);
	float angle = 0;
	NMGLenum error;
	unsigned time;

	/*nmglEnable(NMGL_LIGHT1);
	float lightVector2[4] = { 0, 0.707, 0.707, 0 };
	nmglLightfv(NMGL_LIGHT1, NMGL_POSITION, lightVector);
	float lightDiffuse2[4] = { 1, 1, 0, 1 };
	nmglLightfv(NMGL_LIGHT1, NMGL_DIFFUSE, lightDiffuse);*/

	while(nmglvsNm0Run()){
		nmglEnableClientState(NMGL_VERTEX_ARRAY);
		nmglEnableClientState(NMGL_NORMAL_ARRAY);

		nmglClear(NMGL_COLOR_BUFFER_BIT | NMGL_DEPTH_BUFFER_BIT);
		//nmglTranslatef(1, 0, 0);
		//nmglVertexPointer(4, NMGL_FLOAT, 0, twoTriangles);
		//nmglDrawArrays(NMGL_LINES, 0, 24);
		

		nmglVertexPointer(4, NMGL_FLOAT, 0, vertices_DDR);
		nmglNormalPointer(NMGL_FLOAT, 0, normal_DDR);
		nmglLoadIdentity();
		nmglRotatef(angle, 0.707f, 0.707f, 0);
		materialDiffuse[0] = 1;
		materialDiffuse[2] = 0;
		nmglMaterialfv(NMGL_FRONT_AND_BACK, NMGL_DIFFUSE, materialDiffuse);
		materialSpec[0] = 0.6;
		materialSpec[1] = 0.6;
		materialSpec[2] = 0.6;
		nmglMaterialfv(NMGL_FRONT_AND_BACK, NMGL_SPECULAR, materialSpec);
		nmglDrawArrays(NMGL_TRIANGLES, 0, 3 * amountPolygons);

		nmglVertexPointer(4, NMGL_FLOAT, 0, vertices_DDR2);
		nmglNormalPointer(NMGL_FLOAT, 0, normal_DDR2);
		nmglLoadIdentity();
		materialDiffuse[0] = 0.4;
		materialDiffuse[1] = 1;
		materialDiffuse[2] = 1;
		materialSpec[0] = 0;
		materialSpec[1] = 0;
		materialSpec[2] = 0;
		nmglMaterialfv(NMGL_FRONT_AND_BACK, NMGL_DIFFUSE, materialDiffuse);
		nmglMaterialfv(NMGL_FRONT_AND_BACK, NMGL_SPECULAR, materialSpec);
		nmglRotatef(angle, 0.707, 0.707, 0);
		nmglTranslatef(150, 150, 0);

		nmglDrawArrays(NMGL_TRIANGLES, 0, 3 * amountPolygons2);
		/*nmglBegin(NMGL_TRIANGLES);
		for (int i = 0; i < 3 * amountPolygons2; i++) {
			nmglVertex3fv(&vertices_DDR2[4 * i]);
			nmglNormal3fv(&normal_DDR2[3 * i]);
		}
		nmglEnd();*/
#ifdef __OPEN_GL__
		angle += 0.03;
#else
		angle += 1.72;
#endif // __OPEN_GL__

		nmglDisableClientState(NMGL_VERTEX_ARRAY);
		//nmglDisableClientState(NMGL_NORMAL_ARRAY);

		//nmglFinish();
		nmglvsSwapBuffer();
	}
	//halFree(vertices_DDR);
	//halFree(vertices_DDR2);
	//halFree(normal_DDR);
	//halFree(normal_DDR2);
	nmglvsExit_mc12101();
	return 0x600D600D;
} 

