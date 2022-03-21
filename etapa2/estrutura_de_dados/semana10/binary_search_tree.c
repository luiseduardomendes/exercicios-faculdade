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
    node *max_left = NULL, *index = root, *b1, *b2;
    
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
            
            max_left = index->left;
            while (max_left->right != NULL)
                max_left = max_left->right;
            
            
            // remove the maximum element from its original position
            if (max_left->data < max_left->parent->data)
                max_left->parent->left = NULL;
            else
                max_left->parent->right = NULL;
            
            // save its subtrees
            b1 = max_left->left;
            
            // place maximum
            if(index->parent != NULL){
                if (index->data < index->parent->data)
                    index->parent->left = max_left;
                else
                    index->parent->right = max_left;
            }
            else
                root = max_left;

            // append the subtrees of the removed element
            max_left->left = index->left;
            max_left->right = index->right;

            // insert subtree of the maximum
            bst_insert_subtree(b1, root);

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

void print_inorder_left(node *root){
    if (root != NULL) {
        print_inorder_left(root->left);
        printf("%d\t", root->data);
        print_inorder_left(root->right);
    }
} 

node* bst_insert_subtree(node *orig, node *dest){
    if (orig != NULL){
        
        if (orig->parent->data > orig->data)
            orig->parent->left = NULL;
        else
            orig->parent->right = NULL;
        
        dest = bst_insert(dest, orig->data, NULL);

        bst_insert_subtree(orig->left, dest);
        bst_insert_subtree(orig->right, dest);

        free(orig);
    }
    else{
        return dest;
    }
    
}