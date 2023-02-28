// Alfabeto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//popolare un arrei con dei caratteri e poi contare le vocali e le consonanti
//https://it.wikipedia.org/wiki/ASCII
#include <stdio.h>

int main()
{
    char vet[100];//vettore di 100 caratteri
    int nDati;
    printf("Inserire N°Valori che si vuole inserire");
    scanf("%d", &nDati);
    //controllo <=99
    getchar();//getchar serve per acquisire il laore dell'invio dell'utente dell' nDati
    for (int i = 0; i < nDati; i++) {
        printf("Inserire solo caratteri minuscoli [a-z]");
        scanf("%c", &vet[i]);
        if (!(vet[i] >= 'a' && vet[i] <= 'z')) {//nel caso in cui non sia rispettata la condizione voluta
            printf("ERRORE CARATTERE INVALIDO : {%c}", vet[i]);
            return -1;
        }
        getchar();
    }
    //contiamo vocali
    int vocali=0, consonanti=0;
    for (int i = 0; i < nDati; i++) {
        if (vet[i] == 'a' || vet[i] == 'e' || vet[i] == 'i' || vet[i] == 'o' || vet[i] == 'u' ) {
            vocali++;
        }
        else {
            consonanti++;
        }
    }
    printf("Ho trovato %d Vocali e %d Consonanti",vocali,consonanti);

}