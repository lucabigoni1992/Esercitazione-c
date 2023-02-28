#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h> 

float* CalcolaMedia(float* p, int  len) {

	float* inizio, * ris =(float*) malloc(sizeof(float) * len);//serve a riservare della memori della grandezza che gli passiamo all'interno in questo caso con la 
	inizio = ris;
	for (int i = 0; i < len; i++)
	{
		//abbiamo 3 casi
		//1:se sono all'inizio  ( media dell'attuale +successivo)  
		//2:se sono alla fine  ( media dell'attuale +precedente)    
		//3:altri casi (media attuale + precedente + successivo)
		if (i == 0)
			//mettiamo nella prima cella del vettore puntato da ris il contenuto di: la prima cella del vettore ( inserito dall'utente)+ la seconda cella / 2=media
			*ris = (*p + *(p + 1)) / 2;

		else if (i == len - 1)
			//mettiamo nell'ultima cella del vettore puntato da ris il contenuto di: l'ultima cella del vettore ( inserito dall'utente)+ la penultima cella / 2=media
			*ris = (*p + *(p - 1)) / 2;
		else
			*ris = (*p + *(p - 1) + *(p + 1)) / 3;

		//stampa per debug -> printf("\n  %f ", *ris);

		//scorriamo i puntamenti ai vettori
		ris++;
		p++;
	}
	return inizio;
}


int main()
{
	//float vet[] = { 1,2,3,4 }; //{ 1,2,3,4,56,8,7,5,151,51,51,51,5,5 };

	int len = 5;
	printf("\nInserisci il numero di valori da inserire  :\n");
	scanf("%d", &len);

	float* p = (float*)malloc(sizeof(float) * len);
	//sizeof andiamo a recuperare la grandezza del vettore originale
	//* ris è un puntatore alla prima cella di memoria del vettore che abbiamo istanziato con la malloc
	//la ricalcoliamo per vedere come la possiamo recuperare dinamicamente
	// nel caso si usasse il vettore -> int lenVetUtente = (sizeof(vet) ) / sizeof(float);//lunghezza del vettore diviso lunghezza occupata da un singolo float
	int lenVetUtente = (sizeof(float) * len) / sizeof(float);//lunghezza del vettore diviso lunghezza occupata da un singolo float

	for (int i = 0; i < len; i++)
	{
		printf("Inserisci il valore n %d :", i);
		scanf("%f", (p + i));
	}

	float* inizioRisultato = CalcolaMedia(p, len);

	for (int i = 0; i < len; i++)//la ricalcolo per vedere come si usa  (sizeof(float) * len) / sizeof(float)-> trova la lunghezza
	{
		printf("\n  %f ", *(inizioRisultato + i));
	}
}