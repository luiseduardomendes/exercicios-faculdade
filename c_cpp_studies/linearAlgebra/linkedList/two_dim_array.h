#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "doubly_linked_list.h" 

typedef struct t_node_Matrix{
    List_desc *list;
    struct t_node_Matrix* prev;
    struct t_node_Matrix* next;
}t_node_Matrix;

typedef struct Shape{
    int lines, columns;
}Shape;

typedef struct Matrix{
    t_node_Matrix *head;
    t_node_Matrix *last;
    int size;
    Shape shape;
    bool isEmpty;
}Matrix;

void Matrix_init(Matrix *A, int lines, int columns, ...);
void Matrix_print(Matrix A);
double Matrix_determinant(Matrix A);
bool Matrix_isInversible(Matrix A);
//void mat_insert_begin(Matrix *A, t_node *list);
//void mat_insert_end(Matrix *A, t_node *list);
//bool mat_insert_position(Matrix *A, t_node *list, int pos);
//void mat_clear(Matrix *A);
//bool mat_remove(Matrix *A, int pos);

