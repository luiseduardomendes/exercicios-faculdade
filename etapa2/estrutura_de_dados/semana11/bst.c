#include "bst.h"
#include "stdlib.h"
#include "stdio.h"

pNodoA* InsereAVL (pNodoA *a, int x, int *ok){
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
    x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL) {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (x < a->info) {
        a->esq = InsereAVL(a->esq,x,ok);
        if (*ok) {
            switch (a->FB) {
                case -1: 
                    a->FB = 0; 
                    *ok = 0; 
                    break;
                case 0: 
                    a->FB = 1; 
                    break;
                case 1: 
                    a = Caso1(a,ok); 
                    break;
            }
        }
    }
    else {
        a->dir = InsereAVL(a->dir,x,ok);
        if (*ok) {
            switch (a->FB) {
                case 1: 
                    a->FB = 0; 
                    *ok = 0; 
                    break;
                case 0: 
                    a->FB = -1; 
                    break;
                case -1: 
                    a = Caso2(a,ok); 
                    break;
            }
        }
    }
    return a;
}


pNodoA* Caso1 (pNodoA *a , int *ok)
{
    pNodoA *z;
    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;
    return a;
}


pNodoA* Caso2 (pNodoA *a , int *ok)
{
    pNodoA *z;
    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);
    
    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* rotacao_direita(pNodoA* p){
    pNodoA *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    return p;
}

pNodoA* rotacao_esquerda(pNodoA *p){
    pNodoA *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;
    return p;
} 

pNodoA* rotacao_dupla_direita (pNodoA* p){
    pNodoA *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;
    
    if (v->FB == 1) p->FB = -1;
    else p->FB = 0;
    
    if (v->FB == -1) u->FB = 1;
    else u->FB = 0;
    
    p = v;
    return p;
} 


pNodoA* rotacao_dupla_esquerda (pNodoA *p){
    pNodoA *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;
    if (y->FB == -1) p->FB = 1;
    else p->FB = 0;

    if (y->FB == 1) z->FB = -1;
    else z->FB = 0;
    
    p = y;
    return p;
}


int bst_avl_height_node(pNodoA *a){
    int height_left = 0, height_right = 0;
    
    if (a != NULL){
        height_left = 1 + bst_avl_height_node(a->esq);
        height_right = 1 + bst_avl_height_node(a->dir);

        if (height_left > height_right)
            return height_left;
        return height_right;
    }
    return 0;
}

int bst_factor(pNodoA *a){
    return (bst_avl_height_node(a->esq) - bst_avl_height_node(a->dir));
}

int bst_factor_tree(pNodoA *a){
    int fat_a, fat_b, fat_c;
    
    if (a != NULL){
        fat_a = abs(bst_factor_tree(a->esq));
        fat_b = abs(bst_factor_tree(a->dir));
        fat_c = abs(bst_factor(a));
        
        if (fat_a > fat_b){
            if (fat_a > fat_c)
                return fat_a; // a > b && a > c
            return fat_c; // a > b && a <= c
        }
        if (fat_b > fat_c)
            return fat_b; // b >= a && b > c
        return fat_c; // b >= a && b <= c
    }
    return 0;
}
