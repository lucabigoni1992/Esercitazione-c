// Conversione Decimale-Binario su un numero fisso di bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Scrivere un programma in linguaggio C che converta un numero decimale D in un numero binario rappresentato su N bit.
L’utente inserisce un numero decimale intero positivo D e il numero N di bit su cui il numero decimale deve essere rappresentata.
Il programma visualizzerà i bit che compongono il numero binario partendo dal bit meno significativo.
Il programma segnalerà un errore se il numero N di bit inserito dall’utente non è sufficiente per rappresentare il numero decimale.
Suggerimento. Per effettuare la conversione usare il metodo delle divisioni successive. Ad esempio, per convertire il numero decimale D=19 su N=7 bit, si avrà:
Numero	    | Resto	    |Cifra binaria |Peso
19	        |1(19%2)   |   1          | 0
9 (19/2)	|1 (9%2)    |   1	       | 1
4 (9/2)    	|0 (4%2) 	|   0	       | 2
2 (4/2) 	|0 (2%2) 	|   0	       | 3
1 (2/2)	    |1 (1%2) 	|   1	       | 4
0 (1/2)	    |0 (0%2) 	|   0	       | 5
0 (0/2)	    |0 (0%2) 	|   0	       | 6
Nota: nell’applicazione del metodo delle divisioni successive, l’iterazione termina quando è stato assegnato un valore a ciascuno degli N bit.

*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#define BASE 2
int main(void)
{
	int numero_decimale;	/* numero decimale */
	int N;	/* numero di cifre binarie */
	int bit;	/* cifra binaria */
	int num_bits;	/* contatore per scandire le cifre binarie */
	/* LEGGI IL NUMERO DECIMALE */
	printf("Inserire il numero decimale da convertire:");
	scanf("%d", &numero_decimale);
	/* LEGGI IL NUMERO DI BIT */ printf("Inserisci il numero di bit: ");
	scanf("%d", &N);
	/* VERIFICA CHE IL NUMERO DI BIT SIA SUFFICIENTE PER RAPPRESENTARE IL NUMERO DECIMALE */
	if (pow(BASE, N) - 1 < numero_decimale)
		printf("Errore: il numero di bit e’ insufficiente\n");
	else {
		/* INIZIALIZZA "num_bits" A 0 */ num_bits = 0;

		/* IL CICLO CALCOLA LE CIFRE BINARIE PER RAPPRESENTARE IL NUMERO DECIMALE, PARTENDO DALLA CIFRA BINARIA MENO SIGNIFICATIVA (LSB) */
		while (num_bits < N)
		{
			/* CALCOLA LA CIFRA BINARIA DI PESO "num_bits" */
			bit = numero_decimale % BASE;
			/* CALCOLA IL NUMERO DECIMALE DA DIVIDERE PER "dividendo"
			ALLA PROSSIMA ESECUZIONE DEL CICLO */
			numero_decimale = numero_decimale / BASE;
			/* STAMPA IL RISULTATO */
			printf("Cifrabinaria di peso 2^%d: %d\n", num_bits, bit);

			/* INCREMENTA IL CONTATORE "num_bits" */
			num_bits = num_bits + 1;
		}
	}return(0);

}
