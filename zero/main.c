#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

int main(void) {
    Arvore* arvore = tree_create();
    TNO* raiz = NULL;
    char buffer[4096];
    int atual = 0;

    if (fgets(buffer, 4096, stdin) == NULL) {
        printf("Erro ao ler entrada.\n");
        free(arvore);
        return 1;
    }

    Arvore* testeS = createnfillstringtotree(buffer, &atual);

    printf("Percurso em ordem (arvore vazia):\n");
    printtreeinorder(arvore);
    printf("\n");

    /* Mantem os testes que ja existiam */
    printf("Percurso em ordem (testeS):\n");
    printtreeinorder(testeS);
    printf("\n");

    printf("Percurso pos-ordem (testeS):\n");
    printtreeposorder(testeS);
    printf("\n");

    printf("Percurso pre-ordem (testeS):\n");
    printtreepreorder(testeS);
    printf("\n");

    /* Testa chartoint */
    printf("chartoint('7') = %d\n", chartoint('7'));

    /* Testa no_createnfill */
    if (!no_createnfill(&raiz, 10)) {
        printf("Falha ao criar nos de teste.\n");
        free(arvore);
        free(testeS);
        return 1;
    }

    /* Testa busca/impressao */
    printspecificno(testeS, 20);
    printf("\n");
    printspecificno(testeS, 12);

    /* Testa assinaturas dos giros */
    {
        bool h = true;
        case1_giroesquerda(&raiz, &h);
        case2_girodireita(&raiz, 0);
    }

    printf("Percurso diferente (testeS):\n");
    printtreediferente(testeS);
    printf("\n");

    printf("Percurso em largura/nível (testeS):\n");
    printtreelevelorder(testeS);

    free(raiz);
    free(arvore);
    free(testeS);
    return 0;
}
