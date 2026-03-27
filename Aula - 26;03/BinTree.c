#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct _no{
    struct _no* lef;
    struct _no* rit;
    int index;
} TNo;


typedef struct _tree{
    TNo* inicio;
} Bin;

TNo* NO_createnfill(int x){
    TNo* no = malloc(sizeof(BinTree));
    if(no != NULL){
        no->rit = NULL;
        no->lef = NULL;
        no->index = x;
    }
    return no;
}

BinTree* BT_create(){
    BinTree* arvore = malloc(sizeof(TNo));
    if (arvore != NULL) {
        arvore->inicio = NULL;
    }
    return arvore;
}

bool BT_insert(BinTree* arvore, int x){
    TNo* NO = NO_createnfill(x);
    if(NO == NULL) return 0;
    if (arvore->inicio == NULL) {
        arvore->inicio = NO;
    return 1;
}
    TNo* aux = arvore->inicio;
    while(NO->index > aux->index || NO->index < aux->index){
        if(NO->index > aux->index){
            if(aux->rit != NULL){
                aux = aux->rit;
            } else {
                aux->rit = NO;
                return 1;
            }
        } else if(NO->index < aux->index){
            if(aux->lef != NULL){
                aux = aux->lef;
            } else {
                aux->lef = NO;
                return 1;
            }
        } else {
            puts("cHapo");
            return 0;
        }
    }
    puts("shapooooo");
    return 0;
}

void BT_pre(BinTree*);

void BT_in(BinTree*);

void BT_pos(BinTree*);

void BT_nivel(BinTree*);

TNo* BT_max(BinTree* arvore){
    TNo* max = arvore->inicio;
    while (max->rit != NULL){
        max = max->rit;
    };
    return max;
}

TNo* BT_min(BinTree* arvore){
    TNo* min = arvore->inicio;
    while (min->lef != NULL){
        min = min->lef;
    };
    return min;
};

TNo* BT_sucesso(TNo*);