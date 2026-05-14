#include "AVLtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    struct no* rit;
    struct no* lef;
    struct no* p;
    int balanc;
    int key;
} ano;

typedef struct atree
{
    ano* root;
} tree;

bool AVL_nocreatenfill(ano** x, int y){
    *x = malloc(sizeof(ano));
    if(*x == NULL) return 0;
    (*x)->lef = NULL;
    (*x)->rit = NULL;
    (*x)->p = NULL;
    (*x)->key = y;
    (*x)->balanc = 0;
    return 1;
}


void CASE_1(ano** pt, bool* h){
    ano* p1 = (*pt)->lef;
    if (p1->balanc == -1){          // simples a direita
        (*pt)->lef = p1->rit;
        p1->rit = *pt;
        (*pt)->balanc = 0;
        *pt = p1;
        (*pt)->balanc = 0;
    } else {                        // rotaçao dupla a direita
        ano* p2 = p1->rit;
        p1->rit = p2->lef;
        p2->lef = p1;
        (*pt)->lef = p2->rit;
        p2->rit = *pt;
        (*pt)->balanc = (p2->balanc == -1) ? 1 : 0;
        p1->balanc  = (p2->balanc ==  1) ? -1 : 0;
        *pt = p2;
        (*pt)->balanc = 0;
    }
    *h = false;
}


void CASE_2(ano** pt, bool* h){
    ano* p1 = (*pt)->rit;
    if (p1->balanc == 1){           //rotaçao simples a esquerda
        (*pt)->rit = p1->lef;
        p1->lef = *pt;
        (*pt)->balanc = 0;
        *pt = p1;
        (*pt)->balanc = 0;
    } else {                        //rotaçao dupla a esquerda
        ano* p2 = p1->lef;
        p1->lef = p2->rit;
        p2->rit = p1;
        (*pt)->rit = p2->lef;
        p2->lef = *pt;
        (*pt)->balanc = (p2->balanc ==  1) ? -1 : 0;
        p1->balanc  = (p2->balanc == -1) ?  1 : 0;
        *pt = p2;
        (*pt)->balanc = 0;
    }
    *h = false;
}

void INS_AVL(int x, ano** pt, bool* h){
    if (*pt == NULL){
        AVL_nocreatenfill(pt, x);
        *h = true;
    }
    else if (x == (*pt)->key){
        return;
    }
    else if (x < (*pt)->key){
        INS_AVL(x, &(*pt)->lef, h);
        if (*h == true){
            switch ((*pt)->balanc){
                case  1: (*pt)->balanc =  0; *h = false;
                break;
                case  0: (*pt)->balanc = -1;
                break;
                case -1: CASE_1(pt, h);
                break;
            }
        }
    }
    else {
        INS_AVL(x, &(*pt)->rit, h);
        if (*h == true){
            switch ((*pt)->balanc){
                case -1: (*pt)->balanc =  0; *h = false;
                break;
                case  0: (*pt)->balanc =  1;
                break;
                case  1: CASE_2(pt, h);
                break;
            }
        }
    }
}