/*
dati due vettori di numeri salvare su un 3 °vettore i valori in comune ai due vettori e pari
es
v1 1 2 3 4 5 6
v2 3 6 5 8 9 7
v3 6
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#define MAX 10
int main(void) {
    int arr1[MAX];
    int arr2[MAX];
    int arr3[MAX];
    int tmp = 0;
    for (int i = 0; i < MAX; i++) {
        printf("Inserire un valore del primo vettore\n");
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < MAX; i++) {
        printf("Inserire un valore del secondo vettore\n");
        scanf("%d", &arr2[i]);
    }
    int indArr3 = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr1[i] == arr2[j] && arr1[i] % 2 == 0) {
                arr3[indArr3] = arr1[i];
                indArr3++;
            }
        }
    }
    for (int i = 0; i < indArr3; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}