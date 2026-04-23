#include "AVLtree.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

typedef struct tno {
    struct tno* lef;
    struct tno* rit;
    int key;
    int bal;
} tno ;

typedef struct tree {
    struct tno* root;
} tree ;

tno* no_create(tno** x, int key) {
    *x = malloc(sizeof(tno));
    (*x)->lef = NULL;
    (*x)->rit = NULL;
    (*x)->key = key;
    (*x)->bal = 0;
    return *x;
}

void case1(tno** x, bool h) {
    tno* ptu = (*x)->lef;

    if (ptu->bal == -1) {
        (*x)->lef = ptu->rit;
        ptu->rit = (*x);
        (*x)->bal = 0;
        ptu->bal = 0;
        (*x) = ptu;
    } else {
        tno* ptv = ptu->rit;
        ptu->rit = ptv->lef;
        ptv->lef = ptu;
        (*x)->lef = ptv->rit;
        ptv->rit = (*x);
        (ptv->bal == -1) ? ((*x)->bal = 1) : ((*x)->bal = 0);
        (ptv->bal == 1) ? (ptu->bal = -1) : (ptu->bal = 0);
        (*x) = ptv;
    }
    (*x)->bal = 0;
    h = false;
}

void case2(tno** x, bool h) {
    tno* ptu = (*x)->rit;
    if (ptu->bal == 1) {
        (*x)->rit = ptu->lef;
        ptu->lef = (*x);
        (*x)->bal = 0;
        (*x) = ptu;
    }
    else {
        tno* ptv = ptu->lef;
        ptu->lef = ptv->rit;
        ptv->rit = ptu;
        (*x)->rit = ptv->lef;
        ptv->lef = (*x);
        (ptv->bal == 1) ? ((*x)->bal = -1) : ((*x)->bal = 0);
        (ptv->bal == -1) ? (ptu->bal = 1) : (ptu->bal = 0);
        (*x) = ptv;
    }
    (*x)->bal = 0;
    h = false;
}

void insAVL(int key, tno** x, bool h) {
    if ((*x) == NULL) {
        no_create((x), key);
        h = 1;
    }
    else if (key == (*x)->key) {
        return;
    }
    if (key<(*x)->key) {
        insAVL(key, &(*x)->lef, h);
        if (h == 1) {
            switch ((*x)->bal) {
                case 1:
                    (*x)->bal = 0;
                    h = 0;
                    break;
                case 0:
                    (*x)->bal = -1;
                    break;
                case -1:
                    case1(x, h);
                    break;
                default:
                    puts("Etaporraaaa1");
                    break;
            }
        }
    } else {
        insAVL(key, &(*x)->rit, h);
        if (h == 1) {
            switch ((*x)->bal) {
                case -1:
                    (*x)->bal = 0;
                    h = 0;
                    break;
                case 0:
                    (*x)->bal = 1;
                    break;
                case 1:
                    case2(x, h);
                    break;
                default:
                    puts("etaporraaa2");
                    break;
            }
        }
    }
}