#include <stdio.h>
#include <stdlib.h>

typedef struct t_node{
    struct t_node *next;
    int data;
}t_node;

typedef struct t_node_doubly{
    struct t_node_doubly *next;
    struct t_node_doubly *prev;
    int data;
}t_node_doubly;

int main(){
    t_node =NULL;
    return 0;
}

t_node_doubly* toDoubly(t_node *headLinked){
    
    t_node *ant = NULL, *index = headLinked;
    t_node_doubly* index_doubly = NULL;

    while (index != NULL){
        index_doubly = malloc(sizeof(t_node_doubly));
        
        index_doubly->prev = ant;
        index_doubly->data = index->data;
        index_doubly->next = index->next;
    }  
    return index_doubly;
}