#include "stack.h"

typedef struct {
    bool closed;
}Program_status;

void clearScreen();
void show_option_menu();
void execution_menu_input(tStackNode **top, int input, Program_status *program_status);

int main(){
    tStackNode *top = NULL;
    Program_status pgStatus = {false};
    int opt;
    top = stack_init();

    do {
        clearScreen();
        
        printf("select an option: \n");
        show_option_menu();
        scanf("%d", &opt);

        execution_menu_input(&top, opt, &pgStatus);

    } while(!pgStatus.closed);

    
    return 0;
}

void show_option_menu(){
    printf ("[1] push item\n"
            "[2] pop item\n"
            "[3] show top\n"
            "[4] clear list\n"
            "[0] close program\n");
}

// executes the operation selected by the user input
void execution_menu_input(tStackNode **top, int input, Program_status *program_status){
    int element_id, position;
    
    switch (input){
    case 1:
        printf("Insert data of the element:\n");
        stack_push(top, stack_inputNode());
        break;
    case 2:
        stack_pop(top, NULL);
        break;
    case 3:
        clearScreen();    
        printf("%d", (int)stack_top(*top));
        getc(stdin);
        getc(stdin);
        break;
    case 4:
        *top = stack_clear(*top);
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

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #elif 
        system("cls");
    #endif
}