// Conversione binario decimale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che legga da tastiera un numero binario puro sotto forma di una stringa di caratteri (0 o 1) lunga al massimo 24 bit. Il programma deve:
• controllare che la stringa inserita sia corretta, vale a dire composta solo da caratteri
0 e 1
•	convertire il numero binario inserito nell'equivalente valore decimale
•	stampare sul video il valore decimale.
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
int main(void)
{
	const int MAXDIM = 24;	/* dimensione massima stringa di caratteri */
	char binario[MAXDIM + 1];	/* stringa contenente il numero binario */
	int num_cifre;	/* numero di cifre nel numero binario */
	int decimale;	/* numero decimale risultante */
	int corretto;	/* flag per la ricerca */
	int i;	/* indice dei cicli */

	/* LEGGI IL NUMERO BINARIO */
	printf("Inserisci un numero binario puro di al massimo %d cifre: ", MAXDIM);
	gets_s(binario);
	/* CALCOLA IL NUMERO DI CIFRE DEL NUMERO BINARIO */
	num_cifre = strlen(binario);
	/* VISUALIZZA IL NUMERO INSERITO */
	printf("Il numero binarioinserito e' %s e contiene %d cifre\n",

		binario, num_cifre);
	/* VERIFICA SE IL NUMERO INSERITO CONTIENE SOLO CARATTERI 0 E 1 */
	/* IL NUMERO BINARIO NON E' CORRETTO SE CONTIENE ALMENO UNA CIFRA DIVERSA SIA DA 0 CHE DA 1 */
	corretto = 1;
	for (i = 0; i < num_cifre; i++) if (binario[i] != '0' && binario[i] != '1') corretto = 0;
	if (corretto == 0)
		printf("Il numero binarioinserito non e' valido\n");

	else {
		/* CONVERTI IL NUMERO BINARIO NEL NUMERO DECIMALE CORRISPONDENTE */
		decimale = 0;
		for (i = 0; i < num_cifre; i++)
		{
			if 
				(binario[i] == '1') decimale = 2 * decimale + 1;
			else
				decimale = 2 * decimale;
		}
		/* STAMPA IL RISULTATO */
		printf("Il valore decimale e': %d\n", decimale);
	} exit(0);
}
