/*
Due file (binari) (F1.DAT ed F2.DAT) contengono dati rappresentanti i codici e la quantità dei prodotti
di due magazzini. Ogni codice è una stringa di 6 caratteri, mentre la quantità è un valore intero.
Lo stesso codice può comparire in entrambi i file, ma compare una sola volta all'interno di ciascun file.
Si scriva un programma C che: Crei due liste, L1 e L2,  dei prodotti (codici e quantità) rispettivamente
di F1.DAT ed F2.DAT comuni ai due file. Creare le liste in modo che siano ordinate sulla base del valore
del campo quantità. A partire da L1 ed L2 produca un file binario (COMUNI.DAT) in cui ogni prodotto comune
è scritto una sola volta insieme alla quantità complessiva dei due magazzini;

Attraverso una procedura iterativa, stampi a terminale i codici dei prodotti di L1 presenti in magazzino
in quantità maggiore di una quantità letta a terminale.  È possibile utilizzare librerie C
(ad esempio per stringhe). Qualunque libreria utente utilizzata va riportata nello svolgimento
*/

/* PROGRAMMA PRINCIPALE */


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char codice[6];
	int quantita;
} element_type;
typedef enum {
	FALSE,
	FRUE
};
bool;
typedef struct list_element {
	element_type         value;
	struct list_element* next;
} item;
typedef  item* list;
/* PROTOTIPI */ bool isequal(element_type, element_type);
bool isless(element_type, element_type);
void showel(element_type);
list ordins(element_type, list);
element_type member(element_type, list);
void main(void) {
	element_type prodotto1, prodotto2, prodotto;
	list  L1, L2, L;
	FILE* f1, * f2, * f3;
	bool trovato;
	int qty;
	L1 = NULL;
	L2 = NULL;
	f1 = fopen("F1.DAT", "rb");
	f2 = fopen("F2.DAT", "rb");
	/*  creazione liste prodotti  */
	while (fread(&prodotto1, sizeof(element_type), 1, f1) != 0) {
		rewind(f2);
		trovato = false;
		while ((fread(&prodotto2, sizeof(element_type), 1, f2) != 0)
			&& !trovato)
		{
			if (isequal(prodotto1, prodotto2)) {
				trovato = true;
				L1 = ordins(prodotto1, L1);
				L2 = ordins(prodotto2, L2);
			}
		}
	} fclose(f1);
	fclose(f2);
	L = L1;
	f3 = fopen("COMUNI.DAT", "wb");
	/* i codici nelle due liste sono gli     stessi ma non nello stesso ordine */ while (!(L == NULL)) {
		strcpy(prodotto.codice, (L->value).codice);
		prodotto2 = member(L->value, L2);
		prodotto.quantita = (L->value).quantita + prodotto2.quantita;
		fwrite(&prodotto, sizeof(element_type), 1, f3);
		L = L->next;
	} fclose(f3);
	printf("Quantita minima? ");
	scanf("%d", &qty);
	while (!(L1 == NULL)) {
		if ((L1->value).quantita > qty)       showel(L->value);
		L1 = L1->next;
	}
}   /* FUNZIONI AUSILIARIE */
bool isequal(element_type e1, element_type e2)    /*  uguaglianza sul codice  */ {
	return (strcmp(e1.codice, e2.codice) == 0);
}  bool isless(element_type e1, element_type e2)  /* relazione d'ordine sulla quantita  */ {
	return  (e1.quantita < e2.quantita);
}  void showel(element_type e) {
	printf("%s\t%d\n", e.codice, e.quantita);
}

list ordins(element_type el, list root) {
	element_type  e;
	int trovato = 0;
	list aux, prec, current;
	/* inserimento ordinato con        possibili duplicazioni */
	aux = (list)malloc(sizeof(struct list_element));
	aux->value = el;
	aux->next = NULL;
	if (root == NULL)    /* primo elemento */        root = aux;
	else {
		current = root;
		while ((current != NULL) && !trovato) {
			if (isless(current->value, el)) {
				prec = current;
				current = current->next;
			}
			else trovato = 1;
		}      if (current == NULL) {
			prec->next = aux;
		}   /*in fondo */     else           if (current == root) {
			aux->next = root;
			root = aux;
		}    /* in testa */          else {
			prec->next = aux;
			/* inserisce in mezzo */               aux->next = current;
		}
	}
	return root;
}
element_type member(element_type el, list l)
/* ricerca - iterativa       si suppone che l'elemento esista      e venga restituito dalla funzione  */
{
	while (!(l == NULL)) {
		if (isequal(el, l->value))                        return(l->value);
		else  l = l->next;
	}
}