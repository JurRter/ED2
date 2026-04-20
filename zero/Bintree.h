#ifndef ED2_BINTREE_H
#define ED2_BINTREE_H

#include <stdbool.h>

typedef struct arvre Arvore;
typedef struct no TNO;

bool no_createnfill(TNO** x, int y);
Arvore* tree_create();
void case1_giroesquerda(TNO** x, bool* h);
void case2_girodireita(TNO** x, int h);
TNO* treesearch(TNO* x, int y);
void printspecificno(TNO* x, int y);
void printtreeinorder(Arvore* x);
void printinorder(TNO* x);
void printpreorder(TNO* x);
void printposorder(TNO* x);
int chartoint(char c);
TNO* stringtotree(char *x, int *atual);
void printdiferente(TNO* x);

#endif