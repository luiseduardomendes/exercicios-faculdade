#include "Matrix.h"
#include <stdarg.h>

void Matrix_init(Matrix *A, int lines, int columns, ...){
    va_list ap;
    int i, j;


    list_init(&(A->elements));
    list_print(&(A->elements));

    
    va_start(ap, columns);
    

    for (i = 0; i < columns * lines; i ++){
        
            
        list_insert_begin(&(A->elements), va_arg(ap, t_info));
            
        
    }

    A->isEmpty = false;
    A->shape.lines = lines;
    A->shape.columns = columns;

    va_end(ap);
}  

void Matrix_print(Matrix A){
    int i, j;
    t_node *index = A.elements.head;

    for (i = 0; i < A.shape.columns; i ++){
        for (j = 0; j < A.shape.lines; j ++){
            printf("%.2lf\t", index->info);
            index = index->next;
        }
    }
}