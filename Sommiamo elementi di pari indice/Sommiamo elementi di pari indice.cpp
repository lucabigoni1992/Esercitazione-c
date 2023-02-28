

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main()
{

	//sommiamo gli elmementi del solito indic  e li stampiamo
	int vet[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int vet2[10] = { 11,22,33,44,55,66,77,88,99,00 };
	int* n1, * n2;
	n1 = &vet[0];// n2 = vet;
	n2 = &vet2[0];// n2 = vet2;

	do {
		printf("la somma di %d + %d = %d \n", *n1, *n2, (*n1 + *n2));//si effettua la copiatura
		n1++; n2++;//si scorrono i puntatori
	} while (*n1 != '\0');

}

