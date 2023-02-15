// Sostituisci carattere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall'introduzione del carattere di invio e contiene complessivamente al più 100 caratteri. Il programma deve svolgere le seguenti operazioni:
•	visualizzare la frase inserita
•	costruire una nuova frase in cui tutte le occorrenze del carattere '.' sono sostituite con il carattere di ritorno di linea '\n'. Il programma deve memorizzare la nuova frase in una opportuna variabile
•	visualizzare la nuova frase.

*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
int main(void)
{
	const int MAXDIM = 100;	/* dimensione max stringa di caratteri */
	char frase[MAXDIM + 1];	/* stringa di caratteri inserita */
	char frasemodificata[MAXDIM + 1]; /* nuova stringa modificata */
	int lung_stringa;	/* lunghezza della stringa inserita */ int i;	/* indice dei cicli */
	/* LEGGI LA FRASE INSERITA DA TASTIERA */
	printf("Inserisci una frase di al massimo %d caratteri:", MAXDIM);
	gets_s(frase);
	/* CALCOLA LA LUNGHEZZA DELLA FRASE */
	lung_stringa = strlen(frase);

	/* STAMPA LA FRASE INSERITA */ printf("La frase inserita e': "); puts(frase);
	printf("La frase contiene %d caratteri(inclusi gli spazi)\n", lung_stringa);

	/* ANALIZZA LA FRASE INSERITA CARATTERE PER CARATTERE. RICOPIA LA FRASE
	NELLA STRINGA "frase modificata". SE LA STRINGA INSERITA CONTIENE IL CARATTERE ".", SOSTITUISCILO CON IL CARATTERE DI RITORNO DI LINEA "\n" */ for (i = 0; i < lung_stringa; i = i + 1)
	{
		if (frase[i] == '.') frasemodificata[i] = '\n';
		else frasemodificata[i] = frase[i];
	}
	frasemodificata[lung_stringa] = '\0';
	/* STAMPA LA FRASE MODIFICATA */ printf("La frase modificata e': \n");
	puts(frasemodificata); exit(0);
}
