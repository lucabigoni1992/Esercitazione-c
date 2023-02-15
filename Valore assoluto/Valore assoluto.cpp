// Valore assoluto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si realizzi un programma in linguaggio C che acquisisca da tastiera un numero e stampi il valore assoluto di tale numero.
*/
/* PROGRAMMAZIONE IN C */
/* File: es-valabs.c */
/* Soluzione proposta esercizio "Valore assoluto" */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a, b; /* numero inserito ed il corrispondente valore assoluto */
	/* LEGGI IL NUMERO */ printf("Immetti un numero:");
	scanf("%d", &a);
	/* VERIFICA SE IL NUMERO E' POSITIVO O NEGATIVO */ if (a >= 0)
	{
		/* IL NUMERO E' POSITIVO */
		printf("Il numero %d e' positivo\n", a);
		/* ASSEGNA A b IL VALORE DI a */ b = a;
	}
	else {
		/* IL NUMERO E' NEGATIVO */ printf("Il numero %d e' negativo\n", a);
		/* ASSEGNA A b IL VALORE DI a CAMBIANDO IL SEGNO */ b = -a;
	}
	/* STAMPA IL RISULTATO */
	printf("Il valore assoluto di %d e' %d\n", a, b);
	return(0);
}
