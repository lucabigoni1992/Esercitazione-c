/*

 E' dato un file di testo (SCHEDINA.TXT)
contenente un elenco di risultati per alcune partite di calcio.
Su ciascuna linea sono memorizzati il nome della squadra ospitante (max 20 caratteri),
il nome della squadra ospite (max 20 caratteri) e a seguire un valore (1, 0, o 2) per indicare rispettivamente
la vincita della squadra ospitante, il pareggio o la vittoria della squadra ospite. Si scriva un programma
C strutturato in (almeno due) funzioni dedicate rispettivamente a: leggere il contenuto del file e inserirlo
in una lista L, ordinata in senso decrescente in base al valore del risultato (2, 1, 0);

a partire da L, stampare sul file FUORICASA.TXT, solo i nomi delle squadre vincitrici fuori casa
(valore del risultato 2).  Esempio: Contenuto di SCHEDINA.TXT: Roma Perugia 1                                                          Milan Bologna 2          Nocerina Battipagliese 0                             Inter Juventus 2 Contenuto di FUORICASA.TXT:  Bologna         Juve
*/


#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>




typedef struct {
	char squadra1[20];
	char squadra2[20];
	int  res;
} el_type;
typedef struct nodo {
	el_type  value;

	struct nodo* next;

} NODO;
typedef NODO* list;
typedef enum {
	FALSE, TRUE
}  BOOLEAN;




list  emptylist();
bool  empty(list l);
el_type  head(list l);
list  tail(list l);
list  cons(el_type e, list l);
list ordins(el_type, list);

/* MAIN FILE */
#include <stdio.h> 
#include <stdlib.h>
list  crealista(FILE* f, list L);
void  creafile(FILE* f, list L);
void scrivifile(FILE* f, list L);
BOOLEAN isless(el_type, el_type);
void  main() {
	list  L = emptylist();
	el_type EL;
	FILE* f;
	/* DOMANDA a)  */    f = fopen("SCHEDINA.TXT", "rt");
	L = crealista(f, L);
	fclose(f);
	/* DOMANDA  b)  */    f = fopen("FUORICASA.TXT", "wt");
	scrivifile(f, L);
	fclose(f);
}
list  crealista(FILE* f, list L) {
	el_type EL;
	while (!feof(f)) {
		fscanf(f, "% s % s % d\n", EL.squadra1, EL.squadra2, &EL.res);
		/* INSERIMENTO NELLA LISTA */    L = ordins(EL, L);
	}
	return L;
}  

void  scrivifile(FILE* f, list L) {
	el_type EL;
	while (!empty(L)) {
		EL = head(L);
		if (EL.res == 2)        fprintf(f, "%s", EL.squadra2);
		L = tail(L);
	}

}

/* operatori esportabili */ 

list  emptylist() {
	return NULL;
};
bool  empty(list l) {
	return (l == NULL);
};
el_type  head(list l) { if (empty(l)) { abort(); } else  return(l->value); }

list  tail(list l) {
	if (empty(l)) {
		abort();
		return(0);
	}
	else {
		return (l->next);
	}
}  list  cons(el_type e, list l) {
	list t;
	t = (list)malloc(sizeof(NODO));
	t->value = e;
	t->next = l;
	return(t);
}
BOOLEAN isless(el_type e1, el_type e2) { 
	if (e1.res < e2.res) 
		return TRUE; 
	else 
		return FALSE; 
}
list ordins(el_type el, list l) {
	/* inserimento ordinato con        possibili duplicazioni */
	if (empty(l)) return(cons(el, l));

	else {
		if (FALSE ==isless(el, head(l))) 
			return(cons(el, l));
		else 
			return(cons(head(l), ordins(el, tail(l))));
	}
}