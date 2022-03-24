#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    Node *a,*b,*c,*d,*e,*f,*g,*h;
    a = malloc(sizeof(Node));
    b = malloc(sizeof(Node));
    c = malloc(sizeof(Node));
    d = malloc(sizeof(Node));
    e = malloc(sizeof(Node));
    f = malloc(sizeof(Node));
    g = malloc(sizeof(Node));
    h = malloc(sizeof(Node));

    a->data = 'A';
    a->left = b;
    a->right = c;

    b->data = 'B';
    b->left = NULL;
    b->right = d;

    c->data = 'C';
    c->left = e;
    c->right = f;

    d->data = 'D';
    d->left = NULL;
    d->right = NULL;

    e->data = 'E';
    e->left = g;
    e->right = h;

    f->data = 'F';
    f->left = NULL;
    f->right = NULL;

    g->data = 'G';
    g->left = NULL;
    g->right = NULL;

    h->data = 'H';
    h->left = NULL;
    h->right = NULL;

    printf("preorder left: \n");
    preorderLeft(a);
    printf("\n");

    printf("preorder right: \n");
    preorderRight(a);
    printf("\n");

    printf("posorder left: \n");
    posorderLeft(a);
    printf("\n");

    printf("inorder left: \n");
    inorderLeft(a);
    printf("\n");

    return 0;
}