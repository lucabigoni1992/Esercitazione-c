
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void swap(int* apt, int* bpt);

int main()
{
	int alfa = 5;
	int beta = 13;

	printf("alfa -> %d, beta -> %dn", alfa, beta);

	swap(&alfa, &beta);

	printf("alfa -> %d, beta -> %dn", alfa, beta);
}

void swap(int* apt, int* bpt)
{
	int temp;
	temp = *apt;
	*apt = *bpt;
	*bpt = temp;
}
