// Elevamento a potenza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un algoritmo che riceve in ingresso un numero e ne calcola la sua potenza n-esima sempre con n inserito da tastiera.
es prendiamo base e esponente:
Base=3 Esponente=3  Risultato =3*3*3=27
Il calcolo deve essere fatto da una funzione alla quale si passano i due valori

Consiglio...
1*3=3
3*3=9
9*3=27

usare il risultato precedente e usarlo pre le operazioni successive
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int potenza(int numero, int n);

int main()
{
    int base = 0,esponente=0;
    printf("Inserisci un base ");
    scanf("%d", &base);
    printf("Inserisci un esponente ");
    scanf("%d", &esponente);
    int risultato=potenza(base, esponente);
    printf("%d^%d = %d",base,esponente,risultato);
}
int potenza(int numero, int n) {
    int risultato = 1;
    for (int i = 0; i < n; i++) {
        risultato = risultato * numero;
    }
    return risultato;
}