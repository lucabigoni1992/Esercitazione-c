// Somma di numeri binari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N;	/* numero di cifre binarie */
	int bit_numero1;	/* cifra binaria del primo numero */
	int bit_numero2;	/* cifra binaria del secondo numero */
	int bit_risultato; /* cifra binaria risultato dell’operazione di somma */
	int riporto;	/* riporto */
	int num_bits;	/* contatore per scandire le cifre binarie */
	/* LEGGI IL NUMERO CIFRE BINARIE */ printf("Inserisci il numero di bit: ");
	scanf("%d", &N);
	/* INIZIALIZZA IL RIPORTO A 0 */ riporto = 0;
	/* LEGGI LE CIFRE BINARIE A PARTIRE DAL BIT MENO SIGNIFICATIVO */ printf("\nInserisci i due numeri binari partendo dal bit meno significativo\n");
	/* INIZIALIZZA "num_bits" A 0 */ num_bits = 0;

	while (num_bits < N)
	{
		/* LEGGI LA CIFRA BINARIA DEL PRIMO NUMERO */ printf("\n");
		printf("Inserisci la cifra %d di peso 2^%d del primo numero:", num_bits + 1, num_bits);
		scanf("%d", &bit_numero1);
		/* LEGGI LA CIFRA BINARIA DEL SECONDO NUMERO */
		printf("Inserisci la cifra %d di peso 2^%d del secondonumero:", num_bits + 1, num_bits);
		scanf("%d", &bit_numero2);
		/* SOMMA LE DUE CIFRE BINARIE */
		bit_risultato = bit_numero1 + bit_numero2 + riporto;
		/* VERIFICA CHE IL RISULTATO DELLA SOMMA SIA 0 O 1 */
		/* ASSEGNA IL RIPORTO A 1 SE IL RISULTATO DELLA SOMMA E’ DIVERSO DA 0 O 1, ASSEGNA IL RIPORTO A ZERO ALTRIMENTI */
		if (bit_risultato >= 2)
		{
			bit_risultato = bit_risultato - 2; riporto = 1;
		}
		else
			riporto = 0;
		/* STAMPA IL RISULTATO */
		printf("Ilrisultato per la cifra %d di peso %d e’ %d e il riporto e’ %d\n", num_bits + 1, num_bits, bit_risultato, riporto);
		/* INCREMENTA IL CONTATORE "num_bits" */ num_bits = num_bits + 1;
	}

	/* STAMPA L’INFORMAZIONE SULLA CONDIZIONE DI OVERFLOW */ printf("\n"); if (riporto == 1)
		printf("La somma ha generato overflow\n");
	else
		printf("La somma non ha generato overflow\n");
	exit(0);
}
