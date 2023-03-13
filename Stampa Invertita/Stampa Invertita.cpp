/*
Scrivere un programma che prenda in input una stringa (lunga al pi`u 20) con getchar,
la copi invertita in una variabile e stampi tale variabile.
*/
#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#define INPUT_SIZE 21
int main() {
	int ch;
	char s1[INPUT_SIZE];
	char s2[INPUT_SIZE];
	int i = 0, j = 0;
	while (((ch = getchar()) != EOF) && (i < INPUT_SIZE - 1)) {
		s1[i] = ch;
		i++;
	}
	s1[i] = '\0';
	for (j = 0; j < i; j++) {
		s2[j] = s1[i - 1 - j];
	} s2[i] = '\0';
	printf("\n%s\n", s2);
}