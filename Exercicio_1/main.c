#include "BinTree.h"
#include <stdio.h>

int ancestral(int p, int q, BinTree* root);

int main(void) {
    BinTree* arvore = BT_create();
    if (arvore == NULL) {
        puts("Erro ao criar arvore.");
        return 1;
    }

    int valores[] = {20, 10, 30, 5, 15, 25, 35};
    int n = (int)(sizeof(valores) / sizeof(valores[0]));

    for (int i = 0; i < n; i++) {
        if (!BT_insert(arvore, valores[i])) {
            printf("Falha ao inserir %d\n", valores[i]);
            return 1;
        }
    }

    int p = 10;
    int q = 30;
    int resultado = ancestral(p, q, arvore);

    printf("MCA(%d, %d) = %d\n", p, q, resultado);
    return 0;
}
