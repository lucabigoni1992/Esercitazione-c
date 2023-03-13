// Vettori Rimpimento min  mx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>

using namespace std;
int main()
{
	int vet[500];//creo vettore lunto massimo 500  gli indici banno da 0 a 499
	int nInseriti;
	printf( "Quanti numeri vuoi inserire?  [0-499] \n");
	scanf ("%d", nInseriti);
	if (nInseriti > 499 || nInseriti < 0) {

		//l'indice non piò esere > della dimensione -1 e non può essere un valore negativo
		printf("Errore Indice non valido \n" );
		return -1;
	}
	for (int i = 0; i < nInseriti; i++) {//i mi scorre le posizioni e mi va 0  a nInseriti
		printf("inserisci la Pos '%d' :  " , i  );
		cin >> vet[i];//ogni elemento andra alla posizione ì  che cambia nel tempo
	}
	//stampo
	for (int i = 0; i < nInseriti; i++) 
		printf("alla pos '%d' ho il valore %d \n",i ,vet[i]);
	int min = vet[0];//inizializzo la varabile min con il valore della prima cella del vettore
	for (int i = 0; i < nInseriti; i++) {
		if (vet[i] < min) {
			min = vet[i];
		}
	}		
	printf("\nil valore piu' piccolo e': %d  \n\n",min);
	int max = vet[0];
	for (int i = 0; i < nInseriti; i++)
	{
		if (vet[i] > max) {
			max = vet[i];
		}
	}
	printf("\nil valore piu' grande e': %d  \n", max);
	int somma = vet[0];
	for (int i = 1; i < nInseriti; i++) {//essendo somma = al primo valore  possiamo partire dalla 2° cella
		somma = somma + vet[i];

	}
	printf("\nla somma e': %d  \n", somma);
	printf("la media e': %d  \n", somma/nInseriti);
}
