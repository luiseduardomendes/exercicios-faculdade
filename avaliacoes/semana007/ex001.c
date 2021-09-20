#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define SIZENAME 51
#define NUMPROD 2
#define NUMBRANCH 2
#define NUMMONTH 12

void searchById(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);
void searchByName(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD]);

char month[NUMMONTH][11] = {"Janeiro", "Fevereiro", "Marco", 
                                "Abril", "Maio", "Junho", 
                                "Julho", "Agosto", "Setembro", 
                                "Outubro", "Novembro", "Dezembro"};                


int main() {
    char productNames[NUMPROD][SIZENAME];
    int i, j, k;
    int id[NUMPROD];
    char name[SIZENAME];
    char searchName[SIZENAME];
    float price[NUMPROD];
    int unitSold[NUMPROD][NUMBRANCH][NUMMONTH];
    int option;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    for (i = 0; i < NUMPROD; i ++) {
        clearscreen();
        
        printf("Insira o código do produto %d: ", i + 1);
        scanf("%d", &id[i]);
        
        flushIn();
        printf("Insira o nome do produto %d: ", i + 1);
        fgets(&name, SIZENAME, stdin);
        for (k = 0; k < SIZENAME; k ++) {
            if (name[k] == '\n') {
                name[k] = '\0';
            }
        }
        strcpy(productNames[i], name);
        

        printf("Insira o preço do produto %d: ", i + 1);
        scanf("%f", &price[i]);
        for (j = 0; j < NUMBRANCH; j ++) {
            for (k = 0; k < NUMMONTH; k ++) {
                /*printf("Insira a quatidade vendida do produto %d na filial %d no mês de %s: ", 
                        i + 1, j + 1, month[k]);
                scanf("%d", &unitSold[i][j][k]);*/
                unitSold[i][j][k] = ((float)rand()/RAND_MAX)*(5);

            }
        }
        flushIn();
    }

    do{
        option = mainMenu();
        switch (option)
        {
        case 1:
            searchByName(productNames, id, price);
            break;
        case 2:
            searchById(productNames, id, price, unitSold);
            break;
        case 3:
            profitByBranch(productNames, id, price, unitSold);
            break;
        case 4:
            profitByBranchAndId(productNames, id, price, unitSold);
            break;
        case 5:
            mostLucrativeProd(productNames, id, price, unitSold);
            break;
        }
    } while (option != 0);

    return 0;
}

int mainMenu() {
    int option;
    clearscreen();
    do{
        printf("[1] Realizar pesquisa por nome\n"
        "[2] Realizar pesquisa por código\n"
        "[3] Ver lucro por filial no ano\n"
        "[4] Lucro por filial de um produto\n"
        "[5] Produto mais lucrativo\n"
        "[0] Encerrar Programa \n"
        "Sua opção: ");
        scanf("%d", &option);
    } while (option > 5 || option < 0);
    return option;
}

void searchByName(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD]) {
    int i, j, k;
    char searchName[SIZENAME];
    int index;
    int found;
    int comparison;
    flushIn();
    do {    
        do {
            clearscreen();
            found = 0;
            printf("Informe o nome de um produto [0 para encerrar]: ");
            fgets(&searchName, SIZENAME, stdin);
            for ( k = 0; k < SIZENAME; k ++){
                if (searchName[k] == '\n'){
                    searchName[k] = '\0';
                }
            }
            i = 0; 
            if (strcmp("0", searchName) != 0){
                do {
                    comparison = strcmp(searchName, productNames[i]);
                    if (comparison != 0)
                        i ++;
                    else {
                        index = i;
                        found = 1;
                    }
                } while (comparison != 0 && i < NUMPROD);
        
                if (!(found)) {
                    printf("Produto não encontrado!\n");
                }
                else {
                    printf("  Código                                                Nome     Preço\n");
                    printf("%8d %51s %9.2f\n\n", id[index], productNames[index], price[index]);
                }
                flushIn();
                printf("\nEnter para continuar...\n");
                fgetc(stdin);
            }
            else {
                comparison = 0;
            }
            
        } while (comparison != 0);   
    } while (strcmp("0", searchName));
}

void searchById(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]) {
    
    int i, j, k;
    
    char name[SIZENAME];
    char searchName[SIZENAME];
    int searchId, index;
    int found, sumSold;
    do {
        flushIn();
        clearscreen();
        printf("Informe um código de produto [0 para encerrar]: ");
        flushIn();
        scanf("%d", &searchId);

        if (searchId != 0) {
            found = 0;

            for(i = 0; i < NUMPROD; i ++) {
                if (id[i] == searchId){
                    found = 1;
                    index = i;
                }
            }
            sumSold = 0;
            if (found){
                for (i = 0; i < NUMBRANCH; i ++){
                    for (j = 0; j < NUMMONTH; j ++){
                        sumSold += unitSold[index][i][j];
                    }
                }
                printf("  Código                                                Nome     Preço Vendidos\n");
                printf("%8d %51s %9.2f %8d\n\n", id[index], productNames[index], price[index], sumSold);
            }
            else {
                printf("Produto não encontrado!\n");
            }
            flushIn();
            printf("\nEnter para continuar...\n");
            fgetc(stdin);
        }
    } while (searchId != 0);
}

void profitByBranch(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]){
    int i, j, k;
    float profit, profitMonth;
    clearscreen();


    for (i = 0; i < NUMBRANCH; i ++) {
        profit = 0;
        for (j = 0; j < NUMMONTH; j ++ ) {
            profitMonth = 0;
            for (k = 0; k < NUMPROD; k ++) {
                profitMonth += (price[k] * unitSold[k][i][j]); 
            }
            printf("%14s%14.2f\n", month[j], profitMonth);
            profit += profitMonth;
        }
        printf("Filial %d \nLucro total: R$%.2f\n\n", i+1, profit);
    }
    flushIn();
    printf("Enter para continuar...\n");
    fgetc(stdin);
}

void profitByBranchAndId (char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]) {
    int searchId, found, index;
    int numberSold;

    int i, j;
    do {
        flushIn();
        clearscreen();
        printf("Informe um código de produto [0 para encerrar]: ");
        flushIn();
        scanf("%d", &searchId);

        if (searchId != 0) {
            found = 0;

            for(i = 0; i < NUMPROD; i ++) {
                if (id[i] == searchId){
                    found = 1;
                    index = i;
                }
            }
            if(found) {
                for (i = 0; i < NUMBRANCH; i ++) {
                    printf("Filial: %d\tCódigo: %d\tProduto: %s\n\n", i+1, id[index], productNames[index]);
                    numberSold = 0;
                    printf("\t    Mês     Unidades\tLucro\n");
                    for (j = 0; j < NUMMONTH; j ++) {
                        printf("%16s %8d%14.2f\n", month[j], 
                        unitSold[index][i][j], unitSold[index][i][j] * price[index]);
                        numberSold += unitSold[index][i][j];
                    }
                    printf("\n    Total anual: %8d %14.2f\n\n", numberSold, numberSold * price[index]);
                }
            }
            else {
                printf("Produto não encontrado!\n");
            }
            flushIn();
            printf("\nEnter para continuar...\n");
            fgetc(stdin);
        }
    } while (searchId != 0);
}

void mostLucrativeProd(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]){
    int i, j, k;
    float profit;
    float prodProfit[NUMPROD] = {0}; //lucro de cada produto
    float mostLucrative; // maior valor por produto
    int units[NUMPROD] = {0}; // unidades totais
    for (i = 0; i < NUMPROD; i ++) {
        profit = 0;
        for (j = 0; j < NUMBRANCH; j ++) {
            for (k = 0; k < NUMMONTH; k ++) {
                profit += price[i] * unitSold[i][j][k];
                units[i] += unitSold[i][j][k];
            }
        }
        prodProfit[i] = profit;
        if ( i == 0 ){
            mostLucrative = profit;
        }
        if (mostLucrative < profit) {
            mostLucrative = profit;
        }
    }
    printf("Produtos mais lucrativos: \n\n");
    printf("Nome do produto                                     Código  Unidades  Lucro\n");
    for (i = 0; i < NUMPROD; i ++) {
        if (mostLucrative == prodProfit[i]) {
            printf("%51s%8d%8d%14.2f\n", productNames[i], id[i], units[i], prodProfit[i]);
        }
    }
    flushIn();
    printf("Enter para continuar...\n");
    fgetc(stdin);
}

void flushIn() {
    #ifdef WIN32
        fflush(stdin);
    #elif _POSIX_C_SOURCE >= 199309L
        __fpurge(stdin);
    #endif
}

void clearscreen() {
    #ifdef WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #endif
}
