/*
Si desidera sviluppare un programma in linguaggio C per il calcolo di statistiche sulle temperature registrate in varie città italiane.
Il programma riceve in un file di testo (il cui nome è specificato come primo parametro sulla riga di comando) le informazioni sulle temperature. Ogni riga del file ha il seguente formato:
temperatura luogo dove:
•	temperatura è un numero in formato floating-point che esprime la temperatura rilevata;
•	luogo è il nome del luogo ove la temperatura è stata rilevata (stringa di caratteri priva di spazi composta al massimo da 31 caratteri).
Eventuali righe con formato errato devono essere scartate segnalando l'errore (es. riga n. X errata - ignorata).
Il programma riceve come secondo parametro sulla riga di comando il nome di una località per la quale deve calcolare il valore medio della temperatura.
Infine se è presente un terzo parametro sulla riga di comando (opzionale) allora esso indica una soglia di temperatura per la quale si chiede che il programma indichi il numero di giorni in cui tale soglia è stata superata.
Ad esempio, supponiamo che il file tluoghi.txt contenga i seguenti dati:
24.0 Torino
26.0 Milano
27.2 Milano
26.0 Torino
28.0 Torino
29.4 Milano
Se il programma – denominato temperatura – viene attivato con la seguente riga di comando: temperatura tluoghi.txt Torino
allora deve produrre il seguente output:
Torino:
-	temperatura media 26.0
Se invece il programma venisse attivato con la seguente riga di comando: temperatura tluoghi.txt Torino 24.5
allora deve produrre il seguente output:
Torino:
-	temperatura media 26.0
-	2 giorni con T > 24.5


*//* File: temperatura.c */
/* Soluzione proposta esercizio "Temperature" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	FILE* f;
	float somma, temperatura; int cont, r;
	char citta[31], riga[255];
	if (argc < 3)
	{
		printf("ERRORE: numero di parametri non sufficiente");
		exit(1);
	}
	f = fopen(argv[2], "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire il file");

		exit(1);
	}
	somma = 0;
	cont = 0; while (fgets(riga, 254, f) != NULL)
	{
		r = sscanf(riga, "%f%s", &temperatura, citta);

		if (r == 2)
		{
			if (strcmp(argv[3], citta) == 0)
			{
				somma = somma + temperatura;
				cont++;
			}
		}
		else printf("Riga in formato errato - ignorata\n");

	}
	printf("La media delle temperature della citta' %s e' %f\n", argv[2], somma / cont);
	fclose(f);
	return(0);

}
