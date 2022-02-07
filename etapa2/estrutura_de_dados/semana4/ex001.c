#include "ex001.h"

t_node *list_initialize(){
    t_node *p = NULL;
    return p;
}

t_node* list_append_item(t_node *head){
    t_node *index = NULL, *new_element = NULL;
    
    // allocates memory for the new element
    new_element = (t_node*)malloc(sizeof(t_node));

    // insert data in new element fields
    printf("identifier: ");
    scanf("%d", &(new_element->product_info.id));
    printf("price: ");
    scanf("%f", &(new_element->product_info.price));
    printf("name: ");
    clear_buffer();
    fgets((new_element->product_info.name), SIZE_NAME * sizeof(char), stdin);
    for (int i = 0; i < SIZE_NAME; i ++)
        if (new_element->product_info.name[i] == '\n')
            new_element->product_info.name[i] = ' ';

    new_element->next = NULL;
    
    // appends new element to list
    if(head != NULL){
        for (index = head; index->next != NULL; index = index->next);
        index->next = new_element;
    }
    else
        head = new_element; 

    return head;   
}

void list_print_elements(t_node *head){
    int i, size = 0, count = 0;
    t_node* index = NULL;

    for (index = head; index != NULL; index = index->next)
        size ++;
    
    for(i = list_min(head), count = 0; count < size; i ++)
        for (index = head; index != NULL; index = index->next){
            if (index->product_info.id == i){
                printf("----------------------------\n"
                        "\tname: %s\n"
                        "\tidentifier: %d\n"
                        "\tprice: US$ %.2f\n"
                        "----------------------------\n", 
                        index->product_info.name,
                        index->product_info.id,
                        index->product_info.price);
                count ++;
            }
    }
    
}

int list_min(t_node *head){
    int min = head ->product_info.id;
    t_node *index = NULL;
    for (index = head; index != NULL; index = index->next)
        if (index->product_info.id < min)
            min = index->product_info.id;
    return min;
}

void clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}