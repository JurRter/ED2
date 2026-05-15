#include "AVLtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static long long avl_rotacoes = 0;

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
        avl_rotacoes += 1;
        (*pt)->lef = p1->rit;
        p1->rit = *pt;
        (*pt)->balanc = 0;
        *pt = p1;
        (*pt)->balanc = 0;
    } else {                        // rotaçao dupla a direita
        avl_rotacoes += 2;
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
        avl_rotacoes += 1;
        (*pt)->rit = p1->lef;
        p1->lef = *pt;
        (*pt)->balanc = 0;
        *pt = p1;
        (*pt)->balanc = 0;
    } else {                        //rotaçao dupla a esquerda
        avl_rotacoes += 2;
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

static int height_avl(ano* node){
    if (node == NULL) return 0;
    int lh = height_avl(node->lef);
    int rh = height_avl(node->rit);
    return 1 + (lh > rh ? lh : rh);
}

static void free_avl(ano* node){
    if (node == NULL) return;
    free_avl(node->lef);
    free_avl(node->rit);
    free(node);
}

void run_avl_tests(){
    const int N = 1000000;
    int* arr = malloc(N * sizeof(int));

    // --- Teste 1: Aleatorio ---
    for (int i = 0; i < N; i++) arr[i] = i + 1;
    srand(42);
    for (int i = N - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
    }

    avl_rotacoes = 0;
    ano* root1 = NULL;
    clock_t inicio = clock();
    for (int i = 0; i < N; i++){
        bool h = false;
        INS_AVL(arr[i], &root1, &h);
    }
    clock_t fim = clock();
    double tempo1 = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    int altura1 = height_avl(root1);
    long long rot1 = avl_rotacoes;
    free_avl(root1);

    // --- Teste 2: Ordenado ---
    avl_rotacoes = 0;
    ano* root2 = NULL;
    inicio = clock();
    for (int i = 1; i <= N; i++){
        bool h = false;
        INS_AVL(i, &root2, &h);
    }
    fim = clock();
    double tempo2 = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    int altura2 = height_avl(root2);
    long long rot2 = avl_rotacoes;
    free_avl(root2);

    free(arr);

    printf("=== Arvore AVL ===\n");
    printf("%-12s | %16s | %12s | %6s\n",
           "Entrada", "Rotacoes simples", "Tempo (ms)", "Altura");
    printf("%-12s | %16lld | %12.2f | %6d\n",
           "Aleatoria", rot1, tempo1, altura1);
    printf("%-12s | %16lld | %12.2f | %6d\n",
           "Ordenada", rot2, tempo2, altura2);
}
