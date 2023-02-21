// Esercizio base IF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
L'istruzione if controlla il ramo condizionale.
Il corpo di un'istruzione if viene eseguito se il valore dell'espressione è diverso da zero.
La sintassi per l'istruzione if ha due moduli.

Sintassi
selection-statement:
 if ( expression ){
     cosa fare
  }
 if ( expression ) cosa fare
 else cosa fare
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int n1, n2;
    printf("Immetti n1: ");
    scanf("%d", &n1);
    printf("Immetti n2: "); 
    scanf("%d", &n2);

    if (n1 % 2 == 0 && n2 % 3 == 0) {
        printf("n1  è divisibili per 2 e n3  è divisibili per 3");
    }
    else {
        printf("o n1 non è divisibili per 2 oppure n3  è divisibili per 3");
    }

    if (n1 % 2 == 0 || n2 % 3 == 0) {
        printf("n1  è divisibili per 2 oppure n  è divisibili per 3");
    }
    else {
        printf("entrambe le condizioni non sono everificate");
    }
    if (n1 == n2)
    {
        printf("il primo e' diverso dal seconto");
        printf("il primo e' diverso dal seconto");
        scanf("%d", &n2);
    }
    else{
        printf("il primo e' uguale dal seconto");
    }
    if (n1 > n2)
    {
        printf("il primo e' maggiore del seconto");
    }
    else
    {
        printf("il primo NON e' maggiore oppure è uguale del seconto");
    }
    return 0;
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
