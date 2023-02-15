// Costanti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    /*
Una costante rappresenta un'area della memoria RAM nella quale è memorizzato un preciso valore che non può viene modificato durante l'esecuzione del programma. (ad esempio: PiGreco=3,14)
Il C prevede quattro tipi di costanti:

intere
in virgola mobile
caratteri
stringhe di caratteri

In C le costanti si definiscono in due modi, attraverso:

la parola chiave const;
la direttiva #define.

*/

 const float PiGreco = 3.14;  //(costante in virgola mobile)
const char C = 'x';// (costante carattere)
const int base = 6;// (costante intera)
const char saluto[5] = "ciao"; //(costante stringa, in questo caso può contenere al massimo 4 caratteri)

#define PiGreco 3.14
#define C 'x'
#define base 6
#define saluto ciao
}
