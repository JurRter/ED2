#include "Rubrotree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long rb_rotacoes = 0;
static long long rb_trocas_cor = 0;

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
    rb_rotacoes++;
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
    rb_rotacoes++;
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
                z->p->color = 'B'; rb_trocas_cor++; // case 1 {
                y->color = 'B'; rb_trocas_cor++;
                z->p->p->color = 'R'; rb_trocas_cor++;
                z = z->p->p; // case 1 }
            }
            else{
                if (z == z->p->rit){ // case 2 {
                    z = z->p;
                    LEFT_ROT(t,z);
                }    // case 2 }
                z->p->color = 'B'; rb_trocas_cor++; //case 3 {
                z->p->p->color = 'R'; rb_trocas_cor++;
                RIGHT_ROT(t,z->p->p); //case 3 }
            }
        } // linha 41-56 mas com LEFT_ROT e RIGHT_ROT trocados.
        else{
            rno* y = z->p->p->lef;
            if (y->color == 'R'){
                z->p->color = 'B'; rb_trocas_cor++; // case 1 {
                y->color = 'B'; rb_trocas_cor++;
                z->p->p->color = 'R'; rb_trocas_cor++;
                z = z->p->p; // case 1 }
            }
            else{
                if (z == z->p->lef){ // case 2 {
                    z = z->p;
                    RIGHT_ROT(t,z);
                }    // case 2 }
                z->p->color = 'B'; rb_trocas_cor++; //case 3 {
                z->p->p->color = 'R'; rb_trocas_cor++;
                LEFT_ROT(t,z->p->p); //case 3 }
            }
        }
    }
    t->root->color = 'B';
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

// teste gerado
static int height_rb(rtree* t, rno* node){
    if (node == t->nil) return 0;
    int lh = height_rb(t, node->lef);
    int rh = height_rb(t, node->rit);
    return 1 + (lh > rh ? lh : rh);
}

static void free_rb_nodes(rtree* t, rno* node){
    if (node == t->nil) return;
    free_rb_nodes(t, node->lef);
    free_rb_nodes(t, node->rit);
    free(node);
}

static void free_rb(rtree* t){
    free_rb_nodes(t, t->root);
    free(t->nil);
    free(t);
}

void run_rb_tests(){
    const int N = 1000000;
    int* arr = malloc(N * sizeof(int));

    // --- Teste 1: Aleatorio ---
    for (int i = 0; i < N; i++) arr[i] = i + 1;
    srand(42);
    for (int i = N - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }

    rb_rotacoes = 0;
    rb_trocas_cor = 0;
    rtree* t1 = RB_create();
    clock_t inicio = clock();
    for (int i = 0; i < N; i++){
        rno* z;
        RB_nocreantenfill(t1, &z, arr[i]);
        RB_insert(t1, z);
    }
    clock_t fim = clock();
    double tempo1 = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    int altura1 = height_rb(t1, t1->root);
    long long rot1 = rb_rotacoes;
    long long cor1 = rb_trocas_cor;
    free_rb(t1);

    // --- Teste 2: Ordenado ---
    rb_rotacoes = 0;
    rb_trocas_cor = 0;
    rtree* t2 = RB_create();
    inicio = clock();
    for (int i = 1; i <= N; i++){
        rno* z;
        RB_nocreantenfill(t2, &z, i);
        RB_insert(t2, z);
    }
    fim = clock();
    double tempo2 = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    int altura2 = height_rb(t2, t2->root);
    long long rot2 = rb_rotacoes;
    long long cor2 = rb_trocas_cor;
    free_rb(t2);

    free(arr);

    printf("=== Arvore Rubro-Negra ===\n");
    printf("%-12s | %16s | %15s | %12s | %6s\n",
           "Entrada", "Rotacoes simples", "Trocas de cor", "Tempo (ms)", "Altura");
    printf("%-12s | %16lld | %15lld | %12.2f | %6d\n",
           "Aleatoria", rot1, cor1, tempo1, altura1);
    printf("%-12s | %16lld | %15lld | %12.2f | %6d\n",
           "Ordenada", rot2, cor2, tempo2, altura2);
}
