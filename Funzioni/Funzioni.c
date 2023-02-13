#include <stdio.h>

/*prototipo->firma della funzione
<cosa si restituisce> il nome della funzione (<tipo parametro> nomeParametro... );
void se non si resttuisce niente come nel caso della stampa
*/
int Moltiplicazione(int Add1, int Add2);
void StampaMoltiplicazione(int Add1, int Add2,int ris);

//argc = n° Parametri in ingresso
//argv = i parametri che c'arrivano  ogni programma ha almeno un parametro, "path in cui si trova l'eseguibile"

int main(int argc,char *argv[])
{
/*	for (int i = 0; i < argc; i++) {
		printf("argc[%d] ='%s'\n",i,argv[i]);
	}*/
	int n1 = 4,n2 = 6,somma=0;
	//voglio ottenere la moltiplicazione di n1 *n2 sommando n2volte il valore di n1
	//4*6=24  4+4+4+4+4+4
	for (int i = 0; i < n2; i++) {
		somma = somma + n1;
	}
	StampaMoltiplicazione(n1, n2, somma);
	int somma2 = Moltiplicazione(n1, n2);
	StampaMoltiplicazione(n1, n2, somma2);
}
/*qua scriviamo il codice della funzione*/

void StampaMoltiplicazione(int Add1, int Add2, int ris) {
	printf("la moltiplicazione(fz) di %d * %d = %d", Add1, Add2, ris);
}

int Moltiplicazione(int Add1, int Add2) {
	int somma = 0;
	for (int i = 0; i < Add2; i++) {
		somma = somma + Add1;
	}
	return somma;///quello che viene restituito dalla return deve essere del solito tipo che è nel nome della funzione
}