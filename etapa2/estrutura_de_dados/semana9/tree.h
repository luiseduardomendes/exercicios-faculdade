#pragma once

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// pre-fixado a esquerda
void preorderLeft(Node *a);

// central a esquerda
void inorderLeft(Node *a);

// pre-fixado a direita
void preorderRight(Node *a);

// pos-fixado a esquerda
void posorderLeft(Node *a);