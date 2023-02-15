// Da 3  numeri prendere il massimo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Si scriva un programma in linguaggio C che acquisisca tre numeri interi da tastiera e :
•	determini, stampando un messaggio opportuno quale dei tre numeri(il primo, il secondo o il terzo) sia maggiore
•	stampi il valore di tale numero.
Si trascuri il caso in cui i numeri siano uguali.
Soluzione(con if annidate)
 3" */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
	int a, b, c; /* numeri inseriti */
	/* LEGGI I NUMERI */ printf("Immetti il primo numero: ");
	scanf("%d", &a);
	printf("Immetti il secondo numero: "); scanf("%d", &b);
	printf("Immetti il terzo numero: "); scanf("%d", &c);
	/* VERIFICA SE a E' MAGGIORE DI b */ if (a > b)
	{
		/* CASO a > b */
		/* VERIFICA SE a E' MAGGIORE DI c */ if (a > c)
		{
			/* CASO a > c */
			/* a E' IL MASSIMO POICHE' a > b E a > c */ printf("Il primo numero %d e' maggiore del secondo %d e del terzo %d\n", a, b, c);
			printf("Il valore massimo e' %d\n", a);

		}
		else {
			/* CASO a < c (si e' trascurato il caso in cui i numeri siano uguali) */
			/* c E' IL MASSIMO POICHE' a > b E c > a */
			printf("Il terzo numero %d e' maggiore del primo %d e del secondo%d\n", c, a, b);
			printf("Il valore massimo e' %d\n", c);
		}
	}
	else
	{
		/* CASO a < b */
		/* VERIFICA SE b E' MAGGIORE DI c */ if (b > c)
		{
			/* CASO b > c */
			/* b E' IL MASSIMO POICHE' a < b E b > c */ printf("Il secondo numero %d e' maggiore del primo %d e del terzo %d\n", b, a, c);
			printf("Il valore massimo e' %d\n", b);
		}
		else {
			/* CASO c < b */
				/* c E' IL MASSIMO POICHE' a < b E b < c
			(si e' trascurato il caso in cui i numeri siano uguali) */ printf("Il terzo numero %d e' maggiore del primo %d e del secondo%d\n", c, a, b);
			printf("Il valore massimo e' %d\n", c);
		}
	} return(0);
}
