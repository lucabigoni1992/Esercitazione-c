// Controlo Minuscolo Maiuscolo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Presi in ingresso 10 caratteri verificare se questi caratteri sono minuscoli  se lo sono stampare il corrispettivo maiuscolo.
In fine stampare anche il numero delle conversioni da minuscolo a maiuscolo:

Esempio :
inp : aAbbcD
out : AABBCD Trovate 4 conversioni
inp : AABBCD
out : AABBCD Trovate 0 conversioni

la funzione che si deve realizzare deve controllare il singolo carattere e stampare il maiuscolo se il carattere in ingresso è minuscolo, E RESTITUIRE UN VALORE che permetta di capire se la conversione è avvenuta.

*/
/*
Presi in ingresso 10 caratteri verificare se questi caratteri sono minuscoli  se lo sono stampare il corrispettivo maiuscolo.
In fine stampare anche il numero delle conversioni da minuscolo a maiuscolo:

Esempio :
inp : aAbbcD
out : AABBCD Trovate 4 conversioni
inp : AABBCD
out : AABBCD Trovate 0 conversioni

la funzione che si deve realizzare deve controllare il singolo carattere e stampare il maiuscolo se il carattere in ingresso è minuscolo, E RESTITUIRE UN VALORE che permetta di capire se la conversione è avvenuta.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int conversione(char);

int main() {
    char lettera = ' ';
    int nconversioni = 0;
    printf("Inserire una lettera\n");
    for (int i = 0; i < 10; i++) {
        scanf("%c", &lettera);
        getchar();//per l'invio
        int risultato = conversione(lettera);
        //se restituisce 1 aumenterò un contatore
        if (risultato == 1) {
            nconversioni = nconversioni + 1;
        }


        //stampo il contatore
    }
}


int conversione(char lettera) {

    if (lettera >= 'a' && lettera <= 'z') {
        //print
        lettera =(char)( (int)lettera - 32);
        printf("%c", lettera + 32);
        return 1;
    }
    printf("%c", lettera);
    return 0;
}