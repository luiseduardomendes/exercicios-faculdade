#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../semana10/binary_search_tree.h"

void intersection(node *a, node *b, node **c){
        if (a != NULL){
                if (bst_search(b, a->data) != NULL)
                        *c = bst_insert(*c, a->data, NULL);
                intersection(a->left, b, c);
                intersection(a->right, b, c);
        }  
}

bool tree_cmp(node *a, node *b){
        if (a != NULL && b != NULL)
                return (a->data == b->data &&
                        tree_cmp(a->left, b->left) &&
                        tree_cmp(a->right, b->right));

        else if (a == NULL && b == NULL)
                return true;
        else
                return false;
}

int aproximation(node *a, int key, int aprox){
        if (a != NULL){
                if (a->data != key){
                        if (abs(a->data - key) < abs (aprox - key))
                                aprox = a->data;
                        if (a->data < key)
                                aprox = aproximation(a->right, key, aprox);
                        else
                                aprox = aproximation(a->left, key, aprox);                                
                }
        }
        return aprox;
}


int main(){
        node *a, *b, *c;

        a = NULL;
        b = NULL;
        c = NULL;

        a = bst_insert(a, 10, NULL);
        a = bst_insert(a, 8, NULL);
        a = bst_insert(a, 15, NULL);
        a = bst_insert(a, 5, NULL);
        a = bst_insert(a, 9, NULL);
        a = bst_insert(a, 20, NULL);
        a = bst_insert(a, 4, NULL);
        
        b = bst_insert(b, 10, NULL);
        b = bst_insert(b, 8, NULL);
        b = bst_insert(b, 15, NULL);
        b = bst_insert(b, 5, NULL);
        b = bst_insert(b, 9, NULL);
        b = bst_insert(b, 20, NULL);
        b = bst_insert(b, 1, NULL);

        
        printf("%d\n", aproximation(a, 13, 0));
        
        return 0;
}