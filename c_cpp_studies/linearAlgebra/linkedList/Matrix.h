#include <stdio.h>
#include <stdbool.h>
#include "linkedList/doubly_linked_list.h"

typedef List_desc List;

typedef struct Shape{
    int lines, columns;
}Shape;

typedef struct Matrix{
    Shape shape;
    bool isInversible;
    bool isEmpty;
    List elements;
}Matrix;

void Matrix_init(Matrix *A, int lines, int columns, ...);

void Matrix_print(Matrix A);
