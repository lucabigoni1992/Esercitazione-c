// Stampa dei mesi if else.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Dato un numero intero tra 1 e 12, che rappresenta il mese corrente, stampare il nome del mese per esteso (“Gennaio” ... “Dicembre”).*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int mese; /* mese inserito */
	/* LEGGI IL NUMERO DEL MESE */ printf("Inserisci il numero del mese: ");
	scanf("%d", &mese);
	/* VISUALIZZA IL NOME DEL MESE CORISPONDENTE AL NUMERO INSERITO*/
	if (mese == 1)
		printf("Gennaio\n");
	else if (mese == 2)
		printf("Febbraio\n");
	else if (mese == 3)
		printf("Marzo\n");
	else if (mese == 4)
		printf("Aprile\n");
	else if (mese == 5)
		printf("Maggio\n");
	else if (mese == 6)
		printf("Giugno\n");
	else if (mese == 7)
		printf("Luglio\n");
	else if (mese == 8)
		printf("Agosto\n");
	else if (mese == 9)
		printf("Settembre\n");
	else if (mese == 10)
		printf("Ottobre\n");
	else if (mese == 11)
		printf("Novembre\n");
	else if (mese == 12)
		printf("Dicembre\n");
	else printf("MESEERRATO!\n");

	return(0);
}
