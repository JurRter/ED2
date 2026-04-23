#include <stdio.h>
#include <stdlib.h>
#include "Bintree.h"
#include <stdbool.h>

int main(void) {
    Arvore* arvore = tree_create();
    TNO* raiz = NULL;
    char input[] = "(7(5(3(1)(4))(6))(10(8()(9))(12(11)(14()(16)))))";
    int atual_arvore = 0;
    int atual_altura = 0;
    Arvore* testeS = createnfillstringtotree(input, &atual_arvore);
    TNO* raiz_altura = stringtotree(input, &atual_altura);

    char input2[] = "(7(5(3(1)(4))(6))(10(8()(3))(12(11)(10()(16)))))";
    int atual_arvore2 = 0;
    int atual_altura2 = 0;
    Arvore* testeY = createnfillstringtotree(input2, &atual_arvore2);
    TNO* raiz_altura2 = stringtotree(input2, &atual_altura2);

    char input3[] = "(7(5(3(1)(4))(6))(10(8()(9))(12(11)(14()(16)))))";
    int atual_arvore3 = 0;
    int atual_altura3 = 0;
    Arvore* testeZ = createnfillstringtotree(input3, &atual_arvore3);
    TNO* raiz_altura3 = stringtotree(input3, &atual_altura3);

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
    printf("Soma: %i \n", somadeintervaloarvoe(testeS, 1, 6));
    printf("Teste soma (9, 16):\n");
    printf("Soma: %i \n", somadeintervaloarvoe(testeS, 9, 16));

    if (arvorenbusca(testeS)) {
        puts("e boost");
    } else {
        puts("n e busca");
    }

    if (arvorenbusca(testeY)) {
        puts("e boost");
    } else {
        puts("n e busca");
    }

    if (eigual(testeS, testeZ)){
        puts("e igual");
    } else {
        puts("n e igual");
    }
    if (eigual(testeS, testeY)){
        puts("e igual");
    } else {
        puts("n e igual");
    }
    if (eigual(testeS, testeS)){
        puts("e igual");
    } else {
        puts("n e igual");
    }

    free(raiz);
    free(raiz_altura);
    free(raiz_altura2);
    free(raiz_altura3);
    free(testeY);
    free(testeZ);
    free(arvore);
    free(testeS);
    return 0;
}
