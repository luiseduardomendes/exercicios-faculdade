#pragma once

struct TNodoA{
    int info;
    int FB;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* InsereAVL (pNodoA *a, int x, int *ok);
pNodoA* Caso1 (pNodoA *a , int *ok);
pNodoA* Caso2 (pNodoA *a , int *ok);
pNodoA* rotacao_direita(pNodoA* p);
pNodoA* rotacao_esquerda(pNodoA* p);
pNodoA* rotacao_dupla_direita(pNodoA* p);
pNodoA* rotacao_dupla_esquerda(pNodoA* p);
int bst_avl_height_node(pNodoA *a);
int bst_factor(pNodoA *a);
int bst_factor_tree(pNodoA *a);