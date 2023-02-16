/*
Si scriva un programma in C che acquisisca da tastiera un testo libero, composto da più righe (max 1000) di un numero di caratteri non superiore a 100 ciascuna. L’inserimento termina quando l’utente inserirà una riga uguale a FINE.
Al termine dell’acquisizione del testo, il programma dovrà stampare le seguenti statistiche:
1.	il numero totale di righe inserite  ;
2.	il numero totale di caratteri inseriti;
3.	il numero totale di caratteri alfanumerici inseriti;
4.	il numero totale di parole inserite.

*/#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	const int MAX = 1000; 
	const int LUN = 100;

	char testo[MAX][LUN + 1]; 
	int N; /* righe inserite */
	int ncar, nalfa, npar; int end;

	char riga[300]; int i, j;
	N = 0;
	end = 0;
	do {
		printf("Testo:");
		gets_s(riga);

		if (strlen(riga) > LUN) 
			printf("Errore: riga troppo lunga (max %d caratteri)\n", LUN);
		else if (strcmp(riga, "FINE") == 0)
			end = 1;
		else
		{
			strcpy(testo[N], riga); N++;
		}

	} while (end == 0 && N < MAX);
	printf("L’utente ha inserito %d righe\n", N);
	ncar = 0;
	for (i = 0; i < N; i++) ncar = ncar + strlen(testo[i]);
	printf("L’utente ha inserito %d caratteri\n", ncar);

	nalfa = 0; for (i = 0; i < N; i++)
	{
		for (j = 0; testo[i][j] != 0; j++)
		{
			if (isalnum(testo[i][j])) nalfa++;
		}
	}

	printf("L’utente ha inserito %d caratterialfanumerici\n", nalfa);

	npar = 0; for (i = 0; i < N; i++)
	{
		for (j = 0; testo[i][j] != 0; j++) {
			/* verifico se [i][j] è il carattere iniziale di una parola */
			if (isalpha(testo[i][j]) &&
				((j == 0) || !isalpha(testo[i][j - 1])))
			{
				npar++;
			}

		}
	}
	printf("L’utente ha inserito %d parole\n", npar); 
	return(0);
}
