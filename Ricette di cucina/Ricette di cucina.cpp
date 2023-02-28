/*
Suor Germana vuole realizzare una versione elettronica delle sue famose ricette di cucina, sotto forma di un programma scritto in C. In particolare, si vuole che il programma identifichi quali sono le ricette cucinabili, dato il contenuto attuale del frigorifero di una massaia.
Il programma accede a due file:
1.	un file di testo (denominato Germana.txt) contenente gli ingredienti necessari per tutte le ricette di Suor Germana secondo il seguente formato:
•	ogni riga è nella forma ricetta ingrediente quantità
•	ricetta è una stringa (max 20 caratteri, senza spazi) che indica il nome della ricetta
•	ingrediente è una stringa (max 20 caratteri, senza spazi) che indica il nome di un ingrediente
•	quantità è un numero reale che indica la quantità di tale ingrediente nella ricetta corrispondente
•	sia ricetta, sia ingrediente sono ripetuti più volte nel file, ma sempre in associazione a ingredienti o ricette diversi
•	non è noto a priori il numero di righe del file, né è specificato alcun ordinamento noto per il file.
2.	un file di testo (il cui nome è passato come primo parametro sulla linea di comando) rappresentante il contenuto attuale del frigorifero secondo il seguente formato:
•	ogni riga è nella forma ingrediente quantità
•	ingrediente corrisponde ad uno degli ingredienti presenti nel file delle ricette
•	quantità è un numero reale che identifica la quantità presente di tale ingrediente nel frigorifero
•	ogni ingrediente è presente una sola volta in questo file
•	non è noto a priori il numero di righe del file, né è specificato alcun ordinamento noto per il file.
Il programma riceve come argomenti sulla linea di comando il nome del file contenente le disponibilità del frigorifero ed il nome di una ricetta, e deve fornire in output l'elenco degli ingredienti della ricetta (con l'indicazione se ciascuno di essi è disponibile o meno) e la conclusione finale se la ricetta scelta può essere preparata.
Ad esempio se i file Germana.txt e frigo.txt contenessero i seguenti dati:
(Germana.txt)	(frigo.txt)
padellino uovo 1	uovo 1
frittata olio 0.3	olio 0.5
	padellino olio 0.2	parmigiano 0.1
frittata uovo 1 coque uovo 1 frittata parmigiano 0.2 ed il programma (denominato cerca) venisse attivato con la riga di comando; cerca frigo.txt frittata
allora dovrebbe produrre il seguente risultato:
Ingredienti:
-	olio: OK
-	uovo: OK
-	parmigiano: richiesto 0.2, disponibile 0.1 Ricetta 'frittata' impossibile

*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const int MAXRIGA = 300; const int MAXINGR = 100; const int LUN = 20;

	const char filericette[] = "Germana.txt";
	/* COMPOSIZIONE DELLA RICETTA RICHIESTA */ 
	char ingredienti[MAXINGR][LUN + 1];
	double quantita[MAXINGR]; int Ningr; /* numero ingredienti totale della ricetta */
	FILE* f;
	int ok[MAXINGR]; int i, r;
	char riga[MAXRIGA + 1]; char ricetta[LUN + 1]; char ingr[LUN + 1];
	double qta, qrichiesta; int richiesto, pos, possibile;
	/* Acquisisci argomenti sulla linea di comando */ if (argc != 3)
	{
		printf("ERRORE: numero di argomentierrato\n"); exit(1);
	}
	/* FASE 1: LEGGI IL FILE Germana.txt E RIEMPI I VETTORI
ingredienti[], quantita[] SECONDO QUANTO RICHIESTO
DALLA RICETTA argv[2] */
	f = fopen(filericette, "r");
	if (f == NULL)
	{
		printf("ERRORE:impossibile aprire il file %s\n", filericette); exit(1);
	}
	Ningr = 0;
	while (fgets(riga, MAXRIGA, f) != NULL)
	{
		r = sscanf(riga, "%s %s %lf", ricetta, ingr, &qta);
		if (r == 3)
		{
			if (strcmp(ricetta, argv[2]) == 0)
			{
				strcpy(ingredienti[Ningr], ingr);
				quantita[Ningr] = qta;
				Ningr++;
			}
		}
		else
			printf("Riga in formatoerrato:ignorata\n");

	} fclose(f);
	if (Ningr == 0)
	{
		printf("ERRORE:ricetta %s non trovata\n", argv[2]); exit(1);
	}
	/* FASE 2: LEGGI IL FILE argv[1] E CONFRONTA CON GLI INGREDIENTI RICHIESTI */
/* 2A: leggo argv[1] e per ogni ingrediente aggiorno il vettore ok[] */

	for (i = 0; i < Ningr; i++) ok[i] = 0;
	f = fopen(argv[1], "r");

	while (fgets(riga, MAXRIGA, f) != NULL)
	{
		r = sscanf(riga, "%s%lf", ingr, &qta);

		if (r == 2)
		{
			/* ingr è richiesto? */ richiesto = 0; for (i = 0; i < Ningr; i++)
				if (strcmp(ingr, ingredienti[i]) == 0)
				{
					richiesto = 1; qrichiesta = quantita[i]; pos = i;

				}
			if (richiesto == 1)
			{
				if (qrichiesta <= qta)
				{
					ok[pos] = 1; printf("%s:ok\n", ingr);

				}
				else
				{
					printf("%s:richiesti %f, disponibili%f\n", ingr, qrichiesta, qta);
				}
			}

		}
		else printf("Riga in formatoerrato:ignorata\n");

	}
	fclose(f);

	/* 2A: sulla base del vettore ok[] decido se la ricetta e' fattibile */ possibile = 1; for (i = 0; i < Ningr; i++)
		if (ok[i] == 0) possibile = 0;
	if (possibile == 1) printf("RicettaPOSSIBILE!!!\n");
	else
		printf("RicettaIMPOSSIBILE\n");
	exit(0);
}
