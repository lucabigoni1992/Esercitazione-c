/* PROGRAMMAZIONE IN C */
/* File: controlla-ab-v2.c */
/* Si scriva un programma in linguaggio C che legga due numeri da tastiera, detti A e B, e determini le seguenti informazioni, stampandole a video:
1.	determini se B è un numero positivo o negativo
2.	determini se A è un numero pari o dispari
3.	calcoli il valore di A + B
4.	determini quale scelta dei segni nell’espressione (±A) + (±B) porta al risultato massimo, e quale è questo valore massimo.
Suggerimento. Nel punto 4., il valore massimo della somma di A e B si può ottenere sommando il valore assoluto di A e di B.
" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h> 
int main(void)
{ int a, b; /* numeri inseriti A e B */ int c; /* somma A+B */
/* LEGGI A e B */
	printf("Immetti A: ");
scanf("%d", &a);
printf("Immetti B: "); scanf("%d", &b);

/* CONTROLLA IL SEGNO DI B E STAMPA IL MESSAGGIO OPPORTUNO */ if (b >= 0)
{
	printf("B e’ positivo\n");	
}
else {
	printf("B e’ negativo\n");
}
/* CONTROLLA LA PARITA’ DI A E STAMPA IL MESSAGGIO OPPORTUNO */ /* A e’ pari se il resto della divisione di A per 2 e’ uguale a zero */ if (a % 2 == 0)
{
		printf("A e’ pari\n");
}
else {
	printf("A e’ dispari\n");
}
/* CALCOLA A+B E STAMPA IL RISULTATO */ c = a + b;
printf("La somma %d + %d e’ uguale a %d\n", a, b, c);

/* CALCOLA IL VALORE MASSIMO DELLA SOMMA (+- A) + (+- B) E STAMPA IL RISULTATO*/
/* Il valore massimo e’ ottenuto sommando il valore assoluto di A e di B */
/* Calcola il valore assoluto di A */ 
if (a < 0)
	a = -a;
/* Calcola il valore assoluto di B */ 
if (b < 0) b = -b;

printf("Il valore massimo della somma +-A + +-B e’ uguale a %d\n", a + b);
exit(0);
}
