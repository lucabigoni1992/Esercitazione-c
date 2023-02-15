
/*
Chiedere delle lettere all'utente fino a quando non nserisce il carattere'+'
creare 2 funzioni:
la prima cotrolla se il carattere inserito è una vocale,
l'altra se è una consonante.
contare le covali presenti e le consonanti

input -> ciaoMondodd+ ->Vocali:5 consonanti:6
input -> ciao+ ->Vocali:3 consonanti:1
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

bool controllavocale(int);

int main()
{
    char lettera='a';
    int contaVocale = 0, contaConsonante = 0;
    printf("inserisci una lettera al '+' si finisce:\n");
    scanf ("%c",&lettera);
    getchar();//ci servirà per andare a prender eil carattere\n
    while (lettera != '+') {
        bool ris = controllavocale(lettera);
        if (ris == true)
            contaVocale = contaVocale + 1;
        else
            contaConsonante = contaConsonante + 1;
        printf("inserisci una lettera al '+' si finisce:\n");
        scanf("%c", &lettera);
        getchar();//ci servirà per andare a prender eil carattere\n
    }
    printf("Vocali Trovate: %d\n" , contaVocale);
    printf( "Consonanti Trovate: %d\n", contaConsonante);
}

bool controllavocale(int lettera)
{
    if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u')
        return true;
    return false;
}
