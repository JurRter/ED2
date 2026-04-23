#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

typedef struct no{
    struct no* rit;
    struct no* lef;
    struct no* p;
    int balanc;
    int index;
} tno;

typedef struct arvre{
    tno* root;
} tree;

bool no_createnfill(tno** x, int y){
    *x = malloc(sizeof(TNO));
    if(*x == NULL) return 0;
    (*x)->lef = NULL;
    (*x)->rit = NULL;
    (*x)->p = NULL;
    (*x)->index = y;
    (*x)->balanc = 0;
    return 1;
}

void printno(tno* x) {
    if (x == NULL) {
        printf("(NULL)\n");
        return;
    }
    printf("%p ENDERECO, %i INDEX \n", x, x->index);
}

tree* tree_create(){
    tree* novo = malloc(sizeof(tree));
    if (novo == NULL) return NULL;
    novo->root = NULL;
    return novo;
}

tree* createnfillstringtotree(char *buffer, int *atual){
    tree* novo = malloc(sizeof(tree));
    if (novo == NULL) return NULL;
    novo->root = stringtotree(buffer, atual);
    return novo;
}

void printinorder(TNO* x){
    if(x != NULL){
        printinorder(x->lef);
        printno(x);
        printinorder(x->rit);
    }
}

void printpreorder(tno* x) {
    if (x != NULL) {
        printno(x);
        printpreorder(x->lef);
        printpreorder(x->rit);
    }
}

void imprimePorNivel(tno *raiz) {
    if (raiz == NULL) return;
    TNO *fila[1000];
    int ini = 0, fim = 0;
    int primeiro = 1;
    fila[fim++] = raiz;
    while (ini < fim) {
        tno *atual = fila[ini++];

        if (!primeiro) printf(", ");
        printf("%d", atual->index);
        primeiro = 0;

        if (atual->lef) fila[fim++] = atual->lef;
        if (atual->rit) fila[fim++] = atual->rit;
    }
    printf(".\n");
}

void printposorder(tno* x) {
    if (x!= NULL) {
        printposorder(x->lef);
        printposorder(x->rit);
        printno(x);
    }
}

void arvorepornivel(tree* x) {
    imprimePorNivel(x->root);
}

int alturano(tno* x) {
    int qty = 1;
    if (x->lef != NULL) {
        qty += alturano(x->lef);
    }
    int qty2 = 1;
    if (x->rit != NULL) {
        qty2 += alturano(x->rit);
    }
    if (qty > qty2) {
        return qty;
    } else {
        return  qty2;
    }
}

void printtreeinorder(tree* x){
    if (x == NULL) return;
    printinorder(x->root);
}
void printtreeposorder(tree* x){
    if (x == NULL) return;
    printposorder(x->root);
}
void printtreepreorder(tree* x){
    if (x == NULL) return;
    printpreorder(x->root);
}

void case1_giroesquerda(tno** x, bool* h){
    if (x == NULL || *x == NULL || (*x)->rit == NULL) return;
    tno* ptu = (*x)->rit;
    if(ptu->balanc == -1){
        (*x)->lef = ptu->rit;
        ptu->rit = (*x);
        (*x)->balanc = 0;
        (*x) = ptu;
        if (h != NULL) *h = false;
    }
}
int chartoint(char c) {
    return c-'0';
}

tno* stringtotree(char *x, int *atual){
    tno* root = NULL;
    if (x[(*atual)++] == '(' && x[*atual] != ')') {
        int index = 0;
        while (x[*atual]!=')' && x[*atual]!= '(') {
            index = 10*index + chartoint(x[(*atual)++]);
            if (!no_createnfill(&root, index)) return NULL;
            if (x[*atual] == '(') {
                root->lef = stringtotree(x, atual);
                root->rit = stringtotree(x, atual);
            }
        }
    }
    (*atual)++;
    return root;
}


tno* treesearch(tno* x, int y) {
    if (x == NULL || y == x->index) return x;
    if (x->index > y) {
        return treesearch(x->lef, y);
    } else {
        return treesearch(x->rit, y);
    }
}

void printspecificno(tree* x, int y) {
    if (x == NULL) {
        printf("Arvore nula.\n");
        return;
    }
    tno* aux = treesearch(x->root, y);
    if (aux == NULL) {
        printf("Valor %d nao encontrado.\n", y);
        return;
    }
    printno(aux);
}

void case2_girodireita(tno **x, int h) {
}

tno* LCA(tno* x, int min, int max) {
    if (x == NULL) {
        return NULL;
    }
    if (x->index == min || x->index == max) {
        return x;
    }
    tno* esq = LCA(x->lef, min, max);
    tno* dir = LCA(x->rit, min, max);
    if (esq && dir) return x;
    return esq ? esq : dir;
}

void printlca(tree* x, int p, int q) {
    printno(LCA(x->root, p, q));
}

int somadeintervalo(tno* x, int p, int q) { // p = 3 q = 10
    if (x == NULL) {
        return 0;
    }
    if (x->index < p) {
        return  somadeintervalo(x->rit, p,q);
    }
    if (x->index > q) {
        return  somadeintervalo(x->lef, p, q);
    }
    return x->index
    + somadeintervalo(x->lef, p , q)
    + somadeintervalo(x->rit, p, q);
}

int somadeintervaloarvoe(tree* x, int p, int q) {
    return somadeintervalo(x->root, p, q);
}

bool nbusca(tno* x, int min, int max) {
    if (x == NULL) return 1;
    if (x->index<min || x->index>max) return  false;
    return nbusca(x->lef, min, x->index) && nbusca(x->rit, x->index, max);
}

bool arvorenbusca(tree* x) {
    return nbusca(x->root, INT_MIN, INT_MAX);
}

bool ptreigual(tno* x, tno* y) {
    if (x == NULL && y == NULL) return 1;
    if (x == NULL) return 0;
    if (y == NULL) return 0;
    if (x->index != y->index) return false;
    return (ptreigual(x->lef, y->lef) && ptreigual(x->rit, y->rit));

}

bool eigual(tree* x, tree* y) {
    return ptreigual(x->root, y->root);
}