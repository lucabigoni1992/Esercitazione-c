/* Soluzione proposta esercizio "Media tra due numeri" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int main(void)

{
	int a, b; /* numeri inseriti */
	float somma; /* somma dei due numeri */
	float media; /* media dei due numeri */
	/* STAMPA COSA ESEGUIRA’ IL PROGRAMMA */
	printf("Calcolo della media di due numeri\n\n");
	/* LEGGI I DUE NUMERI / printf("Immetti il primo numero: ") ;
	20	scanf("%d", &a) ;
	printf("Immetti il secondo numero: ") ; scanf("%d", &b) ;
	25	/* CALCOLA LA SOMMA DEI DUE NUMERI */
	somma = a + b;
	/* CALCOLA LA MEDIA DEI DUE NUMERI */
	media = somma / 2;

	/* SOLUZIONE ALTERNATIVA PER IL CALCOLO DELLA MEDIA DEI DUE NUMERI.
	LA MEDIA E’ CALCOLATA SENZA UTILIZZARE LA VARIABILE SOMMA:
	media = ( a + b ) / 2 ;
	*/

	/* STAMPA IL RISULTATO */ printf("\n"); printf("La media aritmetica di %d e %d e’ %f\n", a, b, media);
	return(0);
}
