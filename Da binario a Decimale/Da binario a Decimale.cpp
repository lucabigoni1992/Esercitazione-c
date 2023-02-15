// Da binario a Decimale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Si scriva un programma in linguaggio C che converta un numero binario in un numero decimale. Il numero binario è rappresentato su N bit, e il valore di N è inserito da tastiera. L’utente inserisce le cifre del numero binario un bit alla volta, partendo dal bit meno significativo (ossia dal bit di peso 20). Il programma visualizzerà il numero decimale corrispondente.
Suggerimento. Per calcolare le potenze di 2 utilizzare la funzione pow, includendo la libreria math.h. Ad esempio per calcolare 25, si scriverà pow(2,5). In generale, data una base a, per calcolare y = ab, si scrive y = pow(a,b) includendo la libreria math.h.
Soluzione
Questa soluzione è “generalizzabile” facilmente ad altre basi pur di cambiare il valore della costante BASE.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#define BASE 2
int main(void)
{
	int N;	/* numero di cifre binarie */
	int bit;	/* cifra binaria */
	int peso;	/* peso della cifra binaria */
	int numero;	/* valore decimale del numero binario */
	/* INIZIALIZZA LE VARIABILI */
	peso = 0;	/* LA PRIMA CIFRA BINARIA LETTA AVRA’ PESO ZERO */ numero = 0; /* IL VALORE DECIMALE DEL NUMERO BINARIO E’ INIZIALIZZATO A ZERO */
	/* LEGGI IL NUMERO DI CIFRE BINARIE */
	printf("Immetti il numero di bit del numero binario:");
	scanf("%d", &N);
	/* LEGGI IL NUMERO BINARIO */
	printf("\nImmetti il numero binariopartendo dal bit meno significativo\n");


	while (peso < N)
	{
		/* LEGGI LA CIFRA BINARIA SUCCESSIVA */ printf("Immetti la cifra binaria2^%d:", peso);

		scanf("%d", &bit);
		/* CALCOLA IL VALORE IN DECIMALE DELLA CIFRA BINARIA INSERITA E AGGIUNGILO ALLA CIFRA DECIMALE CALCOLATA FINO AD ORA*/ 
		numero = numero + bit * pow(BASE, peso);

		/* AGGIORNA IL PESO DELLA CIFRA BINARIA */ peso = peso + 1;
	}
	/* STAMPA IL RISULTATO */
	printf("\n"); printf("La cifra decimalecalcolata e’: %d\n", numero);
	return(0);
}
