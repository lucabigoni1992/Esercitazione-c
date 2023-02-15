// Calcolo dell'opposto di un numero binario in complemento a 2 su N bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Scrivere un programma in linguaggio C che riceva in ingresso un numero binario rappresentato in complemento a 2 su N bit.
Inizialmente l'utente inserisce il numero N di bit. Quindi inserisce le cifre del numero binario un bit alla volta, partendo dal bit meno significativo.
Il programma calcola l'opposto del numero binario ricevuto in ingresso. Tale numero sarà visualizzato partendo dalla cifra meno significativa.
Suggerimento. Per poter effettuare il calcolo del risultato,
utilizzare il metodo secondo il quale si considerano le cifre del numero binario in complemento a due a partire dalla meno significativa alla più significativa (ossia da destra verso sinistra).
Si ricopiano in uscita tutti gli zeri fino al primo 1 compreso. Dopo si invertono i restanti bit.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N;	/* numero di cifre del numero binario */ int bit;	/* cifra binaria del numero binario */ int opposto;	/* cifra binaria dell'opposto del numero binario */
	int inverti;	/* flag per indicare se le cifre binarie devono essere invertite */
	int num_bits;	/* contatore per scandire le cifre binarie */
	/* LEGGI IL NUMERO DI CIFRE BINARIE */
	printf("Quanti bit sarannoinseriti?"); 
	scanf("%d", &N);
	/* INIZIALIZZA IL FLAG "inverti":
	-- SE "inverti" E' UGUALE a 1: si invertono tutti i bit inseriti
	25	successivamente
	-- SE "inverti" E' UGUALE A 0: si ricopiano in uscita i bit inseriti successivamente
	"inverti" E' INIZIALIZZATO A 0 ED ASSEGNATO A 1 QUANDO VIENE INSERITO IL PRIMO BIT UGUALE A 1 */
	inverti = 0;
	/* LEGGI LE CIFRE DEL NUMERO BINARIO A PARTIRE DAL BIT MENO SIGNIFICATIVO */ printf("Inserisci il numero binario dal bit meno significativo\n");
	/* INIZIALIZZA "num_bits" A 0*/ num_bits = 0;
	while (num_bits < N)
	{
		/* LEGGI LA CIFRA BINARIA */
		printf("Inserisci il bit di peso %d: ", num_bits); scanf("%d", &bit);
		/* CALCOLA IL VALORE OPPOSTO */
		if (inverti == 0)
		{
			/* RICOPIA IN USCITA LA CIFRA BINARIA INSERITA */
			opposto = bit;
			/* SE HAI TROVATO LA PRIMA CIFRA BINARIA AD 1, AGGIORNA "inverti" */
			if (bit == 1) inverti = 1;
		}
		else
		{
			/* RICOPIA IN USCITA L'INVERSO DELLA CIFRA BINARIA INSERITA */
			if (bit == 1) opposto = 0; else
				opposto = 1;
		}
		/* STAMPA IL RISULTATO */
		printf("Risultato%d\n", opposto);


		/* INCREMENTA IL CONTATORE "num_bits" */
		num_bits = num_bits + 1;
	} 
	return(0);	
}
