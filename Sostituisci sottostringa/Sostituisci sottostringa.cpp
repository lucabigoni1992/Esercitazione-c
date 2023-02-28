// Sostituisci sottostringa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Si scriva un programma in linguaggio C che riceva in ingresso due parole inserite da tastiera.
Si consideri che ciascuna parola può contenere al massimo 30 caratteri.
Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con una sequenza di caratteri '*'.

Ad esempio, inserite le parole abchdfffchdtlchd e chd, il programma deve visualizare la parola ab***fff***tl***.
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
int main(void)
{
	const int MAXDIM = 30;	/* dimensione max stringa di caratteri */
	char parola1[MAXDIM + 1];	/* prima stringa di caratteri inserita */
	char parola2[MAXDIM + 1];	/* seconda stringa di caratteri inserita */
	int lung_stringa1, lung_stringa2; /* lunghezza delle due stringhe inserite */
	int contenuto;	/* flag per la ricerca */
	int i, j;	/* indici dei cicli */

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
	/* VERIFICA SE "parola2" E' CONTENUTA IN "parola1" */
	if (lung_stringa1 < lung_stringa2)
		printf("Laseconda parola e' piu' lunga della prima parola \n");
	else {
		/* IL CICLO FOR ESTERNO SCORRE LA STRINGA "parola1".
		50	PER OGNI CARATTERE "parola1[i]" IL CICLO FOR INTERNO ANALIZZA LA
		LA SOTTOSTRINGA CONTENENTE I CARATTERI COMPRESI TRA "parola1[i]"
		E "parola1[i+lung_stringa2-1]", E VERIFICA SE TALE SOTTOSTRINGA E' UGUALE A "parola2" */
		for (i = 0; i + (lung_stringa2 - 1) < lung_stringa1; i++)
		{
			/* "j" E' L'INDICE DEL CICLO FOR INTERNO. VIENE UTILIZZATO PER
			SCORRERE I CARATTERI DELLA SOTTOSTRINGA "parola2" E DELLA
			SOTTOSTRINGA CONTENENTE I CARATTERI COMPRESI TRA "parola1[i]" E 60	"parola1[i+lung_stringa2-1]" */
			/* IL FLAG "contenuto==1" INDICA CHE LE DUE SOTTOSTRINGHE SONO UGUALI.
			IL FLAG E' INIZIALIZZATO A 1 E VIENE ASSEGNATO A 0 SE ALMENO UN
			65	CARATTERE "parola1[i+j]" NELLA SOTTOSTRINGA E' DIVERSO DAL
			CORRISPONDENTE CARATTERE "parola2[j]" */
			contenuto = 1;
			for (j = 0; j < lung_stringa2 && contenuto == 1; j++) {
				if (parola1[i + j] != parola2[j])
					contenuto = 0;
			}
			/* SE AL TERMINE DEL CONFRONTO TRA LE DUE STRINGHE "contenuto" E' 75	ANCORA UGUALE A 1, ALLORA "parola2" E' CONTENUTA IN "parola1".
			SOSTITUISCI ALLORA TUTTI I CARATTERI COMPRESI TRA "parola1[i]" E "parola1[i+lung_stringa2-1]" CON IL CARATTERE '*' */ if (contenuto == 1)
			{
				for (j = 0; j < lung_stringa2; j++)
					parola1[i + j] = '*';
				/*PER OTTIMIZZARE LA RICERCA SALTA NELLA STRINGA "parola1" LA SOTTOSEQUENZA DI ASTERISCHI APPENA INSERITA */
				i = i + lung_stringa2 - 1;
			}
		}
	}
	/* STAMPA IL RISULTATO */
	printf("La parola risultante e' %s \n", parola1);
	return(0);
}
