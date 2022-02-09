#pragma once
#include "stdio.h"
#include "stdlib.h"

#define SIZE_NAME 15

typedef struct product
{
    int id;
    float price;
    char name[SIZE_NAME];
} t_product;

typedef struct t_node
{
    t_product product_info;
    struct t_node *next;
} t_node;

t_node *list_initialize();

t_node *list_append_item(t_node *head);

t_node *list_insert_element_sort(t_node *head);

void list_print_elements(t_node *head);

void list_print_elements_sort(t_node *head);

void clear_buffer();

int list_min(t_node *head);

void input_node(t_node *new_element);
