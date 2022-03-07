#include "doubly_linked_list_circular.h"
#include "bolsonmain.c"

t_info_node list_middle_element(t_node *head);

int main(){
    t_node *head = NULL;

    head = list_init();

    do{
        head = list_insert_begin(head, list_input_node());
        list_print(head);
        printf("elemento intermediario: %d\n", encontraMeio(head).id);
    } while (1);

    

    return 0;
}

t_info_node list_middle_element(t_node *head){
    t_node *i1 = head, *i2 = head;

    do{
        i1 = i1->next;
        if (i1 == i2)
            return i1->info;
        i2 = i2->prev;
        if (i1 == i2)
            return i1->info;

    } while(1);
}