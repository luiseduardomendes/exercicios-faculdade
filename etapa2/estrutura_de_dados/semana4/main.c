#include "ex001.h"

int main(){
    t_node *head = NULL;

    head = list_initialize();
    do {
        head = list_insert_element_sort(head);
        list_print_elements(head);
    } while(1);


    return 0;
}