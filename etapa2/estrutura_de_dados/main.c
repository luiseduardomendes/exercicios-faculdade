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

t_node_doubly* toDoubly(t_node *headLinked){
    t_node_doubly *head, *ant = NULL;
    t_node *index = headLinked; // inicializa index e ant para armazenar o ultimo elemento lido 
    t_node_doubly* index_doubly = NULL; // inicializa um indice para uma nova lista duplamente encadeada
    
    while (index != NULL){

        index_doubly = malloc(sizeof(t_node_doubly)); // aloca espaco para o nodo
        if (ant == NULL)
            head = index_doubly; // head recebe o primeiro elemento, que e quando ant == NULL e index != NULL
        
        index_doubly->prev = ant; //atribui o valor do ultimo elemento lido como ponteiro para anterior do elemento atual
        index_doubly->data = index->data; // copia os outros campos 
        index_doubly->next = NULL;

        if (index->next != NULL && ant != NULL)
            index_doubly->prev->next = index_doubly; // atribui o valor do proximo em relacao ao anterior
            

        ant = index_doubly;
        index = index->next;
    }  
  
    return head;
}


int main(){
    t_node *v[5] = {NULL};
    t_node_doubly *v2[5] = {NULL}, *index;

    for (int i =0; i < 5; i ++){
        v[i] = malloc(sizeof(t_node));
        v2[i] = malloc(sizeof(t_node_doubly));
    }

    (v[0])->next = v[1];
    (v[0])->data = 1;
    (v[1])->next = v[2];
    (v[1])->data = 2;
    (v[2])->next = v[3];
    (v[2])->data = 3;
    (v[3])->next = v[4];
    (v[3])->data = 4;

    v2[0] = toDoubly(v[0]);

    for (index = v2[0]; index != NULL; index = index->next){
        printf("%p\t%p\t%p\n", index->prev, index, index->next);
    }

    return 0;
}