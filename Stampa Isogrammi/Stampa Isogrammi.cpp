// Stampa Isogrammi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
Il valore N è inserito dall’utente.
I numeri sono memorizzati in un vettore.
Terminato l’inserimento della sequenza di numeri, il programma deve visualizzare una riga di asterischi per ogni numero inserito.
Il numero di asterischi nella riga è pari al valore del numero inserito. Ad esempio, dato il vettore 9 4 6 il programma deve visualizzare:

Elemento 1: 9 *********
Elemento 2: 4 ****
Elemento 3: 6 ******
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> #include <stdlib.h>
int main(void)
{
	const int MAXN = 200;	/* dimensione massima del vettore */
	int N;	/* occupazione del vettore */
	int vet[MAXN];	/* sequenza di numeri interi */
	int i, j;	/* indici dei cicli */
	/* LEGGI LE DIMENSIONI DEL VETTORE */ do {
		printf("Quanti numeri saranno inseriti? ");
		/* Soluzione proposta esercizio "Stampa istogrammi" */
		scanf("%d", &N);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E’ COMPRESA TRA 1 E MAXN */
		if (N > MAXN || N <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);
	} while (N > MAXN || N <= 0);
	/* LEGGI UNA SEQUENZA DI N NUMERI INTERI, MEMORIZZANDOLI IN UN VETTORE */
	printf("Inserisci una sequenza di %d numeri\n", N);
	for (i = 0; i < N; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet[i]);
	} printf("\n");
	/* STAMPA IL VETTORE DI INTERI */
	printf("Lasequenza inserita e’ la seguente\n");
	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	/* STAMPA GLI ISTOGRAMMI */
	printf("Stampa degli istogrammi\n");
	for (i = 0; i < N; i++)
	{
		/* STAMPA IL NUMERO IN POSIZIONE "i" NEL VETTORE "vet" (OSSIA vet[i]) */
		printf("Elemento %d: %d ", i + 1, vet[i]);
		/* STAMPA L’ISTOGRAMMA PER IL NUMERO "vet[i]", OSSIA STAMPA UN NUMERO DI "*" UGUALE A vet[i] */
		for (j = 0; j < vet[i]; j++)
			printf("*");
		printf("\n");
	} return(0);
}
