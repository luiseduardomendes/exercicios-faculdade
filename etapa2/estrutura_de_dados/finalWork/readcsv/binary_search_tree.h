#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    char key[32];
    int occurrences;
}bst_node;

bst_node* bst_init();
bst_node* bst_search(bst_node *root, char* key);
bst_node* bst_insert(bst_node *root, char* key);
// bst_node* bst_remove(bst_node *root, char* key);
void print_inorder_left(bst_node *root);
int strcmp2(char *a, char *b);