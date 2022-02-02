#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct{
    int id;
    float value;
    char name[20];
}t_data;

typedef struct node{
    t_data data;
    struct node *prev;
    struct node *next;
}t_node;

typedef struct{
    t_node* first;
    t_node* last;
    int size;
}t_list;

void list_updateSizeOfDesc(t_list *list);
int list_sizeOf(t_list list);
int list_max(t_list list);
t_list list_createList();
void list_append(t_list *list, t_data data);
void list_print(t_list list);
t_list list_randomList(int size, int min, int max);
void list_removeElement(t_list *list, int elementId);
void list_removeRepeated(t_list *list);