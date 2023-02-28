/*
dato un vettore di 20 elementi char
chiedere all'utente inserire una posizione < di venti, stampare tutti i caratteri da 0 a il numero dato dall'utente
abcdefghilmnopu
3
abc
5
abcde
*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
int main() {
    char vet[5];
    int posizione = 0;
    for (int i = 0; i < 5; i++) {
        printf("Inserire il carattere n %d carattere\n",i);
        scanf("%c", &vet[i]);
        getchar();
    }
    printf("Inserire una posizione\n");
    scanf("%d", &posizione);
    for (int i = 0; i < posizione; i++) {
        printf("%c", vet[i]);
    }

}
