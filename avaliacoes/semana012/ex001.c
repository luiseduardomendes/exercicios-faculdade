#include <stdio.h>
#include <string.h>
#define SIZENAME 81

FILE *dataFile, *auxDataFile;
typedef struct FUNCIONARIO
    {
        float wage;
        char name[SIZENAME];   
    } FUNCIONARIO;

int mainMenu();
int registerEmployee (char fileName[], FUNCIONARIO employee);
void showEmployees(char fileName[]);
void clearscreen();
void flushIn();
void removeEnter(char str[], int strSize);
int removeEmployee(char fileName[], char employeeName[]);

int main() {
    char filename[] = {"funcionario.dat"}, name[SIZENAME];
    int option = 1, flag;
    FUNCIONARIO employee;


    printf("Sistema de gerenciamento de funcionários!\n");
    while (option != 0){
        option = mainMenu();
        flushIn();
        switch (option) {
        case 1:
            do {
                printf("Insira o salário do funcionário: R$");
                scanf("%f", &employee.wage);
                flushIn();
                if (employee.wage < 0){
                    printf("Valor inserido inválido, insira outro\n");
                }
            } while (employee.wage < 0);
            printf("Insira o nome do funcionário: ");
            fgets(employee.name, sizeof(employee.name), stdin);
            removeEnter(employee.name, SIZENAME);
            flag = registerEmployee(filename, employee);
            break;
        case 2:
            showEmployees(filename);
            break;
        case 3: 
            printf("Insira o nome do funcionário a ser removido: ");
            fgets(name, sizeof(SIZENAME), stdin);
            flag = removeEmployee(filename, name);
            break;
        case 4:
            dataFile = fopen(filename, "wb");
            fclose(dataFile);
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
        printf("[3] Remover o cadastro de um funcionário\n");
        printf("[4] Excluir todos os dados\n");
        printf("[0] Encerrar o programa\n");
        printf("Sua opção: ");
        scanf("%d", &option);
        if (option < 0 || option > 4){
            printf("Valor inserido inválido, insira outro\n");
            printf("[Enter para continuar]\n");
            flushIn();
            getchar();            
        }
    } while (option < 0 || option > 4);
}

int registerEmployee (char fileName[], FUNCIONARIO employee) {
    int flag = 1;

    if(!(dataFile = fopen(fileName, "ab"))){
        flag = 0;
    }
    else{
        if(fwrite(&employee, sizeof(FUNCIONARIO), 1, dataFile) != sizeof(FUNCIONARIO)){
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
        rewind(dataFile);
        printf("----------Funcionários----------\n\n");
        fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        while (!feof(dataFile)) {
            printf("Nome:\t %s\n", employee.name);
            printf("Salário:\t R$%.2f\n\n", employee.wage);
            fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        }
        printf("--------------------------------\n\n");
        printf("[Enter para continuar]\n");
        flushIn();
        getchar();  
    }    
    fclose(dataFile);
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

void removeEnter(char str[], int strSize){
    int i;
    for(i = 0; i < strSize; i++)
        if (str[i] == '\n')
            str[i] = '\0';    
}

int removeEmployee(char fileName[], char employeeName[]) {
    int flag = 1;
    FUNCIONARIO employee;
    if(!(dataFile = fopen(fileName, "rb+"))){
        flag = 0;
    }
    else{
        rewind(dataFile);
        
        fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        printf("%d\n", ftell(dataFile));
        while (!feof(dataFile)) {
            if (strcmp(employeeName, employee.name) == 0){
                strcpy(employee.name, "");
                employee.wage = 0;
                fseek(dataFile, -1*sizeof(employee), SEEK_CUR);
                printf("%d\n", ftell(dataFile));
                fwrite(&employee, sizeof(employee), 1, dataFile);
                printf("%d\n", ftell(dataFile));
            }
            fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        }
        rewind(dataFile);
        if(!(auxDataFile = fopen("aux.dat", "ab"))){
            flag = 0;
        }
        else {
            while (!feof(dataFile)) {
                fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
                if (strcmp(employee.name, "") != 0){
                    fwrite(&employee, sizeof(employee), 1, auxDataFile);
                }
            }
            fclose(dataFile);
            fclose(auxDataFile);
            remove(fileName);
            rename("aux.dat", fileName);
        }   
    }
    return flag;
}
