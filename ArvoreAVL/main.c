#include <stdio.h>
#include <stdlib.h>
#include "arv_avl.c"
#include "menu.c"

int main()
{

    executar_menu();

        /****EXEMPLOS****/

    /** Rotacao esquerda dupla **/
//    int flag = 0;
//
//    ArvAVL_t *raiz = criar_avl(7);
//    raiz = insere_ArvAVL(raiz, 4, &flag);
//    raiz = insere_ArvAVL(raiz, 12, &flag);
//    raiz = insere_ArvAVL(raiz, 6, &flag);
//    raiz = insere_ArvAVL(raiz, 5, &flag);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nArvore completa:\n");
//    print_arvore(raiz, 0);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\n Busca pela chave 4:\n");
//    ArvAVL_t *resultado = Busca(raiz, 4);
//    printf("Info retornada no ponteiro de resultado: %d", resultado->info);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\n Busca pela chave 10:\n");
//    resultado = Busca(raiz, 10);
//    printf("Info retornada no ponteiro de resultado: %d\n\n", resultado->info);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nRemocao com 2 filhos:\n");
//
//    raiz = remove_ArvAVL(raiz, 5);
//    print_arvore(raiz, 0);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nRemocao com 1 filho:\n");
//
//    raiz = remove_ArvAVL(raiz, 4);
//    print_arvore(raiz, 0);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nRemocao sem filhos:\n");
//
//    raiz = remove_ArvAVL(raiz, 12);
//    print_arvore(raiz, 0);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nRemocao de valor nao existente:\n");
//
//    raiz = remove_ArvAVL(raiz, 12);
//    print_arvore(raiz, 0);
//
//    printf("\n\n--------------------------------------------\n\n");
//    printf("\n\nInserçao de repetido:\n");
//
//    raiz = insere_ArvAVL(raiz, 6, &flag);
//    print_arvore(raiz, 0);

    /** Rotacao direita dupla **/
//        int flag = 0;
//
//        ArvAVL_t *raiz = criar_avl(8);
//        raiz = insere_ArvAVL(raiz, 6, &flag);
//        raiz = insere_ArvAVL(raiz, 12, &flag);
//        raiz = insere_ArvAVL(raiz, 9, &flag);
//        raiz = insere_ArvAVL(raiz, 10, &flag);
//
//        //printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nArvore completa:\n");
//        print_arvore(raiz, 0);
//
//        printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nRemocao com 2 filhos:\n");
//
//        raiz = remove_ArvAVL(raiz, 10);
//        print_arvore(raiz, 0);

    /** Rotacao simples direita **/
//        int flag = 0;
//
//        ArvAVL_t *raiz = criar_avl(5);
//        raiz = insere_ArvAVL(raiz, 4, &flag);
//        raiz = insere_ArvAVL(raiz, 1, &flag);
//
//        //printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nArvore completa:\n");
//        print_arvore(raiz, 0);
//
//        printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nRemocao com 2 filhos:\n");
//
//        raiz = remove_ArvAVL(raiz, 4);
//        print_arvore(raiz, 0);

    /** Rotacao simples esquerda **/
//        int flag = 0;
//
//        ArvAVL_t *raiz = criar_avl(5);
//        raiz = insere_ArvAVL(raiz, 6, &flag);
//        raiz = insere_ArvAVL(raiz, 8, &flag);
//
//        printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nArvore completa:\n");
//        print_arvore(raiz, 0);
//
//        printf("\n\n--------------------------------------------\n\n");
//        printf("\n\nRemocao com 2 filhos:\n");
//
//        raiz = remove_ArvAVL(raiz, 6);
//        print_arvore(raiz, 0);

    return 0;
}
