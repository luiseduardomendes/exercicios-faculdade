#include "doubly_linked_list.h"

void list_init(List_desc *desc){
    desc->head = NULL;
    desc->isEmpty = true;
    desc->last = NULL;
    desc->size = 0;
}

void list_insert_begin(List_desc *d, t_info data){
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

void list_insert_end(List_desc *d, t_info data){
    t_node *new_elem = NULL;

    new_elem = (t_node*) malloc (sizeof(t_node));

    new_elem->next = NULL;
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
    (d->size) ++;
}

void list_clear(List_desc *d){
    t_node *index = NULL;

    for(index = d->head->next; index->next != NULL; index = index->next)
        free(index->prev);
    free(index->prev);
    free(index);

    list_init(d);
}


bool list_remove(List_desc *d, int pos){
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

bool list_insert_position(List_desc *d, t_info data, int pos){
    t_node *index = NULL, *new_element = NULL;
    int i;

    // allocates memory to the new node
    new_element = (t_node*) malloc (sizeof(t_node));
    new_element->info = data;

    if(pos <= d->size && pos >= 0){ // verify if position is valid
        if (!(d->isEmpty)){ // if list is not empty
            if (pos == 0){ // if position is the first element 
                list_insert_begin(d, data);
            }
            else if(pos == d->size){ // position is the last element
                list_insert_end(d, data);
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
            list_insert_begin(d, data);
        }
        (d->size) ++;
        d->isEmpty = false;
    }
    else{
        return false;
    }
    return true;
}

void list_print(List_desc *d){
    t_node *index = NULL;

    if(!(d->isEmpty)) {
        for (index = d->head; index != NULL; index = index->next)
            printf("%.2lf\t", index->info);
        printf("\n");
    }   
    else
        printf("List is empty\n");
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #elif 
        system("cls");
    #endif
}