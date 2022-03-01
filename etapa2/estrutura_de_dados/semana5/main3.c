#include "doubly_linked_list_circular.h"

int main(){
    t_node *head = NULL, *node1, *node2, *a1, *a2;
    t_info_node data;
    data.id = 1;
    data.price = 1;
    strcpy(data.name, "1");


    head = list_init();
    head = list_insert_end(head, data);
    data.id ++;
    head = list_insert_end(head, data);
    data.id ++;
    head = list_insert_end(head, data);
    data.id ++;
    head = list_insert_end(head, data);
    data.id ++;
    head = list_insert_end(head, data);

    //list_print(head);

    node1 = head->next;
    node2 = head->prev->prev;

    a1 = node1->prev;
    a2 = node2->next;
    node1->prev = node2->prev;
    node2->next = node1->next;
    node1->next->prev = node2;
    node2->prev->next = node1;
    node1->next = a2;
    node2->prev = a1;
    a2->prev = node1;
    a1->next = node2;

    list_print(head);



    return 0;
}