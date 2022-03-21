#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

node* bst_search(node *root, int key){
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

node* bst_insert(node *root, int item, node *prev){
    if (root == NULL){
        root = malloc(sizeof(node));
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

node* bst_remove(node *root, int item){
    node *buffer = NULL, *index = root;
    
    index = bst_search(root, item);
    
    if (index != NULL){
        if (index->left == NULL && index->right == NULL){
            if (index->parent->data > index->data)
                index->parent->left = NULL;
            else
                index->parent->right = NULL;

            free(index);
        }
        else if (index->left != NULL && index->right != NULL){
            buffer = index->left;
            while (buffer->right != NULL)
                buffer = buffer->right;
            
            if (buffer->data < buffer->parent->data)
                buffer->parent->left = NULL;
            else
                buffer->parent->right = NULL;
            
            if (index->data < index->parent->data)
                index->parent->left = buffer;
            else
                index->parent->right = buffer;
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
        
}

void print_inorder_left(node *root){
    if (root != NULL) {
        print_inorder_left(root->left);
        printf("%d\t", root->data);
        print_inorder_left(root->right);
    }
} 