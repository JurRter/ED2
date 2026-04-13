#include "BinTree.h"
#include <stdio.h>

struct _no {
    struct _no* lef;
    struct _no* rit;
    int index;
};

struct _tree {
    TNo* inicio;
};

int main(void) {
    BinTree* arvore = BT_create();

    if (arvore == NULL) {
        puts("Erro ao criar arvore.");
        return 1;
    }

    int valores[] = {10, 5, 17, 3, 7, 12, 20, 7};
    int n = (int)(sizeof(valores) / sizeof(valores[0]));

    puts("Teste de insercao:");
    for (int i = 0; i < n; i++) {
        if (BT_insert(arvore, valores[i])) {
            printf("Inserido: %d\n", valores[i]);
        } else {
            printf("Nao inserido (duplicado/erro): %d\n", valores[i]);
        }
    }

    puts("\nTeste de validacao BST:");
    if (BT_is_bst(arvore)) {
        puts("BST.\n");
    } else {
        puts("n é BST\n");
    }

    puts("Teste de validacao NAO-BST com Strtobintree:");
    
    char forma_nao_bst[] = "(10(5()())(8()()))";
    int pos = 0;
    
    BinTree* arvore_nao_bst = BT_create();
    if (arvore_nao_bst == NULL) {
        puts("Erro ao criar arvore nao-BST.");
        return 1;
    }
    arvore_nao_bst->inicio = Strtobintree(forma_nao_bst, &pos);
    if (arvore_nao_bst->inicio == NULL) {
        puts("Erro ao fazer parse da arvore nao-BST.");
        return 1;
    }
    if (BT_is_bst(arvore_nao_bst)) {
        puts("Falhou: deveria NAO ser BST.\n");
    } else {
        puts("Correto: NAO e BST.\n");
    }

    puts("Fim dos testes.");

    return 0;
}