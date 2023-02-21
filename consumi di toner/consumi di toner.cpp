/*
Si desidera analizzare la statistica dei consumi di toner di un’azienda per ottimizzare gli acquisti futuri.
La quantità di cartucce di toner prelevate dal magazzino ogni giorno è riportata all’interno di un file di testo il cui nome è passato come primo parametro sulla riga di comando.
Il file contiene una riga per ogni giorno.Ogni riga contiene in sequenza :
•	il nome del dipartimento che ha prelevato il toner(una stringa lunga al massimo 5 caratteri);
•	un numero intero(valore minimo 1 e massimo 99) che indica la quantità di cartucce di toner prelevate in quel giorno da quel dipartimento.
Non è noto il numero di righe presenti nel file.
Il programma riceve inoltre come secondo argomento sulla linea di comando il nome di un dipartimento per il quale calcolare l’indicatore statistico dato come terzo argomento sulla linea di comando secondo la seguente codifica : • - min indica che si desidera il valore minimo;
• - max indica che si desidera il valore massimo;
• - med indica che si desidera il valore medio(da stamparsi in output con un cifra dopo la virgola).
Ad esempio se il file TONER.TXT contenesse i seguenti dati :
CONT 10
MAGAZ 20
CONT 15
ed il programma(che si suppone chiamato stat) venisse attivato con la seguente linea di comando :
stat toner.txt CONT - med
allora dovrebbe generare in output la seguente riga;
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	const int MAX = 100; const int LUNDIP = 5;
	int cont, tot, min, max, r;
	FILE* f;
	char riga[MAX + 1]; char nomedip[LUNDIP + 1]; int consumo;

	if (argc != 4)
	{
		printf("ERRORE: numero di argomentierrato\n"); exit(1);

	}
	f = fopen(argv[1], "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire file %s\n", argv[1]); exit(1);
	}
	/* Si è scelto di far sì che il programma calcoli comunque tutte e 35	tre le statistiche, e poi stampi solamente quella richiesta. Così facendo il codice è più semplice */
	cont = 0; tot = 0;
	max = 0;
	min = 1000;
	while (fgets(riga, MAX, f) != NULL)
	{
		r = sscanf(riga, "%s%d", nomedip, &consumo);

		if (strcmp(nomedip, argv[2]) == 0)
		{
			if (consumo > max)
				max = consumo;
			if (consumo < min) min = consumo;
			tot = tot + consumo;
			cont++;
		}
	}
	fclose(f);
	if (cont > 0)
	{
		if (strcmp(argv[3], "-min") == 0)
			printf("%d\n", min); else if (strcmp(argv[3], "-max") == 0) printf("%d\n", max);
			else if (strcmp(argv[3], "-med") == 0) printf("%.1f\n", (double)tot / cont);
			else
			printf("Errore:comando %s non riconosciuto\n", argv[3]);

	}
	else printf("Errore:dipartimento %s non trovato\n", argv[2]);


	exit(0);
}
