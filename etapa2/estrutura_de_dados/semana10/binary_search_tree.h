#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *parent;
    struct node *left;
    struct node *right;

    int data;
}node;

node* bst_search(node *root, int key);
node* bst_insert(node *root, int item, node *prev);
node* bst_remove(node *root, int item);
void print_inorder_left(node *root);