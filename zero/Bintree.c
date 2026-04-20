#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

struct no {
    struct no* rit;
    struct no* lef;
    struct no* p;
    int balanc;
    int index;
};

struct arvre {
    TNO* root;
};

bool no_createnfill(TNO** x, int y){
    *x = malloc(sizeof(TNO));
    if(*x == NULL) return 0;
    (*x)->lef = NULL;
    (*x)->rit = NULL;
    (*x)->p = NULL;
    (*x)->index = y;
    (*x)->balanc = 0;
    return 1;
}

void printno(TNO* x) {
    if (x == NULL) {
        printf("(NULL)\n");
        return;
    }
    printf("%p ENDERECO, %i INDEX \n", x, x->index);
}

Arvore* tree_create(){
    Arvore* novo = malloc(sizeof(Arvore));
    if (novo == NULL) return NULL;
    novo->root = NULL;
    return novo;
}

Arvore* createnfillstringtotree(char *buffer, int *atual){
    Arvore* novo = malloc(sizeof(Arvore));
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

void printpreorder(TNO* x) {
    if (x != NULL) {
        printno(x);
        printpreorder(x->lef);
        printpreorder(x->rit);
    }
}

void printposorder(TNO* x) {
    if (x!= NULL) {
        printposorder(x->lef);
        printposorder(x->rit);
        printno(x);
    }
}

void printdiferente(TNO* x) {
    if (x == NULL) return;
    printno(x);
    printno(x->lef);
    printno(x->rit);
    printdiferente(x->lef);
    printdiferente(x->rit);
}

void printtreeinorder(Arvore* x){
    if (x == NULL) return;
    printinorder(x->root);
}
void printtreeposorder(Arvore* x){
    if (x == NULL) return;
    printposorder(x->root);
}
void printtreepreorder(Arvore* x){
    if (x == NULL) return;
    printpreorder(x->root);
}
void printtreediferente(Arvore* x) {
    if (x == NULL) return;
    printdiferente(x->root);
}

void case1_giroesquerda(TNO** x, bool* h){
    if (x == NULL || *x == NULL || (*x)->rit == NULL) return;
    TNO* ptu = (*x)->rit;
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

TNO* stringtotree(char *x, int *atual){
    TNO* root = NULL;
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


TNO* treesearch(TNO* x, int y) {
    if (x == NULL || y == x->index) return x;
    if (x->index > y) {
        return treesearch(x->lef, y);
    } else {
        return treesearch(x->rit, y);
    }
}

void printspecificno(Arvore* x, int y) {
    if (x == NULL) {
        printf("Arvore nula.\n");
        return;
    }
    TNO* aux = treesearch(x->root, y);
    if (aux == NULL) {
        printf("Valor %d nao encontrado.\n", y);
        return;
    }
    printno(aux);
}

void case2_girodireita(TNO **x, int h) {
}
