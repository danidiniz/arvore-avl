#include <stdio.h>
#include <stdlib.h>
#include "arv_avl.h"

arv_avl_t *criar_avl(int _info){
    arv_avl_t *raiz = (arv_avl_t*)malloc(sizeof(arv_avl_t));
    raiz->info = _info;
    raiz->altura = 0;
    raiz->esq = NULL;
    raiz->dir = NULL;
    return raiz;
}

int altura_NO(arv_avl_t* no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

int fator_balanceamento_NO(arv_avl_t* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

void *busca(arv_avl_t *raiz, int valor, int *pos_do_elemento){
    if(raiz == NULL){
        printf("\nChave nao encontrada\n");
        *pos_do_elemento = -1;
    }
    else if (raiz->info == valor){
        printf("\nValor encontrado!\n");
    } else {
        if (valor < raiz->info){
            *pos_do_elemento = 2* (*pos_do_elemento) + 1;
            busca(raiz->esq, valor, *pos_do_elemento);
        }
        else{
            *pos_do_elemento = 2* (*pos_do_elemento) + 2;
            busca(raiz->dir, valor, *pos_do_elemento);
        }
    }
}

void print_pre_ordem(arv_avl_t *raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        printf("%d\n", raiz->info);
        print_pre_ordem(raiz->esq);
        print_pre_ordem(raiz->dir);
    }
}

void print_em_ordem(arv_avl_t *raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        print_em_ordem(raiz->esq);
        printf("%d\n", raiz->info);
        print_em_ordem(raiz->dir);
    }
}

void print_pos_ordem(arv_avl_t *raiz){
    if(raiz == NULL)
        return;
    if(raiz != NULL){
        print_pos_ordem(raiz->esq);
        print_pos_ordem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

/*---------------------------------------*/

arv_avl_t *rotacao_LL(arv_avl_t *A){
    printf("RotacaoLL no elemento %d\n", A->info);
    arv_avl_t *B;
    B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    A->altura = maior(altura_NO(A->esq),altura_NO(A->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),A->altura) + 1;
    A = B;
    return A;
}

arv_avl_t *rotacao_RR(arv_avl_t *A){
    printf("RotacaoRR no elemento %d\n", A->info);
    arv_avl_t *B;
    B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    A->altura = maior(altura_NO(A->esq),altura_NO(A->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),A->altura) + 1;
    A = B;
    //printf("Retornou %d\n", A->info);
    return A;
}

arv_avl_t *rotacao_LR(arv_avl_t *A){
    A->esq = rotacao_RR(A->esq);
    A = rotacao_LL(A);
    //printf("Fim da LR Retornou %d\n", A->info);
    return A;
}

arv_avl_t *rotacao_RL(arv_avl_t *A){
    A->dir = rotacao_LL(A->dir);
    A = rotacao_RR(A);
    return A;
}


arv_avl_t *insere_arv_avl(arv_avl_t *raiz, int valor, int *flag){
    if(raiz == NULL){//árvore vazia ou nó folha
        raiz = criar_avl(valor);
        *flag = 1;
    }
    else {
        if(valor < raiz->info){
            raiz->esq = insere_arv_avl(raiz->esq, valor, flag);
            if(*flag == 1){
                if(fator_balanceamento_NO(raiz) >= 2){
                    if(valor < raiz->esq->info ){
                        printf("\n\nAntes de rotacionar LL:\n");
                        print_arvore(raiz, 0);
                        printf("\n\n--------------------------------------------\n\n");

                        raiz = rotacao_LL(raiz);

                        printf("Apos rotacao LL:\n");
                        print_arvore(raiz, 0);
                    }
                    else{
                        printf("\n\nRotacao LR do %d\n", raiz->info);
                        printf("Antes de rotacionar LR:\n");
                        print_arvore(raiz, 0);
                        printf("\n\n--------------------------------------------\n\n");

                        raiz = rotacao_LR(raiz);

                        printf("Apos rotacao LR:\n");
                        print_arvore(raiz, 0);
                    }
                }
            }
        }
        else if(valor > raiz->info){
            raiz->dir = insere_arv_avl(raiz->dir, valor, flag);
            //printf("Inseriu na dir: %d\nValor da flag: %d\n\n", raiz->dir->info, *flag);
            if(*flag == 1){
                //printf("Fator bal do %d: %d\n", raiz->info, fatorBalanceamento_NO(raiz));
                if(fator_balanceamento_NO(raiz) >= 2){
                    if(raiz->dir->info < valor){

                        printf("\n\nAntes de rotacionar RR:\n");
                        print_arvore(raiz, 0);
                        printf("\n\n--------------------------------------------\n\n");

                        raiz = rotacao_RR(raiz);

                        printf("Apos rotacao RR:\n");
                        print_arvore(raiz, 0);

                    }else{
                        printf("\n\nRotacao RL do %d\n", raiz->info);
                        printf("Antes de rotacionar RL:\n");
                        print_arvore(raiz, 0);
                        printf("\n\n--------------------------------------------\n\n");

                        raiz = rotacao_RL(raiz);

                        printf("Apos rotacao RL:\n");
                        print_arvore(raiz, 0);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            flag = 0;
        }
        //printf("final do metodo e valor %d\n", raiz->info);

        raiz->altura = maior(altura_NO(raiz->esq),altura_NO(raiz->dir)) + 1;
    }
    return raiz;
}

arv_avl_t *procura_menor(arv_avl_t *atual){
    arv_avl_t *no1 = atual;
    arv_avl_t *no2 = atual->dir;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    return no1;
}

arv_avl_t *remove_arv_avl(arv_avl_t *raiz, int valor){
	if(raiz == NULL){// valor não existe
	    printf("valor não existe!!\n");
	    return 0;
	}

	if(valor < raiz->info){
        raiz->esq = remove_arv_avl(raiz->esq,valor);
	    if(raiz!= NULL){
            if(fator_balanceamento_NO(raiz) >= 2){
                if(altura_NO(raiz->dir->esq) <= altura_NO(raiz->dir->dir))
                    raiz = rotacao_RR(raiz);
                else
                    raiz = rotacao_RL(raiz);
            }
	    }
	}

	if(raiz->info < valor){
        raiz->dir = remove_arv_avl(raiz->dir,valor);
	    if(raiz != NULL){
            if(fator_balanceamento_NO(raiz) >= 2){
                if(altura_NO(raiz->esq->dir) <= altura_NO(raiz->esq->esq) )
                    raiz = rotacao_LL(raiz);
                else
                    raiz = rotacao_LR(raiz);
            }
	    }
	}

	if(raiz->info == valor){
	    if((raiz->esq == NULL || raiz->dir == NULL)){/* Nó tem 1 filho ou nenhum */
			arv_avl_t *oldNode = raiz;
			if(raiz->esq != NULL)
                raiz = raiz->esq;
            else
                raiz = raiz->dir;
			free(oldNode);
		}
		else { /* Nó tem 2 filhos */
			arv_avl_t *temp = procura_menor(raiz->esq);
			raiz->info = temp->info;
			raiz->esq = remove_arv_avl(raiz->esq, raiz->info);
            if(fator_balanceamento_NO(raiz) >= 2){
				if(altura_NO(raiz->esq->dir) <= altura_NO(raiz->esq->esq))
					raiz = rotacao_LL(raiz);
				else
					raiz = rotacao_LR(raiz);
			}
		}
		if (raiz != NULL)
            raiz->altura = maior(altura_NO(raiz->esq),altura_NO(raiz->dir)) + 1;
		return raiz;
	}

	raiz->altura = maior(altura_NO(raiz->esq),altura_NO(raiz->dir)) + 1;

	return raiz;
}


void print_arvore(arv_avl_t *raiz, int espaco){
    if (raiz == NULL)
        return;

    espaco += TAM_ESPACO;

    /* Percorre até nó mais a direita */
    print_arvore(raiz->dir, espaco);

    printf("\n");
    int i;
    for (i = TAM_ESPACO; i < espaco; i++)
        printf(" ");
    printf("%d(%d)\n", raiz->info, raiz->altura);

    print_arvore(raiz->esq, espaco);
}
