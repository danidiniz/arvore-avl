#include <stdio.h>
#include <stdlib.h>
#include "arv_avl.h"
#include "menu.h"

void executar_menu(){
    while(quit != 8){
        printf("--------------- MENU ---------------\n");
        printf("0- Criar arvore.\n");
        printf("1- Inserir.\n");
        printf("2- Remover.\n");
        printf("3- Busca.\n");
        printf("4- Printar arvore.\n");
        printf("5- Printar pre-ordem.\n");
        printf("6- Printar em-ordem.\n");
        printf("7- Printar pos-ordem.\n");
        printf("8- Finalizar programa.\n\n");

        do{
        printf("O que deseja? ");
        scanf("%d", &quit);

        switch(quit){
        case 0:
            printf("Valor da raiz: ");
            scanf("%d", &n);
            raiz = criar_avl(n);
            break;
        case 1:
            if(raiz == NULL){
                printf("Crie a arvore primeiro.\n");
                break;
            }
            printf("Valor do elemento: ");
            scanf("%d", &n);
            raiz = insere_arv_avl(raiz, n, &flag);
            break;
        case 2:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            printf("Elemento que deseja remover: ");
            scanf("%d", &n);
            raiz = remove_arv_avl(raiz, n);
            break;
        case 3:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            printf("Elemento que deseja procurar: ");
            scanf("%d", &n);
            busca(raiz, n, &pos_element);
            if(pos_element == -1) pos_element = 0;
            else printf("Posicao do elemento no array: %d\n", pos_element);
            break;
        case 4:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            print_arvore(raiz, 0);
            break;
        case 5:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            print_pre_ordem(raiz);
            break;
        case 6:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            print_em_ordem(raiz);
            break;
        case 7:
            if(raiz == NULL){
                printf("Arvore vazia.\n");
                continue;
            }
            print_pos_ordem(raiz);
            break;
        case 8:
            break;
        case 9:
            break;
        }

        printf("\n");
        //printf("\n--------------------------------------------------------------------------\n\n");

        } while(quit != 8);

    }
}
