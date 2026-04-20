#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"
#include "../Aula - 28_03/BinTree.h"

int main(void) {
    Arvore* arvore = tree_create();
    TNO* raiz = NULL;
    char buffer[4096];
    int atual = 0;
    fgets(buffer, 4096, stdin);
    Arvore* testeS = tree_create();
    testeS->root = Strtobintree(buffer, &atual);
    

    if (arvore == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }

    if (!no_createnfill(&raiz, 10)) {
        printf("Erro ao criar o no raiz.\n");
        free(arvore);
        return 1;
    }

    printf("Print em ordem da arvore vazia: ");
    printtreeinorder(arvore);
    printf("\n");

    if (treesearch(raiz, 10) != NULL) {
        printf("No encontrado: ");
        printspecificno(raiz, 10);
        printf("\n");
    }

    if (treesearch(raiz, 99) == NULL) {
        printf("Valor 99 nao encontrado.\n");
    }






    free(raiz);
    free(arvore);
    return 0;
}
