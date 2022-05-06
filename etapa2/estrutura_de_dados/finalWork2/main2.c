#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

int main(){
    rbt_node *root;
    int num;
    root = rbt_init();

    printf("Insira um numero: ");
    scanf("%d", &num);
    do {
        printf("Hello\n");
        root = rbt_insert(root, num);
        rbt_print_inorder_left(root);
        printf("\nInsira um numero: ");
        scanf("%d", &num);
    } while (num != 0);
    
    return 0;
}