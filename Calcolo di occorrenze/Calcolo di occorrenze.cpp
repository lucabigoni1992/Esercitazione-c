/*
Scrivere un programma in linguaggio C che legge N numeri interi da tastiera e li memorizza in un vettore. Il numero N viene inserito dall’utente ed è minore di 20. Il programma deve visualizzare, per ogni cifra contenuta nel vettore, il numero di occorrenze.
Ad esempio, si supponga N=7 e si consideri la sequenza di numeri 1 6 15 6 2 15 15. Il programma deve visualizzare:
numero 1 occorrenze 1 numero 6 occorrenze 2 numero 15 occorrenze 3
numero 2 occorrenze 1
Suggerimento. Per ogni numero presente nel vettore, il numero di occorrenze deve essere visualizzato una sola volta (ad esempio per i numeri 6 e 15). Utilizzare un vettore di supporto per poter tenere traccia dei numeri nel vettore per cui sono già state calcolate le occorrenze. Gestire questo vettore di supporto in modo analogo al vettore per la compattazione di una sequenza, visto nell’esercizio 5.7 “Compattazione di un vettore”.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>	
int main(void)
{
	const int MAXN = 20;	/* dimensione massima del vettore */
	int vet[MAXN];	/* serie di numeri interi */
	int compatto[MAXN];	/* serie compatta di numeri interi:
contiene, senza ripetizione, i valori del vettore "vet" */
	int N;	/* dimensione del vettore "vet" */
	int N_compatto;	/* dimensione del vettore "compatto" */
	int i, j, t;	/* indici dei cicli */
	int trovato;	/* flag per la ricerca */
	int occorrenze;	/* numero di occorrenze */
	/* LEGGI LE DIMENSIONI DEL VETTORE */
	do {
		printf("Quanti numeri saranno inseriti? ");
		/* Soluzione proposta esercizio "Calcolo di occorrenze" */
		scanf("%d", &N);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E’ COMPRESA TRA 1 E MAXN */
		if (N > MAXN || N <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);
	} while (N > MAXN || N <= 0);
	/* LEGGI UNA SERIE DI N NUMERI INTERI, MEMORIZZANDOLI IN UN VETTORE */
	printf("Inserisci il vettore di %d elementi\n", N);
	for (i = 0; i < N; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet[i]);
	} printf("\n");

	/* STAMPA IL VETTORE DI INTERI */
	printf("Stampa del vettore inserito\n");
	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	/* AGGIORNA IL VETTORE "compatto" E CALCOLA IL NUMERO DI OCCORRENZE */
	/*INIZIALMENTE IL VETTORE "compatto" NON CONTIENE NESSUN NUMERO */
	N_compatto = 0;
	/* IL CICLO FOR SCANDISCE IL VETTORE "vet1" */
	for (i = 0; i < N; i++)
	{
		/* INIZIALIZZA IL FLAG "trovato". IL FLAG ASSUME I VALORI
	-- "trovato" E’ UGUALE A 0 SE IL VETTORE "compatto" NON CONTIENE
	IL VALORE IN "vet[i]"
	-- "trovato" E’ UGUALE A 1 SE IL VETTORE "compatto" CONTIENE IL VALORE IN "vet[i]" */
		trovato = 0;
		/* PER OGNI ELEMENTO vet1[i] DI vet1, IL CICLO FOR SCANDISCE IL VETTORE
		"compatto" E VERIFICA SE "compatto" CONTIENE IL VALORE IN "vet1[i]"
		70	LA RICERCA TERMINA QUANDO SI TROVA UNA CELLA "compatto[j]"
		UGUALE A "vet1[i]" O QUANDO SONO STATE CONSIDERATE TUTTE LE CELLE DEL VETTORE "compatto" */
		for (j = 0; j < N_compatto && trovato == 0; j++)
		{
			/* SE "compatto" CONTIENE "vet1[i]", AGGIORNA IL FLAG "trovato" */
			if (compatto[j] == vet[i])
				trovato = 1;
		}

		if (trovato == 0)
		{
			/* SE "trovato" E’ UGUALE A 0, COPIA NEL VETTORE "compatto" IL VALORE IN "vet[i]" */
			compatto[N_compatto] = vet[i];
			N_compatto = N_compatto + 1;
			/* CALCOLA IL NUMERO DI OCCORRENZE DI "vet[i]" NEL VETTORE "vet". IL CICLO FOR SCANDISCE IL VETTORE "vet" E CONTA QUANTE VOLTE
				IL VALORE IN "vet[i]" E’ PRESENTE NEL VETTORE "vet" */
			occorrenze = 0;
			for (t = 0; t < N; t++)
			{
				if (vet[t] == vet[i])
					occorrenze = occorrenze + 1;
			}
			/* STAMPA DELLE OCCORRENZE */ printf("Elemento %d: %d, occorrenze%d\n", i + 1, vet[i], occorrenze);


		}
	} return(0);
}
