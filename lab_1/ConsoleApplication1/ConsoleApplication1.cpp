#include <stdio.h>
//var №8
int main()
{
	char a;
	_asm
	{
		mov ax, 45
		mov bh, 6
		div bh //ax = 45 / 6
		mov ah, 0

		mov bx, ax //bx = 45 / 6

		mov al, 3
		mov bl, 22
		mul bl //ax = 3 * 22

		sub ax, bx //ax = 22 * 3 - 45 / 6
		mov bh, 14
		div bh    //ax = (22 * 3 - 45 / 6)/14
		mov ah, 0

		mov bx, ax // bx = chislitel

		mov al, 134
		mov ax, 7
		mov bl, 5
		mul bl // ax = 7*5

		sub al, bl //al = 134-35
		idiv al //ax= chislitel/znam
		mov ah, 0

		mov bl, 2
		mul bl

		add ax, 4
		mov a, al
	}
	printf("%d", a);
}