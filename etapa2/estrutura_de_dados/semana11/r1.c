#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

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