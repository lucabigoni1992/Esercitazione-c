

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
//sia copia il contenuto del 1° array nel 2°
int main()
{
	char st[20] = { 'a','b','c', 'a','b','c', 'a','b','c', 'a','b','c', 'a','b','c', 'a','b','c', 'd' };
	char st2[20];
	char* p, * j;
	p = &st[0];
	j = &st2[0];

	do {
		*j = *p;//si effettua la copiatura
		p++; j++;//si scorrono i puntatori
	} while (*p != '\0');
	*j = '\0';
	*p = '\0';
	printf("%s", j);
	printf("%s", p);
	printf("%s", st);
	printf("%s", st2);

}