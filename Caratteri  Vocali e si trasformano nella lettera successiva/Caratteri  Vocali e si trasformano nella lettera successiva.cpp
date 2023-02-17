
/*
chiedere all'utente n caratteri, creare una funzione che controlli se sono vocali,
se lo sono li trasforma nella lettera dell'alfabeto seguente e stampi quella lettera.
si devono stampare solamente le vocali trasformate

a->b
e->f
i->l
o->p
u->v

Es
css->(niente)
acss->b
aeciao =bflbp
aabbb=bb
adde= bf
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char controllo_vocale(char);

int main()
{
    char carattere = ' ';
    printf("Inserisci carattere\n");
    scanf("%c", &carattere);
    getchar();
    while (carattere != '+') {
        //
        char dato = controllo_vocale(carattere);
        if (dato != ' ')
            printf("%c\n", dato);
        printf("Inserisci carattere\n");
        scanf("%c", &carattere);
        getchar();

    }
}

char controllo_vocale(char carattere) {
    if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u') {
        carattere = carattere + 1;
        return carattere;
    }

    return ' ';
}

