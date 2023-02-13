#include <stdio.h>
/*fare una funzione che preso un numero stampi un triangolo equilatero  nella seguente maniera:
1 *
2 *
  **
3 *
  **
  ***
5 *
  **
  ***
  ****
  *****
le funzioni che non restituiscono un valore come in questo caso sono di tipo void
*/
//prototipo
void stampa(int n);

int main(void) {
    int n = 0;
    printf("Inserisci l'altezza\n");
    scanf("%d", &n);
    stampa(n);

    return 0;
}

void stampa(int n) {
    //i=1 ->*
    //i=2 ->**
    //i=3 ->***
    for (int i = 1; i <= n; i++) {//contare quante righe abbiamo stampato
        for (int j = 0; j < i; j++) {//qunti asterischi della singola riga
            printf("*");
        }
        printf("\n");

    }
}