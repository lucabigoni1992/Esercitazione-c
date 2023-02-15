/*PROGRAMMAZIONEINC*/ /*File:precedente_successivo.c*/ /*Soluzionepropostaesercizio"Precedenteesuccessivo"*/ 
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	int a;/*numero inserito*/
	int prec, succ;/*numero precedente e numero successivo*/
	/*LEGGIILNUMERO*/
	printf("Immettiilnumero:");
	scanf("%d", &a); /*CALCOLA IL NUMEROPRECEDENTE*/
	prec = a - 1;
	/*CALCOLAILNUMEROSUCCESSIVO*/
	succ = a + 1; /*STAMPAILRISULTATO*/ 
	printf("\n");
	printf("Il numero inserito e'  %d\n", a); 
	printf("Il numero precedente a %d e' %d\n", a, prec);
	printf("Il numero successivo a %d e' %d\n", a, succ);
	return 0;
}