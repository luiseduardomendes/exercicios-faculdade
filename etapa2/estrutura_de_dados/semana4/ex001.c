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
    console_input_keyboard_to_node(new_element);

    new_element->next = NULL;
    
    // appends new element to list
    list_insert_last_element(head, new_element);

    return head;   
}

t_node *list_insert_element_sort(t_node *head){
    t_node *index = NULL, *new_element = NULL, previous;
    int position = 0;

    // allocates memory for the new element
    new_element = (t_node*)malloc(sizeof(t_node));

    // insert data in new element fields
    console_input_keyboard_to_node(new_element);

    new_element->next = NULL;

    // appends new element to list
    if(head == NULL)
        head = list_insert_first_element(head, new_element);
    else{
        index = head;
        position = 0;
        while (index != NULL && index->product_info.id < new_element->product_info.id){
            position ++;
            index = index->next;
        }
        
        if(index != NULL)
            head = list_insert_element_in_position(head, new_element, position);
        else
            head = list_insert_last_element(head, new_element);
    }
    
    return head;   
}

void list_print_elements(t_node *head){
    t_node* index = NULL;
    for (index = head; index != NULL; index = index->next)    
        console_output_data_element(*index);

}

void list_print_elements_sort(t_node *head){
    int i, count = 0;
    t_node* index = NULL;

    // this function has more complexity than the list_print_elements()
    // cause it prints elements sorted without change the original order
    // of the list, deppending on list size, its run can be slow
    
    // prints elements from the min ID until print all the elements
    // increments size when prints a data
    // increments i when check if i is an identifier of a node for all nodes

    for(i = list_min(head), count = 0; count < list_size(head); i ++)
        for (index = head; index != NULL; index = index->next){
            if (index->product_info.id == i){
                console_output_data_element(*index);
                count ++;
            }
    }
    
}

// auxiliar functions

t_node* list_insert_first_element(t_node* head, t_node* element) {
    element->next = head;
    return element;
}

t_node* list_insert_element_in_position(t_node* head, t_node* element, int position){
    t_node *index = NULL, buffer;
    int i;

    if (position == 0)
        head = list_insert_first_element(head, element);

    else if (list_size(head) == position)
        head = list_insert_last_element(head, element);

    else if (position < list_size(head)){
        for (index = head, i = 0; i < position-1; i ++, index = index->next);
        buffer = *index;
        index->next = element;
        element->next = buffer.next;
    }

    return head;
}

t_node* list_insert_last_element(t_node* head, t_node* element){
    t_node *index = NULL;
    
    if(head != NULL){
        for (index = head; index->next != NULL; index = index->next);
        index->next = element;
    }
    else
        head = element;

    return head;
}

void console_input_keyboard_to_node(t_node *element){
    printf("identifier: ");
    scanf("%d", &(element->product_info.id));
    printf("price: ");
    scanf("%f", &(element->product_info.price));
    printf("name: ");
    console_clear_buffer();
    fgets((element->product_info.name), SIZE_NAME * sizeof(char), stdin);
    for (int i = 0; i < SIZE_NAME; i ++)
        if (element->product_info.name[i] == '\n')
            element->product_info.name[i] = ' ';
}

void console_output_data_element(t_node element){
    printf("----------------------------\n"
        "\tname: %s\n"
        "\tidentifier: %d\n"
        "\tprice: US$ %.2f\n"
        "----------------------------\n", 
        element.product_info.name,
        element.product_info.id,
        element.product_info.price);
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

void console_clear_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}