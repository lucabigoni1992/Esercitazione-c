/*
Si desidera sviluppare un programma in linguaggio C per il calcolo delle superfici e dei volumi di un edificio.
Il programma riceve sulla riga di comando due parametri: il primo è il nome del file che contiene le dimensioni dell’edificio mentre il secondo è il numero di piani di cui è composto l’edificio.
La struttura dell’edificio è descritta in un file di testo così organizzato. 
Per ogni piano è presente una prima riga contenente due valori interi: il numero di stanze presenti nel piano e l’altezza del piano
. Tale riga è seguita da tante righe quante sono le stanze, ognuna contenente due valori che rappresentano le dimensioni della stanza.
Tutte le stanze sono di forma rettangolare, tutte le dimensioni sono espresse in centimetri e sono date come numeri interi positivi.
Il programma deve calcolare e presentare sull’unità di output standard: • la superficie totale di tutte le stanze dell’edificio, espressa in metri quadri
• il volume totale di tutte le stanze dell’edificio, espresso in metri cubi.
Ad esempio, se il programma – supposto chiamarsi dimef – venisse attivato con la seguente riga di comando: dimef CASA.TXT 2
(ovvero l’edificio è composto da due piani e le relative dimensioni si trovano nel file CASA.TXT) ed il file CASA.TXT contenesse i seguenti dati:
2 300
200 200
200 400
1 200
200 300
(ovvero il primo piano è alto 300 cm e consiste di due stanze rispettivamente di 200 cm × 200 cm e 200 cm × 400 cm, mentre il secondo piano è alto 200 cm e consiste di un’unica stanza di 200 cm × 300 cm) allora il programma dovrebbe produrre il seguente output:
Superficie totale dell’edificio: 18.00 metri quadri
Volume totale dell’edificio: 48.00 metri cubi

*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int main(int argc, char* argv[])
{
	const int MAX = 100;
	int nPiani;
	double areaTot; /* superficie totale in m^2 */
	double volTot; /* volume totale in m^3 */
	double areaPiano; /* superficie di 1 piano in m^2 */
	int p, s, x, y, r;
	int nStanze, hPiano;

	FILE* f;
	char riga[MAX + 1];
	if (argc != 3)
	{
		printf("ERRORE: numero argomentierrato\n");
		return(1);
	}
	/* argv[1] -> nome del file */ /* argv[2] -> numero di piani */
	r = sscanf(argv[2], "%d", &nPiani);
	if (r != 1 || nPiani < 1)
	{
		printf("ERRORE: numero piani errato\n");
		return(1);
	}
	f = fopen(argv[1], "r"); if (f == NULL)
	{
		printf("ERRORE:impossibile aprire file %s\n", argv[1]); return(1);

	}
	areaTot = 0.0; volTot = 0.0;
	/* per ogni piano p=1...nPiani */
	for (p = 1; p <= nPiani; p++)
	{
		/* leggere nStanze e altezza hPiano */
		if (fgets(riga, MAX, f) == NULL)
		{
			printf("ERRORE: il file e’ finito troppo presto\n");
			return(1);
		} 
		if (sscanf(riga, "%d%d", &nStanze, &hPiano) != 2)
		{
			return(1);
		}
		/* opzionale: controllare che nStanze>=1 e 1<=hPiano<=h_max */
		areaPiano = 0.0;
		/* per ogni stanza del piano, da 0 a nStanze-1 */
		for (s = 0; s < nStanze; s++)
		{
			/* leggi le misure */
			if (fgets(riga, MAX, f) == NULL)
			{
				printf("ERRORE: il file e’ finito troppo presto\n");
				return(1);
			}
			else
			{
				if (sscanf(riga, "%d%d", &x, &y) != 2)
				{
					return(1);
				}

				areaPiano = areaPiano + (x * y) / 10000.0;
				/* aggiorna areaPiano */
			}
		}
		areaTot = areaTot + areaPiano;
		volTot = volTot + areaPiano * (hPiano / 100.0);
	}

	fclose(f);
	printf("Superficie totale dell’edificio: %.2f metri quadri\n", areaTot);
	printf("Volume totale dell’edificio: %.2f metri cubi\n", volTot);
	return(0);
}
