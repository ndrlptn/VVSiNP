#include <iostream>
#include <string>
int main()
{
	setlocale(LC_ALL, "RUS");

	char source[] = "шалаш шшлаа аалшш аалшш ншалаш шалашн шалаш";  //кол-во элементов в строке  
	int count, count2;

	count = 0;
	std::cout << source << "\n";
	_asm {
		mov eax, 0; //счетчик слов-перевертышей слова "шалаш"

		mov cl, 0;// 'ш'
		mov bx, 0;// 'a'
		mov dl, 0;// 'л'

		lea esi, source;

	reading: // Пробегаемся по строке до разделителя ' ' и до букв ш а л. Если встречается буква ш или л или а, увеличиваем cl, dl, bx соответственно.
		     // Если не встретилась ни одна из букв, переходим до следующего пробела
		mov al, [esi];

		cmp al, 0;
		je end;

		cmp al, ' ';
		je divide;

		cmp al, 'ш';
		je add_sh;

		cmp al, 'а';
		je add_a;

		cmp al, 'л';
		je add_l;

		jmp	skip;


	next: //следующий символ
		inc esi;
		jmp reading;


	skip:
		inc esi;
		cmp[esi], ' ';
		jne skip;// пропускаем пока не встретим слово

		cmp[esi], 0;
		je end;

		// зануляем счётчики для следующего слова
		mov cl, 0;
		mov bx, 0;
		mov dl, 0;
		jmp reading;
	divide:
		inc esi;
		cmp cl, 2; // 'ш' = 2
		je check_a;
		mov cl, 0;
		mov bx, 0;
		mov dl, 0;
		jmp reading;

	check_a:
		mov cl, 0;
		cmp bx, 2;// 'a' = 2
		je check_l;
		mov bx, 0;
		mov dl, 0;

	check_l:
		mov bx, 0;
		cmp dl, 1; // 'л' = 1
		je summ_count;
		mov dl, 0;

	summ_count:
		mov dl, 0;
		mov eax, 0; //counter
		inc eax;

		cmp count, 0;
		jg add_count; //count > 0

		mov count, eax;
		jmp reading;

	add_count:
		inc count;
		jmp reading;

	add_sh:
		inc cl;
		jmp next;

	add_a:
		inc bx;
		jmp next;

	add_l:
		inc dl;
		jmp next;

	end:
		cmp cl, 2;
		je check_a;
	}

	std::cout << count;
	return 0;
}
