#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>

int main() {
	int x;
	int y1;
	int a;
	printf("Input x:");
	std::cin >> x;
	printf("Input a:");
	std::cin >> a;
	int y2;
	_asm {
		mov eax, x;
		mov ebx, a;
		cmp eax, 4;
		jle Higher; // eax <= 4

	Lower:
		sub eax, ebx;
		mov y1, eax;
		jmp result1;
	Higher:
		mov ebx, 4;
		imul ebx;
		mov y1, eax;

	result1:
		mov ecx, x;
		and ecx, 1b;
		cmp ecx, 0;
		je ifEven;
	ifOdd:
		mov y2, 7;
		jmp Result;

	ifEven:
		mov eax, x;
		mov bh, 2;
		div bh;
		add eax, a;
		mov y2, eax;
		jmp Result;


	Result:
		mov eax, y1;
		add y2, eax;
	}
	printf("result %d", y2);

	return 0;
}
