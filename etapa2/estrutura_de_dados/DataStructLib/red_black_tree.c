#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

rbt_node* rbt_init(){
    return NULL;
}

rbt_node* rbt_search(rbt_node *root, int key){
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

rbt_node* rbt_create_node(int item){
    rbt_node *x = NULL;
    x = malloc(sizeof(rbt_node));
    x->data = item;
    x->left = NULL;
    x->right = NULL;
    x->parent = NULL;
    return x;
}

rbt_node* rbt_insert(rbt_node *root, int item){
    rbt_node *y = root, *x = root;
    rbt_node *z = NULL;
    z = rbt_create_node(item);
    printf("Hello");
    while (x != NULL){
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;

    if (y == NULL)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;
        
    z->color = RBT_RED;

    root = rbt_insert_fixup(root, z);
    
    return root;
}

rbt_node *rbt_insert_fixup(rbt_node *root, rbt_node *z) {
    rbt_node *x = NULL, *y = NULL;
    
    while (z->parent != NULL || z->parent->color == RBT_RED) {
        if(z->parent == z->parent->parent->left) {
            y = z->parent->parent->right;
            if (y != NULL && y->color == RBT_RED) {
                z->parent->color = RBT_BLACK;
                y->color = RBT_BLACK;
                z->parent->parent->color = RBT_RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    root = rbt_left_rotate(root, z);
                }
                z->parent->color = RBT_BLACK;
                z->parent->parent->color = RBT_RED;
                root = rbt_right_rotate(root, z);
            }
        }
        else {
            y = z->parent->parent->left;
            if (y != NULL && y->color == RBT_RED) {
                z->parent->color = RBT_BLACK;
                y->color = RBT_BLACK;
                z->parent->parent->color = RBT_RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    root = rbt_right_rotate(root, z);
                }
                z->parent->color = RBT_BLACK;
                z->parent->parent->color = RBT_RED;
                root = rbt_left_rotate(root, z);
            }
        }
    }
    root->color = RBT_BLACK;
    return root;
}

rbt_node *rbt_left_rotate(rbt_node *root, rbt_node *x) {
    rbt_node *y;
    y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent != NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
    
    return root;
}

rbt_node *rbt_right_rotate(rbt_node *root, rbt_node *x) {
    rbt_node *y;
    y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent != NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
    
    return root;
}

void rbt_print_inorder_left(rbt_node *root){
    if (root != NULL) {
        rbt_print_inorder_left(root->left);
        printf("%d ", root->data);
        rbt_print_inorder_left(root->right);
    }
} 


