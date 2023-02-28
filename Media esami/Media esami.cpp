/*
Si desidera calcolare e stampare il valor medio dei voti riportati dagli studenti in esami universitari. I voti sono riportati in un file di testo il cui nome è fornito come primo parametro sulla linea di comando.
Il file contiene una riga per ogni esame registrato. Ogni riga contiene in sequenza:
•	il numero di matricola dello studente (al massimo 6 cifre)
•	il codice dell'esame, composto da 4 cifre di cui quella più significativa indica l'anno di corso dell'esame (1 per il primo anno, 2 per il secondo anno, . . . )
•	la data dell'esame, composta da 8 cifre secondo il formato AAAAMMGG (es. il 23 gennaio 2007 sarebbe indicato come 20070123)
•	il voto ottenuto (al massimo 2 cifre).
Non è noto a priori il numero di righe presenti nel file. La media deve essere stampata con una sola cifra dopo la virgola. Si noti che il file contiene la registrazione anche delle insufficienze (ossia voti < 18) ma tali voti non devono essere considerati nel calcolo della media.
Il programma riceve inoltre come ulteriori parametri sulla linea di comando delle indicazioni circa l'insieme di voti da considerare nel calcolo della media, secondo la seguente codifica:
•	-aN media dei voti degli esami dell'anno N-esimo; • -sM media dei voti dello studente con matricola M;
•	-eC media dei voti dell'esame con codice C.
Si può assumere che sia presente sempre solo uno di questi tre parametri. Ad esempio se il file VOTI.TXT contenesse i seguenti dati:
1234 1001 20050123 30
98765 1001 20050123 18
98765 1021 20050912 21 1234 2027 20051023 28
il programma (che si suppone chiamato media) dovrebbe generare i seguenti risultati quando attivato come indicato:
linea di comando	output prodotto
media VOTI.TXT -s1234	29.0
media VOTI.TXT -a1	23.0
media VOTI.TXT -e1001	24.0

*/


#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const int MAX = 100;
	char comando;
	int valore;
	int r, voto, matricola, codice; int nVoti, totVoti;
	FILE* f;
	char riga[MAX + 1];
	/* controlla gli argomenti */
	/* argv[1] -> nome del file */
		/* argv[2] -> comando
	argv[2][0] == '-' argv[2][1] == 'a' oppure 's' oppure 'e' argv[2][dal 2 in poi] -> numero intero */
	if (argc != 3)
	{
		printf("ERRORE: numero di argomentierrato\n"); exit(1);
	}

	r = sscanf(argv[2], "-%c%d", &comando, &valore);
	if (r != 2 || (comando != 'a' && comando != 's' && comando != 'e')) {
		printf("ERRORE:comando %s non riconosciuto\n", argv[2]); exit(1);
	}
	/* leggi il file, per ogni riga controlla se deve essere
	45	considerata (in funzione di comando) */
	f = fopen(argv[1], "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire file %s\n", argv[1]);

		exit(1);
	}
	totVoti = 0;
	nVoti = 0;

	while (fgets(riga, MAX, f) != NULL)
	{
		r = sscanf(riga, "%d %d %*s %d", &matricola, &codice, &voto);
		/* Nota: %*s fa sì che la stringa NON venga memorizzata */

		if (r == 3)
		{
			if (((comando == 's' && matricola == valore) ||
				(comando == 'e' && codice == valore) ||
				(comando == 'a' && (codice / 1000) == valore))
				&& voto >= 18)
			{
				totVoti = totVoti + voto; nVoti++;

			}
		}
	} fclose(f);
	if (nVoti > 0)
	{
		printf("Valore medio: %.1f\n", (double)totVoti / (double)nVoti);
	}
	else
	{
		printf("Non ci sono esami che soddisfano i criteri di ricerca\n");
	}
	exit(0);

}
