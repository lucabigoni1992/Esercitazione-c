// Ricerca un elemento in vettore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*

Si scriva una funzione in C, denominata cerca, che ricerchi la presenza di un elemento in un vettore di interi.
La funzione riceve in ingresso tre parametri:
1.	un vettore di interi v[] nel quale ricercare il valore;
2.	un un valore intero N che indica quanti elementi contiene il vettore;
3.	il valore intero x che deve essere ricercato.
La funzione deve restituire un valore intero, ed in particolare:
•	se il valore x è presente nel vettore, allora la funzione restituisce l'indice della posizione alla quale si trova tale valore;
•	se il valore x è presente più volte, si restituisca l'indice della prima occorrenza; • se il valore x non è presente nel vettore, si restituisca -1.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
int cerca(int v[], int N, int x)
{
	int pos, i;
	pos = -1;
	for (i = 0; (i < N) && (pos == -1); i++)
		if (v[i] == x)
			pos = i;

	return pos;
}

int main()
{
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int valoreDaCercare;
	printf("Inserire il valore da cercare:\n");
	scanf("%d", &valoreDaCercare);
	printf("Il valore chercato è alla pos: %d\n", cerca(v, 10, valoreDaCercare));
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
