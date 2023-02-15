/* PROGRAMMAZIONE IN C */
/* File: aree.c */
/* Soluzione proposta esercizio "Calcolo di aree"

1.	l’area del quadrato di lato D
2.	l’area del cerchio di diametro D
3.	l’area del triangolo equilatero di lato D
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	

#define _CRT_SECURE_NO_DEPRECATE
#define M_PI 3.14

int main(void)
{
	float d;	/* numero inserito */
	float aq, ac, at;	/* area quadrato, cerchio, triangolo */
	float r;	/* raggio del cerchio */
	float rad3_4;	/* costante pari a radice(3)/4 */
	rad3_4 = sqrt(3) / 4;
	/* STAMPA COSA ESEGUIRA’ IL PROGRAMMA */
	printf("Calcolo di aree\n\n");
	/* LEGGI IL NUMERO / printf("Immetti il valore di D: ") ; 25	scanf("%f", &d) ;
	/* CALCOLA L’AREA DEL QUADRATO DI LATO D */
	aq = d * d;
	/* soluzione alternativa per il calcolo dell’area del quadrato utilizzando la funzione pow(base, esponente) definita in math.h aq = pow(d, 2) ;
*/
/* CALCOLA L’AREA DEL CERCHIO DI DIAMETRO D */
	/* calcola il raggio del cerchio */ r = d / 2;
	/* calcola l’area del cerchio */
	ac = M_PI * (r * r);
	/* nota: il valore di PI greco e’ definito in math.h come M_PI */
	/* soluzione alternativa per il calcolo dell’area del cerchio ac = M_PI * pow(r, 2) ;
		*/
	/* CALCOLA L’AREA DEL TRIANGOLO EQUILATERO DI LATO D */ at = rad3_4 * (d * d);
	/* soluzione alternativa per il calcolo dell’area del triangolo equilatero at = rad3_4 * pow( d, 2 ) ;
*/
/* STAMPA IL RISULTATO */
	printf("\n");
	printf("Le aree calcolate sono:\n"); printf("Area del quadrato di lato %f = %f\n", d, aq); printf("Area del cerchio di diametro %f = %f\n", d, ac); printf("Area del triangolo equilatero di lato %f = %f\n", d, at);

	exit(0);
}
