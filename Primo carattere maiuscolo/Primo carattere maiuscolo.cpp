// Primo carattere maiuscolo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall'introduzione del carattere di invio. La frase contiene sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma deve svolgere le seguenti operazioni:
•	visualizzare la frase inserita
•	costruire una nuova frase in cui il primo carattere di ciascuna parola nella frase di partenza è stato reso maiuscolo. Tutti gli altri caratteri devono essere resi minuscoli. Il programma deve memorizzare la nuova frase in una opportuna variabile
•	visualizzare la nuova frase.
Ad esempio la frase cHe bElLA gIOrnaTa diviene Che Bella Giornata.
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
int main(void)
{
	const int MAXDIM = 100;	/* dimensione massima stringa di caratteri */
	char frase[MAXDIM + 1];	/* stringa di caratteri inserita */
	char nuovafrase[MAXDIM + 1];	/* stringa di caratteri modificata */
	int lung_stringa;	/* lunghezza della stringa inserita */
	int i;	/* indice dei cicli */
	/* LEGGI LA FRASE INSERITA DA TASTIERA */
	printf("Inserisci una frase di al massimo %d caratteri:", MAXDIM);
	gets_s(frase);
	/* CALCOLA LA LUNGHEZZA DELLA FRASE */
	lung_stringa = strlen(frase);
	/* STAMPA LA FRASE INSERITA */ printf("La frase inserita e': "); puts(frase);
	printf("La frase contiene %d caratteri(inclusi gli spazi)\n", lung_stringa);

	/* COSTRUISCI LA NUOVA FRASE */ 
	for (i = 0; i < lung_stringa; i++)
	{
		/* IL CARATTERE "frase[i]" E' LA PRIMA LETTERA DI UNA PAROLA SE IL
	CARATTERE PRECEDENTE ("frase[i-1]") ERA UNO SPAZIO OPPURE SE E' IL PRIMO
	CARATTERE DELLA FRASE (OSSIA i==0). IN QUESTO CASO IL CARATTERE "frase[i]"
	E' CONVERTITO IN CARATTERE MAIUSCOLO. IN TUTTI GLI ALTRI CASI IL CARATTERE
	"frase[i]" E' CONVERTITO IN CARATTERE MINUSCOLO */
		if ((i == 0) || isspace(frase[i - 1]))
			nuovafrase[i] = toupper(frase[i]);
		else 
			nuovafrase[i] = tolower(frase[i]);
	}
	nuovafrase[lung_stringa] = '\0';
	/* STAMPA LA FRASE MODIFICATA */ printf("La frase modificata e': "); puts(nuovafrase);
	return(0);
}
