// Codifica di una parola.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Codifica di una parola
Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall'introduzione del carattere di invio. La frase contiene sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma deve svolgere le seguenti operazioni:
•	visualizzare la frase inserita;
•	costruire una nuova frase tale che ogni lettera vocale presente nella frase di partenza sia seguita dalla lettera 'f' (se la vocale è minuscola) o dalla lettera 'F' (se la vocale è maiuscola) nella nuova frase. Il programma deve memorizzare la nuova frase in una opportuna variabile.
•	visualizzare la nuova frase.
Ad esempio, la frase VacAnze di NaTAle diviene VafcAFnzef dif NafTAFlef.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
int main(void)
{
	const int MAXDIM = 100;	/* dimensione max stringa di caratteri */
	char frase[MAXDIM + 1];	/* stringa di caratteri inserita */
	char frasemodificata[2 * MAXDIM + 1]; /* nuova stringa modificata */
	int lung_stringa;	/* lunghezza della stringa inserita */
	int i, j;	/* indici dei cicli */
	/* LEGGI LA FRASE INSERITA DA TASTIERA */
	printf("Inserisci una frase di al massimo %d caratteri:", MAXDIM);
	gets_s(frase);
	/* CALCOLA LA LUNGHEZZA DELLA FRASE */
	lung_stringa = strlen(frase);
	/* STAMPA LA FRASE INSERITA */ printf("La frase inserita e': "); puts(frase);
	printf("La frase contiene %d caratteri(inclusi gli spazi)\n", lung_stringa);

	/* COSTRUISCI LA NUOVA FRASE */
	/* L'INDICE "i" E' USATO PER SCORRERE LA STRINGA "frase". L'INDICE "j" E' USATO PER SCORRERE LA STRINGA "frasemodificata" */
	for (i = 0, j = 0; i < lung_stringa; i++)
	{
		/* RICOPIA IL CARATTERE IN "frase[i]" nella cella "frasemodificata[j]" */
		/* INCREMENTA IL CONTATORE "j" PER ACCEDERE ALLA CELLA SUCCESSIVA NELLA STRINGA "frasemodificata" */
		frasemodificata[j] = frase[i];
		j = j + 1;
		/* SE "frase[i]" CONTIENE UNA VOCALE MINUSCOLA,
		INSERISCI IL CARATTERE "f" NELLA CELLA "frasemodificata[j]" */
		/* INCREMENTA IL CONTATORE "j" PER ACCEDERE ALLA CELLA SUCCESSIVA
	NELLA STRINGA "frasemodificata" */
		if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') {
			frasemodificata[j] = 'f'; j = j + 1;
		}
		else {
			/* SE "frase[i]" CONTIENE UNA LETTERA VOCALE IN CARATTERE MAIUSCOLO, INSERISCI IL CARATTERE "F" NELLA CELLA "frasemodificata[j]" */
			/* INCREMENTA IL CONTATORE "j" PER ACCEDERE ALLA CELLA SUCCESSIVA NELLA STRINGA "frasemodificata" */
			if (frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U')
			{
				frasemodificata[j] = 'F';
				j = j + 1;
			}

		}
	} frasemodificata[j] = '\0';
	/* STAMPA LA FRASE MODIFICATA */
	printf("La frase modificata e': ");
	puts(frasemodificata); return(0);
}
