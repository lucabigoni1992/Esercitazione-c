/*
dato un file legge i numeri nel file,
aggiungerli a un albero binario
poi vedere quanto quest'albero è profondo al massimo (distanza massima tra radice e la foglia più lontana)
tutti i valori nell'albero binario in ordine crescnte, per ogni valore dire qunte volte è presente nel file e la sua profondità
Es
Se il file contiene i seguenti elementi :
1
2
3
55
-9
4
8
7
12
19

il risultato sarà:
l'altezza massima e': 7

Valore: -9  trovato: 1 profondita': 1
Valore: 1  trovato: 1 profondita': 0
Valore: 2  trovato: 1 profondita': 1
Valore: 3  trovato: 1 profondita': 2
Valore: 4  trovato: 1 profondita': 4
Valore: 7  trovato: 1 profondita': 6
Valore: 8  trovato: 1 profondita': 5
Valore: 12  trovato: 1 profondita': 6
Valore: 19  trovato: 1 profondita': 7
Valore: 55  trovato: 1 profondita': 3
*/
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

FILE* intfile;

typedef struct T { // Comincio a definire la struttura che mi servirà
    int value; // Come posso notare ho il valore attuale e due puntatori: uno al
    int Occorrenza;
    // figlio sinistro
    struct T* T_l, * T_r; // E l'altro al figlio destro
} *tree, dim;

tree mergetree(int el, int occ, tree t1, tree t2) { // Mergetree unisce due alberi
    tree t0 = (tree)malloc(sizeof(dim));
    t0->T_l = t1;
    t0->T_r = t2;
    t0->value = el;
    t0->Occorrenza = occ;
    return t0;
}

tree createleaf(int el, int occ) {
    return mergetree(
        el, occ, NULL,
        NULL); // Ogni foglia è formata da un valore e due puntatori nulli
}

int isvoidtree(tree t) { // Verifico che un albero sia vuoto
    return (t == NULL);    // Se non c'è nulla è ovvio che è un albero vuoto...
}

tree leftchild(
    tree t) { // Restituisce il figlio sinistro accedendo alla struttura tree
    return t->T_l;
}

tree rightchild(
    tree t) { // Restituisce il figlio destro, accedendo alla struttura tree
    return t->T_r;
}

int root(
    tree t) { // Restituisce la radice, sempre facendo accesso alla struttura
    return t->value;
}
int rootOcc(tree t) { // Restituisce la radice, sempre facendo accesso alla struttura
    return t->Occorrenza;
}
tree insert(int el, tree t) { // Si inserisce un intero el, nell'albero t
    if (isvoidtree(t)) { // Se l'albero è vuoto, allora verrà creata una foglia CON OCCORRENZA 1 
        return createleaf(el, 1);
    }
    if (root(t) == el) { //SE è UGUALE A UN NODO ESISTENTE , SI AUMENTA L'OCCORRENZA
        t->Occorrenza++;
        return t;
    }
    if (root(t) > el) { // Altrimenti si procede da direttive, ovvero se il
        // valore della radice è >= dell'elemento
        return mergetree(root(t), rootOcc(t), insert(el, leftchild(t)), rightchild(t)); // Andrà a sinistra
    }

    if (root(t) < el) { // Ae la radice è invece minore dell'elemento, verrà
        // inserita a destra.
        return mergetree(root(t), rootOcc(t), leftchild(t), insert(el, rightchild(t)));
    }
    else {
        return t;
    }
}

int Altezza(tree t) {
    if (isvoidtree(t)) { // Se l'albero è vuoto, allora verrà creata una foglia CON OCCORRENZA 1 
        return -1;
    }
    else {
        int altsx = Altezza(leftchild(t));
        int altdx = Altezza(rightchild(t));
        if (altsx > altdx)
            return altsx + 1;
        return altdx + 1;
    }
}

void showtree(tree t, int alt=0) {
    int i;

    if (isvoidtree(t) == false) {
        showtree(leftchild(t),alt+1);
        printf("Valore: %d  trovato: %d profondita': %d \n", root(t), rootOcc(t), alt);
        showtree(rightchild(t),alt+1);
    }
}


int main()
{
    cout << "Hello World! " << endl;
    if ((intfile = fopen("nodi.txt", "r")) == NULL) { // Apro il file che mi serve
        cout<<"ERRORE: Non riesco ad aprire il file 'nodi.txt' " << endl;

        return (2);
    }

    cout << " * Ho aperto il file "<< endl;

    int num;            // Scansiono il file di interi
    tree albero = NULL; // Inizializzo l'albero vuoto

    while (fscanf(intfile, "%d", &num) != EOF) {
        albero = insert(num, albero);
    }
    cout << "l'altezza massima e': " << Altezza(albero)<<endl<<endl;
    showtree(albero);
}
