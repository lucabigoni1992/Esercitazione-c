/*
Un'azienda ha dotato i propri dipendenti di un sensore wireless che emette un codice numerico ogni volta che un dipendente attraversa la porta d'ingresso/uscita dell'azienda o ne transita nelle vicinanze. L'azienda ha meno di 1000 dipendenti. Ad ogni attraversamento, il sensore registra ora e minuti del passaggio, insieme al codice del dipendente (un codice alfanumerico di max 10 caratteri).
Si desidera sviluppare un programma in linguaggio C per il calcolo delle ore lavorative dei dipendenti dell'azienda. Il programma riceve sulla linea di comando un primo parametro, che rappresenta il nome del file contenente gli attraversamenti, ed un secondo parametro (opzionale), che rappresenta il codice numerico di un dipendente.
Il file è relativo ai passaggi di una sola giornata, ed è composto da una serie di righe, ciascuna delle quali corrisponde ad un passaggio, ed è composta da tre campi:
ora minuti codice_dipendente
Se il programma viene invocato con un due parametri sulla linea di comando (vi è il codice del dipendente), allora dovrà stampare, per il dipendente specificato, il numero totale di minuti lavorati. Per determinare il numero di minuti lavorati occorre confrontare l'orario del primo passaggio con l'orario dell'ultimo passaggio per quel dipendente.
Se invece il programma viene invocato con un solo parametro sulla linea di comando (il codice del dipendente è assente), allora il programma dovrà stampare il numero totale di dipendenti diversi che hanno lavorato in quel giorno (ossia che sono passati almeno una volta dalla porta).
Ad esempio, dato il seguente file di testo passaggi.txt:
8 30 abc222
8 30 abc123
8	31 azx112
9	10 abc123
12 10 abc123
il programma (chiamato orario.c) si dovrà comportare nel modo seguente:
c:> orario passaggi.txt Ci sono 3 dipendenti diversi.
c:> orario passaggi.txt abc123
Il dipendente abc123 ha lavorato per 220 minuti.

*//* File: orario.c */
/* Soluzione proposta esercizio "Minuti lavorati" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const int MAX = 100; const int NUMDIP = 1000; const int LUNMAT = 10;
	FILE* f;
	int min, max, tempo, passaggi, r; int ore, minuti; char riga[MAX + 1];
	char matricola[LUNMAT + 1];
	char nomi[NUMDIP][LUNMAT + 1]; int N, i, presente;
	/* controllo parametri:
argv[1] -> nome del file argv[2] -> matricola dipendente (opzionale)
*/
	if (argc != 2 && argc != 3)
	{
		printf("ERRORE: numero di parametrierrato\n"); exit(1);
	}
	/* apertura del file */
	f = fopen(argv[1], "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire il file %s\n", argv[1]);

		exit(1);
	}
	if (argc == 2)
	{
		/* CALCOLO DEL NUMERO DI DIPENDENTI DIVERSI */ N = 0;
		while (fgets(riga, MAX, f) != NULL)
		{
			r = sscanf(riga, "%*d %*d %s", matricola);
			/* NOTA: gli asterischi nella stringa di formato della sscanf (come %*d) servono per far leggere il dato corrispondente ma non memorizzarlo in alcuna variabile.
			In effetti qui i primi due campi numerici non ci servono */

			if (r != 1)
			{
				printf("Riga in formato errato - ignorata\n");
			}
			else
			{
				/* Cerca se 'matricola' è già presente */ presente = 0; for (i = 0; i < N && presente == 0; i++)
					if (strcmp(matricola, nomi[i]) == 0)
						presente = 1;
				/* Se è nuovo, aggiungilo */ if (presente == 0)
				{
					strcpy(nomi[N], matricola);
					N++;
				}
			}

		}
		fclose(f);
		printf("Ci sono %d dipendentidiversi\n", N);
	}
	else
	{
		/* CALCOLO DEL TEMPO LAVORATO DAL DIPENDENTE LA CUI MATRICOLA È argv[2] */ max = 0;
		min = 24 * 60;
		passaggi = 0;
		while (fgets(riga, MAX, f) != NULL)
		{
			r = sscanf(riga, "%d %d %s", &ore, &minuti, matricola); if (r != 3)
			{
				printf("Riga in formato errato - ignorata\n");

			}
			else {
				tempo = ore * 60 + minuti;
				if (strcmp(matricola, argv[2]) == 0)
				{
					if (tempo < min) min = tempo; if (tempo > max)
						max = tempo;
					passaggi++;
				}
			}
		}
		fclose(f);
		if (passaggi >= 2) printf("Ildipendente di matricola %s ha lavorato per %d minuti\n", argv[2], max - min);
		else
			printf("ERRORE: Il dipendente %s ha fatto solo %d passaggi\n", argv[2], passaggi);
	}
	return(0);
}
