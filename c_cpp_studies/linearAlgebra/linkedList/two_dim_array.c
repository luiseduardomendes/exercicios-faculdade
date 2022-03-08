#include "two_dim_array.h"


/*
void mat_init(Matrix *A){
    A->head = NULL;
    A->isEmpty = true;
    A->last = NULL;
    A->shape.columns = 0;
    A->shape.lines = 0;
}

void mat_insert_begin(Matrix *A, t_info data){
    t_node *new_elem = NULL;
    
    new_elem = (t_node*) malloc (sizeof(t_node));
    
    new_elem->prev = NULL;
    new_elem->next = d->head;
    new_elem->info = data;    

    if(!(d->isEmpty)){
        d->head->prev = new_elem; 
    }
    else
        d->last = new_elem;
    
    d->head = new_elem;
    d->isEmpty = false;
    (d->size) ++;
}

void mat_insert_end(Matrix *A, ){
    List_desc *new_list = NULL;

    new_list = malloc (sizeof(List_desc));

    new_list->last = NULL;
    new_elem->info = data;
    d->isEmpty = false;

    if(!(d->isEmpty)){ // if (list.is_empty() == false)
        new_elem->prev = d->last;
        d->last->next = new_elem;
    }
    else{ 
        new_elem->prev = NULL;
        d->head = new_elem;
        d->last = new_elem;
    }   
}

void mat_clear(Matrix *A){
    t_node *index = NULL;

    for(index = d->head->next; index->next != NULL; index = index->next)
        free(index->prev);
    free(index->prev);
    free(index);

    mat_init(A);
}


bool mat_remove(Matrix *A, int pos){
    t_node *index = NULL;
    int i;
    bool flag;
    
    if(!(d->isEmpty)){
        if(pos > d->size || index < 0){
            flag = false;
        }
        else{
            if (pos == 0){
                d->head = d->head->next;
                free(d->head->prev);
                d->head->prev = NULL;
            }
            else if (pos == d->size){
                d->last = d->last->prev;
                free(d->last->next);
                d->last->next = NULL;
            }else{
                for (i = 0, index = d->head; i < pos; i ++, index = index->next);
                index->prev->next = index->next;
                index->next->prev = index->prev;
                free(index);
            }
            (d->size) --;
            flag = true;
        }
    }
    else{
        flag = false;
    }
    return flag;
}

bool mat_insert_position(Matrix *A, t_info data, int pos){
    t_node *index = NULL, *new_element = NULL;
    int i;

    // allocates memory to the new node
    new_element = (t_node*) malloc (sizeof(t_node));
    new_element->info = data;

    if(pos <= d->size && pos >= 0){ // verify if position is valid
        if (!(d->isEmpty)){ // if list is not empty
            if (pos == 0){ // if position is the first element 
                mat_insert_begin(d, data);
            }
            else if(pos == d->size){ // position is the last element
                mat_insert_end(d, data);
            }
            else{ // positions is in the middle of the list
                for(index = d->head, i = 0; i < pos; index = index->next, i ++);
                new_element->next = index;
                new_element->prev = index->prev;
                index->prev->next = new_element;
                index->prev = new_element;
            }
        }
        else{ // new element is the first element added
            mat_insert_begin(d, data);
        }
        (d->size) ++;
        d->isEmpty = false;
    }
    else{
        return false;
    }
    return true;
}*/

void Matrix_print(Matrix A){
    int i, j;
    t_node_Matrix *index;

    for ( index = A.head; index != NULL; index = index->next ) {
        list_print(index->list);
    }
}

void Matrix_init(Matrix *A, int lines, int columns, ...){
    int i, j;
    va_list ap;
    
    t_node_Matrix *mI, *last_index = NULL;
    
    va_start(ap, columns);

    for (i = 0; i < lines; i ++){   
        mI = (t_node_Matrix*) malloc(sizeof(t_node_Matrix));
        mI->list = malloc(sizeof(List_desc));

        if (i == 0){
            A->head = mI;
        }
        else if (i == lines - 1){
            A->last = mI;      
        }
        
        mI->next = NULL;
        mI->prev = last_index;        

        if (last_index != NULL)
            last_index->next = mI;
        
        list_init(mI->list);

        for (j = 0; j < columns; j ++) 
            list_insert_begin((mI->list), va_arg(ap, t_info));
        
        last_index = mI;
    }

    A->isEmpty = false;
    A->shape.lines = lines;
    A->shape.columns = columns;

    va_end(ap);
}  

bool Matrix_isInversible(Matrix A){
    if (Matrix_determinant(A) != 0)
        return true;
    else return false;
}

double Matrix_determinant(Matrix A){
    return 0;
}