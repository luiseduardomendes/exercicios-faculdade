#include "ex001.h"

int main(){
    t_node *head = NULL;

    head = list_initialize();
    do {
        printf("insert item with id sorted:\n");
        head = list_insert_element_sort(head);
        list_print_elements(head);
    } while(list_size(head) < 3);
    do {
        printf("append items\n");
        head = list_append_item(head);
        printf("not sorted items: \n");
        list_print_elements(head);
        printf("sorted items: \n");
        list_print_elements_sort(head);
    } while(1);
    
    return 0;
}