#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef double t_info;

typedef struct t_node{
    t_info info;
    struct t_node* prev;
    struct t_node* next;
}t_node;

typedef struct List_desc{
    t_node *head;
    t_node *last;
    int size;
    bool isEmpty;
} List_desc;

void list_init(List_desc *desc);
void list_insert_begin(List_desc *d, t_info data);
void list_insert_end(List_desc *d, t_info data);
bool list_insert_position(List_desc *d, t_info data, int pos);
void list_clear(List_desc *d);
bool list_remove(List_desc *d, int pos);
void list_print(List_desc *d);
void clear_screen();