#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "red_black_tree.h"

rbt_node* rbt_init(){
    return NULL;
}

rbt_node* rbt_search(rbt_node *root, char word[]){
    while(root != NULL){
        if (!strcmp(word, root->word))
            return root;
        else {
            if (strcmp2(word, root->word))
                root = root->left;
            else
                root = root->right;
        }
    }
    return NULL;
}

rbt_node* rbt_create_node(char word[], char synonym[]){
    rbt_node *x = NULL;
    x = malloc(sizeof(rbt_node));
    strcpy(x->word, word);
    strcpy(x->synonym, synonym);
    x->left = NULL;
    x->right = NULL;
    x->parent = NULL;
    return x;
}

rbt_node* rbt_insert(rbt_node *root, char word[], char synonym[]){
    rbt_node *y = root, *x = root;
    rbt_node *z = NULL;
    z = rbt_create_node(word, synonym);
    while (x != NULL){
        y = x;
        if (strcmp2(z->word, x->word))
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (strcmp2(z->word, y->word))
        y->left = z;
    else
        y->right = z;

    z->color = RBT_RED;

    root = rbt_insert_fixup(root, z);

    return root;
}

rbt_node *rbt_insert_fixup(rbt_node *root, rbt_node *z) {
    rbt_node *x = NULL, *y = NULL;

    while (z->parent != NULL && z->parent->color == RBT_RED) {
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
                root = rbt_right_rotate(root, z->parent->parent);
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
                root = rbt_left_rotate(root, z->parent->parent);
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
    if (x->parent == NULL)
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
    if (x->parent == NULL)
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
        printf("%s - %s\n", root->word, root->synonym);
        rbt_print_inorder_left(root->right);
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

