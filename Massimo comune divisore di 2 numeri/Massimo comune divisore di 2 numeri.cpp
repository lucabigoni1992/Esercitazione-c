// Massimo comune divisore di 2 numeri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Si scriva un programma in linguaggio C per calcolare il massimo comun divisore (MCD) di due numeri interi positivi.
Il MCD è definito come il massimo tra i divisori comuni ai due numeri.
Suggerimento. Si considerino due numeri interi N1 e N2.
Il MCD di N1 e N2 è il massimo tra i numeri che sono divisori (con resto uguale a zero) sia di N2 che di N1.
In particolare, si supponga che sia N1 minore di N2. Il MCD è il massimo tra i numeri compresi tra 1 e N1 che sono divisori (con resto uguale a zero) sia di N1 che di N2.
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int numero1, numero2; /* numeri inseriti */ int minimo; /* valore minimo tra numero1 e numero2 */ int divisore; /* divisore del numero. E’ un contatore per
scandire tutti i valori tra 1 e "minimo" */
	int mcd;	/* massimo comun divisore */
	/* LEGGI I DUE NUMERI */ printf("Inserisci il primo numero: "); scanf("%d", &numero1);

	printf("Inserisci il secondonumero: "); scanf("%d", &numero2);
	/* CONTROLLA SE ENTRAMBI I NUMERI SONO POSITIVI */
	if (numero1 <= 0 || numero2 <= 0)
		printf("Errore: hai inserito un numero nullo o negativo\n");
	else {
		/* CALCOLA IL VALORE INFERIORE TRA I DUE NUMERI INSERITI*/
		if (numero1 < numero2)
			minimo = numero1;
		else minimo = numero2;
		/* PER CALCOLARE IL MASSIMO COMUN DIVISORE CONSIDERA
	TUTTI I NUMERI COMPRESI TRA 1 E "minimo". IL MASSIMO COMUN DIVISORE
	E’ IL MASSIMO TRA I VALORI COMPRESI TRA 1 e "minimo" CHE E’ DIVISORE SIA DI "numero1" CHE DI "numero2" */ divisore = 1;
	mcd = 1;
	while (divisore <= minimo) {
		/* VERIFICA SE IL NUMERO RAPPRESENTATO IN "divisore"
		45	E’ DIVISORE, CON RESTO UGUALE A 0, SIA DI "numero1" CHE
			if ( numero1%divisore == 0 && numero2%divisore == 0 )
			{	/* POICHE’ IL RESTO E’ UGUALE A 0, IL VALORE DI "divisore"
		50		E’ UN POSSIBILE MASSIMO COMUN DIVISORE. AGGIORNA IL VALORE DEL MASSIMO COMUM DIVISORE */
		mcd = divisore; printf("%d e’ divisore \n", mcd);
	}
	/* INCREMENTA IL VALORE DI "divisore" */
	divisore = divisore + 1;
	}
	/* STAMPA IL RISULTATO */
	printf("\n");
	printf("Ilmassimo comun divisore per i numeri %d e %d e’ %d\n", numero1, numero2, mcd);
	return(0);
}

