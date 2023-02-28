#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <stdlib.h>
#include <math.h>

struct Posizione {
	float latitudine;
	float longitudine;
};


void CalcolaMinimoEMassimo(int posLen, Posizione& minVal, Posizione* posizioni);
void CalcolDistanza(int posLen, float* distanza, Posizione* posizioni);

int main(int argc, char* argv[])
{
	printf("argc: %d", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	//poi i seguenti parametri, arriveranno da riga di comando
	Posizione posizioni[1000];
	posizioni[0] = { 0.12,0.13 };
	posizioni[1] = { 0.15987,0.15789 };
	posizioni[2] = { 0.95555,0.15789 };
	int posLen = 3;
	posizioni[3] = { 0.95555,0.25789 };//se aggiungo una posizione aumento posLen
	posLen++;// pos len si aumenta ogni volta che si aggiunge un elemento nel vettore,PosLen mi indica il numero gli elementi pesenti nel vettore
	posizioni[4] = { 0.95555,1.258 };//se aggiungo una posizione aumento posLen
	posLen++;// pos len si aumenta ogni volta che si aggiunge un elemento nel vetore,PosLen mi indica il numero gli elementi pesenti nel vettore
	Posizione minVal = posizioni[0];//vado a settare i minimi valori a un elemento, i valori esistono e se lo scorriamo dall'inizio posso considerarli come i minimi
	CalcolaMinimoEMassimo(posLen, minVal, posizioni);
	printf("\n\nLatitudine minima: %f\n", minVal.latitudine);
	printf("Longitudine minima: %f\n", minVal.longitudine);
	//andiamo a calcolra la lunghezza del percorso
	float distanza = 0;
	CalcolDistanza(posLen, &distanza, posizioni);
	printf("distanza: %f\n", distanza);

}


/*
REALE ->distanza (A,B) = R * arccos(sin(latA) * sin(latB) + cos(latA) * cos(latB) * cos(lonA-lonB))
PIANO CARTESIANO->distanza=sqrt((y1-y2)(y1-y2)+(x1-x2)(x1-x2));

*/
void CalcolDistanza(int posLen, float* distanza, Posizione* posizioni) {
	if (posLen <= 0) {
		distanza = 0;//do dei valori di default
	}
	else {//sltrimenti vado a calcolare
		//for (int i = 0; i < posLen; i++) =>errore se ho 4 punti devo fare 3 somme
		//distanza (p1 e p2)+ (p2 e p3) + (p3 ep4)
		for (int i = 0; i < posLen; i++) {
			float x1, x2, y1, y2;
			x1 = posizioni[i].latitudine;
			x2 = posizioni[i + 1].latitudine;
			y1 = posizioni[i].longitudine;
			y2 = posizioni[i + 1].longitudine;

			float distanza2p = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));//per semplicità usiamo pitagora e calcolo la distanza tra 2 punti
			*distanza += distanza2p;//sommiamo le varie distanze
		}
	}
}

void CalcolaMinimoEMassimo(int posLen, Posizione& minVal, Posizione* posizioni)
{
	if (posLen <= 0) {
		minVal = { 0,0 };//do dei valori di default
	}
	else {//sltrimenti vado a calcolare
		for (int i = 0; i < posLen; i++) {
			if (minVal.latitudine > posizioni[i].latitudine) {
				minVal.latitudine = posizioni[i].latitudine;
			}
			if (minVal.longitudine > posizioni[i].longitudine) {
				minVal.longitudine = posizioni[i].longitudine;
			}
		}
	}
}