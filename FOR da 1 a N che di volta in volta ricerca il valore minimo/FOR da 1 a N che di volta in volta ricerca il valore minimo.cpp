/*

Quindi definiamo le variabili che ci servono:

N – La variabile intera che rappresenta la quantità dei numeri da inserire.

min – La variabile intera che contiene il valore minimo.

i – La variabile contatore per il ciclo for. Ovviamente il contatore deve essere un intero.

pos – La variabile intera che indica il numero d’ordine del valore minimo.

Dopo avere dichiarato le variabili occorre prendere in input N e controllare che sia maggiore di zero.

Poi inseriamo il primo numero e lo assegniamo alla variabile min.
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, min, n, pos;

	do {
		printf("Quanti numeri vuoi inserire? : \n");
		scanf("%d", &N);
	} while (N <= 0);

	printf("Inserisci un numero : \n");
	scanf("%d", &min);
	pos = 1;

	for (int i = 1; i < N; i++) {
		printf("Inserisci un numero : \n");
		scanf("%d", &n);

		if (n < min) {
			min = n;
			pos = i + 1;
		}
	}
	printf("Il minimo  e' %d, numero ordine : %d", min, pos);

	return 0;
}