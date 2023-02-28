/*
(cifrario di cesare)
chiedere all'utente di inserire 10 caratteri,e un numero,
inserire questi valori in un vettore, creare un secondo vettore che ha i caratteri del primo ma traslati n
posizioni nell'alfabeto se la traslazione supera la z
mettere un -; stampare il 2° vettore
dell'alfabeto es
carateri   : abc n=3:
traslazione :a->d b->e c->f ris
risultato :  def
carateri   : aazz n=1:
traslazione :a->b a->b z->- z->- ris
risultato :  bb--
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

int main(void) {
    char vet1[10];
    char vet2[10];
    int n = 0;
    for (int i = 0; i < 10; i++) {
        printf("Inserire un valore\n");
        scanf("%c", &vet1[i]);
        getchar();
    }
    printf("Inserire il numero di traslazioni\n");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++) {
        if (vet1[i] + n <= 'z') {
            vet2[i] = vet1[i] + n;
        }
        else {
            vet2[i] = '-';
        }


    }
    printf("\n%s\n", vet2);



    return 0;

}