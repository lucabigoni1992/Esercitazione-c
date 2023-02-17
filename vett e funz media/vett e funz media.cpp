/*
preso un vettore di 10 interi con i valori passati dall'utnte,  dopo aver preso i valori setituire la media
*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
float media(int[]);
int main() {
    int vet[10];
    for (int i = 0; i < 10; i++) {
        printf("Inserire un numero\n");
        scanf("%d", &vet[i]);
    }
    float dato = media(vet);
    printf("%f\n", dato);
}

float media(int vet[10]) {
    int somma = 0;
    float media = 0;
    for (int i = 0; i < 10; i++) {
        somma = somma + vet[i];
    }
    media = somma / 10;
    return media;
}