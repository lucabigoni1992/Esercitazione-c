
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
/// <summary>
/// Esempio Passaggio per valore perchè andiamoa copiare i valori che sono presenti nel main
/// </summary>
/// <param name="vet"></param>
/// <param name="lung"></param>
/// <returns></returns>
int sommaArr(int vet[], int lung) {
	int somma = 0;
	for (int i = 0; i < lung; i++) {
		somma += vet[i];
	}
	return somma;
}
int sommaArr2(int vet[], int lung) {
	int somma = 0;
	for (int* p = vet; p < (vet + lung); p++) {
		somma += *p;
	}
	return somma;
}

void sommaArr3(int vet[], int lung, int* somma) {//qua si restituisce il valore in un puntatore (quindi nlla variabile del main)
	*somma = 0;
	for (int* p = vet; p < (vet + lung); p++) {
		*somma += *p;
	}
}


void sommaArr4(int* vet, int lung, int* somma) {//come il precedente ma si punta all'array del main scorrendo come un puntatatore
	*somma = 0;
	for (int* inizio = vet; inizio < (vet + lung); inizio++) {
		*somma += *inizio;
	}
}
/// <summary>
/// qua non viene restituito un array ma si modifica direttamente l'arry passato dal main 
/// </summary>
/// <param name="v"></param>
/// <param name="n"></param>
void bubbleSort(int* v, int n)
{
	int* p, s, t;
	do
	{
		s = 0;
		//imposto al primo indirizzo, del primo elmento dell'array
		for (p = v; p < (v + n - 1); p++)//(v+n-1) l'ultimo indirizzo dell'array
			//p++ scorro gli elementi
			if (*p > *(p + 1)) { // scambio elementi
				t = *p;//*p verrà sovrascritto quindi mi salvo in contenuto in t
				*p = *(p + 1);
				*(p + 1) = t;//metto l'elemento salavato nella variabile successiva
				s++;//dico che ho trovato almeno unoscambio
			}
	} while (s > 0);//vado avanti fino a quando c'è almeno un' elemento da scambiare
}
//int vet[10]
//int * p=vet// è come puntare alla prima cella dell'array
//se io passso dalla funzione del main vet implicitamente passo l'indi della prima cella di memoria del vettore
//ricordo che scrive int *p= vet è uguale a scrivere int *p1=&vet[0] quindi vet=&vet[0] sono la solita cosa

void stampa(int* vet, int n) {
	for (int* p = vet; p < (vet + n); p++) {
		printf(" vet[%d] indirizzo: %p valore: %d \n", p - vet, p, *p);
	}
}

void SommaATuttiGliElementi(int* vet, int n, int add) {
	for (int* p = vet; p < (vet + n); p++) {//mi ciclo tutto il vettore con il puntatore p partendo alla 1° cella di memoria
		*p = *p + add;//sommo all'array dichiarato fuori (nel nostro caso nel main) il valore presente in ADD
	}
}
//by slide 
int lunghezza(char* s) {
	char* p = s;//puntiamo al primo elemento della stringa puntata da s
	while (*p != '\0')
		p++;
	return	(p - s);//differenza ta il punto iniziale e il valore a cui sono arrivato
}


int main()
{
	int vet[] = { -91,2,-332,42,5,16,71,28,9,30 };
	int somma = 0;
	somma = sommaArr(vet, 10);
	printf("Somma es no puntatori : %d \n", somma);
	somma = sommaArr2(vet, 10);//qua ci viene restituita una copia del valore all'interno della funzione
	printf("Somma es1 puntatori : %d \n", somma);
	sommaArr3(vet, 10, &somma);//qua si passa l'indirizzo della cella di memoria che vogliamo ci venga modificata
	printf("Somma es2 puntatori : %d \n", somma);
	sommaArr4(vet, 10, &somma);
	printf("Somma es3 puntatori : %d \n", somma);
	bubbleSort(vet, 10);//passo un array non ordinato e il medesimo array mi viene ritornato ordinato
	stampa(vet, 10);
	SommaATuttiGliElementi(vet, 10, 15);//voglio che ogni cella divet sia aumenta di 15
	printf("\nDopo la Somma \n");

	//la media con i puntattori  media(vet, lung, &media)= la media deve essere tornata nella variabile media es sommaArr4

	//stampare un vettore all'incontrario(vet, lung) 

	stampa(vet, 10);
	char str[] = { 'c','i','a','o','\0' };//stringa ultimo carattere =\0

	//contare il numero delle 'c' nel vettore, ritornare il visultato per riferimento(str, lung,'c', &numerodiVolte) 


	printf("il vettore e' lungo:%d", lunghezza(str));

}