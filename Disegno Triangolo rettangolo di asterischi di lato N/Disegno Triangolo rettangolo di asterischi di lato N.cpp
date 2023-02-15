// Disegno Triangolo rettangolo di asterischi di lato N.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

1.	Si realizzi un programma in linguaggio C che legga un numero intero N e visualizziun quadrato di asterischi di lato N (vedi esempio con N = 5).
2.	Si realizzi una variante del programma per visualizzare solo i lati del quadrato (vediesempio con N = 5).
3.	Si realizzi una variante del programma per visualizzare un triangolo isoscele rettangolo di lato N (vedi esempio con N = 5).
4.	Si realizzi una variante del programma per visualizzare un quadrato di lato N comenell’esempio del caso 4 (con N = 5).
	Caso 1	Caso 2	Caso 3	Caso 4
	*****	*****	*   	*++++
	*****	*	*	**  	**+++
	*****	*	*	***   	***++
	*****	*	*	****	****+
	*****	*****	*****	*****

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> #include <stdlib.h>
int main(void)
{
	int lato; /* lato del triangolo */
	int riga, colonna; /* riga e colonna del triangolo */
	/* LEGGI IL LATO DEL TRIANGOLO */
	printf("Inserisci il lato del triangolo:"); scanf("%d", &lato);
	/* CONTROLLA SE IL LATO DEL TRIANGOLO E’ UN NUMERO MAGGIORE DI 0 */ if (lato <= 0)
		printf("Errore, il lato deve essere maggiore di zero\n");
	else {
		/* IL CICLO PIU’ ESTERNO SCANDISCE LA RIGHE DEL TRIANGOLO */
			/* INIZIALIZZA LA VARIABILE PER LA SCANSIONE DELLE RIGHE DEL
		TRIANGOLO */ riga = 0;
		while (riga < lato)
		{
			/* IL CICLO PIU’ INTERNO SCANDISCE LE COLONNE DEL TRIANGOLO */
			/* PER OGNI RIGA STAMPA "*" SOLO SE colonna <= riga */
			/*INIZIALIZZA LA VARIABILE PER LA SCANSIONE DELLE COLONNE DEL
			35	TRIANGOLO */
			colonna = 0;
			while (colonna <= riga)
			{
				/* STAMPA "*" senza andare a capo */
				printf("*");
				/* INCREMENTA "colonna" PER PASSARE ALLA COLONNA SUCCESSIVA */ colonna = colonna + 1;

			}
			/* TERMINATA LA STAMPA DI UNA RIGA SI DEVE RIPORTARE IL CURSORE AL MARGINE SINISTRO DELLO SCHERMO */ printf("\n");

			/* INCREMENTA "riga" PER PASSARE ALLA RIGA SUCCESSIVA */ riga = riga + 1;
		}
	}
	return(0);
}
