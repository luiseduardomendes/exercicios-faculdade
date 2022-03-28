#include "bst.h"
#include "stdio.h"
#include "stdlib.h"

int main(){
    pNodoA *root = NULL;
    int v[] = {8,4,9,2,6,1}, i, num;

    for (i = 0; i < 6; i ++){
        root = InsereAVL(root, v[i], &num);
    }

    printf("root:                   %d\n", bst_avl_height_node(root));
    printf("root->right:            %d\n", bst_avl_height_node(root->dir));
    printf("root->left:             %d\n", bst_avl_height_node(root->esq));
    printf("root->right->right:     %d\n", bst_avl_height_node(root->dir->dir));
    printf("root->left->right:      %d\n", bst_avl_height_node(root->esq->dir));
    printf("root->right->left:      %d\n", bst_avl_height_node(root->dir->esq));
    printf("root->left->left:       %d\n", bst_avl_height_node(root->esq->esq));
    return 0;

}