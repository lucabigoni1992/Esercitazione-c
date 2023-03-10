// Compattazione di un vettore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che legge N numeri interi da tastiera e li memorizza in un vettore. Il numero N viene inserito dall'utente ed ? minore di 20. Il programma deve generare un secondo vettore che compatta i numeri contenuti nel primo vettore. In particolare:
?	ogni numero che compare ripetuto nel primo vettore, deve comparire una sola volta nel secondo vettore
?	ogni numero uguale a zero presente nel primo vettore non deve comparire nel secondo vettore.
Il programma deve visualizzare il contenuto del secondo vettore.
Ad esempio, si supponga N=8 e si consideri la sequenza di numeri 1 18 3 0 24 3 6 0 inseriti da tastiera. Il programma deve visualizzare 1 18 3 24 6.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	const int MAXN = 20;	/* dimensione massima del vettore */
	int vet[MAXN];	/* sequenza di numeri interi */
	int compatto[MAXN];	/* sequenza compatta di numeri interi */
	int N;	/* dimensione del vettore "vet" */
	int N_compatto;	/* dimensione del vettore "compatto" */
	int i, j;	/* indici dei cicli */
	int trovato;	/* flag per la ricerca */
	/* LEGGI LE DIMENSIONI DEL VETTORE */ do {
		printf("Quanti numeri saranno inseriti? ");
		/* Soluzione proposta esercizio "Compattazione di un vettore" */
		scanf("%d", &N);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E' COMPRESA TRA 1 E MAXN */ if (N > MAXN || N <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);

	} while (N > MAXN || N <= 0);
	/* LEGGI UNA SEQUENZA DI N NUMERI INTERI, MEMORIZZANDOLI IN UN VETTORE */
	printf("Inserisci una sequenza di %d numeri\n", N); for (i = 0; i < N; i++)
	{
		printf("Elemento %d: ", i + 1); scanf("%d", &vet[i]);

	}
	printf("\n");
	/* STAMPA IL VETTORE DI INTERI */ printf("Lasequenza inserita e' la seguente\n");

	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	/* AGGIORNA IL VETTORE "compatto" */

		/* INIZIALMENTE IL VETTORE "compatto" NON CONTIENE NESSUN NUMERO */
	N_compatto = 0;
	/* IL CICLO FOR SCANDISCE IL VETTORE "vet" */
	for (i = 0; i < N; i++)
	{
		/* CONSIDERA SOLO LE CELLE IN "vet" CON VALORE DIVERSO DA 0 */ if (vet[i] != 0)
		{
			/* INIZIALIZZA IL FLAG "trovato". IL FLAG ASSUME I VALORI
		-- "trovato" E' UGUALE A 0 SE IL VETTORE "compatto" NON CONTIENE
		IL VALORE IN "vet[i]"
		-- "trovato" E' UGUALE A 1 SE IL VETTORE "compatto" CONTIENE
		IL VALORE IN "vet[i]" */
			trovato = 0;
			/* IL CICLO FOR SCANDISCE IL VETTORE "compatto" E VERIFICA SE IL VALORE IN "vet[i]" E' PRESENTE NEL VETTORE "compatto".
			70	LA RICERCA TERMINA QUANDO SI TROVA ALMENO UNA CELLA "compatto[j]"
			CHE HA LO STESSO VALORE DI "vet[i]" O QUANDO SONO STATE CONSIDERATE TUTTE LE CELLE DEL VETTORE "compatto" */
			for (j = 0; j < N_compatto && trovato == 0; j++)
			{
				/* SE "compatto" CONTIENE "vet[i]", AGGIORNA IL FLAG "trovato" */ if (compatto[j] == vet[i]) trovato = 1;
			}

			if (trovato == 0)
			{
				/* SE "trovato" E' UGUALE A 0, IL VETTORE "compatto" NON CONTIENE
				IL VALORE IN "vet[i]". ACCODA NEL VETTORE "compatto" IL VALORE IN
				85	"vet[i]" E INCREMENTA LE DIMENSIONI DEL VETTORE "compatto" */
				compatto[N_compatto] = vet[i]; N_compatto = N_compatto + 1;
			}
		}

	}
	/* STAMPA DEL VETTORE RISULTANTE (VETTORE "compatto") */ printf("Stampa del vettore risultante\n"); if (N_compatto == 0)
		printf("Il vettore risultante non contiene nessun elemento\n");

	else {
		printf("Il vettore risultante contiene %d elementi \n", N_compatto); for (i = 0; i < N_compatto; i++)
			printf("Elemento %d: %d\n", i + 1, compatto[i]); printf("\n");
	} return(0);
}
