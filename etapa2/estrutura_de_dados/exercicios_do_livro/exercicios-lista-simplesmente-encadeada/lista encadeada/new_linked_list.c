#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME_SIZE 10

typedef struct t_data
{
    int id;
    char name[NAME_SIZE];
}t_data;


typedef struct t_node
{
    t_data data;
    struct t_node *next;
}t_node;

t_node* invert_list(t_node* head);
void list_print(t_node* head);

int main()
{
    t_node *head = NULL, *e1 = NULL, *e2 = NULL, *e3 = NULL;
    head = (t_node*)malloc(sizeof(t_node));
    e1 = (t_node*)malloc(sizeof(t_node));
    e2 = (t_node*)malloc(sizeof(t_node));
    e3 = (t_node*)malloc(sizeof(t_node));
    head->data.id = 0;
    head->next = e1;
    e1->data.id = 1;
    e1->next = e2;
    e2->data.id = 2;
    e2->next = e3;
    e3->data.id = 3;
    e3->next = NULL;
    list_print(head);
    head = invert_list(head);
    list_print(head);
    return 0;    
}
t_node* invert_list(t_node* head)
{
    t_node *index = NULL, buffer, *output = NULL;
    t_node *prev = NULL, *prev2 = NULL;
    t_node bufferPrev, bufferPrev2;

    bufferPrev = *(head->next);
    bufferPrev2 = *head;
    prev = (head->next);
    prev2 = head;


    for (index = head->next->next; index->next->next != NULL; index = index->next){
        

    }
    head->next = NULL;

    output = index;
    return output;      
}

void list_print(t_node *head){
    t_node *index = NULL;

    for (index = head; index != NULL; index = index->next)
        printf("%d ", index->data.id);
    printf("\n");

}