// Numeri di Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che calcoli e stampi i primi N numeri della serie di Fibonacci, con N inserito da tastiera.
La serie di Fibonacci inizia con 1, 1 ed ogni numero successivo è dato dalla somma dei due precedenti: 1, 1, 2, 3, 5, 8, 13, 21 . . .
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
int main(void)
{
	int N;	/* numero di termini della serie */
	int ValoreStampato;	/* nuovo termine della serie */
	int prec_1, prec_2; /* due termini precedenti nella serie */ 
	int numStampati;	/* contatore per scandire i termini della serie */

	/* LEGGI IL NUMERO TERMINI DELLA SEQUENZA */
	printf("Inserisci il numero di termini della serie di Fibonacci:");
	scanf("%d", &N);
	/* INIZIALIZZA A 1 I PRIMI DUE TERMINI DELLA SERIE */
	prec_1 = 1; prec_2 = 1;
	/* INIZIALIZZA A 1 IL PRIMO VALORE DELLA SERIE */
	ValoreStampato = 1;
	/* INIZIALIZZA A 0 IL CONTATORE CHE SCANDISCE I TERMINI DELLA SERIE */
	numStampati = 0;
	while (numStampati < N)
	{
		/* I PRIMI DUE TERMINI DELLA SERIE SONO UGUALI A 1.
		I TERMINI SUCCESSIVI SONO CALCOLATI COME SOMMA DEI DUE TERMINI PRECEDENTI */
		if (numStampati >= 2)
		{
			/* CALCOLA IL NUOVO TERMINE DELLA SERIE */
			ValoreStampato = prec_1 + prec_2;
			/* AGGIORNA IL VALORE DEI DUE TERMINI PRECEDENTI NELLA SERIE */
			prec_2 = prec_1;
			prec_1 = ValoreStampato;
		}
		/* STAMPA UN NUOVO TERMINE DELLA SERIE */
		printf("%d", ValoreStampato);
		/* INCREMENTA IL CONTATORE "num_termini" */
		numStampati = numStampati + 1;
	}

	/* RIPORTA A CAPO IL CURSORE AL TERMINE DELLA STAMPA DELLA SERIE */
	printf("\n");
	return(0);
}
