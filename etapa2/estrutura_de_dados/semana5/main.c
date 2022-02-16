#include "doubly_linked_list.h"

typedef struct {
    bool closed;
}Program_status;

void execution_menu_input(t_node **head, int input, Program_status *program_status);
void show_option_menu();

int main(){
    t_node *head = NULL;
    int element_id, opt;

    Program_status program_status;
    program_status.closed = false;

    head = list_init();

    do {
        clear_screen();
        
        printf("select an option: \n");
        show_option_menu();
        scanf("%d", &opt);

        execution_menu_input(&head, opt, &program_status);

    } while(!program_status.closed);

    
    return 0;
}

void show_option_menu(){
    printf ("[1] insert item begin\n"
                "[2] insert item end\n"
                "[3] remove item\n"
                "[4] show list\n"
                "[5] show list reversed\n"
                "[6] clear list\n"
                "[0] close program\n");
}

// executes the operation selected by the user input
void execution_menu_input(t_node **head, int input, Program_status *program_status){
    int element_id;

    switch (input){
    case 1:
        printf("Insert data of the element:\n");
        *head = list_insert_begin(*head, list_input_node());
        break;
    case 2:
        printf("Insert data of the element:\n");
        *head = list_insert_end(*head, list_input_node());
        break;
    case 3:
        printf("write the id of the element that you wanna remove: ");
        scanf("%d", &element_id);
        *head = list_remove(*head, element_id);
        break;
    case 4:
        clear_screen();    
        list_print(*head);
        getc(stdin);
        getc(stdin);
        break;
    case 5:
        clear_screen();
        list_print_reversed(*head);
        getc(stdin);
        getc(stdin);
        break;
    case 6:
        *head = list_clear(*head);
        break;
    case 0:
        program_status->closed = true;
        break;
    default:
        printf("Please, insert a valid code\n");
        getc(stdin);
        getc(stdin);
        break;
    }
}