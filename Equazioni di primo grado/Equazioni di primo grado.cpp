// Equazioni di primo grado.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*con a e b inseriti da tastiera, scrivere un programma in linguaggio C per determinare il valore di x, se esiste, che risolve l’equazione.*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
int main(void)
{
	float a, b; /* coefficienti a e b */ float x; /* valore di x che risolve l’equazione */
	printf("Risoluzione equazioni di primo grado\n");
	/* LEGGI a e b /
	scanf("%f", &a) ;
	scanf("%f", &b) ;
	/* x VIENE CALCOLATO COME x=-b/a. SI DEVONO VERIFICARE I VALORI DI a E b */
	if (a != 0)
	{
		x = -b / a;
		printf("Lasoluzione e’ x = %f\n", x);
	}
	else
	{
		/* CASO a==0 */ if (b == 0)
		{
			printf("Equazioneindeterminata(ammetteinfinitesoluzioni)\n");

		}
		else {
			printf("Equazioneimpossibile (non ammettesoluzioni)\n");
		}
	} return(0);
}
