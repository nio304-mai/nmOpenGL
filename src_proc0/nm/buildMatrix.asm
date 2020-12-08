// void buildMatrix(nm32f *array, const nm32f *delta, int k);

global _buildMatrix: label;// объявление глобальной метки

data ".data_demo3d"        //секция инициализированных данных
	M10: word[2] = (float(1), float(0)); // extract X0,X1 from (X0,Y0;X1,Y1)T vec
	buf: word[64];					// buf to copy odd words from vreg to mem
	tmpAddress: word;				// used to remember address of y or w row
end ".data_demo3d";  

begin ".text_demo3d"			// начало секции кода
<_buildMatrix>	// определение глобальной метки
    ar5 = ar7 - 2;
    
    push ar0,gr0;
    push ar1,gr1;
    push ar2,gr2;
    push ar3,gr3;
    
    ar0 = [--ar5];  // x coords
    ar2 = [--ar5];  // delta
    gr0 = [--ar5];  // k 

	ar3 = ar0 with gr3 = gr0;
	ar3 += gr3;

	gr1 = gr0;
	gr1 >>= 1;
	gr1--;
	vlen = gr1;
	fpu 0 rep vlen vreg0 = [ar0++];
	fpu 0 rep vlen vreg2 = [ar2];
<Loop>
	gr0;
	if =0 goto Exit;
	fpu 0 .float vreg0 = vreg0 + vreg2;
	fpu 0 rep vlen [ar3++] = vreg0;
	gr0--;
	goto Loop;

<Exit>
	gr7 = gr0;
    pop ar3,gr3;
    pop ar2,gr2;
    pop ar1,gr1;
    pop ar0,gr0;

    return;          // возврат из функции, возвращаемое значение хранится в gr7
end ".text_demo3d";      // признак окончания секции кода
