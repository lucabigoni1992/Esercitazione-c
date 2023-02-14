
/*

Scrivi una funzione chiamata Controllo che passati 3 valori: massimo, minimo, e il valore controllo restituisca se il valorè è compreso nel range
chiedere all'utente quanti volori vuole inserire, il massimo e il minimo.
Per ogni valore, chiamare la funzione Controllo di sopra e stampare se il valore è compresa o meno

QUANTI VALORI? 5
INSERIRE IL MASSIMO : 10
INSERIRE IL MINIMO:5

1  ->NON COMPRESO
2  ->NON COMPRESO
34 ->NON COMPRESO
7  -> COMPRESO
5  ->NON COMPRESO



*/
#include <stdio.h>
using namespace std;
//prototipo
int compreso(int, int, int);
void compresoSenzaValori(int, int, int);

int main()
{
    int Nnumeri, max, min;
    printf( "quanti numeri vuoi inserire?\n");
    scanf("%d", &Nnumeri);
    printf( "qual è il numero massimo che vuoi inserire?\n");
    scanf("%d", &max);
    printf( "qual è il numero minimo che vuoi inserire?\n");
    scanf("%d", &min);
    for (int i = 0; i < Nnumeri; i++) {
        int n;
        printf( "inserire il valore: \n");
        scanf("%d", &n);
         int ris=  compreso(min, max, n);
         if(ris==1)
             printf("il valore è compreso\n");
         else//caso ko
             printf("il valore NON è compreso\n");
      //  compresoSenzaValori(min, max, n);
    }

}

int compreso(int min, int max, int n)
{
    if (min<n && max>n)//CASO OK
        return 1;
    else//caso ko
        return 0;
}
void compresoSenzaValori(int min, int max, int n)
{
    if (min<n && max>n)//CASO OK
        printf( "il valore è compreso\n");
    else//caso ko
        printf( "il valore NON è compreso\n");
}





