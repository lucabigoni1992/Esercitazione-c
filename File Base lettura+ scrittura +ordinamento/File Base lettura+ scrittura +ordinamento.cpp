#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>

#include<iostream>
#include<fstream>

using namespace std;


void OrdinaArray(int* p)
{
	int* ini = p;
	for (int* p1 = p; *p1 != -999; p1++)
		for (int* p2 = p; *p2 != -999; p2++)
			if (*p1 > *p2) {
				int tmp = *p1;
				*p1 = *p2;
				*p2 = tmp;
			}
	p = ini;
}
void SrivereFile(string nomeFile, int* p)
{
	ofstream FILE(nomeFile);//apriamo il flusso di lettura verso il file
	while (*p != -999) {
		FILE << *p; //<< servono per scrivere
		FILE << "\n"; //<< servono per scrivere
		p++;
	}
	FILE.close();//chiudo lettura
}
void LeggiFile(string nomeFile, int* vett)
{
	string a;
	int i = 0;
	ifstream FILE(nomeFile);//apriamo il flusso di lettura verso il file
	if (!FILE.is_open()) {
		cout << "errore" << endl;
		return;
	}
	while (FILE >> vett[i])//>> servono per leggere
	{
		i++;
	}
	vett[i] = -999;

	FILE.close();//chiudo lettura

}
/*

	string Leggi = "Pippo2.txt";
	string Scrivi= "Pippo2.txt";
*/
void leggiOrdinaScrivi(string Leggi, string Scrivi) {
	int arr2[1000];
	int* p2 = arr2;
	LeggiFile(Leggi, p2);
	OrdinaArray(p2);
	SrivereFile(Scrivi, p2);
}


int main() {
	string nomeFile = "Pippo.txt";
	int arr[] = { 1,3,4,5,6,1,2,3,4,4,4,-999 };
	int arr2[1000];
	int* p = arr;
	SrivereFile(nomeFile, p);
	int* p2 = arr2;
	LeggiFile(nomeFile, p2);

	while (*p2 != -999) {
		cout << *p2; //<< servono per scrivere	
		p2++;
	}
	p2 = arr2;
	OrdinaArray(p2);
	SrivereFile(nomeFile, p2);
	cout << endl;; //<< servono per scrivere	
	cout << endl;; //<< servono per scrivere	

	while (*p2 != -999) {
		cout << *p2 << endl;; //<< servono per scrivere	
		p2++;
	}

	string Leggi = "Pippo.txt";
	string Scrivi = "Pippo2.txt";

	leggiOrdinaScrivi(Leggi, Scrivi);
}