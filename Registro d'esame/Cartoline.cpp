/*
Realizzare un programma in linguaggio C per registrare le cartoline scambiate tra un gruppo di amici (massimo 20 amici).
L'elenco delle cartoline è memorizzato in un file di testo, composto da un numero imprecisato di linee, ciascuna delle quali contiene tre elementi: il nome del mittente, il nome del destinatario ed il nome della località da cui la cartolina è stata inviata. I nomi degli amici e delle località sono da intendersi privi di spazi e lunghi al massimo 30 caratteri ciascuno.
Il programma riceve come primo parametro sulla linea di comando il nome del file di testo, mentre il secondo parametro può essere la stringa new oppure la stringa find.
Il comando new richiede ulteriori tre parametri sulla linea di comando, corrispondenti ai nomi degli amici e della località, e deve aggiungere tali informazioni in coda al file. Il programma deve segnalare con un messaggio errore l'eventuale tentativo di re-introdurre una cartolina identica ad una già esistente.
Il comando find è invece seguito da un solo ulteriore parametro sulla linea di comando, corrispondente al nome di un amico. In questo caso il programma deve stampare l'elenco degli amici che hanno spedito cartoline all'amico specificato e le località corrispondenti.
Esempio
Supponiamo che il programma si chiami cartoline e che il file car.txt contenga i seguenti dati:

	Gino Toni Rimini
	Gino Luigi Rimini
	Toni Gino Maldive
	Luigi Toni Moncalieri

In tal caso attivando il programma nel seguente modo: cartoline car.txt find Toni
dovrà essere generato il seguente output:

Cartoline ricevute da Toni:
	Gino da Rimini
	Luigi da Moncalieri
Invece, attivando il programma col seguente comando:
cartoline car.txt new Toni Luigi Roma
dovrà essere aggiunta in coda al file car.txt la seguente riga:
Toni Luigi Roma



*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
	const int MAX = 100; const int LUN = 30;
	FILE* f;
	char riga[MAX + 1];
	char mitt[LUN + 1], dest[LUN + 1], luogo[LUN + 1]; int r, esiste;
	/* Controlla i parametri sulla linea di comando */ 
	if (argc == 4 && strcmp(argv[2], "find") == 0) {
		/* comando 'find' */
		/* cerca all'interno del file se esiste un amico 'destinatario'
		25	uguale ad argv[3] */
		f = fopen(argv[1], "r"); if (f == NULL)
		{
			printf("ERRORE:impossibile aprire file %s\n", argv[1]);

			exit(1);
		}
		printf("Cartolinericevute da %s:\n", argv[3]);

		while (fgets(riga, MAX, f) != NULL)
		{
			r = sscanf(riga, "%s %s %s", mitt, dest, luogo);
			if (r == 3)
			{
				/* controlla se l'amico è quello giusto */ 
				if (strcmp(dest, argv[3]) == 0)
				{
					printf("	%s da %s\n", mitt, luogo);

				}
			}
			else printf("Riga in formato errato - ignorata\n");
		}

		fclose(f);
	}
	else if (argc == 6 && strcmp(argv[2], "new") == 0)
	{
		/* comando 'new' */
		/* controlla se esiste già una cartolina con mittente == argv[3]
		60	destinatario == argv[4]
		luogo == argv[5]
		*/
		esiste = 0;
		f = fopen(argv[1], "r");
		if (f == NULL)
		{
			printf("ERRORE:impossibile aprire file %s\n", argv[1]); exit(1);

		}
		while (fgets(riga, MAX, f) != NULL)
		{
			r = sscanf(riga, "%s %s %s", mitt, dest, luogo);

			if (r == 3)
			{
				/* controlla se la cartolina è duplicata */ if (strcmp(mitt, argv[3]) == 0 &&
					strcmp(dest, argv[4]) == 0 &&
					strcmp(luogo, argv[5]) == 0)
				{
					esiste = 1;
					printf("Attenzione:cartolina già esistente\n");


				}
			}
			else printf("Riga in formato errato - ignorata\n");
		}

		fclose(f);
		/* se non esiste ancora, aggiunge una nuova riga al file */
		if (esiste == 0)
		{
			/* aggiungi una riga */ f = fopen(argv[1], "a"); if (f == NULL)
			{
				printf("ERRORE:impossibilemodificare il file %s\n", argv[1]); exit(1);
			}
			fprintf(f, "%s %s %s\n", argv[3], argv[4], argv[5]);

			fclose(f);
		}
	}
	else
	{
		printf("ERRORE: Numero di parametri errato o comando sconosciuto\n"); 
		printf("Utilizzo: %s nomefile find nomeamico\n", argv[0]); 
		printf("oppure : %s nomefile new amicomittente amicodestinatarioluogo\n",  argv[0]);
		return(1);
	}
	return(0);
}
