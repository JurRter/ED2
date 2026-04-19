#ifndef ED2_BINTREE_H
#define ED2_BINTREE_H

#include <stdbool.h>

typedef struct arvre Arvore;
typedef struct no TNO;

bool no_createnfill(TNO** x, int y);
Arvore* tree_create();
void case1_giroesquerda(TNO** x, bool* h);
void case2_girodireita(TNO** x, int h);

#endif