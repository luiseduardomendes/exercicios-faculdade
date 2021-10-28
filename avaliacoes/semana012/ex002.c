#include <stdio.h>
#define SIZENAME 81

FILE *dataFile, *auxDataFile;
typedef struct FUNCIONARIO
    {
        float wage;
        char name[SIZENAME];   
    } FUNCIONARIO;

void updateWage(FUNCIONARIO *employee, float percent);
void showEmployees(char fileName[], char updatedFileName[]);


int main() {
    FILE *localDataFile1, *localDataFile2;
    FUNCIONARIO employee;
    int sucessful;
    char fileName[] = {"funcionario.dat"};
    char newFileName[] = {"atualizados.dat"};
    
    sucessful = updateFile(fileName, newFileName);
    if (sucessful){
        showEmployees(fileName, newFileName);
    }    
}

void updateWage(FUNCIONARIO *employee, float percent) {
    employee->wage += (employee->wage * percent) / 100;
}

void showEmployees(char fileName[], char updatedFileName[]) {
    FUNCIONARIO employee, employeeAux;

    clearscreen();
    if ((dataFile = fopen(fileName, "rb")) && (auxDataFile = fopen(updatedFileName, "rb"))) {
        rewind(dataFile);
        rewind(auxDataFile);
        printf("----------Funcionários----------\n\n");
        fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
        fread(&employeeAux, sizeof(FUNCIONARIO), 1, auxDataFile);
        while (!feof(dataFile) || !feof(dataFile)) {
            printf("Nome:\t %s\n", employee.name);
            printf("Salário antigo:\t R$%.2f\n", employee.wage);
            printf("Salário atual:\t R$%.2f\n\n", employeeAux.wage);
            fread(&employee, sizeof(FUNCIONARIO), 1, dataFile);
            fread(&employeeAux, sizeof(FUNCIONARIO), 1, auxDataFile);
        }
        printf("--------------------------------\n\n");
        printf("[Enter para continuar]\n");
        flushIn();
        getchar();  
        fclose(dataFile);
        fclose(auxDataFile);
    }
    else{
        printf("Erro na abertura do arquivo!");
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

int updateFile(char fileName[], char newFileName[]) {
    FUNCIONARIO *employee;
    float percent;
    int flag = 1;

    printf("Informe o percentual do aumento salarial: ");
    scanf("%f", &percent);
    
    if ((dataFile = fopen(fileName, "rb")) != NULL && (auxDataFile = fopen(newFileName, "wb")) != NULL) {
        rewind(dataFile);
        rewind(auxDataFile);
        
        fread(&employee, sizeof(employee), 1, dataFile);
        while(!(feof(dataFile))) {
            updateWage(&employee, percent);
            fwrite(&employee, sizeof(employee), 1, auxDataFile);
            fread(&employee, sizeof(employee), 1, dataFile);
        }
        fclose(dataFile);
        fclose(auxDataFile);
    }
    else{
        printf("Erro na abertura de arquivo\n");
        flag = 0;
    }
    return flag;
}