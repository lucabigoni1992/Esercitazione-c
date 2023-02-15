// Ricerca di un elemento in vettore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi.
I numeri sono memorizzati in un vettore. Il valore N è inserito dall'utente, ma  il vettore può contenere al massimo 30 numeri.
Terminato l'inserimento della sequenza di numeri, l'utente inserisce un valore di riferimento.
Il programma deve indicare se tale valore di riferimento è contenuto nel vettore.*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
int main(void)
{
	const int MAXN = 30;	/* dimensione massima del vettore */
	int N;	/* occupazione effettiva del vettore */
	int vet[MAXN];	/* sequenza di numeri interi */
	int i;	/* indice dei cicli */
	int numero;	/* numero da ricercare nella sequenza */
	int trovato;	/* flag per indicare se la sequenza contiene il numero inserito */
	/* LEGGI LE DIMENSIONI DEL VETTORE */ do {
		printf("Quanti numeri saranno inseriti? ");
		/* Soluzione proposta esercizio "Ricerca di un elemento in un vettore" */
		scanf("%d", &N);

		/* LA DIMENSIONE MASSIMA DEL VETTORE E' COMPRESA TRA 1 E MAXN */
		if (N > MAXN || N <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);

	} while (N > MAXN || N <= 0);
	/* LEGGI UNA SEQUENZA DI N NUMERI INTERI, MEMORIZZANDOLI IN UN VETTORE */
	printf("Inserisci una sequenza di %d numeri\n", N);
	for (i = 0; i < N; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet[i]);

	}
	printf("\n");
	/* STAMPA IL VETTORE DI INTERI */
	printf("Lasequenza inserita e' la seguente\n");
	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	/* LEGGI IL NUMERO DA RICERCARE NELLA SEQUENZA */ printf("Inserisci il numero da cercare nella sequenza:");
	scanf("%d", &numero);
	/* VERIFICA SE LA SEQUENZA DI NUMERI CONTIENE IL NUMERO INSERITO */
	/* INIZIALIZZA IL FLAG "trovato". IL FLAG ASSUME I VALORI
	55	-- "trovato" E' UGUALE A 0 SE IL VETTORE "vet" NON CONTIENE IL VALORE "numero" -- "trovato" E' UGUALE A 1 SE IL VETTORE "vet" CONTIENE IL VALORE "numero" */
	trovato = 0;
	/* IL CICLO FOR SCANDISCE IL VETTORE "vet" E VERIFICA SE CONTIENE 60	IL VALORE "numero".
	LA RICERCA TERMINA QUANDO SI TROVA UNA CELLA "vet[i]"
	UGUALE A "numero" O QUANDO SONO STATE CONSIDERATE TUTTE LE CELLE DEL VETTORE */
	for (i = 0; i < N && trovato == 0; i++)
	{
		if (vet[i] == numero)
			/* SE "vet" CONTIENE IL VALORE IN "numero", AGGIORNA IL FLAG "trovato" */ trovato = 1;

	}
	/* STAMPA IL RISULTATO */
	if (trovato == 0)
		printf("Il numero %d non e' contenuto nella sequenza inserita\n", numero);
	else
		printf("Il numero %d e' contenuto nella sequenza inserita\n", numero);
	return(0);
}
