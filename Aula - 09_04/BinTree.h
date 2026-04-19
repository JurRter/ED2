#ifndef BINTREE_H
#define BINTREE_H

#include <stdbool.h>

typedef struct _tree BinTree;

typedef struct _no TNo;

BinTree* BT_create();

bool BT_insert(BinTree* arvore, int x);
/**
 *  @param x valor do index
 *  @param arvore recebe uma arvore
 *  @return Se deu certo
 */

int BT_altura(BinTree* arvore);

TNo* Strtobintree(char *str, int* x);

int no_altura(TNo* no);

void BT_pre(BinTree*);

void BT_in(BinTree*);

void BT_pos(BinTree*);

void BT_nivel(BinTree*);

bool BT_is_bst(BinTree* arvore);

int BT_nivel_cada(BinTree*);


#endif