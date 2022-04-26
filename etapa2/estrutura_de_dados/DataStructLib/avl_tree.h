#pragma once

typedef struct avl_node{
    int info;
    int FB;
    struct avl_node *esq;
    struct avl_node *dir;
}avl_node;

avl_node* avl_insert (avl_node *a, int x, int *ok);
avl_node* Caso1 (avl_node *a , int *ok);
avl_node* Caso2 (avl_node *a , int *ok);
avl_node* rotacao_direita(avl_node* p);
avl_node* rotacao_esquerda(avl_node* p);
avl_node* rotacao_dupla_direita(avl_node* p);
avl_node* rotacao_dupla_esquerda(avl_node* p);
int bst_avl_height_node(avl_node *a);
int bst_factor(avl_node *a);
int bst_factor_tree(avl_node *a);