// Conta vocali e consonanti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall'introduzione del carattere di invio. La frase contiene sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma dovrà stampare su schermo le seguenti informazioni:
•	per ognuna delle lettere dell'alfabeto, il numero di volte che la lettera compare nella stringa
•	il numero di consonanti presenti nella stringa
•	il numero di vocali presenti nella stringa.

*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
int main(void)
{
	const int MAXDIM = 100;	/* dimensione massima stringa di caratteri */
	const int NUMLETTERE = 26;	/* numero di lettere dell'alfabeto */
	char frase[MAXDIM + 1];	/* stringa di caratteri inserita */
	int lung_stringa;	/* lunghezza della stringa inserita */
	int vocali, consonanti;	/* contatori numero di vocali e di consonanti */
	int contatori[NUMLETTERE];	/* memorizza il numero di occorrenze per ogni lettera */
	int posizione_alfabeto;	/* posizione nell'alfabeto di una lettera */
	int i;	/* indice dei cicli */
	/* LEGGI LA FRASE INSERITA DA TASTIERA */
	printf("Inserisci una frase di al massimo %d caratteri:", MAXDIM);
	gets_s(frase);
	/* CALCOLA LA LUNGHEZZA DELLA FRASE */
	lung_stringa = strlen(frase);

	/* STAMPA LA FRASE INSERITA */
	printf("La frase inserita e': ");
	puts(frase);
	printf("La frase contiene %d caratteri(inclusi gli spazi)\n", lung_stringa);


	/* AZZERA IL VETTORE DEI CONTATORI. OGNI CELLA DI QUESTO VETTORE E' ASSOCIATA A UNA LETTERA DELL'ALFABETO. LA CELLA 0 ALLA LETTERA A, LA CELLA 1 ALLA B E COSI' VIA */
	for (i = 0; i < NUMLETTERE; i++)
		contatori[i] = 0;
	/* ANALIZZA LA FRASE LETTERA PER LETTERA E AGGIORNA IL VETTORE DEI CONTATORI */
	for (i = 0; i < lung_stringa; i++)
	{
		if (frase[i] >= 'A' && frase[i] <= 'Z')
		{
			/* IL CARATTERE ESAMINATO E' UNA LETTERA MAIUSCOLA POICHE'
			IL SUO CODICE ASCII E' COMPRESO TRA QUELLI DELLE LETTERE A E Z.
			50	PER RICAVARE LA CELLA DEL VETTORE "contatori" DA INCREMENTARE
			DEVI IDENTIFICARE LA POSIZIONE DELLA LETTERA NELL'ALFABETO.
			POICHE' I CODICI ASCII DELLE LETTERE MAIUSCOLE SONO CONSECUTIVI,
			BASTERA' SOTTRARRE AL CARATTERE ESAMINATO IL CODICE ASCII DELLA
			PRIMA LETTERA DELL'ALFABETO ('A') */

			posizione_alfabeto = frase[i] - 'A'; contatori[posizione_alfabeto] ++;
		}
		else
		{
			if (frase[i] >= 'a' && frase[i] <= 'z')
			{
				/* IL CARATTERE ESAMINATO E' UNA LETTERA MINUSCOLA POICHE'
				IL SUO CODICE ASCII E' COMPRESO TRA QUELLI DELLE LETTERE a E z.
				65	PER RICAVARE LA CELLA DEL VETTORE "contatori" DA INCREMENTARE
				DEVI IDENTIFICARE LA POSIZIONE DELLA LETTERA NELL'ALFABETO.
				POICHE' I CODICI ASCII DELLE LETTERE MINUSCOLE SONO CONSECUTIVI,
				BASTERA' SOTTRARRE AL CARATTERE ESAMINATO IL CODICE ASCII DELLA PRIMA LETTERA DELL'ALFABETO ('a') */

				posizione_alfabeto = frase[i] - 'a'; contatori[posizione_alfabeto] ++;
			}
		}
	}
	/* STAMPA I CONTATORI DELLE VARIE LETTERE */ for (i = 0; i < NUMLETTERE; i = i + 1) printf("Lalettera %c compare %d volte \n",

		'A' + i, contatori[i]);
	/* CALCOLA IL NUMERO DI VOCALI */
	/* SOMMA IL NUMERO DI OCCORRENZE PRESENTI NEL VETTORE "contatori" NELLE CELLE ASSOCIATE ALLE LETTERE A, E, I, O, U, Y */
	vocali = contatori['A' - 'A'] + contatori['E' - 'A'] + contatori['I' - 'A'] + contatori['O' - 'A'] + contatori['U' - 'A'] + contatori['Y' - 'A'];
	/* CALCOLA IL NUMERO DI CONSONANTI */
	/* IL NUMERO DI CONSONANTI SI OTTIENE SOTTRAENDO DAL NUMERO COMPLESSIVO
		DI OCCORRENZE DI TUTTE LE LETTERE, IL NUMERO COMPLESSIVO DI VOCALI */
	consonanti = 0; for (i = 0; i < NUMLETTERE; i = i + 1) consonanti = consonanti + contatori[i];

	consonanti = consonanti - vocali;
	/* STAMPA IL NUMERO DI VOCALI E CONSONANTI */ printf("Il numero di vocali e': %d\n", vocali);
	printf("Il numero di consonanti e': %d\n", consonanti);
	return(0);
}
