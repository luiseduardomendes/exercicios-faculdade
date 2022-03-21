#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

int main(){
    node *root = NULL;
    int v[] = {40, 30, 50, 90, 45, 80, 95, 20, 25, 70, 75, 65}, i;

    for (i = 0; i < 12; i ++){
        root = bst_insert(root, v[i], NULL);
    }

    print_inorder_left(root);
    printf("\n");

    //printf("%p\n", bst_search(root, 30));
    //printf("%p\t%p\t%p\n", root, root->left, root->right);
    //printf("%p\t%p\t%p\n", root->left, root->left->left, root->left->right);
    //printf("%p\t%p\t%p\n", root->right, root->right->left, root->right->right);
    root = bst_remove(root, 90);

    print_inorder_left(root);
    printf("\n");
    
    
    root = bst_remove(root, 20);

    print_inorder_left(root);
    printf("\n");

    root = bst_remove(root, 50);

    print_inorder_left(root);
    printf("\n");

    root = bst_remove(root, 40);

    print_inorder_left(root);
    printf("\n");

    return 0;
}

