// Divisori di un numero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* Sia dato un numero intero positivo N inserito da tastiera. Si scriva un programma in linguaggio C che calcoli i numeri interi che sono divisori (con resto uguale a zero) di N.
Dire inoltre se N è un numero primo. Suggerimento.
•	Un numero M è divisore di un numero N se il resto della divisione N/M è uguale a zero.
•	Un numero è primo se è divisibile solo per 1 o per il numero stesso.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero; /* numero inserito */ int divisore; /* divisore del numero. E' un contatore per scandire tutti i valori tra 1 e "numero" */
	int primo;	/* flag per indicare se il numero inserito e' primo */

	/* LEGGI UN NUMERO */ printf("Inserisci un numero intero positivo:"); scanf("%d", &numero);
	/* CONTROLLA SE IL NUMERO E' POSITIVO */ if (numero <= 0) printf("Errore: hai inserito un numero nullo o negativo\n");
	else {
		/* PER CALCOLARE I DIVISORI CONSIDERA TUTTI I NUMERI COMPRESI TRA 1 E "numero" */
		divisore = 1;
		/* INIZIALIZZA IL FLAG "primo":
		30	-- SE "primo" E' UGUALE a 1: "numero" E' PRIMO
		-- SE "primo" E' UGUALE A 0: "numero" NON E' PRIMO.
		IPOTIZZA CHE "numero" SIA PRIMO ED INIZIALIZZA primo=1.
		ALL'INTERNO DEL CICLO ASSEGNA primo=0 SE VERIFICHI CHE
		"numero" NON E' PRIMO (OSSIA SE E' DIVISIBILE CON RESTO ZERO
		35	ALMENO PER UN VALORE DIVERSO DA 1 E DA "numero") */
		primo = 1;
		/* IL CICLO ANALIZZA TUTTI I VALORI DI "divisore" COMPRESI TRA 1 E "numero" */
		while (divisore <= numero)
		{
			/* VERIFICA SE IL RESTO DELLA DIVISIONE E' UGUALE A ZERO */ if (numero % divisore == 0)
			{
				/* STAMPA IL RISULTATO */
				printf("%d e' divisore di %d\n", divisore, numero);
				/* SE "divisore" E' DIVERSO SIA DA 1 CHE DA "NUMERO" ALLORA "numero" NON E' PRIMO*/
				if (divisore != 1 && divisore != numero)
					primo = 0;
			}
			/* INCREMENTA IL VALORE DEL POSSIBILE DIVISORE DI "numero" */
			divisore = divisore + 1;
		}
	}
	/* STAMPA IL RISULTATO */
	if (primo == 1)
		printf("%d e' un numero primo \n", numero);
	else 
		printf("%d non e' un numero primo \n", numero);
	exit(0);
}
