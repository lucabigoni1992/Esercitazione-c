// Classificazione sequenze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C per poter analizzare una sequenza di numeri. Dati N numeri interi letti da tastiera si vogliono calcolare e stampare su schermo diversi risultati:
•	quanti sono i numeri positivi, nulli e negativi
•	quanti sono i numeri pari e dispari
•	se la sequenza dei numeri inseriti è crescente, decrescente oppure né crescente né decrescente.
Suggerimento. Una sequenza è crescente se ogni numero è maggiore del precedente, decrescente se ogni numero è minore del precedente, né crescente né decrescente in tutti gli altri casi.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int totale;	/* quanti numeri saranno inseriti */ int numero;	/* ultimo numero inserito */
	int numero_precedente;	/* penultimo numero inserito */
	int N;	/* contatore per scandire i
	numeri della sequenza */
	int positivi, negativi, nulli; /* contatori numeri postivi, negativi, o nulli */
	int pari, dispari;	/* contatori numeri pari o dispari */
	int crescente, decrescente;	/* flag per indicare se la sequenza e'		crescente o decrescente */
	/* LEGGI QUANTI NUMERI SARANNO INSERITI */
	printf("Quanti numeri sarannoinseriti?");
	scanf("%d", &totale);

	/* INIZIALIZZA A ZERO I CONTATORI DI NUMERI POSITIVI, NEGATIVI, NULLI, PARI E DIPARI */
	positivi = 0; negativi = 0;
	nulli = 0; pari = 0; dispari = 0;
	/* INIZIALIZZA I FLAG PER INDICARE SE LA SEQUENZA E' CRESCENTE O DECRESCENTE 35	-- SE "crescente" E' UGUALE a 1: SEQUENZA CRESCENTE
	-- SE "crescente" E' UGUALE a 0: SEQUENZA NON CRESCENTE
	-- SE "decrescente" E' UGUALE a 1: SEQUENZA DECRESCENTE
	-- SE "decrescente" E' UGUALE a 0: SEQUENZA NON DECRESCENTE
	INIZIALIZZA AD 1 ENTRAMBI I FLAG. ALL'INTERNO DEL CICLO WHILE
	40	ASSEGNA I FLAG A 0 SE VERIFICHI CHE LA SEQUENZA NON E' CRESCENTE O NON E' DECRESCENTE */
	crescente = 1; decrescente = 1;
	/* INIZIALIZZA IL CONTATORE DEI NUMERI GIA' INSERITI */
	N = 0;
	/* RIPETI IL SEGUENTE CICLO FINO A QUANDO NON SONO STATI INSERITI TUTTI I NUMERI DELLA SEQUENZA */
	while (N < totale)
	{
		/* LEGGI UN NUMERO */ printf("Inserisci il numero %d: ", N + 1);
		scanf("%d", &numero);

		/* SE IL NUMERO E' UGUALE A ZERO INCREMENTA IL CONTATORE "nulli" */
		if (numero == 0)
			nulli = nulli + 1;
		else
		{
			/* IL NUMERO E' DIVERSO DA ZERO. SE NUMERO E' POSITIVO
			INCREMENTA IL CONTATORE "positivi" ALTRIMENTI INCREMENTA IL CONTATORE "negativi" */
			if (numero > 0)
				positivi = positivi + 1; else
				negativi = negativi + 1;
		}
		/* SE IL NUMERO E' PARI INCREMENTA IL CONTATORE "pari"
	ALTRIMENTI INCREMENTA IL CONTATORE "dispari" */
		if (numero % 2 == 0) pari = pari + 1;
		else
			dispari = dispari + 1;
		/* PER VERIFICARE SE LA SEQUENZA E' CRESCENTE O DECRESENTE
		CONFRONTA IL NUMERO CORRENTE CON IL PENULTIMO NUMERO INSERITO.
		LA VERIFICA PUO' ESSERE FATTA SOLO QUANDO SONO STATI INSERITI
		80	ALMENO DUE NUMERI DELLA SEQUENZA, OSSIA N>1. INFATTI,
		N==0 QUANDO VIENE INSERITO IL PRIMO NUMERO E N==1 QUANDO VIENE INSERITO IL SECONDO NUMERO */
		if (N > 1)
		{
			/* SE IL NUMERO CORRENTE E' MAGGIORE DEL PRECEDENTE LA SEQUENZA NON E' DECRESCENTE */ if (numero > numero_precedente) decrescente = 0;
			else
			{
				/* SE IL NUMERO CORRENTE E' MINORE DEL PRECEDENTE LA SEQUENZA NON E' CRESCENTE */ if (numero < numero_precedente)
					crescente = 0;
				else {
					/* SE IL NUMERO CORRENTE E' UGUALE AL PRECEDENTE LA SEQUENZA NON E' STRETTAMENTE CRESCENTE NE'
					100	STRETTAMENTE DECRESCENTE */
					crescente = 0; decrescente = 0;
				}
			}
		}
		/* IL NUMERO CORRENTE SARA' IL PENULTIMO NUMERO INSERITO NELLA PROSSIMA ITERAZIONE DEL CICLO */ numero_precedente = numero;

		/* INCREMENTA IL CONTATORE DEI NUMERI INSERITI */
		N = N + 1;
	}
	/* STAMPA IL RISULTATO */
	printf("Hai inserito: %d positivi, %d negativi, %d uguali a zero\n", positivi, negativi, nulli);
	printf("Hai inserito: %d pari, %d dispari\n", pari, dispari);
	if (crescente == 1) printf("Lasequenza e' crescente\n");

	else
	{
		if (decrescente == 1) printf("Lasequenza e' decrescente\n");
		else printf("Lasequenza non e' ne‘ crescente ne‘ decrescente\n");
	}
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
