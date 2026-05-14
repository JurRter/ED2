#include "Rubrotree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Rno{
    struct Rno* rit;
    struct Rno* lef;
    struct Rno* p;
    int key;
    char color;
} rno;

typedef struct Rtree{
    struct Rno* root;
    struct Rno* nil;
} rtree;


rtree* RB_create(){
    rtree* t = malloc(sizeof(rtree));
    rno* nil = malloc(sizeof(rno));
    nil->color = 'B';
    nil->lef = nil->rit = nil->p = NULL;
    t->nil = nil;
    t->root = nil;
    return t;
}

bool RB_nocreantenfill(rtree* t, rno** x, int y){
    *x = malloc(sizeof(rno));
    if(*x == NULL) return 0;
    (*x)->lef = t->nil;
    (*x)->rit = t->nil;
    (*x)->p = t->nil;
    (*x)->key = y;
    (*x)->color = 'R';
    return 1;
}

void LEFT_ROT(rtree* t, rno* x){
    rno* y = x->rit;
    x->rit = y->lef;
    if (y->lef != t->nil)
        y->lef->p = x;
    y->p = x->p;
    if (x->p == t->nil)
        t->root = y;
    else if (x == x->p->lef)
        x->p->lef = y;
    else
        x->p->rit = y;
    y->lef = x;
    x->p = y;
}

void RIGHT_ROT(rtree* t, rno* x){ // mesma coisa so que pro outro lado
    rno* y = x->lef;
    x->lef = y->rit;
    if (y->rit != t->nil)
        y->rit->p = x;
    y->p = x->p;
    if (x->p == t->nil)
        t->root = y;
    else if (x == x->p->rit)
        x->p->rit = y;
    else
        x->p->lef = y;
    y->rit = x;
    x->p = y;
}

void RB_insertFIX(rtree* t, rno* z){
    while (z->p->color == 'R'){
        if (z->p == z->p->p->lef){
            rno* y = z->p->p->rit;
            if (y->color == 'R'){
                z->p->color = 'B'; // case 1 {
                y->color = 'B';
                z->p->p->color = 'R';
                z = z->p->p; // case 1 }
            } 
            else{
                if (z == z->p->rit){ // case 2 {
                    z = z->p;
                    LEFT_ROT(t,z);
                }    // case 2 } 
                z->p->color = 'B'; //case 3 {
                z->p->p->color = 'R';
                RIGHT_ROT(t,z->p->p); //case 3 }
            }
        } // linha 41-56 mas com LEFT_ROT e RIGHT_ROT trocados.
        else{
            rno* y = z->p->p->rit;
            if (y->color == 'R'){
                z->p->color = 'B'; // case 1 {
                y->color = 'B';
                z->p->p->color = 'R';
                z = z->p->p; // case 1 }
            }
            else{
                if (z == z->p->rit){ // case 2 {
                    z = z->p;
                    RIGHT_ROT(t,z);
                }    // case 2 }
                z->p->color = 'B'; //case 3 {
                z->p->p->color = 'R';
                LEFT_ROT(t,z->p->p); //case 3 }
            }
        }
    }
}

void RB_insert(rtree* t, rno* z){
    rno* x = t->root;
    rno* y = t->nil;
    while (x != t->nil){
        y = x;
        if (z->key < x->key){
            x = x->lef;
        } else{
            x = x->rit;
        }
        z->p = y;
        if (y == t->nil){
            t->root = z;
        }
        else if ( z->key < y->key){
            y->lef = z;
        } else{
            y->rit = z;
        }
        z->lef = t->nil;
        z->rit = t->nil;
        z->color = 'R';
    }
    RB_insertFIX(t,z);
}


void RB_transplante(rtree* t,rno* u,rno* v){
    if (u->p == NULL){
        t->root = v;
    }
    else if (u == u->p->lef){
        u->p->lef = v;
    }
    else{
        u->p->rit = v;
    }
        v->p = u->p;
}
