#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_NAME 20
typedef struct t_info_node{
    int id;
    char name[SIZE_NAME];
    float price;
}t_info_node;

typedef struct t_node{
    t_info_node info;
    struct t_node* prev;
    struct t_node* next;
}t_node;

t_node* list_init(void);
void list_print(t_node* head);
void list_print_reversed(t_node *head);
t_node* list_insert_begin(t_node *head, t_info_node data);
t_node* list_insert_end(t_node *head, t_info_node data);
t_node* list_clear(t_node* head);
t_node* list_remove(t_node *head, int id);


void list_print_node(t_node node);
t_info_node list_input_node();
void clear_screen();