// Fattoriale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C che acquisisca un numero intero positivo N da tastiera e stampi il valore del fattoriale di N.
Suggerimento. Si ricorda che il fattoriale di un numero è il prodotto di tutti i numeri compresi tra 1 ed N.
N! = 1 · 2 · 3 · ... · (N − 1) · N Inoltre 0! = 1.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N; /* numero inserito */
	int fattoriale;	/* fattoriale del numero */
	/* LEGGI UN NUMERO */
	printf("Inserisci un numero intero positivo:");
	scanf("%d", &N);
	/* VERIFICA CHE IL NUMERO INSERITO SIA POSITIVO */ 
	if (N < 0)
		printf("Errore: il numero inserito deve esserepositivo\n");

	else {
		/* INIZIALIZZA IL VALORE DEL FATTORIALE */ fattoriale = 1;

		/* IL FATTORIALE E' CALCOLATO COME PRODOTTO
		TRA TUTTI I NUMERI COMPRESI TRA "N" E 1 */ while (N > 1)
		{
			/* AGGIORNA IL VALORE DEL FATTORIALE */
			fattoriale = fattoriale * N;
			/* DECREMENTA IL VALORE DI "N" */
			N = N - 1;
		}
		/* STAMPA IL RISULTATO */ printf("\n");
		printf("Ilfattoriale e' %d\n", fattoriale);


	}
	exit(0);
}
