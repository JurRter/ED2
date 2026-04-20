#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"


typedef struct no
{
    struct no* rit;
    struct no* lef;
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
    (*x)->index = y;
    (*x)->balanc = 0;
    return 1;
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
        printf("%d ", x->index);
        printinorder(x->rit);
    }
}

void printno(tno* x) {
    printf("%p ENDEREÇO, %i INDEX", x, x->index);
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
