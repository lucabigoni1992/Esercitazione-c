// Vettore Ordinato.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
I numeri sono memorizzati in un vettore. Il valore N è inserito dall’utente, ma il vettore può contenere al massimo 30 numeri.
Terminato l’inserimento della sequenza di numeri, il programma deve verificare se il vettore contiene una sequenza di numeri ordinata in modo strettamente crescente.
*/
#include <iostream>

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	const int MAXN = 30;	/* dimensione massima del vettore */
	int N;	/* occupazione del vettore */
	int vet[MAXN];	/* sequenza di numeri interi */
	int i;	/* indice dei cicli */
	int crescente;	/* flag per indicare se la sequenza e’ crescente */
	/* LEGGI LE DIMENSIONI DEL VETTORE */
	do {
		printf("Quanti numeri saranno inseriti? ");
		/* Soluzione proposta esercizio "Verificare se un vettore di interi e’ ordinato" */
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
	/* VERIFICA SE LA SEQUENZA DI NUMERI E’ ORDINATA IN MODO CRESCENTE */
	/* INIZIALIZZA IL FLAG "crescente". IL FLAG ASSUME I VALORI
	50	-- "crescente" E’ UGUALE A 1 SE LA SEQUENZA E’ CRESCENTE -- "crescente" E’ UGUALE A 0 SE LA SEQUENZA NON E’ CRESCENTE */ crescente = 1;
	/* IL CICLO FOR SCANDISCE IL VETTORE "vet" E CONTROLLA SE LA SEQUENZA
	55	MEMORIZZATA NEL VETTORE E’ CRESCENTE. LA RICERCA TERMINA QUANDO SI VERIFICA
	CHE LA SEQUENZA NON E’ CRESCENTE O QUANDO SONO STATE CONSIDERATE TUTTE
	LE CELLE DEL VETTORE */
	/* NEL CICLO FOR SI CONFRONTA OGNI CELLA DEL VETTORE CON LA CELLA PRECEDENTE.
	60	SI OSSERVA CHE LA CELLA CON INDICE 0 (VET[0]) NON PUO’ ESSERE CONFRONTATA
	CON LA CELLA PRECEDENTE (CON INDICE -1). PERTANTO L’INDICE "i" DEL CICLO ASSUME I VALORI TRA 1 E N-1 */
	for (i = 1; i < N && crescente == 1; i++)
	{
		if (vet[i] <= vet[i - 1])
			/* SEQUENZA NON CRESCENTE, AGGIORNA IL FLAG "crescente" */ crescente = 0;
	}
	/* STAMPA IL RISULTATO */ if (crescente == 0) printf("Lasequenza non e’ crescente\n");
	else printf("Lasequenza e’ crescente\n");

	return(0);
}
