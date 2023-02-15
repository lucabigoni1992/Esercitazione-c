// Operazione di shift di un vettore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di N numeri interi. Il valore N è inserito dall’utente. I numeri sono memorizzati in un vettore. Il programma esegue le seguenti operazioni:
1.	visualizza il vettore
2.	esegue uno spostamento (shift) a sinistra di una posizione del contenuto del vettore.Pertanto ogni elemento del vettore deve assumere il valore dell’elemento immediatamente successivo all’interno del vettore. L’elemento di indice N-1 deve assumere il valore zero.
Ad esempio dato il vettore: 1 10 15 18 Il programma deve generare il vettore: 10 15 18 0 Il programma visualizza il vettore ottenuto.
3.	esegue uno spostamento (shift) a destra di una posizione del contenuto del vettoreottenuto nel passo precedente. Pertanto ogni elemento del vettore deve assumere il valore dell’elemento immediatamente precedente all’interno del vettore. L’elemento di indice 0 deve assumere il valore zero.
Ad esempio dato il vettore: 10 15 18 0 Il programma deve generare il vettore: 0 10 15 18 Il programma visualizza il vettore ottenuto.
Nota. Nella definizione di “destra” e “sinistra” si immagini il vettore stampato orizzontalmente, a partire dalla cella di indice 0.
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	const int MAXN = 200; /* dimensione massima del vettore */
	int N;	/* dimensione del vettore */
	int vet[MAXN];	/* sequenza di numeri interi */
	int i;	/* indice dei cicli */
	/* LEGGI LE DIMENSIONI DEL VETTORE */ do {
		printf("Quanti numeri sarannoinseriti?");
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
	/* ESEGUI UNO SPOSTAMENTO (SHIFT) A SINISTRA DI UNA POSIZIONE DEL CONTENUTO DEL VETTORE. ASSEGNA IL VALORE 0 ALLA CELLA vet[N-1] */
	for (i = 0; i < N - 1; i++)
		/* COPIA NELLA CELLA vet[i] IL CONTENUTO DELLA CELLA SUCCESSIVA vet[i+1] */
		vet[i] = vet[i + 1];

	/* ASSEGNA IL VALORE 0 ALLA CELLA vet[N-1]. NOTA: QUESTA ASSEGNAZIONE DEVE
	ESSERE FATTA AL TERMINE DEL CICLO FOR. INFATTI SE VIENE FATTA PRIMA DEL CICLO FOR SI PERDEREBBE IL VALORE INIZIALMENTE CONTENUTO NELLA CELLA vet[N-1].
	QUESTO VALORE DEVE INVECE ESSERE ASSEGNATO ALLA CELLA vet[N-2] */
	vet[N - 1] = 0;
	/* STAMPA IL VETTORE DI INTERI */
	printf("Stampa del vettore dopo l’operazione di shift a sinistra\n");
	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	/* ESEGUI UNO SPOSTAMENTO (SHIFT) A DESTRA DI UNA POSIZIONE DEL CONTENUTO DEL VETTORE. ASSEGNA IL VALORE 0 ALLA CELLA vet[0] */
	for (i = N - 1; i > 0; i--)
		/* COPIA NELLA CELLA vet[i] IL CONTENUTO DELLA CELLA PRECEDENTE vet[i-1] */
		vet[i] = vet[i - 1];
	/* ASSEGNA IL VALORE 0 ALLA CELLA vet[0]. NOTA: QUESTA ASSEGNAZIONE DEVE
	70	ESSERE FATTA AL TERMINE DEL CICLO FOR. INFATTI SE VENISSE FATTA PRIMA DEL CICLO FOR SI PERDE IL VALORE INIZIALMENTE CONTENUTO NELLA CELLA vet[0]. QUESTO VALORE DEVE INVECE ESSERE ASSEGNATO ALLA CELLA vet[1] */
	vet[0] = 0;
	/* STAMPA IL VETTORE DI INTERI */
	printf("Stampa del vettore dopo l’operazione di shift a destra\n");
	for (i = 0; i < N; i++)
		printf("Elemento %d: %d\n", i + 1, vet[i]);
	printf("\n");
	return(0);
}
