// Opposto numero binario in complemento a 2 su N bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma che riceve in ingresso un numero binario rappresentato in complemento a 2 su N bit. Inizialmente l’utente inserisce il numero N di bit. Quindi inserisce le cifre del numero binario un bit alla volta, partendo dal bit più significativo (MSB). Terminato l’inserimento del numero, il programma esegue le seguenti operazioni:
1.	visualizza il numero inserito partendo dal bit più significativo
2.	calcola l’opposto del numero binario ricevuto in ingresso
3.	visualizza l’opposto del numero binario ricevuto in ingresso partendo dal bit piùsignificativo (MSB).
Per poter effettuare il calcolo del risultato,
utilizzare il metodo secondo il quale si considerano le cifre del numero binario in complemento a due a partire dalla meno significativa (LSB)
alla più significativa (MSB) (ossia da destra verso sinistra). Si ricopiano in uscita tutti gli zeri fino al primo 1 compreso. Dopo si invertono i restanti bit.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	const int MAXN = 200; /* dimensione massima del vettore */
	int N;	/* numero di cifre del numero binario */
	int bit[MAXN];	/* numero binario */
	int opposto[MAXN];	/* opposto del numero binario */
	int inverti;	/* flag per indicare se le cifre binarie devono essere invertite */
	int i;	/* indice dei cicli */
	/* LEGGI IL NUMERO DI CIFRE BINARIE */
	do {
		printf("Quanti bit sarannoinseriti?");
		scanf("%d", &N);
		if (N > MAXN || N <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);

	} while (N > MAXN || N <= 0);
	/* LEGGI LE CIFRE BINARIE E MEMORIZZALE NEL VETTORE. L’ELEMENTO "bit[0]"
	35	CONTIENE IL BIT PIU’ SIGNIFICATIVO. L’ELEMENTO "bit[N-1]" CONTIENE IL BIT MENO SIGNIFICATIVO */
	printf("Inserisci le cifre binarie partendo dalla piu’ significativa\n");
	for (i = 0; i < N; i++)
	{
		scanf("%d", &bit[i]);
	}
	/* STAMPA IL NUMERO BINARIO INSERITO */
	printf("Il numero binario inserito e’ il seguente:\n");
	for (i = 0; i < N; i++)
		printf("Bit di peso %d: %d\n", N - 1 - i, bit[i]);
	printf("\n");

	/* LEGGI LE CIFRE DEL NUMERO BINARIO A PARTIRE DALLA CIFRA MENO SIGNIFICATIVA
	("bit[N-1]") A QUELLA PIU’ SIGNIFICATIVA ("bit[0]") ED ESEGUI LA CONVERSIONE */
	/* INIZIALIZZA IL FLAG "inverti":
-- SE "inverti" E’ UGUALE a 1: si invertono tutte le cifre binarie successive
-- SE "inverti" E’ UGUALE A 0: si ricopiano in uscita i bit successivi
"inverti" E’ INIZIALIZZATO A 0 ED ASSEGNATO A 1 QUANDO SI TROVA IL PRIMO BIT UGUALE A 1 */
	inverti = 0;
	for (i = N - 1; i >= 0; i--)
	{
		/* CALCOLA IL VALORE OPPOSTO*/
			if (inverti == 0)
			{
				/* RICOPIA IN USCITA LA CIFRA BINARIA INSERITA */
				opposto[i] = bit[i];
				/* SE HAI TROVATO LA PRIMA CIFRA BINARIA AD 1, AGGIORNA "inverti" */
				if (bit[i] == 1)
					inverti = 1;
			}
			else
			{
				/* RICOPIA IN USCITA L’INVERSO DELLA CIFRA BINARIA INSERITA */
				if (bit[i] == 1)
					opposto[i] = 0;
				else
					opposto[i] = 1;
			}
	}
	/* STAMPA IL RISULTATO A PARTIRE DALLA CIFRA PIU’ SIGNIFICATIVA */
	printf("Il numero binario risultante e’ il seguente:\n");
	for (i = 0; i < N; i++)
		printf("bit di peso %d: %d\n", N - 1 - i, opposto[i]);
	printf("\n");
	return(0);
}
