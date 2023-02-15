// Classificazione triangolo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Si scriva un programma in linguaggio C che legga da tastiera i valori delle lunghezze dei tre lati di un triangolo (detti A, B e C), e determini:
•	se il triangolo è equilatero
•	se il triangolo è isoscele
•	se il triangolo è scaleno
•	se il triangolo è rettangolo.
Soluzione parziale
In questa prima soluzione si assume, per il momento, che i valori A, B, C descrivano correttamente un triangolo.
Nota. Per il calcolo del quadrato, è da preferirsi l'espressione a*a piuttosto che pow(a,2) in quanto è affetta da errori di approssimazione molto minori.

*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h> 
#include <stdlib.h>
#include <math.h>
int main(void)

{
	float a, b, c; /* lati del triangolo */
	/* LEGGI A, B e C */
	printf("Immetti A: ");
	scanf("%f", &a);
	printf("Immetti B: "); scanf("%f", &b);
			printf("Immetti C: "); scanf("%f", &c);
	printf("Verifico leproprieta' del triangolo di lati: %f, %f, %f\n", a, b, c);

	
		/* VERIFICA SE E' EQUILATERO (3 LATI UGUALI)*/ if (a == b && b == c) printf("Iltriangolo e' equilatero\n");
		else
				printf("Iltriangolo non e' equilatero\n");
	/* VERIFICA SE E' ISOSCELE (2 LATI UGUALI)*/ if (a == b || b == c || a == c) printf("Iltriangolo e' isoscele\n");
		else
		printf("Iltriangolo non e' isoscele\n");
	/* VERIFICA SE E' SCALENO (3 LATI DIVERSI)*/ if (a != b && b != c && a != c)
			printf("Iltriangolo e' scaleno\n");
	else printf("Iltriangolo non e' scaleno\n");
	/* VERIFICA SE E' RETTANGOLO (TEOREMA DI PITAGORA) */
		/* verifica se il lato A e' l'ipotenusa */ if (a * a == b * b + c * c)
		printf("Iltriangolo e' rettangolo (ipotenusa A)\n");
	else printf("Iltriangolo non e' rettangolo (ipotenusa A)\n");
	
		/* verifica se il lato B e' l'ipotenusa */ if (b * b == a * a + c * c)
			printf("Iltriangolo e' rettangolo (ipotenusa B)\n");
		else
			printf("Iltriangolo non e' rettangolo (ipotenusa B)\n");
	/* verifica se il lato C e' l'ipotenusa */ if (c * c == b * b + a * a)
		printf("Iltriangolo e' rettangolo (ipotenusa C)\n");
		else
		printf("Iltriangolo non e' rettangolo (ipotenusa C)\n");
	/* verifica se il triangolo e' rettangolo */
	if ((a * a == b * b + c * c) ||
			(b * b == a * a + c * c) ||
		(c * c == b * b + a * a))
		printf("Iltriangolo e' rettangolo\n");
	else printf("Iltriangolo non e' rettangolo\n");
	
		exit(0);
}
