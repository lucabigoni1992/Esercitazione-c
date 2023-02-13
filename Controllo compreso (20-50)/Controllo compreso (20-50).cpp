#include <stdio.h>
/*una funzione che preso un numero restituisca true se è compreso tra 20 e 50, chiedere all'utente di inserire 10 numeri
5 -> false
10->false
21->true
20->false
*/
//prototipo
int verify(int n);

int main(void) {
    int n = 0;
    for (int i = 0; i < 10; i++) {
        printf("Inserisci un numero\n");
        scanf("%d", &n);
        if (verify(n) == 0)
            printf("True");
        else
            printf("False");
    }
    return 0;
}

int verify(int n) {
    if (n <= 20 || n >= 50) {
        return-1;
    }
    else {
        return 0;
    }
}



