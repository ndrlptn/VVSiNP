#include <stdio.h>
#include <bitset>

int main()
{
	char a;

				 // 28 = 00011100
	_asm {
		MOV al, 1010b // 00001010
		and al, 28 // 00001000
		not al     // 11110111
		SAL al, 2 //  1 101 1100
		
		XOR al, 01110000b
		
		mov a, al
	}

	printf("%d", a);

	return 0;
}