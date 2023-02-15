// Da 2 numeri prendere il massimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C che acquisisca due numeri interi da tastiera e:
•	determini, stampando un messaggio opportuno quale dei due numeri (il primo o il secondo) sia maggiore
•	stampi il valore di tale numero.
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a, b; /* numeri inseriti */
	/* LEGGI I NUMERI */ 
	printf("Immetti il primo numero: ");
	scanf("%d", &a);
	printf("Immetti il secondo numero: ");
	scanf("%d", &b);
	/* VERIFICA SE a E’ MAGGIORE DI b */ if (a > b)
	{
		printf("Il primo numero %d e’ maggiore del secondo numero %d\n", a, b);
		printf("Il valore massimo e’ %d\n", a);
	}
	else {
		/* CASO a <= b */
		/* VERIFICA SE b E’ MAGGIORE DI a */
		if (a < b)
		{
			printf("Il secondo numero %d e’ maggiore del primo numero %d\n", b, a);
			printf("Il valore massimo e’ %d\n", b);

		}
		else
			/* CASO a = b */
			printf("Il primo numero %d ed il secondo numero %d sono uguali\n", a, b);
	}
	exit(0);
}
