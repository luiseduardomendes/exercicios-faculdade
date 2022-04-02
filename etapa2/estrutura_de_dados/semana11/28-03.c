#include "bst.h"
#include "stdio.h"
#include "stdlib.h"

int main(){
    pNodoA *a = NULL, *b= NULL;
    int v[] = {42, 15, 88, 6, 27, 63, 94, 20, 57, 71}, i, num;

    for (i = 0; i < 10; i ++){
        a = InsereAVL(a, v[i], &num);
    }

    b = malloc(sizeof(pNodoA));
    b->info = 42;
    b->esq = malloc(sizeof(pNodoA));
    b->esq->info = 15;
    b->esq->dir = malloc(sizeof(pNodoA));
    b->esq->dir->info = 27;
    b->esq->dir->esq = malloc(sizeof(pNodoA));
    b->esq->dir->esq->info = 20;


    printf("tree a factor: %d\n", bst_factor_tree(a));
    printf("tree b factor: %d\n", bst_factor_tree(b));
    
    return 0;

}