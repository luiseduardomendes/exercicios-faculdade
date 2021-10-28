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
int addEmployee (char fileName[], FUNCIONARIO employee);
void registerEmployee (char fileName[]);
void showEmployees(char fileName[]);
void clearscreen();
void flushIn();
void removeEnter(char str[], int strSize);
int removeEmployee(char fileName[], char employeeName[]);
void removeEmployeeIO(char fileName[]); 
int deleteAllData(char fileName[]);

int main() {
    char filename[] = {"funcionario.dat"};
    int option = 1;

    printf("Sistema de gerenciamento de funcionários!\n");
    while (option != 0){
        flushIn();
        option = mainMenu();
        flushIn();
        switch (option) {
        case 1:
            registerEmployee(filename);
            break;
        case 2:
            showEmployees(filename);
            break;
        case 3: 
            removeEmployeeIO(filename);
            break;
        case 4:
            deleteAllData(filename);
            break;
        }
    }    
    
    printf("\nEncerrado\n");
    return 0;

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

void registerEmployee (char fileName[]){
    FUNCIONARIO employee;
    int addSucessful;
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
    addSucessful = addEmployee(fileName, employee);
    if (!addSucessful)
        printf("Arquivo não encontrado");
    else if (addSucessful == -1) 
        printf("Erro na escrita");
    printf("--------------------------------\n\n");
    printf("[Enter para continuar]\n");
    flushIn();
    getchar(); 
}

int addEmployee (char fileName[], FUNCIONARIO employee) {
    int flag = 1;

    if(!(dataFile = fopen(fileName, "ab")))
        flag = 0;

    else
        if(!fwrite(&employee, sizeof(FUNCIONARIO), 1, dataFile))
            flag = -1;

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
            printf("Nome:\t\t %s\n", employee.name);
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

void removeEmployeeIO(char fileName[]){
    int foundEmployee;
    char name[SIZENAME];

    printf("Insira o nome do funcionário a ser removido: ");
    fgets(name, SIZENAME, stdin);
    removeEnter(name, SIZENAME);
    foundEmployee = removeEmployee(fileName, name);
    if (!foundEmployee)
        printf("Arquivo não foi aberto!\n");
    if(foundEmployee == -1)
        printf("Funcionario não encontrado!\n");
    printf("[Enter para continuar]\n");
    flushIn();
    getchar(); 
}

int removeEmployee(char fileName[], char employeeName[]) {
    int flag = 1, found = 0;
    FUNCIONARIO buffer;
    if(!(dataFile = fopen(fileName, "rb")) || !(auxDataFile = fopen("aux.dat", "wb"))){
        flag = 0;
    }
    else{
        rewind(dataFile);
        fread(&buffer, sizeof(buffer), 1, dataFile);
        while (!feof(dataFile)) {
            if (strcmp(employeeName, buffer.name) != 0){
                fwrite(&buffer, sizeof(buffer), 1, auxDataFile);
            }
            else{
                found = 1;
            }
            fread(&buffer, sizeof(buffer), 1, dataFile);
        }
        fclose(dataFile);
        fclose(auxDataFile);
        remove(fileName);
        rename("aux.dat", fileName);
    }
    if(!found)
        flag = -1;
    return flag;
}

int deleteAllData(char fileName[]){
    int flag;
    int delete;
    do {
        printf("Deseja apagar todos os dados?\n"
        "Esta operação não pode ser desfeita\n");
        printf("[1] Apagar\n");
        printf("[0] Cancelar\n");
        printf("Sua opção: ");
        scanf("%d", &delete);
    } while (delete != 0 && delete != 1);
    if (delete){
        if(dataFile = fopen(fileName, "wb")){
            fclose(dataFile);
        }
        else{
            printf("O arquivo não foi encontrado!\n");
        }
    }
    printf("--------------------------------\n\n");
    printf("[Enter para continuar]\n");
    flushIn();
    getchar(); 
    return flag;
}
