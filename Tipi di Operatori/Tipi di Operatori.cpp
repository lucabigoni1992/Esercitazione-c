// Tipi di Operatori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE

int main()
{
	//Gli operatori permettono di ottenere un determinato risultato da un'operazione
   /*
	Operatore unario, binario, ternario in C
		Un operatore si dice unario quando ha questa sintassi :

	<operando><operatore>

		Si dice binario quando presenta questa sintassi :

	<operando1><operatore><operando2>

		Invece, si dice ternario quando ha questa sintassi :

	<operando1><simbolo><operando2><simbolo><operando3>

	+ (somma) – addiziona due operandi e concatena due stringhe
	– (differenza) -sottrae il secondo operando dal primo
	/ (divisione) – divide il primo operando per il secondo.
	* (moltiplicazione) – moltiplica i due operandi.
	% (resto – operatore modulo) – restituisce il resto della divisione tra due operandi.
	*/
	int addendo1 = 3, addendo2 = 4;
	int somma = addendo1 + addendo2;
	addendo1++;//incremento di 1
	addendo1--;//decremento di uno
	int risAumento = addendo1++; //Quindi, prima si assegna il valore di x a y e poi si incrementa la x.
	int risAumento2 = ++addendo1;// Prima si incrementa il valore di x e poi si assenga ad y.


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
