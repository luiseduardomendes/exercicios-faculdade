#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// pre-fixado a esquerda
void preorderLeft(Node *root) {
    if (root!= NULL) {
        printf("%c,",root->data);
        preorderLeft(root->left);
        preorderLeft(root->right);
    }
}

// central a esquerda
void inorderLeft(Node *root) {
    if (root!= NULL) {
        inorderLeft(root->left);
        printf("%c,",root->data);
        inorderLeft(root->right);
    }
}

// pre-fixado a direita
void preorderRight(Node *root) {
    if (root!= NULL) {
        printf("%c,",root->data);
        preorderRight(root->right);
        preorderRight(root->left);
    }
}

//pos-fixado a esquerda
void posorderLeft(Node *root) {
    if (root!= NULL) {
        posorderLeft(root->left);
        posorderLeft(root->right);
        printf("%c,",root->data);
    }
} 