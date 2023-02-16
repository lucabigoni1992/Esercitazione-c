/*
Si desidera sviluppare un programma in linguaggio C per gestire in modo informatico un registro di esame.
Il registro è memorizzato in un file di testo con nome registro.txt e contiene i dati di N studenti, ove N è il numero intero scritto nella prima riga del file. Dopo questa prima riga, ogni riga successiva contiene il dato relativo ad un singolo studente, indicando il numero di matricola dello studente (numero intero compreso 1 e 999999) ed il voto conseguito (numero intero con valore tra 18 e 30, oppure zero per indicare che l’esame non è ancora stato sostenuto).
Il programma può essere attivato in due modi diversi.
Se viene attivato passando come primo parametro sulla linea di comando la parola stat allora deve fornire le seguenti statistiche: numero di studenti promossi (e relativa percentuale sul totale, espressa con una cifra dopo la virgola) e voto medio degli studenti promossi (indicato con una sola cifra dopo la virgola).
Il programma può anche essere attivato passando come primo parametro la parola voto, come secondo parametro il numero di matricola di uno studente e come ultimo parametro il voto conseguito dallo studente. In questo caso il programma deve inserire nel file il voto dello studente, segnalando però errore nel caso che lo studente non sia iscritto all’esame (ossia il suo numero di matricola non compaia nel file) oppure abbia già superato l’esame (ossia voto diverso da zero nella riga contenente la sua matricola).
Ad esempio se il file registro.txt contenesse i seguenti dati:
3
33467 30
24356 0
224678 18
 ed il programma – supposto chiamarsi esame – venisse attivato con la seguente riga di comando: esame stat allora il programma dovrebbe produrre il seguente output:
promossi = 2 (66.7 %) voto medio = 24.0
Se invece il programma venisse attivato nel seguente modo:
esame voto 24356 24
allora dopo l’esecuzione del programma il file registro.txt dovrebbe contenere i seguenti dati:
3
33467 30
24356 24
224678 18



*/

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const int MAX = 1000; const int LUN = 80; const char nomefile[] = "registro.txt";

	int matricola[MAX]; int voto[MAX]; int N;
	FILE* f;
	char riga[LUN + 1]; char comando[LUN + 1];
	int r, r1, r2, mat, vot, c, somma, i, trovato, pos;
	/* 1) Leggi il contenuto del file all’interno dei vettori */ f = fopen(nomefile, "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire il file %s\n", nomefile);

		exit(1);
	}
	fgets(riga, LUN, f); r = sscanf(riga, "%d", &N);
	if (r != 1)
	{
		printf("ERRORE:formato errato nella prima riga\n"); exit(1);
	}

	c = 0;
	while (fgets(riga, LUN, f) != NULL)
	{
		r = sscanf(riga, "%d%d", &mat, &vot);


		if (r != 2 || mat < 1 || mat>999999 ||
			!(vot == 0 || (vot >= 18 && vot <= 30)))
		{
			printf("ATTENZIONE: riga in formato errato - ignorata\n");
		}
		else {
			/* aggiungi ai vettori */ matricola[c] = mat;
			voto[c] = vot;
			c++;
		}
	}
	fclose(f);
	if (c != N)
	{
		printf("ERRORE di coerenza nel file\n");
		exit(1);
	}
	/* 2) Acquisisci il comando dell’utente */
	if (!(
		(argc == 2 && strcmp(argv[1], "stat") == 0) ||
		(argc == 4 && strcmp(argv[1], "voto") == 0)
		))
	{
		printf("ERRORE: numero argomentierrato\n"); exit(1);
	}
	strcpy(comando, argv[1]);
	if (strcmp(comando, "voto") == 0)
	{
		r1 = sscanf(argv[2], "%d", &mat); r2 = sscanf(argv[3], "%d", &vot); if (r1 != 1 || r2 != 1)
		{
			printf("ERRORE:matricola e voto devono essere numerici\n"); exit(1);
		}
	}

	/* 2a) "stat" */ if (strcmp(comando, "stat") == 0) {
		/* 2a1) calcola e stampa le statistiche */
		c = 0;
		somma = 0; for (i = 0; i < N; i++)
		{
			if (voto[i] != 0)
			{
				c++; somma = somma + voto[i];
			}
		}

		printf("promossi = %d (%f %%)\n", c, (double)c / (double)N * 100.0); printf("voto medio = %f\n", (double)somma / (double)c);
	}
	else if (strcmp(comando, "voto") == 0)
	{
		/* 2b) "voto nmatricola valorevoto" */
		/* ricerca ’mat’ all’interno del vettore matricola[] */
			/* output: trovato=1/0, pos */
		trovato = 0; for (i = 0; i < N && trovato == 0; i++)
		{
			if (matricola[i] == mat)

			{
				trovato = 1; pos = i;
			}
		}
		/* controlla se e’ valido */ if (trovato == 1 && voto[pos] == 0)
		{
			/* modifica il voto all’interno del vettore */
			voto[pos] = vot;
			/* salva i vettori su file */
			f = fopen(nomefile, "w"); if (f == NULL)
			{
				printf("ERRORE:impossibilescrivere il file modificato\n"); exit(1);
			}
			/* la prima riga contiene il numero di studenti */ fprintf(f, "%d\n", N);
			for (i = 0; i < N; i++) fprintf(f, "%d%d\n", matricola[i], voto[i]);


			fclose(f);
		}
		else {
			printf("Impossibile registrare il voto\n"); if (trovato == 0) printf("Lo studente non esiste\n");
			else printf("L’esame e’ gia’ stato superato\n");

		}
	}
	else {
		printf("ERRORE:comando non valido\n");

		return(1);
	}
	return(1);
}
