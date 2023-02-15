/*1.	Si realizzi un programma in linguaggio C che legga un numero intero N
e visualizziun quadrato di asterischi di lato N(vedi esempio con N = 5).
Caso 
	*****	
	*****	
	*****	
	*****	
	*****	


*/
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
int main(void)
	{
	int lato;	/* lato del quadrato */
	int riga, colonna; /* riga e colonna del quadrato */
	/* LEGGI IL LATO DEL QUADRATO */
	printf("Inserisci il lato del quadrato:");

	scanf("%d", &lato);
	/* CONTROLLA SE IL LATO DEL QUADRATO E' UN NUMERO MAGGIORE DI 0 */ if (lato <= 0)
	printf("Errore, il lato deve essere maggiore di zero\n");
	else {
		/* IL CICLO PIU' ESTERNO SCANDISCE LA RIGHE DEL QUADRATO */
			/* INIZIALIZZA LA VARIABILE PER LA SCANSIONE DELLE RIGHE DEL QUADRATO */
		riga = 0;
		while (riga < lato)
		{
				/* IL CICLO PIU' INTERNO SCANDISCE LE COLONNE DEL QUADRATO */
			/* PER OGNI RIGA STAMPA "*" PER OGNI COLONNA */
			/*INIZIALIZZA LA VARIABILE PER LA SCANSIONE DELLE COLONNE DEL QUADRATO */
					colonna = 0;
			while (colonna < lato)
			{
				/* STAMPA "*" senza andare a capo */
					printf("*");
				/* INCREMENTA "colonna" PER PASSARE ALLA COLONNA SUCCESSIVA */ colonna = colonna + 1;
			}
			
				/* TERMINATA LA STAMPA DI UNA RIGA SI DEVE RIPORTARE IL CURSORE AL MARGINE SINISTRO DELLO SCHERMO */ printf("\n");
				/* INCREMENTA "riga" PER PASSARE ALLA RIGA SUCCESSIVA */ riga = riga + 1;
		}
	} return 0;
}
