#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
int ricercadicotomica(int a[], int n, int sx, int dx);
int main() {
	int a[] = { 1,3,5,7,9 };
	int i; int res;
	for (i = 0; i < 10; i++)
	{
		res = ricercadicotomica(a, i, 0, 4);
		if (res >= 0)
			printf("Valore%dpresenteinposizione%d\n", i, res);
		else printf("Valore%dnonpresente\n", i);
	}
}
int ricercadicotomica(int a[], int n, int sx, int dx)
{
	int mid;
	if (sx == dx)
		if (a[sx] == n)
			return sx; else return-1;
	else {
		mid = (sx + dx) / 2;
		if (a[mid] == n)
			return mid;
		else
			if (a[mid] > n)
				return ricercadicotomica(a, n, sx, mid);
			else
				return ricercadicotomica(a, n, mid + 1, dx);
	}
}