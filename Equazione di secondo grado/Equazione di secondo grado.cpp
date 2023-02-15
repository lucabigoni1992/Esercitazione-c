// Equazione di secondo grado.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Si realizzi un programma in linguaggio C per risolvere equazioni di secondo grado.In particolare, data una generica equazione di secondo grado nella forma
ax2 + bx + c = 0
dove a, b, c sono coefficienti reali noti e x rappresenta l’incognita, il programma determini le due radici x1 ed x2 dell’equazione data, ove esse esistano.
Si identifichino tutti i casi particolari(a = 0, ∆ ≤ 0, ...) e si stampino gli opportuni messaggi informativi.
Soluzione
 */

#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	float a, b, c; /* coefficienti a, b e c */ float delta;	/* discriminante */
	float x1, x2; /* valori di x che risolvono l’equazione */

	printf("Risoluzione equazioni di secondo grado\n");
	/* LEGGI a e b /
	scanf("%f", &a) ;
	scanf("%f", &b) ;
	scanf("%f", &c) ;
	/* Se a==0, allora in realtà è un’equazione di primo grado */

	if (a == 0)
	{
		/* x VIENE CALCOLATO COME x=-c/b.
		SI DEVONO VERIFICARE I VALORI DI b E c */
		if (b != 0)
		{
			x1 = -c / b;
			printf("Unasoluzione: x = %f\n", x1);

		}
		else
		{
			/* CASO b==0 */ if (b == 0)
			{
				printf("Equazioneindeterminata(ammetteinfinitesoluzioni)\n");

			}
			else {
				printf("Equazioneimpossibile (non ammettesoluzioni)\n");


			}
		}
	}
	else /* a != 0, quindi è una ’vera’ equazione di secondo grado */
	{
		/* Calcoliamo il discriminante ’delta’ */ delta = b * b - 4 * a * c;
		// printf("Il discriminante vale: %f\n", delta) ;
		if (delta < 0)
		{
			printf("Non ci sono soluzioni in campo reale\n");
		}
		else if (delta == 0)
		{
			x1 = -b / (2 * a);
			printf("Unasoluzionedoppia: x = %f\n", x1);

		}
		else /* delta > 0 */
		{
			/* caso normale */
			x1 = (-b - sqrt(delta)) / (2 * a); x2 = (-b + sqrt(delta)) / (2 * a);
			printf("Duesoluzioni: x = %f e x = %f\n", x1, x2);


		}
	}
	return(0);
}
