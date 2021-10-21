#include <stdio.h>
#define SIZENAME 81


FILE* dataFile;
typedef struct FUNCIONARIO
    {
        float wage;
        char name[SIZENAME];   
    } FUNCIONARIO;


int main() {
    char filename[] = {"funcionario.dat"};
    int option;
    FUNCIONARIO employee;

    printf("Sistema de gerenciamento de funcionários!\n");
    while (option != 0){
        option = mainMenu();
        switch (option) {
        case 1:
            printf("Insira o salário do funcionário: R$");
            scanf("%f", &employee.wage);
            flushIn();
            printf("Insira o nome do funcionário: ");
            fgets(employee.name, SIZENAME, stdin);
            registerEmployee(filename, employee);
            break;
        case 2:
            showEmployees(filename);
            break;
        }
    }


    
}

int mainMenu() {
    int option;
    do {
        clearscreen();
        printf("O que deseja fazer?\n");
        printf("[1] Cadastrar um novo funcionário\n");
        printf("[2] Listar os funcionários cadastrados\n");
        printf("[0] Encerrar o programa\n");
        printf("Sua opção: ");
        scanf("%d", &option);
        if (option < 0 || option > 2){
            printf("Valor inserido inválido, insira outro\n");
            printf("[Enter para continuar]\n");
            flushIn();
            getchar();            
        }
    } while (option < 0 || option > 2);
}

int registerEmployee (char fileName[], FUNCIONARIO employee) {
    int flag = 1;

    if(!(dataFile = fopen(fileName, "ab"))){
        flag = 0;
    }
    else{
        if(fwrite(&employee, sizeof(FUNCIONARIO), 1, fileName) != sizeof(FUNCIONARIO)){
            flag = 0;
        }
    }
    fclose(dataFile);
    return flag;    
}

void showEmployees(char fileName[]) {
    FUNCIONARIO employee;
    int flag;
    clearscreen();
    if (dataFile = fopen(fileName, "rb")){
        printf("----------Funcionários----------\n\n");
        fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        do {
            printf("Nome:\t %s\n", employee.name);
            printf("Salário:\t R$%.2f\n\n", employee.wage);
            fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        } while (!feof);
        printf("--------------------------------\n\n");
        printf("[Enter para continuar]\n");
        flushIn();
        getchar();  
    }    
}

void clearscreen() {
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #endif
}

void flushIn() {
    #ifdef _WIN32
        fflush(stdin);
    #elif _POSIX_C_SOURCE >= 199309L
        __fpurge(stdin);
    #endif
}