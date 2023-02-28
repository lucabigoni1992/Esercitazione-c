

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
//trova i numeri pari e stampali 
int main()
{

	//trova i numeri pari e stampali 
	int vet3[] = { 43,2,4324,32,4,2,4,7,23,4,4,43,7,4,3,4,3 };
	int* pari = vet3;//pari = &vet2[0]
	do {
		if (*pari % 2 == 0) {
			printf("trovato numero pari: %d \n", *pari);//si effettua la copiatura
		}
		pari++;
	} while (*pari != '\0');//un array finisce SEMPRE  con il caratte \0
}

