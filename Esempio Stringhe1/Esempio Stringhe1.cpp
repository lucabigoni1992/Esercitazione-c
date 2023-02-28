#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h>
#define SSIZE 20
#define INPUTSIZE 10
int min(int, int);
int main(void)
{
	char* s0; char* s1;
	char s2[SSIZE];
	char s3[SSIZE] = { 'a','r','r','a','y','\0' };
	char s4[SSIZE];
	int i = 0;
	int ch;
	printf("%p\n", "ciao");
	/*ciao e'una stringa(puntatore a una sequenza di caratteri terminatada \0) che viene piazzata nella memoria
	gia'inizializzata del programma Gli array sono puntatori,sesono terminati daun carattere nullo sono quindi anche
	stringhe*/
	s0 = s3;
	printf("%p-%p||%s-%s\n", s0, s3, s0, s3);
	/*Possiamoprendereilpuntatoreal3carattere*/
	s0 = &s3[2];
	printf("%p-%p||%s-%s\n", s0, s3, s0, s3);
	/*Chee'lastessacosadi*/
	printf("%d\n", &s3[2] == s3 + 2);
	s0 = (char* )"prova";
	s1 = (char*)"ciaociao";
	printf("%p-%p\n", s0, s1);
	printf("%ld\n", s1 - s0);
	/*Stampa 6 perche' len(prova)=5ma  viene aggiunto il carattere nullo al termine.Prendiamo due stringhe da
	input usando solo la funzione getchar notare che getchar prende anche gli accapo come caratteri*/
	while ((ch = getchar()) != EOF && i < SSIZE - INPUTSIZE - 1)
	{
		s2[i] = ch;
		/**(s2+i)=ch*//*alternativa*/
		i++;
	}
	s2[SSIZE - INPUTSIZE - 1] = 0;
	printf("\n");
	/*s2e'oraunastringaperche's2[SSIZE-INPUTSIZE-1]e' ilcaratterenullo*/
	printf("Haiinserito:%s\n", s2);
	/*Concateniamos2eds3nellospaziocheabbiamo*/
	int min;
	if (strlen(s2) < strlen(s3)) {
		min = strlen(s2);
	}
	else {
		min = strlen(s3);
	}
	strncat(s2, s3, min);
	printf("%s\n", s2); /*Compariamos2eds3*/
	printf("Risultatocomparazionedi%sed%s:%d\n", s2, s3, strcmp(s2, s3));
	printf("%lu\n", strlen(s4));
	/*Questo valore non si puo' predire,infatti le variabi li locali non vengono inizializzate e quindi il
	loro contenuto puo'essere zero omeno,posso anche ottenere un segmentation fault perche' se non trova nessuno
	zero chela fermila funzione strl e non puo' andare a leggere una porzione di memoria che non e'concesso leggere*/
	return 0;
}