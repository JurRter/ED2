#include "BinTree.h"
#include <stdio.h>

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
        puts("Resultado: eh arvore de busca (BST).\n");
    } else {
        puts("Resultado: NAO eh arvore de busca (BST).\n");
    }

    puts("Fim dos testes.");

    return 0;
}