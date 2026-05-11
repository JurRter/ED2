#include "Rubrotree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Rno{
    struct Rno* rit;
    struct Rno* lef;
    struct Rno* p;
    int key;
    int bal;
    char color;
} rno;

typedef struct Rtree{
    struct Rno* root;
} rtree;


void RB_transplante(rtree* t,rno* u,rno* v){
    if (u->p == NULL){
        t->root = v;
    }
    else if (u == u->p->lef){
        u->p->lef = v;
    }
    else
};

