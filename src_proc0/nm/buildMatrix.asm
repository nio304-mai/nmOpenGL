global _buildMatrix: label;// объявление глобальной метки

data ".data_demo3d"        //секция инициализированных данных
	dx: long;
	dy: long;
end ".data_demo3d";  

begin ".text_demo3d"			// начало секции кода
<_buildMatrix>	// определение глобальной метки
    ar5 = ar7 - 2;
    
    push ar0,gr0;
    push ar1,gr1;
    push ar2,gr2;
    push ar3,gr3;
    push ar4,gr4;
    push ar5,gr5;
    push ar6,gr6;
    
    ar0 = [--ar5];  // x coords
    ar4 = [--ar5];  // y coords
    ar6 = [--ar5];  // z coords
    ar2 = [--ar5];  // deltaX, deltaY
    ar1 = [--ar5];  // deltaZ

    gr0 = [--ar5];  // k 

	//gr7 = gr0;
	//goto Exit;
	
	// gr0 - column counter
	ar3,gr3 = [ar2++] with gr1 = gr0 >> 1; //gr0 - Number of columns (/2)
	[dx] = ar3,gr3;
	ar3,gr3 = [ar2];
	[dy] = ar3,gr3;

	ar2 = ar4;
	ar4 = ar6;

<NextColumn> // do { Process column } while (gr1 > 0)
	gr2 = gr0; // gr0 используется для перехода от строки к строке
	// Выбрать количество обрабатываемых слов (gr3)
	gr4 = 32;
	gr1 - gr4;
	if >= goto LoadFirstRow;
	gr4 = gr1;
<LoadFirstRow>
	ar3 = ar0 with gr3 = gr0;
	ar5 = ar2 with gr5 = gr0;
	ar6 = ar4 with gr6 = gr0;

	ar3 += gr3 with gr3 = gr4;
	gr3 <<= 1;
	gr3 = gr0 - gr3;
	ar5 += gr5 with gr5 = gr3;
	ar6 += gr6 with gr6 = gr3;

	gr4--; 
	vlen = gr4 with gr4++; // Restore pair counter after decrementing for vlen

	// Load first row values
	fpu 0 rep vlen vreg0 = [ar0++];
	fpu 1 rep vlen vreg0 = [ar2++];
	fpu 2 rep vlen vreg0 = [ar4++];
	
	// Load deltas
	gr7 = dx;
	fpu 0 rep vlen vreg2 = [gr7];
	gr7 = dy;
	fpu 1 rep vlen vreg2 = [gr7];
	fpu 2 rep vlen vreg2 = [ar1++];
<NextRow>
	fpu 0 .float vreg0 = vreg0 + vreg2;
	fpu 1 .float vreg0 = vreg0 + vreg2;
	fpu 2 .float vreg0 = vreg0 + vreg2;
	fpu 0 rep vlen [ar3++] = vreg0;
	fpu 1 rep vlen [ar5++] = vreg0;
	fpu 2 rep vlen [ar6++] = vreg0;
	ar3 += gr3;
	ar5 += gr5;
	ar6 += gr6 with gr2--;
	if > goto NextRow;
	// Exit NextRow
	gr1 = gr1 - gr4; 
	if > goto NextColumn;

<Exit>
    pop ar6,gr6;
    pop ar5,gr5;
    pop ar4,gr4;
    pop ar3,gr3;
    pop ar2,gr2;
    pop ar1,gr1;
    pop ar0,gr0;

    return;          // возврат из функции, возвращаемое значение хранится в gr7
end ".text_demo3d";      // признак окончания секции кода
