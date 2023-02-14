// Variabili.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
   /*
   Ad una variabile viene dato un nome univoco
   Ci sono alcune parole  che non possono essere utilizzate dal programmatore :char; int; float; long; double; short; signed; unsigned; enum; const; default; auto; break; continue; switch; case; while; do; for; if; else; goto; return; extern; register; static; sizeof; struct; typedef; union; void; volatile.
 E' consigliabile dare alle variabili nomi sensat
 Tipi di dichiarazione	Rappresentazione	   N.di byte
        char	            Carattere	            1 (8 bit)
        int	                Numero intero	        2 (16 bit) *
        short             	Numero intero "corto"	2 (16 bit)
        long            	Numero intero "lungo"	4 (32 bit)
        float           	Numero reale	        4 (32 bit)
        double	            Numero reale "lungo"	8 (64 bit)
        */

    //Il tipo int permette di rappresentare numeri interi. Possiamo dichiarare un int con due varianti: short e long,
    int a;
   // Il tipo char può contenere qualsiasi carattere definito secondo lo standard ASCII, quindi qualsiasi lettera(maiuscola o minuscola), cifra(da 0 a 9) e simbolo previsto dalla codifica.
    char a='a';
    //I tipi float e double sono i cosiddetti numeri in virgola mobile, che rappresentano l'insieme dei numeri reali
   // La differenza tra i due sta nel numero di bit riservati alla rappresentazione dei numeri, che si va a riflettere sul range di numeri e sul numero di cifre dopo la virgola che possiamo memorizzare.
    double x = 7.0;
    float y = 6.3;

}

