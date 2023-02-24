/*
Leggere da tastiera N (0<N≤400) numeri interi,
contare e visualizzare quanti sono i numeri positivi e di questi calcolare e visualizzare la somma,
contare e visualizzare quanti sono i numeri negativi e di questi calcolare e visualizzare la somma

una funzione serve per fare una volta solamente un operazione senza doverla scrivere più volte
*/
#include <iostream>
using namespace std;

int PariODispari(int numero) {
	if (numero % 2 == 0) {
		cout << "il numero e' pari " << numero << endl;
		return 1;
	}
	else {
		cout << "il numero e' dispari " << numero << endl;
		return 0;
	}
}

int main()
{
	int n = 0;
	int numero = 0, sommaPari = 0, sommaDispari = 0;
	do {
		cout << "Inserisci un valore N (0<N≤400)" << endl;
		cin >> n;
	} while (!(n > 0 && n <= 400));//quando non è in questo
	for (int i = 0; i < n; i++) {
		cout << "Inserisci il " << i+1 << " valore: " << endl;
		cin >> numero;
		if (PariODispari(numero) == 1) {
			sommaPari = sommaPari + numero;
		}
		else {
			sommaDispari = sommaDispari + numero;
		}
	}
	cout << "la somma dei Pari    :" << sommaPari << endl;
	cout << "la somma dei Dispari :" << sommaDispari << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
