// Controllo Compreso [N M] Stampa PARI COMPRESI e somma dei dispari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*creare una funzione che: Dati due numeri N ed M STAMAPARE I NUMERI PARI COMPRESI TRA M E N  E stampare la somma dei dispari
	Es:
		n= 5   m= 10 risultati :6 8 10  somma dispari 5+7+9=21
		n= 5   m= 6  risultati :6       somma dispari 5*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>

/*creare una funzione che: Dati due numeri N ed M STAMAPARE I NUMERI PARI COMPRESI TRA M E N  E stampare la somma dei dispari
	Es:
		n= 5   m= 10 risultati :6 8 10  somma dispari 5+7+9=21
		n= 5   m= 6  risultati :6       somma dispari 5*/

void n_compresi(int, int);

int main(void) {
	int n = 0;
	int m = 0;
	printf("Inserire numero n\n");
	scanf("%d", &n);
	printf("Inserire numero m\n");
	scanf("%d", &m);
	n_compresi(n, m);
	return 0;
}


void n_compresi(int n, int m) {
	int somma_dispari = 0;
	for (int i = n; i <= m; i++) {
		if (i % 2 == 0) {
			printf("%d\t", i);
		}
		else {
			somma_dispari = somma_dispari + i;
		}
	}
	printf("\n%d", somma_dispari);
	return;
}