/* Soluzione proposta esercizio "Media tra due numeri" */
/*
Specificatore di formato
Espressione
%c	char – carattere singolo
%d (%i)int – intero decimale con segno
%e (%E)float o double – formato esponenziale
%f float o double – reale con segno
%g (%G)float o double – %f o %e in base alle esigenze
%o	int – valore in base 8 senza segno
%p	pointer – valore di una variabile puntatore
%s	array di char – stringa di caratteri
%u	int – intero senza segno
%x (%X)
int – valore in base 16 senza segno


*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int main(void)

{
	int a, b; /* numeri inseriti */
	float somma; /* somma dei due numeri */
	float media; /* media dei due numeri */
	/* STAMPA COSA ESEGUIRA' IL PROGRAMMA */
	printf("Calcolo della media di due numeri\n\n");
	/* LEGGI I DUE NUMERI */
	printf("Immetti il primo numero: ");
	scanf("%d", &a);
	printf("Immetti il secondo numero: ");
	scanf("%d", &b);
	/* CALCOLA LA SOMMA DEI DUE NUMERI */
	somma = a + b;
	/* CALCOLA LA MEDIA DEI DUE NUMERI */
	media = somma / 2;

	/* SOLUZIONE ALTERNATIVA PER IL CALCOLO DELLA MEDIA DEI DUE NUMERI.
	LA MEDIA E' CALCOLATA SENZA UTILIZZARE LA VARIABILE SOMMA:
	media = ( a + b ) / 2 ;
	*/

	/* STAMPA IL RISULTATO */ 
	printf("\n");
	printf("La media aritmetica di %d e %d e' %f\n", a, b, media);
	return(0);
}
