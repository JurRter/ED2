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

    for (int i = 0; i < n; i++) {
        if (BT_insert(arvore, valores[i])) {
            printf("Inserido: %d\n", valores[i]);
        } else {
            printf("Nao inserido (duplicado/erro): %d\n", valores[i]);
        }
    }

    return 0;
}