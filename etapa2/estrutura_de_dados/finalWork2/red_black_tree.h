#pragma once

#include <stdio.h>
#include <stdlib.h>

enum {RBT_RED, RBT_BLACK};

typedef struct rbt_node {
    struct rbt_node *parent;
    struct rbt_node *left;
    struct rbt_node *right;
    int color;
    char word[64];
    char synonym[64];
    
}rbt_node;

rbt_node* rbt_init();
rbt_node* rbt_search(rbt_node *root, char word[]);
rbt_node* rbt_insert(rbt_node *root, char word[], char synonym[]);
rbt_node* rbt_remove(rbt_node *root, char word[]);
rbt_node* rbt_insert_fixup(rbt_node *root, rbt_node *z);
rbt_node* rbt_left_rotate(rbt_node *root, rbt_node *z);
rbt_node* rbt_right_rotate(rbt_node *root, rbt_node *z);
void rbt_print_inorder_left(rbt_node *root);
int strcmp2(char *a, char *b);