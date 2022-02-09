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

t_node* list_insert_last_element(t_node* head, t_node* element);
t_node* list_insert_element_in_position(t_node* head, t_node* element, int position);
t_node* list_insert_first_element(t_node* head, t_node* element);

void list_print_elements(t_node *head);
void list_print_elements_sort(t_node *head);
int list_min(t_node *head);
int list_size(t_node *head);

void console_input_keyboard_to_node(t_node *new_element);
void console_output_data_element(t_node element);
void console_clear_buffer();
