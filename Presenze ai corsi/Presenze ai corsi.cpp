/*
Un professore vuole realizzare un programma che gli permetta di effettuare delle statistiche sulle presenze ai corsi universitari da lui tenuti.
Ogni corso universitario è caratterizzato da un codice (es. 06AZNDI). Ogni volta che il docente effettua una lezione, deve richiamare il programma per inserire le informazioni relative a tale lezione, ed in particolare: data e numero di studenti presenti alla lezione.
Le informazioni sono memorizzate in un file di lavoro denominato lezioni.txt. Tale file è composto da un numero variabile, non noto a priori, di righe, ciascuna delle quali contiene le informazioni relative ad una singola lezione. Il file può contenere le informazioni relative a molti corsi diversi, liberamente inframmezzati. Il formato di ciascuna riga del file è il seguente:
codice data numstudenti
dove:
•	codice è il codice del corso (max 10 caratteri, senza spazi);
•	data è la data della lezione, rappresentata come numero intero tra 1 e 365;
•	numstudenti è il numero di studenti presenti, rappresentato come numero intero positivo.
Il programma viene richiamato con due argomenti sulla linea di comando: il primo argomento indica il codice del corso interessato, mentre il secondo indica l'operazione da eseguire. L'operazione può essere I per “inserimento” oppure S per “statistiche.” In particolare:
•	nel caso di inserimento di una nuova lezione (relativa al corso indicato sulla linea di comando), il programma chiederà all'utente le informazioni necessarie (data e numero di studenti) ed aggiornerà il file di lavoro aggiungendovi una riga. Compiuta tale elaborazione, il programma termina.
•	stampa delle statistiche di un corso. In tal caso il programma calcola e stampa, per il corso indicato sulla linea di comando, le seguenti quantità: data della lezione con il maggior numero di studenti, data della lezione con il minor numero di studenti, numero medio di studenti presenti alle lezioni. In seguito il programma termina.
Ad esempio, supponendo che il programma sia denominato registro, e che il file lezioni.txt sia inizialmente vuoto, una possibile interazione con il programma è la seguente (si noti che c:> è il prompt del sistema operativo):
c:> registro 06AZNDI I
Data: 101 Studenti: 40 c:> registro 04KKZWE I
Data: 104 Studenti: 99 c:> registro 06AZNDI I
Data: 98 Studenti: 45 c:> registro 06AZNDI S
Il minimo di studenti si e' raggiunto in data 101 Ilmassimo di studenti si e' raggiunto in data 98

La media di studenti vale 42.5

*/

/* PROGRAMMAZIONE IN C */
/* File: registro.c */
/* Soluzione proposta esercizio "Presenze ai corsi" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const char nomefile[] = "studenti.txt";
	const int MAX = 100;
	char riga[MAX + 1];
	char codice[MAX + 1];
	int data, stud, r;
	FILE* f;
	int totStud; /* somma tutte presenze */
	int nLezioni; /* numero di lezioni del corso */
	int minStud, maxStud;
	int dataMinStud, dataMaxStud;

	/* Controlla i parametri ricevuti */
	/* argv[1] -> codice del corso */
	/* argv[2] -> comando "I" oppure "S" */
	if (argc != 3)
	{
		printf("ERRORE: numero di parametrierrato\n"); exit(1);
	}

	if (strcmp(argv[2], "I") != 0 && strcmp(argv[2], "S") != 0)
	{
		printf("ERRORE:comando %s non riconosciuto\n", argv[2]); exit(1);

	}
	/* se il comando è 'I' */ if (strcmp(argv[2], "I") == 0)
	{
		/* acquisisci i dati da tastiera */
		printf("Data:"); 
		gets_s(riga);
		r = sscanf(riga, "%d", &data);

		if (r != 1 || data < 1 || data > 366)
		{
			printf("ERRORE: Data assente o non valida\n"); exit(1);

		}
		printf("Studenti:"); 
		gets_s(riga);
		r = sscanf(riga, "%d", &stud);

		if (r != 1 || stud < 1)
		{
			printf("ERRORE: Numero studentiassente o non valido\n");
			exit(1);

		}
		/* aggiungi una riga al file */
		f = fopen(nomefile, "a");
		if (f == NULL)
		{
			printf("ERRORE: non riesco a modificare il file %s\n", nomefile);
			exit(1);
		}

		fprintf(f, "%s %d %d\n", argv[1], data, stud);
		fclose(f);

	}
	else if (strcmp(argv[2], "S") == 0) {
		/* se il comando è 'S' */
		nLezioni = 0;
		totStud = 0;
		minStud = 5000;
		maxStud = -1;

		/* leggi tutte le righe il file */
		f = fopen(nomefile, "r");
		if (f == NULL)
		{
			printf("ERRORE:impossibileleggere file %s\n", nomefile);
			exit(1);
		}
		while (fgets(riga, MAX, f) != NULL)
		{
			r = sscanf(riga, "%s %d %d", codice, &data, &stud);
			if (r != 3)
			{
				printf("Riga in formato errato - ignorata\n");

			}
			else {
				/* se la riga è relativa al corso che mi interessa */
				if (strcmp(codice, argv[1]) == 0)
				{
					/* aggiorna statistiche */
					nLezioni++; totStud = totStud + stud;
					if (stud > maxStud)
					{
						maxStud = stud; dataMaxStud = data;
					}

					if (stud < minStud)
					{
						minStud = stud; dataMinStud = data;

					}
				}
			}
		}
		fclose(f);
		/* stampa statistiche */
		if (nLezioni >= 1)
		{
			printf("Il minimo di studenti si e' raggiunto in data %d\n", dataMinStud);
			printf("Il massimo di studenti si e' raggiunto in data %d\n", dataMaxStud);
			printf("La media del numero di studenti vale %.1f\n",
				(double)totStud / (double)nLezioni);
		}
		else {
			printf("Non ci sono lezioni del corso %s\n", argv[1]);

		}
	}
	exit(0);
}
