#include <iostream>
#include <string>

int main()
{
	float result = 0;
	float const e = 2.718;
	//					   0        4  8  12   16 20
	float array[] = { 250 - 4 * 6, 33,  4, 2, 17, 1 };
	float x;
	float a;
	std::cout << "Input x: ";
	std::cin >> x;
	std::cout << "Input a: ";
	std::cin >> a;

	double summ = x + a;
	_asm
	{
		fld summ;
		fcos; //st[0] = cos(sum)
		fmul array + 4;
		fadd array + 8;
		fdiv array + 12;
		fsub array + 16;
		fdivR array;
		
		
		fld x;
		fld e;
		fyl2x; // st[1] = st[1] * log_2(st[0]); p.s. st[1] = x, st[0] = e;
		f2xm1; // st[0] = 2^(st[0]) - 1
		fadd array + 20;
		fchs;
		
		
		fld a;
		fsin;
		fmul st(0), st(1);

		fadd array + 12;
		fadd array + 8;

		fmul st(0), st(2);
		fsub array + 16;

		fstp result;


	}


	std::cout << result;
	return 0;
}


