#include "doubly_linked_list.h"

t_node* list_init(void){
    t_node *head = NULL;
    return head;
}

void list_print(t_node* head){
    t_node *index = NULL;

    if(head != NULL)
        for (index = head; index != NULL; index = index->next)
            list_print_node(*index);
    else
        printf("List is empty\n");
}

void list_print_reversed(t_node *head){
    t_node *index = NULL;
    if(head != NULL){
        // place the index in the last position of the list
        for (index = head; index->next != NULL; index = index->next);
        for (index; index != NULL; index = index->prev)
            list_print_node(*index);
    }
    else
        printf("List is empty\n");
}

t_node* list_insert_begin(t_node *head, t_info_node data){
    t_node *new_elem = NULL;
    
    new_elem = (t_node*) malloc (sizeof(t_node));
    
    // primeiro elemento da lista atualizada eh new_elem, logo ele
    // sera sucedido pelo elemento inicial da lista antiga
    new_elem->prev = NULL;
    new_elem->next = head;
    new_elem->info = data;    

    if(head != NULL) // if (list.is_empty() == false)
        head->prev = new_elem;
    
    // novo elemento inicial sera o elemento adicionado
    head = new_elem;

    

    return head;
}

t_node* list_insert_end(t_node *head, t_info_node data){
    t_node *new_elem = NULL, *index = NULL;

    new_elem = (t_node*) malloc (sizeof(t_node));

    // ultimo elemento da lista atualizada eh new_elem, logo ele
    // sera precedido pelo elemento final da lista antiga
    new_elem->next = NULL;
    new_elem->info = data;

    if(head != NULL){ // if (list.is_empty() == false)
        // posiciona index na ultima posicao
        for(index = head; index->next != NULL; index = index->next);

        new_elem->prev = index;
        index->next = new_elem;
    }
    else{ // if (list.is_empty() == true)
        // novo elemento inicial sera o elemento adicionado
        // caso a lista inserida seja vazia
        new_elem->prev = NULL;
        head = new_elem;
    }   

    return head;
}

t_node* list_clear(t_node* head){
    t_node *index = NULL;

    for(index = head->next; index->next != NULL; index = index->next)
        free(index->prev);
    free(index->prev);
    free(index);


    head = NULL;

    return head;
}


t_node* list_remove(t_node *head, int id){
    t_node *index = NULL;
    
    for(index = head; index != NULL; index = index->next){
        if (index->info.id == id){
            
            if (index == head){ // index in first element
                if(head->next != NULL){ // list has more than one element
                    head = index->next;                    
                    head->prev = NULL;
                }

                else // list has only one element
                    head = NULL;
                
            }

            else if (index->next == NULL){ // index in last element
                index->prev->next = NULL;
            }
            
            else { // index in a middle position
                index->next->prev = index->prev;
                index->prev->next = index->next;
            }
            free(index);
        }
    }
    return head;
}


// AUXILIAR FUNCTIONS

void list_print_node(t_node node){
    printf("-----------------------------\n");
    printf ("ID: %25d\n"                  
            "Name: %23s\n"
            "Price(US$): %17.2f\n\n",
            node.info.id, 
            node.info.name, 
            node.info.price);
}

t_info_node list_input_node(){
    t_info_node node;
    char i;

    printf ("ID: ");
    scanf("%d", &node.id);
    getchar();
    printf("name: ");
    fgets(node.name, SIZE_NAME, stdin);
    for (i = 0; node.name[i] != '\n'; i ++);
    node.name[i] = '\0';
    printf("price (US$): ");
    scanf("%f", &node.price);

    return node;
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #elif 
        system("cls");
    #endif
}