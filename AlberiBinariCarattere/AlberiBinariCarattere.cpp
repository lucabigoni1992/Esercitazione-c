
/* preso un testo da un file andare a inserire i caratteri (accettare solo i caratteri minuscoli)
di quel testo all'interno du un albero binario di ricerca,
calcolare la frequenza delle lettere(la frequenza indica qunte volte una lettera è presente all'interno dell'albero

restiuiamo i 5 caratteri più frequenti all'interno di una lista
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

typedef struct Nodo {
	int frequenza;
	char carattere;
	struct Nodo* l, * r;
}*pNodo, nodo;

bool isEmpty(pNodo nodo) {
	return nodo == NULL;
}
bool isCharacterMinor(const pNodo& nodo, char cr)
{
	return nodo->carattere < cr;
}
bool isCharacterMajor(const pNodo& nodo, char cr)
{
	return nodo->carattere > cr;
}
bool isEqual(pNodo nodo, char el) {
	return nodo->carattere == el;
}
pNodo UnisciNode(char el, int fr, pNodo t1, pNodo t2) {
	//malloc si crea una nuova zona di memori
	//della dimensione della sizeof(pNodo)
	pNodo p = (pNodo)malloc(sizeof(pNodo));
	p->l = t1;
	p->r = t2;
	p->carattere = el;
	p->frequenza = fr;
	return p;
}
pNodo createElem(char el, int occ) {
	return UnisciNode(el, occ, NULL, NULL);
}
pNodo rigthNode(pNodo n) {
	return n->r;
}
pNodo lefthNode(pNodo n) {
	return n->l;
}
int getFr(pNodo n) {
	return n->frequenza;
}
char getCr(pNodo n) {
	return n->carattere;
}
void InsertIntoArray(pNodo n, pNodo albero, int occ) {

	int min = n[0].frequenza;
	int i = 0;
	for (int j= 0; j < occ; j++) {
		if (n[j].frequenza < min) {
			min = albero->frequenza;
			i = j;
		}
	}

		if (n[i].frequenza < albero->frequenza) {
			n[i].carattere = albero->carattere;
			n[i].frequenza = albero->frequenza;
			return;
		}
	}


void PiuFrequenti(pNodo minimi, pNodo albero) {
	if (isEmpty(albero) == false) {
		PiuFrequenti(minimi, lefthNode(albero));
		InsertIntoArray(minimi, albero, 5);
		PiuFrequenti(minimi, rigthNode(albero));
	}
}
pNodo insert(char cr, pNodo nodo) {
	//caso base dove usciamo e finiamo la ricorsione
	if (isEmpty(nodo)) {
		//sezione inserimento
		return createElem(cr, 1);
	}
	else {
		if (isEqual(nodo, cr)) {
			nodo->frequenza++;
			return nodo;
		}
		if (isCharacterMajor(nodo, cr))
		{//ramo sx
			return UnisciNode(nodo->carattere,nodo->frequenza,  insert(cr, lefthNode(nodo)), rigthNode(nodo));
		}
		if (isCharacterMinor(nodo, cr)) {//ramo dx
			return UnisciNode(nodo->carattere,nodo->frequenza,  lefthNode(nodo), insert(cr, rigthNode(nodo)));
		}
	}
	// se ho trovato il carattere aumento la frequenza

	//altrimenti lo metto a dx o sx a seconda del loro ordine alfabetico
}

void showtree(pNodo t) {
	int i;

	if (isEmpty(t) == false) {
		showtree(lefthNode(t));
		printf("Valore :%c  trovato:%d \n", t->carattere, t->frequenza);
		showtree(rigthNode(t));
	}
}

int main() {
	FILE* pfile;
	cout << "Programma avviato" << endl;
	cout << "[Fase 1] apro il file..." << endl;
	if ((pfile = fopen("Text.txt", "r")) == NULL)
	{
		cout << "Errore Apertura 'File'" << endl;
		return -1;
	}
	cout << "[Fase 2] carico il file..." << endl;
	char carattere = 0;
	pNodo albero = NULL;//ROOT
	//EOF-> end of file
	//si va avanti fino alla fine del file
	while (fscanf(pfile, "%c", &carattere) != EOF) {
		if (carattere >= 'a' && carattere <= 'z')
			albero = insert(carattere, albero);
	}
	showtree(albero);
	cout << "[Fase 5] Inizio calcolo dei 5 piu' frequenti..." << endl;
	nodo minimi[5];
	for (int i = 0; i < 5; i++)
		minimi[i].frequenza = 0;
	PiuFrequenti(minimi, albero);
	cout << "[Fase 6] Stampa dei 5 piu' frequenti..." << endl;
	for (int i = 0; i < 5; i++)
		cout << " \t Trovato :" << minimi[i].carattere << endl;


}