#pragma once
#ifndef prob2_h
#define prob2_h
#include <iostream>
#include <algorithm>
#include <iomanip>
float a, b, c, four = 4, negativeOne = -1, two = 2;
float x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, sqrtval;
void prompt() {
	std::cout << "To see the two real roots of [ aX^2 + bX + c = 0 ], enter the a,b,c values: ";
	std::cin >> a >> b >> c;
}
void sqrtCalculate() {
	sqrtval = sqrt(x3);
}

void prob2() {
	_asm {
		call prompt;
	loop1:
		fld b;
		fld b;
		fmul;
		fstp x1;	//x1 = b^2

		fld a;
		fld c;
		fmul;
		fld four;
		fmul;
		fstp x2;	//x2 = 4ac

		fld x1;
		fld x2;
		fsub;
		fstp x3;	//x3 = (b^2 - 4ac)
		call sqrtCalculate;
		mov eax, sqrtval;
		mov x3, eax;


		fld b;
		fld negativeOne;
		fmul;
		fstp x4;	//x4 = -b

	 //will hold x5 = -b -sqrt(b^2 - 4ac)
		fld x4;
		fld x3;
		fsub;
		fstp x5;

	//will hold x6 = -b + sqrt(b^2 - 4ac)
		fld x4;
		fld x3;
		fadd;
		fstp x6;

	//will hold x7 = 2a
		fld two;
		fld a;
		fmul;
		fstp x7;
	//will hold x8 = -b - sqrt(b^2 - 4ac)/2a
		fld x5;
		fld x7;
		fdiv;
		fstp x8;
	//wild hold x9 = -b + sqrt(b^2 - 4ac)/2a
		fld x6;
		fld x7;
		fdiv;
		fstp x9;

	}//end of asm
	std::cout << std::fixed << std::setprecision(2) << "X1 = " << x8 << "			X2  = " << x9 << std::endl;
}//end of prob2() 
#endif // !prob2_h
