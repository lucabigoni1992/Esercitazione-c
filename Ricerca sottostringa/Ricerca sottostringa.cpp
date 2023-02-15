// Ricerca sottostringa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C che riceva in ingresso due parole inserite da tastiera.
Si consideri che ciascuna parola può contenere al massimo 30 caratteri.
Il programma deve verificare se la seconda parola inserita è contenuta almeno una volta
all’interno della prima parola (ossia se la seconda parola è una sottostringa della prima parola).
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	const int MAXDIM = 30;	/* dimensione max stringa di caratteri */
	char parola1[MAXDIM + 1];	/* prima stringa di caratteri */
	char parola2[MAXDIM + 1];	/* seconda stringa di caratteri */
	int lung_stringa1, lung_stringa2; /* lunghezza delle due stringhe */
	/* LEGGI LA PRIMA PAROLA INSERITA DA TASTIERA */
	printf("Inserisci una parola di al massimo %d caratteri:", MAXDIM);
	gets_s(parola1);
	/* CALCOLA LA LUNGHEZZA DELLA PAROLA */
	lung_stringa1 = strlen(parola1);
	/* STAMPA LA PAROLA INSERITA */
	printf("La parola %s contiene %d lettere\n", parola1, lung_stringa1);
	/* LEGGI LA SECONDA PAROLA INSERITA DA TASTIERA */
	printf("Inserisci una parola di al massimo %d caratteri:", MAXDIM);
	gets_s(parola2);
	/* CALCOLA LA LUNGHEZZA DELLA PAROLA */
	lung_stringa2 = strlen(parola2);
	/* STAMPA LA PAROLA INSERITA */
	printf("La parola %s contiene %d lettere\n", parola2, lung_stringa2);
	/* VERIFICA SE "parola2" E’ CONTENUTA IN "parola1" */ if (lung_stringa1 < lung_stringa2)
		printf("Laseconda parola e’ piu’ lunga della prima parola \n");

	else {
		if (strstr(parola1, parola2) != NULL)
			printf("Laseconda parola e’ contenuta nella prima \n");
		else
			printf("Laseconda parola non e’ contenuta nella prima \n");
	} exit(0);
}
