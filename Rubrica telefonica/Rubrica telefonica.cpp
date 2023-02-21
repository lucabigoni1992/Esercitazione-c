/*
Si realizzi un programma in linguaggio C in grado di gestire una rubrica di nomi e numeri telefonici.
La rubrica deve contenere fino a 100 voci diverse.
Ciascuna voce è composta da un nome (max 40 caratteri) e da un numero di telefono (max 20 caratteri).
Il programma deve fornire all’utente un menù di scelta, con le seguenti voci:
1)	Aggiungi nuova voce in rubrica
2)	Ricerca esatta per nome
3)	Ricerca approssimata per nome
4)	Stampa completa rubrica
0) Esci dal programma
Una volta che l’utente ha scelto l’operazione desiderata (1-4), il programma acquisirà i dati necessari dall’utente ed eseguirà il comando. Nota: nella rubrica non possono esistere due voci con lo stesso nome.

*/#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	const int MAX = 100; /* numero max di voci */ const int LUNN = 40; /* lunghezza del nome */ const int LUNT = 20; /* lunghezza n. telefono */
	char nome[MAX][LUNN + 1]; char tel[MAX][LUNT + 1];
	int N; /* numero di voci memorizzate */
	int comando; /* comando dell’utente 0-4 */
	char riga[200]; char sn[LUNN + 1];
	char st[LUNT + 1];
	int i, duplicato, trovato, pos;
	/* INIZIALIZZAZIONI */
	N = 0;
	do {
		/* STAMPA DEL MENU */
		puts("1) Aggiungi nuova voce in rubrica"); puts("2) Ricerca esatta per nome"); puts("3) Ricerca approssimata per nome"); puts("4) Stampa completa rubrica"); puts("0) Esci dal programma");

		/* LETTURA DEL COMANDO */ printf("Inserisci il comando:");
		gets_s(riga);
		comando = atoi(riga);

		/* ESECUZIONE DEL COMANDO */
		switch (comando)
		{
		case 1:
			/* Acquisisci i dati */
			printf("Inserisci il nome da aggiungere:");
			gets_s(sn); printf("Inserisci il numero di telefonocorrispondente:");
			gets_s(st);

			/* Verifica se i dati sono validi */ if (N == MAX)
			{
				puts("ERRORE:rubricapiena");
				break;
			}
			duplicato = 0;
			for (i = 0; i < N; i++)
				if (strcmp(sn, nome[i]) == 0)
					duplicato = 1;
			if (duplicato == 1)
			{
				puts("ERRORE: nome duplicato");
				break;
			}
			/* Aggiungi il nome in rubrica */
			strcpy(nome[N], sn);
			strcpy(tel[N], st); N++;
			break;
		case 2: /* ricerca esatta */
			printf("Inserisci il nome da ricercare:"); 
			gets_s(sn);
			trovato = 0;
			for (i = 0; i < N && trovato == 0; i++)
			{
				if (strcmp(sn, nome[i]) == 0)
				{
					trovato = 1;
					pos = i;
				}
			}
			if (trovato == 1)
			{
				printf("Iltelefono di %s e’: %s\n", sn, tel[pos]);
			}
			else
			{
				printf("Nessun %s e’ presente in rubrica\n", sn);
			}
			break;
		case 3: /* ricerca approssimata */ printf("Inserisci una parte del nome da ricercare:"); gets_s(sn);

			trovato = 0;
			for (i = 0; i < N; i++)
			{
				if (strstr(nome[i], sn) != NULL)
				{
					printf("%s:%s\n", nome[i], tel[i]); trovato = 1;
				}
			}

			if (trovato == 0) printf("Nontrovato...\n");

			break;
		case 4:
			printf("CONTENUTO DELLA RUBRICA (%d VOCI)\n", N);
			for (i = 0; i < N; i++)
				printf("%s: %s\n", nome[i], tel[i]);
			break;
		case 0: puts("Arrivederci"); break;
		default:
			printf("ERRORE NEL PROGRAMMA(comando=%d)\n", comando);
		}

	} while (comando != 0);
	return(0);
}
