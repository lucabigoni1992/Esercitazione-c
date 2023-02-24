// Massimo e minimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int numero;	/* numero inserito */
	int N;	/* quanti numeri saranno inseriti */
	int max, min;	/* valore massimo e minimo tra i numeri inseriti */
	/* LEGGI QUANTI NUMERI SARANNO INSERITI */
	printf("Indica quanti numeri saranno inseriti:"); 
	scanf("%d", &N);
	/* VERIFICA CHE LA SEQUENZA INSERITA CONTENGA ALMENO UN NUMERO*/
	if (N <= 0)
		printf("Errore: non sara' inserito nessun numero \n");
	else {
		/* LEGGI UN NUMERO */
		printf("Inserisci un numero:");
		scanf("%d", &numero);
		/* N VIENE DECREMENTATO POICHE' E' STATO INSERITO UN NUMERO */
		N = N - 1;

		/* INIZIALIZZA "max" e "min" CON IL PRIMO NUMERO INSERITO */
		max = numero; min = numero;
		/* LEGGI GLI ALTRI NUMERI DELLA SEQUENZA */
		while (N > 0)
		{
			/* LEGGI UN NUMERO */ printf("Inserisci un numero:");

			scanf("%d", &numero);
			/* AGGIORNA IL VALORE MASSIMO "max" */ if (numero > max)
				max = numero;
			else
			{
				/* AGGIORNA IL VALORE MINIMO "min" */ if (numero < min)
					min = numero;

			}
			/* N VIENE DECREMENTATO POICHE' E' STATO INSERITO UN NUMERO */
			N = N - 1;
		}

		/* STAMPA IL RISULTATO */
		printf("\n");
		printf("Valoremassimo %d, Valore minimo %d\n", max, min);
	}
	return(0);
}
