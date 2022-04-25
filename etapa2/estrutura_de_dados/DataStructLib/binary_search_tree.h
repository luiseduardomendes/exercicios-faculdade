#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
    int data;
}bst_node;

bst_node* bst_init();
bst_node* bst_search(bst_node *root, int key);
bst_node* bst_insert(bst_node *root, int item, bst_node *prev);
bst_node* bst_remove(bst_node *root, int item);
void print_inorder_left(bst_node *root);