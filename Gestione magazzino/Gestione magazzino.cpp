/*Un'azienda deve tenere traccia dei beni presenti in un magazzino. L'utente inserisce da tastiera dei “comandi” nel seguente formato:
bene EU quantità
dove:
•	bene è il nome di un bene;
•	EU è la lettera 'E' per entrata, 'U' per uscita;
•	quantità è la quantità di bene entrata o uscita.
L'utente termina il caricamento inserendo un comando pari a FINE. In tal caso il programma deve stampare le quantità di beni presenti a magazzino.
Esempio:
viti E 10 dadi E 50 viti U 5 viti E 3
FINE
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define LUN 30
int main(void)
{
	char prodotti[MAX][LUN]; 
	char prod[LUN]; 
	int quantita[MAX];
	int qta; char dir;
	int i;
	int trovato;
	int N; /* dimensione dei vettori prodotti[] e quantita[] */
	N = 0;

	do {
		/* acquisisci un comando dall'utente */
			/* NOTA: non si può usare il costrutto scanf("%s %c %d", prod, &dir, &qta) ;
		in quanto non funziona per l'ultima riga (FINE) */
		printf("Comando:");

		scanf("%s", prod);
		if (strcmp(prod, "FINE") != 0)
		{
			scanf(" %c %d", &dir, &qta);

			if (dir == 'E') /* entrata */
			{
				/* trova la posizione del prodotto nel vettore prodotti[] */ 
				trovato = -1;
				for (i = 0; i < N; i++)
				{
					if (strcmp(prodotti[i], prod) == 0) trovato = i;
				}

				if (trovato != -1) /* prodotto esiste già */
				{
					/* incrementa la posizione corrispondente del vettore quantita[] */
					quantita[trovato] = quantita[trovato] + qta;
				}
				else /* prodotto nuovo */ {
					/* aggiungi il prodotto al magazzino in posizione nuova */
					strcpy(prodotti[N], prod);
					quantita[N] = qta;
					N++;
				}

			}
			else /* uscita */ {
				/* trova la posizione del prodotto nel vettore prodotti[] */ 
				trovato = -1;
				for (i = 0; i < N; i++)
				{
					if (strcmp(prodotti[i], prod) == 0) trovato = i;
				}

				if (trovato == -1)
				{
					printf("Prodotto %s non trovato in magazzino\n", prod);
				}
				else
				{
					/* decrementa la posizione corrispondente del vettore quantita[] */ quantita[trovato] = quantita[trovato] - qta;

				}
			}
		}
	} while (strcmp(prod, "FINE") != 0);
	for (i = 0; i < N; i++)
	{
		printf("%s%d\n", prodotti[i], quantita[i]);


	}
	return(0);
}
