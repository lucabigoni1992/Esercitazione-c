/*
In un concorso di intelligenza, N giudici esprimono il loro giudizio su K candidati. 
Il giudizio è un valore numerico tra 0 e 5.
Si scriva un programma in linguaggio C per determinare il candidato più intelligente, ed il giudice più severo.
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAXK 100 /* max n. candidati */
#define MAXN 10 /* max n. giudici */
int main(void)
{
	int voti[MAXK][MAXN];
	int tot[MAXK]; /* somma dei voti per ogni candidato */ int totg[MAXN]; /* somma dei voti di ogni giudice */ int K, N; int i, j;
	int min, max, posmin, posmax;

	printf("Quanticandidati ci sono? "); scanf("%d", &K);
	printf("Quantigiudici ci sono? ");
	scanf("%d", &N);
	for (i = 0; i < K; i++)
	{
		printf("Immettere i giudizi per il candidato%d\n", i + 1);

		for (j = 0; j < N; j++)
		{
			printf("Giudice %d, cosa pensi del candidato %d? ", j + 1, i + 1);
			scanf("%d", &voti[i][j]);
		}
	}
	for (i = 0; i < K; i++) tot[i] = 0;
	for (j = 0; j < N; j++) totg[j] = 0;
	for (i = 0; i < K; i++) {
		/* già fatto tot[i] = 0 ; */
		for (j = 0; j < N; j++)
		{
			tot[i] = tot[i] + voti[i][j]; totg[j] = totg[j] + voti[i][j];
		}
	}
	max = tot[0]; posmax = 0; for (i = 1; i < K; i++)
	{
		if (tot[i] > max)
		{
			max = tot[i]; posmax = i;
		}
	}
	printf("Il vincitore e' il candidato numero %d\n", posmax + 1);
	min = totg[0]; posmin = 0; for (i = 1; i < N; i++)
	{
		if (totg[i] < min)
		{
			min = totg[i]; posmin = i;
		}
	}
	printf("Ilgiudice piu' severo e' il numero %d\n", posmin + 1);
	return(0);
}
