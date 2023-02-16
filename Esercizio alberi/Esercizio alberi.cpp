
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    t0->Occorrenza = el;
    return (t0);
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
    if (isvoidtree(t)) { // Se l'albero è vuoto, allora verrà creata una foglia
        return createleaf(el, 1);
    }
    if (root(t) == el) {
        t->Occorrenza++;
        return t;
    }
    if (root(t) > el) { // Altrimenti si procede da direttive, ovvero se il
        // valore della radice è >= dell'elemento
        return mergetree(root(t), rootOcc(t), insert(el, leftchild(t)),
            rightchild(t)); // Andrà a sinistra
    }

    if (root(t) < el) { // Ae la radice è invece minore dell'elemento, verrà
        // inserita a destra.
        return mergetree(root(t), rootOcc(t), leftchild(t), insert(el, rightchild(t)));
    }
    else {
        return t;
    }
}

int mintree(tree t) { // Trovo il minimo per dicotomia: sapendo che più mi muovo
    // in basso
    if (isvoidtree(leftchild(t))) {
        return root(t); // Ed a sinistra, più ho un numero piccolo.
    }
    else {
        return mintree(leftchild(t)); // Ripeto la procedura ricorsivamente.
    }
}

int maxtree(tree t) {
    if (isvoidtree(rightchild(t))) {
        return root(t); // Come per il minimo, solo che in questo caso
    }
    else {
        return maxtree(rightchild(t)); // Mi muovo in basso a destra
    }
}
void SearchTree(tree t, int val, int* trovato) {
    int i;
    if (isvoidtree(t) == false && *trovato == 0) { // non siamo in un valore null
        if (root(t) == val) {
            *trovato = 1;
            SearchTree(t, val, trovato);
        }
        else {
            SearchTree(leftchild(t), val, trovato);
            SearchTree(rightchild(t), val, trovato);
        }
    }
}

void  MediaAlbero(tree t, int* somma, int* nelementi) {
    int i;

    if (isvoidtree(t) == false) {
        MediaAlbero(leftchild(t), somma, nelementi);
        *somma = *somma + root(t);
        (*nelementi)++;
        MediaAlbero(rightchild(t), somma, nelementi);
    }
}
void showtree(tree t) {
    int i;

    if (isvoidtree(t) == false) {
        showtree(leftchild(t));
        printf("Valore :%d  trovato:%d \n", root(t), rootOcc(t));
        showtree(rightchild(t));
    }
}

int main() {

    if ((intfile = fopen("nodi.txt", "r")) == NULL) { // Apro il file che mi serve
        printf("ERRORE: Non riesco ad aprire il file 'nodi.txt'\n");

        return (2);
    }

    printf("*Ho aperto il file ");

    int num;            // Scansiono il file di interi
    tree albero = NULL; // Inizializzo l'albero vuoto

    while (fscanf(intfile, "%d", &num) != EOF) {
        albero = insert(num, albero);
    }

    printf("*Ho costruito l'albero binario\n\n");
    printf("Cosa vuoi fare adesso?\n");
    printf("S-> Stampare l'albero\n");
    printf("m-> Cercare il minimo\n");
    printf("M-> Cercare il massimo\n");
    printf("C-> Cercare un valore nell'albero\n");
    printf("E-> La MEDIA dei valori nell'albero\n");
    printf("U-> Uscire.\n\n");

    char tmp;
    int val = 0, trovato = 0;

    printf(">");

    while ((tmp = getchar()) != 'U') {
        int somma = 0;
        int nElementi = 0;
        switch (tmp) {
        case 'S': // Serve a mostrare l'albero
            showtree(albero);
            printf("\n");
            break;

        case 'm': // Stampa a video il valore minimo
            printf("Il valore minimo dell'albero binario è %d\n", mintree(albero));
            break;

        case 'M': // Stampa a video il valore massimo
            printf("Il valore massimo dell'albero binario è %d\n", maxtree(albero));
            break;
        case 'C': // Stampa a video il valore massimo
            printf("Che valore vuoi cercare?\n");
            scanf("%d", &val);
            trovato = 0;
            SearchTree(albero, val, &trovato);
            if (trovato == 0) {
                printf("Valore NON trovato! \n");
            }
            else {
                printf("Valore trovato! \n");
            }
            break;
        case 'E': // Serve a mostrare l'albero
            MediaAlbero(albero, &somma, &nElementi);
            printf("La somma e':%d \n", somma);
            printf("Il n° dielementi e':%d \n", nElementi);
            printf("La la media e':%fl \n", (double)somma / nElementi);
            break;

        default:
            printf(">");
            break;
        }
    }
    fclose(intfile);

    return (0);
}