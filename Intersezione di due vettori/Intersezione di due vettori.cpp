// Intersezione di due vettori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Siano dati due vettori di interi inseriti da tastiera. La lunghezza dei due vettori è inserita dall'utente da tastiera. I due vettori possono avere lunghezze diverse, ma possono contenere al massimo 30 numeri. Si scriva un programma in linguaggio C per generare un terzo vettore che contiene l'intersezione tra due vettori. Tale vettore deve contenere i numeri presenti in entrambi i vettori dati.
Ad esempio, si assuma che siano stati inseriti i due vettori:
1	6 15 20 25
2	20 18 6
Il programma deve visualizzare la sequenza 6 20.

*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	const int MAXN = 30;	/* dimensione massima dei vettori */
	int vet1[MAXN], vet2[MAXN]; /* vettori di interi */
	int N1, N2;	/* dimensione dei vettori */
	int intersezione[MAXN];	/* intersezione tra i due vettori di interi */ int N_intersezione;	/* dimensione del vettore intersezione */
	int i, j;	/* indici dei cicli */
	int trovato;	/* flag per la ricerca */
	/* LEGGI LE DIMENSIONI DEL PRIMO VETTORE */
	do
	{
		printf("Quanti numeri sarannoinseriti nel primo vettore?");
		scanf("%d", &N1);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E' COMPRESA TRA 1 E MAXN */
		if (N1 > MAXN || N1 <= 0)
			printf("Errore: il numero deve essere compreso tra 0 e %d\n", MAXN);
	} while (N1 > MAXN || N1 <= 0);
	/* LEGGI IL PRIMO VETTORE */
	printf("Inserisci il primo vettore di %d elementi\n", N1);
	for (i = 0; i < N1; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet1[i]);
	} printf("\n");
	/* STAMPA DEL PRIMO VETTORE */
	printf("Stampa del primo vettore\n");
	for (i = 0; i < N1; i++)
		printf("Elemento %d: %d\n", i + 1, vet1[i]);
	printf("\n");
	/* LEGGI LE DIMENSIONI DEL SECONDO VETTORE */
	do {
		printf("Quanti numeri sarannoinseriti nel secondovettore?");
		scanf("%d", &N2);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E' COMPRESA TRA 1 E MAXN */
		if (N2 > MAXN || N2 <= 0)
			printf("Errore: il numero deve essere compreso tra 0 e %d\n", MAXN);
	} while (N2 > MAXN || N2 <= 0);
	/* LEGGI IL SECONDO VETTORE */
	printf("Inserisci il secondovettore di %d elementi\n", N2);
	for (i = 0; i < N2; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet2[i]);
	} printf("\n");

	/* STAMPA DEL SECONDO VETTORE */
	printf("Stampa il secondo vettore\n");
	for (i = 0; i < N2; i++)
		printf("Elemento %d: %d\n", i + 1, vet2[i]);
	printf("\n");
	/* AGGIORNA IL VETTORE "intersezione" */
	/* INIZIALMENTE IL VETTORE "intersezione" NON CONTIENE NESSUN NUMERO */
	N_intersezione = 0;
	/* IL CICLO FOR SCANDISCE IL VETTORE "vet1" */
	for (i = 0; i < N1; i++)
	{
		/* INIZIALIZZA IL FLAG "trovato". IL FLAG ASSUME I VALORI
	-- "trovato" E' UGUALE A 0 SE IL VETTORE "vet2" NON CONTIENE
	IL VALORE IN "vet1[i]"
	-- "trovato" E' UGUALE A 1 SE IL VETTORE "vet2" CONTIENE IL VALORE IN "vet1[i]" */
		trovato = 0;
		/* PER OGNI ELEMENTO "vet1[i]" DI "vet1", IL CICLO FOR SCANDISCE IL
		VETTORE "vet2" E VERIFICA SE "vet2" CONTIENE IL VALORE IN "vet1[i]"
		95	LA RICERCA TERMINA QUANDO SI TROVA UNA CELLA "vet2[j]" UGUALE A "vet1[i]" O QUANDO SONO STATE CONSIDERATE TUTTE LE CELLE DEL VETTORE "vet2" */
		for (j = 0; j < N2 && trovato == 0; j++)
		{
			if (vet2[j] == vet1[i])
			{
				/* SE "vet2" CONTIENE IL VALORE IN "vet1[i]", QUESTO VALORE E' INSERITO NEL VETTORE "intersezione" */
				intersezione[N_intersezione] = vet1[i];
				/* INCREMENTA LA DIMENSIONE DEL VETTORE "intersezione" */
				N_intersezione = N_intersezione + 1;
				/* AGGIORNA IL FLAG "trovato" */
				trovato = 1;
			}
		}
	}
	/* STAMPA DEL VETTORE "intersezione" */
	printf("Stampa del vettore intersezione\n");
	if (N_intersezione == 0)
		printf("Il vettore intersezione non contiene nessun elemento\n");

	else
	{
		printf("Il vettore intersezione contiene %d elementi \n", N_intersezione);
		for (i = 0; i < N_intersezione; i++)
			printf("Elemento %d: %d\n", i + 1, intersezione[i]);
		printf("\n");
	}
}
