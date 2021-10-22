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
    char fileName[] = {"funcionario.dat"};
    char newFileName[] = {"atualizados.dat"};
    float percent;

    printf("Informe o percentual do aumento salarial: ");
    scanf("%f", &percent);

    if ((localDataFile1 = fopen(fileName, "rb")) != NULL && (localDataFile2 = fopen(newFileName, "wb")) != NULL) {
        rewind(localDataFile1);
        rewind(localDataFile2);
        
        printf("%d\n", fread(&employee, sizeof(employee), 1, localDataFile1));
        while(!(feof(localDataFile1))) {
            updateWage(&employee, percent);
            fwrite(&employee, sizeof(employee), 1, localDataFile2);
            fread(&employee, sizeof(employee), 1, localDataFile1);
        }
        fclose(localDataFile1);
        fclose(localDataFile2);
        showEmployees(fileName, newFileName);
    }
    else{
        printf("hello\n");
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
    }    
    fclose(dataFile);
    fclose(auxDataFile);
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
