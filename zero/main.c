#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"

int main(void) {
    Arvore* arvore = tree_create();
    TNO* raiz = NULL;
    char input[] = "(7(5(3(1)(4))(6))(10(8()(9))(12(11)(14()(16)))))";
    int atual_arvore = 0;
    int atual_altura = 0;
    Arvore* testeS = createnfillstringtotree(input, &atual_arvore);
    TNO* raiz_altura = stringtotree(input, &atual_altura);

    printf("Entrada usada (maior): %s\n\n", input);
    printf("Desenho da arvore:\n");
    printf("            7\n");
    printf("         /     \\\n");
    printf("        5       10\n");
    printf("      /   \\    /  \\\n");
    printf("     3     6  8    12\n");
    printf("    / \\        \\   / \\\n");
    printf("   1   4        9 11 14\n");
    printf("                      \\ \n");
    printf("                       16\n");

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
    arvorepornivel(testeS);
    printf("\n");

    printf("Percurso em largura/nivel (testeS):\n");
    arvorepornivel(testeS);
    printf("\n");

    printf("Altura da arvore (alturano): %d\n", alturano(raiz_altura));

    printf("Teste LCA (1, 6):\n");
    printlca(testeS, 1, 6);
    printf("Teste LCA (9, 16):\n");
    printlca(testeS, 9, 16);

    printf("Teste soma (1, 6):\n");
    printf("Soma: %i \n", somadeintervaloarvore(testeS, 1, 6));
    printf("Teste soma (9, 16):\n");
    printf("Soma: %i \n", somadeintervaloarvore(testeS, 9, 16));

    free(raiz);
    free(raiz_altura);
    free(arvore);
    free(testeS);
    return 0;
}
