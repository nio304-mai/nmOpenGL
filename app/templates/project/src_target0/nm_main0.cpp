#include "nmgl.h"
#include "nmglvs_nmc0.h"

float triangles[36]{
	0,0,
	0,3,
	3,0,

	0,0,
	0,7,
	7,0,

	0,0,
	0,15,
	15,0,

	0,0,
	0,31,
	31,0,

	0, 10,
	15, 30,
	26, 5,

	0, 10,
	15, 30,
	26, 5
};

float color[72]{
	1,0,0, 1,
	1,0,0, 1,
	1,0,0, 1,

	1,0,1, 1,
	1,0,1, 1,
	1,0,1, 1,
	
	1,0,1, 1,
	1,0,1, 1,
	1,0,1, 1,
		
	1,0,1, 1,
	1,0,1, 1,
	1,0,1, 1,
		
	1,0,1, 1,
	1,0,1, 1,
	1,0,1, 1,

	1,0,1, 1,
	1,0,1, 1,
	1,0,1, 1,

};

int main()
{
	nmglvsNm0Init();

	nmglClearColor(0, 0, 0.4f, 1.0f);

	nmglMatrixMode(NMGL_PROJECTION);
	nmglOrthof(-768/2, 768 / 2, -768 / 2, 768 / 2, 0, 100);
	//nmglOrthof(0, 768, 0, 768, 0, 100);
	

	nmglVertexPointer(2, NMGL_FLOAT, 0, triangles);
	nmglColorPointer(4, NMGL_FLOAT, 0, color);
	nmglEnableClientState(NMGL_VERTEX_ARRAY);
	nmglEnableClientState(NMGL_COLOR_ARRAY);
	while(nmglvsNm0Run()){
		nmglClear(NMGL_COLOR_BUFFER_BIT);

		nmglDrawArrays(NMGL_TRIANGLES, 0, 18);

		nmglvsSwapBuffer();
	}
	nmglDisableClientState(NMGL_VERTEX_ARRAY);
	nmglDisableClientState(NMGL_COLOR_ARRAY);
	nmglvsExit_mc12101();
	return 0x600D600D;
}
