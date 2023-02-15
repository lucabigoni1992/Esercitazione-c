/*
Si scriva una funzione in C, denominata iniziali, che valuti quanti caratteri iniziali sono in comune tra due stringhe date. La funzione riceve due parametri, entrambi di tipo stringa, e restituisce il numero intero. Ad esempio:
• se la funzione venisse chiamata come iniziali("ciao", "cielo"), dovrebbe restituire 2 in quanto i primi due caratteri sono identici.
• se la funzione venisse chiamata come iniziali("ciao", "salve"), dovrebbe restituire
0 in quanto nessun carattere iniziale è in comune Soluzione

*/#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int iniziali(char a[], char b[])
{
	int n;
	n = 0;
	while (a[n] != 0 && b[n] != 0 && a[n] == b[n]) 
		n++;
	return n;
}

int main()
{
	char v[10] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b' };
	char v2[10] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b' };
	char v3[10] = { 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a' };
	printf("IL NUMERO DI VALORI UGUALI E': %d\n", iniziali(v, v2));
	printf("IL NUMERO DI VALORI UGUALI E': %d\n", iniziali(v2, v3));
}

