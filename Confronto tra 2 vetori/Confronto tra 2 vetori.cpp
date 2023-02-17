/*
dato due vettore di 5 elementi char
chiedere all'utente inserire entrambi i vettori, poi confrontarli e stampare il numero di elementi in comune
vet1 abcde
vet2 aedfg
ris = 3


*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int main() {
    char vet1[5];
    char vet2[5];
    int conta = 0;
    for (int i = 0; i < 5; i++) {
        printf("Inserire un carattere nel Vett1\n");
        scanf("%c", &vet1[i]);
        getchar();
    }
    for (int i = 0; i < 5; i++) {
        printf("Inserire un carattere nel Vett2\n");
        scanf("%c", &vet2[i]);
        getchar();
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (vet1[i] == vet2[j]) {
                conta++;
            }
        }
    }
}
