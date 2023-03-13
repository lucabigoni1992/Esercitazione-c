/*
Dichiarare due variabili intere, e due puntatori coerenti.
Puntare a tali variabili,
quindi verificare che i due indirizzi sono differenti fra loro,
mediante un semplice confronto fra i puntatori .
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Un puntatore è una variabile che contiene l'indirizzo di memoria di un'altra variabile.
	//L'asterisco (*) viene chiamato operatore di indirezione o deferenziazione e restituisce il contenuto dell'oggetto puntato dal puntatore;
	//mentre l'operatore "e commerciale" (&) restituisce l'indirizzo della variabile

	//quando si dichiara in puntatatore si mette lo star per indicare che è un puntatore
	//quando gli si da un indirizzo (assegnamo un puntamento) non gli va dato lo star
	//quando vogliamo prender eil valore puntato da un puntatore gli si da uno star

	int a = 4;
	int* P;//PUNTATORE PUNTA SEMPRE ALLA PRIMA CELLA DI MEMORIA DI UNA VARIABILE 
	//P => ha un assegnazione di un indirizzo, in questo caso l'indirizzo di a
	P = &a;//&a-> indica l'indirizzo della cella di memoria di a e P 
	printf("Puntatore : %p  :insirizzo di A : %p \n", P, &a);
	printf("Puntatore Val : %d  :valore di A : %d \n", *P, a);
	*P = 5;//si modifica il contenuto puntato da p quindi si modifica a
	printf("Puntatore Val : %d  :valore di A : %d \n", *P, a);

	int b = 25;
	int c = 0;
	//*P => valore puntato da p
	*P = b + c;//qua non si modifica ne P NE B NE C  ma si modifica la cella di memoria puntata da P,quindi A
	printf("Puntatore Val : %d  :valore di A : %d - valore di b : %d  - valore di C : %d \n", *P, a, b, c);


	 int x = 994589, y = 9999, *p;
	p = &y;
	p = &x;
	*p = y;

	printf("Puntatore Val : %d  :indirizzo : %p  \n", *p, p);
	printf("x Val : %d  :ind di x: %p  \n", x, &x);
	printf("y Val : %d  :ind di y: %p  \n", y, &y);
	int* p2;
	p2 = &x;
	*p = 78;//p e p2 puntano entrambe a x, quindi se modifico una delle due modifico il valore puntato da entrambe
	printf("Puntatore P  Val : %d  :IND PUNTATO: %p  \n", *p, p);
	printf("Puntatore P2 Val : %d  :IND PUNTATO: %p  \n", *p2, p2);
	printf("x Val : %d  :ind di x: %p  \n", x, &x);
	printf("y Val : %d  :ind di y: %p  \n", y, &y);



	float x2 = 1, y2 = 1, * p3;
	p3 = &x2;
	printf("*p3: %f  \n", *p3);
	printf("p3: %p  \n", p3);


	return 0;
}