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

t_node *list_insert_element_sort(t_node *head){
    t_node *index = NULL, *new_element = NULL, previous;

    // allocates memory for the new element
    new_element = (t_node*)malloc(sizeof(t_node));

    // insert data in new element fields
    input_node(new_element);

    new_element->next = NULL;

    // appends new element to list
    if (head != NULL){ //list is not empty
        if(head-> next != NULL){ // list has more than one element
            index = head;
            while (index->next != NULL && index->next->product_info.id < new_element->product_info.id)
            // while not reaches the end of list and not reach the position sort
                index = index->next;
            
            if(index->next == NULL){ // reaches the end of list 
                index->next = new_element;
            }
            else{ // reaches the position sort
                if(index->product_info.id < new_element->product_info.id){
                    t_node *buffer = index->next;
                    index->next = new_element;
                    new_element->next = buffer;
                }
                else{ // match in the first position
                    new_element->next = index;
                    head = new_element;
                }
            }
        } 
        else{ // list has only one element
            if(head->product_info.id > new_element->product_info.id){
                new_element->next = head;
                head = new_element;
            }
            else{
                head->next = new_element;
            }
        }
    }
    else{ //list is empty
        head = new_element;
    
    }
    return head;   
}

void list_print_elements(t_node *head){
    t_node* index = NULL;
    for (index = head; index != NULL; index = index->next)    
        printf("----------------------------\n"
                "\tname: %s\n"
                "\tidentifier: %d\n"
                "\tprice: US$ %.2f\n"
                "----------------------------\n", 
                index->product_info.name,
                index->product_info.id,
                index->product_info.price);

}

void list_print_elements_sort(t_node *head){
    int i, size = 0, count = 0;
    t_node* index = NULL;

    size = list_size(head);
    
    for(i = list_min(head), count = 0; count < size; i ++)
        for (index = head; index != NULL; index = index->next){
            if (index->product_info.id == i){
                output_data_element(*index);
                count ++;
            }
    }
    
}

// auxiliar functions

void input_node(t_node *new_element){
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
}

void output_data_element(t_node e){
    printf("----------------------------\n"
        "\tname: %s\n"
        "\tidentifier: %d\n"
        "\tprice: US$ %.2f\n"
        "----------------------------\n", 
        e.product_info.name,
        e.product_info.id,
        e.product_info.price);
}

int list_size(t_node *head){
    t_node *index;
    int size = 0;
    for (index = head; index != NULL; index = index->next)
        size ++;
    return size;
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