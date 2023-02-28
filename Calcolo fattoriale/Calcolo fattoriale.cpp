// Calcolo fattoriale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*	8.1	Calcolo fattoriale
Si scriva una funzione in C,
denominata fattoriale, che calcoli il fattoriale di un numero intero dato.
Per via della velocità di crescita della funzione, il valore restituito deve essere codificato in un double,
nonostante sia in effetti un valore intero. */
//5=5*4*3*2
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>

int fattoriale(int n)
{
	int val;
	if (n < 0)
		return (-1); /* errore! */
	if (n == 0 || n == 1)
		return 1;
	val = 1;
	for (int i = 2; i <= n; i++) 
		val = val * i;
	return val;
}

int main()
{
	int fatt;
	printf("Di che numero vuoi calcolare il fattoriale?");
	scanf("%d", &fatt);
	printf("il fattoriale e': %d", fattoriale(fatt));

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
