#ifndef ARV_AVL_H_INCLUDED
#define ARV_AVL_H_INCLUDED
#define TAM_ESPACO 10

/* Estrutura da árvore */
typedef struct arvore_avl{
    int info;
    int altura;
    struct arvore_avl *esq;
    struct arvore_avl *dir;
}arv_avl_t;

/* Criação da arvore */
arv_avl_t *criar_avl(int _info);

/* Rotações */
arv_avl_t *rotacao_LL(arv_avl_t *A);
arv_avl_t *rotacao_RR(arv_avl_t *A);
arv_avl_t *rotacao_LR(arv_avl_t *A);
arv_avl_t *rotacao_RL(arv_avl_t *A);

/* Busca */
void *busca(arv_avl_t *raiz, int valor, int *pos_do_elemento);

/* Inserir */
arv_avl_t *insere_arv_avl(arv_avl_t *raiz, int valor, int *flag);

/* Remover */
arv_avl_t *procura_menor(arv_avl_t *atual);
arv_avl_t *remove_arv_avl(arv_avl_t *raiz, int valor);

/* Prints */
void print_arvore(arv_avl_t *raiz, int espaco);
void print_pre_ordem(arv_avl_t *raiz);
void print_em_ordem(arv_avl_t *raiz);
void print_pos_ordem(arv_avl_t *raiz);

/* Funções de suporte */
int altura_NO(arv_avl_t* no);
int fator_balanceamento_NO(arv_avl_t* no);
int maior(int a, int b);

#endif // ARV_AVL_H_INCLUDED
