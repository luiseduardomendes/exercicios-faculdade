#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

bst_node* bst_init(){
    return NULL;
}

bst_node* bst_search(bst_node *root, int key){
    while(root != NULL){
        if (key == root->data)
            return root;
        else {
            if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
    }
    return NULL;
}

bst_node* bst_insert(bst_node *root, int item, bst_node *prev){
    if (root == NULL){
        root = malloc(sizeof(bst_node));
        root->data = item;
        root->right = NULL;
        root->left = NULL;
        root->parent = prev;
        if(prev != NULL)
            if (root->parent->data > item)
                prev->left = root;
            else
                prev->right = root;
    }
    else {
        if (root->data < item)
            bst_insert(root->right, item, root);
        else
            bst_insert(root->left, item, root);
    }
    return root;
}

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

void print_inorder_left(bst_node *root){
    if (root != NULL) {
        print_inorder_left(root->left);
        printf("%d\t", root->data);
        print_inorder_left(root->right);
    }
} 

