// Scanf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Specificatore di formato
Espressione
% c	char ? carattere singolo
% d(% i)int ? intero decimale con segno
% e(% E)float o double ? formato esponenziale
% f float o double ? reale con segno
% g(% G)float o double ?% f o% e in base alle esigenze
% o	int ? valore in base 8 senza segno
% p	pointer ? valore di una variabile puntatore
% s	array di char ? stringa di caratteri
% u	int ? intero senza segno
% x(% X)
int ? valore in base 16 senza segno
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

void main() {
	int intero;
	float virgola;
	char c;

	printf("\nInserisci un carattere: ");
	scanf("%c", &c);
	printf("Carattere: %c", c);

	printf("\nInserisci un numero intero: ");
	scanf("%d", &intero);
	printf("Intero: %d", intero);

	printf("\nInserisci un numero con la virgola: ");
	scanf("%f", &virgola);
	printf("Numero con la virgola: %5.2f", virgola);

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
