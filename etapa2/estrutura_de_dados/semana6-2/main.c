#include "queue.h"

typedef struct {
    bool closed;
}Program_status;

void clearScreen();
void show_option_menu();
void execution_menu_input(tDescriptor **descriptor, int input, Program_status *program_status);

int main(){
    tDescriptor *descriptor = NULL;
    Program_status pgStatus = {false};
    int opt;
    descriptor = queue_init();

    do {
        clearScreen();
        
        printf("select an option: \n");
        show_option_menu();
        scanf("%d", &opt);

        execution_menu_input(&descriptor, opt, &pgStatus);

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
void execution_menu_input(tDescriptor **descriptor, int input, Program_status *program_status){
    int element_id, position;
    
    switch (input){
    case 1:
        printf("Insert data of the element:\n");
        queue_push(*descriptor, queue_inputNode());
        break;
    case 2:
        queue_pop(*descriptor, NULL);
        break;
    case 3:
        clearScreen();    
        printf("%d", (int)queue_first(*descriptor));
        getc(stdin);
        getc(stdin);
        break;
    case 4:
        *descriptor = queue_clear(*descriptor);
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
    #else
        system("cls");
    #endif
}