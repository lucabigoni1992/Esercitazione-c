// Fusione di due vettori ordinati.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h> #include <stdlib.h>
int main(void)
{
	const int MAXN = 20;	/* dimensione massima del vettore */
	int vet1[MAXN], vet2[MAXN];	/* vettori di interi */
	int N1, N2;	/* dimensione dei vettori */
	int fusione[2 * MAXN];	/* risultato fusione di vet1 e vet2 */
	int N_fusione;	/* dimensione del vettore "fusione" */
	int i, j, t;	/* indici dei cicli */
	/* LEGGI LE DIMENSIONI DEL PRIMO VETTORE */ do
	{
		printf("Quanti numeri sarannoinseriti nel primo vettore?"); scanf("%d", &N1);
		/* LA DIMENSIONE MASSIMA DEL VETTORE E’ COMPRESA TRA 1 E MAXN */ if (N1 > MAXN || N1 <= 0)
			printf("Errore: il numero deve essere compreso tra 0 e %d\n", MAXN);
	} while (N1 > MAXN || N1 <= 0);
	/* LEGGI IL PRIMO VETTORE */
	printf("Inserisci il primo vettore di %d elementi\n", N1); for (i = 0; i < N1; i++)
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
		printf("Quanti numeri sarannoinseriti nel secondovettore?"); scanf("%d", &N2);

		/* LA DIMENSIONE MASSIMA DEL VETTORE E’ COMPRESA TRA 1 E MAXN */
		if (N2 > MAXN || N2 <= 0)
			printf("Errore: il numero deve essere compreso tra %d e 0\n", MAXN);
	} while (N2 > MAXN || N2 <= 0);
	/* LEGGI IL SECONDO VETTORE */ printf("Inserisci il secondovettore di %d elementi\n", N2); for (i = 0; i < N2; i++)
	{
		printf("Elemento %d: ", i + 1);
		scanf("%d", &vet2[i]);
	} printf("\n");

	/* STAMPA DEL SECONDO VETTORE */
	printf("Stampa il secondo vettore\n");
	for (i = 0; i < N2; i++)
		printf("Elemento %d: %d\n", i + 1, vet2[i]);
	printf("\n");
	/* AGGIORNA IL VETTORE "fusione" */
	/* IL VETTORE "fusione" HA DIMENSIONE PARI ALLA SOMMA DELLE
	80	DIMENSIONI DI "vet1" E "vet2" */
	N_fusione = N1 + N2;
	/* I VETTORI "vet1", "vet2" E "fusione" SONO VISITATI RISPETTIVAMENTE CON GLI INDICI "j", "t", E "i" */
	for (i = 0, j = 0, t = 0; i < N_fusione && j < N1 && t < N2; i++)
	{
		if (vet1[j] <= vet2[t])
		{
			/* GLI ELEMENTI DI "vet1" SONO ACCODATI NEL VETTORE "fusione" */
				/* SE "vet1[j]" E’ MINORE O UGUALE DI "vet2[t]", ALLORA "vet1[j]"
			E’ COPIATO IN "fusione[i]" PER PRIMO. VIENE INCREMENTATO "j", MENTRE "i" E’ INCREMENTATO DAL CICLO FOR */
			fusione[i] = vet1[j];
			j = j + 1;

		}
		else /* vet1[j] > vet2[t] */ {
			/* GLI ELEMENTI DI "vet2" SONO ACCODATI NEL VETTORE "fusione" */
			/* SE "vet1[t]" E’ MAGGIORE DI "vet2[j]", ALLORA "vet2[t]"
			100	E’ COPIATO IN "fusione[i]" PER PRIMO. VIENE INCREMENTATO "t", MENTRE
			"i" E’ INCREMENTATO DAL CICLO FOR */ fusione[i] = vet2[t];
			t = t + 1;
		}

	}
	if (i < N_fusione)
	{
		/* IL VETTORE "fusione" DEVE ESSERE ANCORA COMPLETATO INSERENDO
		110	GLI ELEMENTI FINALI DI "vet1" O "vet2" */
		if (j == N1)
		{
			/* TUTTI GLI ELEMENTI DI "vet1" SONO STATI COPIATI IN "fusione".
			115	"fusione" VIENE ORA COMPLETATO CON GLI ELEMENTI DI "vet2" NON ANCORA
			CONSIDERATI */
			for (; i < N_fusione; i++, t++) fusione[i] = vet2[t];

		}
		else {
			/* TUTTI GLI ELEMENTI DI "vet2" SONO STATI COPIATI IN "fusione".
			"fusione" VIENE ORA CON GLI ELEMENTI DI "vet1" NON ANCORA
			125	CONSIDERATI */
			for (; i < N_fusione; i++, j++) fusione[i] = vet1[j];
		}
	}

	/* STAMPA DEL VETTORE "fusione"*/
	printf("Ilvettore risultante contienecontiene %d elementi\n", N_fusione);
	for (i = 0; i < N_fusione; i++)
		printf("Elemento %d: %d\n", i + 1, fusione[i]);
	printf("\n"); return(0);
}
