// Parola palindroma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Scrivere un programma in linguaggio C che riceve in ingresso una parola inserita da tastiera. Si consideri che la parola può contenere sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al massimo 30 caratteri. Il programma deve svolgere le seguenti operazioni:
•	visualizzare la parola inserita
•	aggiornare la parola in modo che tutti i caratteri siano minuscoli. Il programma deve visualizzare la parola ottenuta
•	verificare se la parola è palindroma. Una parola è palindroma se può essere letta indifferentemente da sinistra verso destra e da destra verso sinistra. Ad esempio, le seguenti parole sono palindrome: otto, madam.
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
int main(void)
{
	const int MAXDIM = 30;	/* dimensione massima stringa di caratteri */
	char parola[MAXDIM + 1];	/* stringa di caratteri inserita */
	int numcaratteri;	/* numero di caratteri della stringa inserita */
	int palindroma;	/* flag per la ricerca */
	int i, j;	/* indici dei cicli */

	/* LEGGI LA STRINGA DI CARATTERI INSERITA DA TASTIERA */
	printf("Inserisci una parola di al massimo %d caratteri:", MAXDIM);
	scanf("%s", parola);
	/* VISUALIZZA LA STRINGA DI CARATTERI INSERITA */
	printf("La parola inserita e’: %s \n", parola);
	/* LEGGI IL NUMERO DI CARATTERI DELLA STRINGA */
	numcaratteri = strlen(parola);
	printf("La parola contiene %d caratteri\n", numcaratteri);
	/* CONVERTI TUTTI I CARATTERI DELLA STRINGA IN CARATTERI MINUSCOLI */
	for (i = 0; i < numcaratteri; i++)
		parola[i] = tolower(parola[i]);

	/* VISUALIZZA LA STRINGA DI CARATTERI DOPO LA CONVERSIONE */
	printf("La parola inseritascritta solo con caratteri in minuscolo e’: %s\n", parola);
	/* VERIFICA SE LA STRINGA "parola" E’ PALINDROMA */
/* INIZIALIZZA IL FLAG "palindroma". IL FLAG ASSUME I VALORI -- "palindroma" E’ UGUALE A 1 SE "parola" E’ PALINDROMA
-- "palindroma" E’ UGUALE A 0 SE "parola" NON E’ PALINDROMA
45	*/
	palindroma = 1;
	/* IL CICLO FOR SCANDISCE LA STRINGA DI CARATTERI "parola" E VERIFICA SE E’ PALINDROMA L’INDICE "i" SCORRE LA PRIMA META’ DI "parola". L’INDICE 50	"j" SCORRE LA SECONDA META’ DI "parola" PARTENDO DALL’ULTIMO CARATTERE.
	LA RICERCA TERMINA QUANDO SI TROVA SI VERIFICA CHE LA STRINGA "parola"
	NON E’ PALINDROMA O QUANDO SONO STATI CONSIDERATI TUTTI I CARATTERI DI "parola" */
	for (i = 0, j = numcaratteri - 1;
		i < numcaratteri / 2 && palindroma == 1; i++, j--)
	{
		if (parola[i] != parola[j])
			palindroma = 0;
	}
	/* STAMPA DEL RISULTATO */ if (palindroma == 1)
		printf("La parola e’ palindroma\n");
	else printf("La parola non e’ palindroma\n");
	return(0);

}
