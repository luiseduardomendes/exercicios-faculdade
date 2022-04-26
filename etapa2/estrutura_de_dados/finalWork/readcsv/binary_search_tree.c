#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bst_node* bst_init(){
    return NULL;
}

bst_node* bst_search(bst_node *root, char* key){
    while(root != NULL){
        if (strcmp2(key, root->key) == 0)
            return root;
        else {
            if (strcmp2(key, root->key) == -1)
                root = root->left;
            else
                root = root->right;
        }
    }
    return NULL;
}

bst_node* bst_insert(bst_node *root, char* key){
    int cmp;
    if (root == NULL){
        root = malloc(sizeof(bst_node));
        strcpy(root->key, key);
        root->right = NULL;
        root->left = NULL;
        root->occurrences = 1;
    }
    else {
        cmp = strcmp2(root->key, key);
        if (cmp == -1)
            root->right = bst_insert(root->right, key);
        else if (cmp == 1)
            root->left = bst_insert(root->left, key);
        else
            root->occurrences ++;
    }
    return root;
}
/*
bst_node* bst_remove(bst_node *root, int item){
    bst_node *index = root, *max;
    
    if (index != NULL){
        if (index->left == NULL && index->right == NULL){
            if (index->parent->data > index->data)
                index->parent->left = NULL;
            else
                index->parent->right = NULL;

            free(index);
        }
        else if (index->left != NULL && index->right != NULL){ // has two subtrees
            max = index->left;
            while (max->right != NULL) // finds the max value of the subtree at the left
                max = max->right;

            max->parent->right = max->left;
            max->left->parent = max->parent;
            max->left = index->left;
            index->left->parent = max;
            max->right = index->right;
            index->right->parent = max;
            max->parent = index->parent;

            free(index);
        }
        else if (index->left != NULL){
            if (index->parent->data > index->data)
                index->parent->left = index->left;
            else
                index->parent->right = index->left;
        }
        else{
            if (index->parent->data > index->data)
                index->parent->left = index->right;
            else
                index->parent->right = index->right;
        }
    }
    return root;
}
*/
void print_inorder_left(bst_node *root){
    if (root != NULL) {
        print_inorder_left(root->left);
        printf("%d\t%s\n", root->occurrences, root->key);
        print_inorder_left(root->right);
    }
} 

int strcmp2(char *a, char *b){
    while (*a == *b && *a != '\0' && *b != '\0'){
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0')
        return 0;
    else if (*a == '\0')
        return 1;
    else if (*b == '\0')
        return -1;
    else {
        if (*a > *b)
            return 1;
        else
            return -1;
    }

}