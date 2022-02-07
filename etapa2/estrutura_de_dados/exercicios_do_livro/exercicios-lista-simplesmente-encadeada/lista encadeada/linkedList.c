#include "linkedList.h"

void list_updateSizeOfDesc(t_list *list){
    int size = 0;
    t_node *index;

    for(index = list->first; index != NULL; index = index->next)
        size ++;

    list->size = size;
}

int list_sizeOf(t_list list){
    return list.size;
}

int list_max(t_list list){
    int number = list.first->data.id;
    t_node *index;

    for(index = list.first->next; index != NULL; index = index->next)
        if (index->data.id > number)
            number = index->data.id;

    return number;
}

t_list list_createList(){
    t_list list;
    list.first = NULL;
    list.last = NULL;
    list.size = 0;

    return list;
}

void list_append(t_list *list, t_data data){
    t_node *newNode;

    newNode = (t_node *) malloc(sizeof(t_node));
    newNode->data = data;

    if(list->size != 0){
        newNode->prev = list->last;
        newNode->next = NULL;

        list->last->next = newNode;
        list->last = newNode;
    }
    else{
        newNode->prev = NULL;
        newNode->next = NULL;

        list->first = newNode;
        list->last = newNode;
    }

    (list->size) ++;
}

void list_print(t_list list){
    t_node *index;

    for(index = list.first; index != NULL; index = index->next)
        printf("%d\t", index->data.id);
    printf("\n");
}

t_list list_randomList(int size, int min, int max){
    srand(time(NULL));
    int i = 0;
    t_data data;
    t_list list = list_createList();

    for(i = 0; i < size; i ++){
        data.id = min + (rand() % max+1);
        data.value = 0;
        strcpy(data.name, "Name");

        list_append(&list, data);
    }
    return list;
}

void list_removeElement(t_list *list, int elementId){
    t_node *index;
    for(index = list->first; index != NULL; index = index->next)
        if(index->data.id == elementId){
            if(index->next == NULL){
                index->prev->next = NULL;
                list->last = index->prev;
            }
            else if(index->prev == NULL){
                index->next->prev = NULL;
                list->first = index->next;
            }
            else{
                index->prev->next = index->next;
                index->next->prev = index->prev;
            }
            free(index);
            (list->size) --;
            break;
        }
}
void list_removeRepeated(t_list *list){
    t_node *i = NULL, *j = NULL;
    
    
    for(i = list->first;i != NULL; i = i->next){
        
        for (j = i->next; j != NULL; j = j->next){
            if(i != j && i->data.id == j->data.id){
                list_removeElement(list, j->data.id);
            }
        }
    }
}

