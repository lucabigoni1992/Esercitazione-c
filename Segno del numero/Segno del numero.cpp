// Segno del numero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Si realizzi un programma in linguaggio C che acquisisca da tastiera un numero e stampi un messaggio che indichi se tale numero sia positivo oppure negativo.*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a; /* numero inserito */
	/* LEGGI IL NUMERO */ printf("Immetti un numero:");
	scanf("%d", &a);
	/* VERIFICA SE IL NUMERO E’ POSITIVO O NEGATIVO */ if (a >= 0)
	{
		/* IL NUMERO E’ POSITIVO O NULLO */
		printf("Il numero %d e’ positivo\n", a);
	}
	else {
		/* IL NUMERO E’ NEGATIVO */
		printf("Il numero %d e’ negativo\n", a);

	}
	return(0);
}
