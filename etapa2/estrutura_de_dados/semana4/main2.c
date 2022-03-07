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
    return 0;
}

t_node_doubly* toDoubly(t_node *headLinked){
    t_node_doubly* index_doubly = headLinked;
    t_node *ant = NULL;
    while (headLinked != NULL){
        index_doubly = malloc(sizeof(t_node_doubly));
        
        index->prev = ant;
        index->data = 
    }
    else    
        return NULL;
}