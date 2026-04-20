#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"


typedef struct no
{
    struct no* rit;
    struct no* lef;
    struct no* p;
    int balanc;
    int index;
} tno;

typedef struct arvre
{
    tno* root;
} tree;

bool no_createnfill(tno** x, int y){
    *x = malloc(sizeof(tno));
    if(*x == NULL) return 0;
    (*x)->lef = NULL;
    (*x)->rit = NULL;
    (*x)->p = NULL;
    (*x)->index = y;
    (*x)->balanc = 0;
    return 1;
}

void printno(tno* x) {
    printf("%p ENDEREÇO, %i INDEX", x, x->index);
}

tree* tree_create(){
    tree* novo = malloc(sizeof(tree));
    if (novo == NULL) return NULL;
    novo->root = NULL;
    return novo;
}

void printinorder(tno* x){
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

void printposorder(tno* x) {
    if (x!= NULL) {
        printposorder(x->lef);
        printposorder(x->rit);
        printno(x);
    }
}

void printtreeinorder(tree* x){
    printinorder(x->root);
}

void case1_giroesquerda(tno** x, bool* h){
    tno* ptu = (*x)->rit;
    if(ptu->balanc == -1){
        (*x)->lef = ptu->rit;
        ptu->rit = (*x);
        (*x)->balanc = 0;
        (*x) = ptu;
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
            if (x[*atual=='(']) {
                root->lef = stringtotree(x, atual);
                root->rit = stringtotree(x, atual);
            }
        }
    }
    (*atual)++;
    return root;
}

void printdiferente(tno* x) {
    if (x == NULL) return;
    printno(x);
    printno(x->lef);
    printno(x->rit);
    printdiferente(x->lef);
    printdiferente(x->rit);
}

tno* treesearch(tno* x, int y) {
    if (x == NULL || y == x->index) return x;
    if (x->index > y) {
        return treesearch(x->lef, y);
    } else {
        return treesearch(x->rit, y);
    }
}

void printspecificno(tno* x, int y) {
    if (x->index == y) {
        printno(x);
        return;
    } else if (y > x->index) {
        printspecificno(x->lef, y);
    } else {
        printspecificno(x->rit, y);
    }
}

void case2_girodireita(tno **x, int h) {
    //ue
}


void novo() {
}
