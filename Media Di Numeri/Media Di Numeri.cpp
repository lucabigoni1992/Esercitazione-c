// Media Di Numeri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C per calcolare la media aritmetica
di una serie di numeri inseriti da tastiera.
L'introduzione di un valore particolare pari a 
“0” indica il termine del caricamento dei dati.
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int numero; /* numero inserito */
	int conta; /* conta quanti numeri sono inseriti */
	float somma; /* somma dei numeri inseriti */
	float media; /* media dei numeri inseriti */

	/* "somma" e "media" sono di tipo float per calcolare la media come valore decimale con la virgola*/
	/* INIZIALIZZA LE VARIABILI */
	somma = 0; conta = 0;
	/* LEGGI UN NUMERO */ 
	printf("Inserire una serie di numeri. La condizione di terminazione e' il numero zero.\n");
	printf("Inserisci numero: "); 
	scanf("%d", &numero);
	/* LEGGI UNA SERIE DI NUMERI, FINO A QUANDO NON E' INSERITO IL NUMERO 0 */
	while (numero != 0)
	{
		/* AGGIORNA LA SOMMA DEI NUMERI INSERITI */
		somma = somma + numero;
		/* INCREMENTA IL CONTATORE DEI NUMERI INSERITI FINO AD ORA */
		conta = conta + 1;
		/* LEGGI UN NUMERO */
		printf("Inserisci numero:");
		scanf("%d", &numero);
	}
	/* CALCOLA LA MEDIA DEI NUMERI INSERITI */ 
	media = somma / conta;

	/* STAMPA IL RISULTATO */
	printf("\n");
	printf("Numeri inseriti %d, Somma %f, Media %f \n", conta, somma, media);
	return(0);
}
