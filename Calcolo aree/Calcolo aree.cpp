/* PROGRAMMAZIONE IN C */
/* File: aree.c */
/* Soluzione proposta esercizio "Calcolo di aree"

1.	l'area del quadrato di lato D
2.	l'area del cerchio di diametro D
3.	l'area del triangolo equilatero di lato D
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	

#define _CRT_SECURE_NO_DEPRECATE
#define M_PI 3.14

int main(void)
{
	float lato;	/* numero inserito */
	float aq, ac, at;	/* area quadrato, cerchio, triangolo */
	float r;	/* raggio del cerchio */

	/* STAMPA COSA ESEGUIRA' IL PROGRAMMA */
	printf("Calcolo di aree\n\n");
	/* LEGGI IL NUMERO */
	printf("Immetti il valore di D: ") ; 	
	scanf("%f", &lato) ;
	/* CALCOLA L'AREA DEL QUADRATO DI LATO D */
	aq = lato * lato;
	/* soluzione alternativa per il calcolo dell'area del quadrato utilizzando la funzione pow(base, esponente) definita in math.h aq = pow(d, 2) ;
*/
/* CALCOLA L'AREA DEL CERCHIO DI DIAMETRO D */
	/* calcola il raggio del cerchio */
	r = lato / 2;
	/* calcola l'area del cerchio */
	ac = M_PI * (r * r);
	/* nota: il valore di PI greco e' definito in math.h come M_PI */
	/* soluzione alternativa per il calcolo dell'area del cerchio ac = M_PI * pow(r, 2) ;
		*/
	/* CALCOLA L'AREA DEL TRIANGOLO EQUILATERO DI LATO D */ 
	at =  (lato * lato)/2;
	/* soluzione alternativa per il calcolo dell'area del triangolo equilatero at = rad3_4 * pow( d, 2 ) ;
*/
/* STAMPA IL RISULTATO */
	printf("\n");
	printf("Le aree calcolate sono:\n");
	printf("Area del quadrato di lato %f = %f\n", lato, aq);
	printf("Area del cerchio di diametro %f = %f\n", lato, ac); 
	printf("Area del triangolo equilatero di lato %f = %f\n", lato, at);

	exit(0);
}
