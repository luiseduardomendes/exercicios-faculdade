/*
Você deve elaborar um programa que auxilie o mercado a analisar as vendas das 
filiais do mercado ao final de um mês. Ou seja, o programa só deve lidar com a
quantidade vendida por cada loja de cada produto em um dado mês. O programa deve:
* Pedir para o usuário informar o nome (máximo de 50 caracteres) de cada um dos
P produtos da loja.
* Pedir para o usuário informar o preço de cada um dos P produtos. Assuma que o
preço é o mesmo em todas as filiais.
* Pedir para o usuário informar o código de cada um dos P produtos. Assuma que o
código de um produto é o mesmo em todas as filiais.
* Pedir para o usuário informar a quantidade de cada produto que foi vendida por
cada filial no mês.
* Pedir para o usuário informar o nome de um produto e exibir o código e o preço
deste produto. Caso o nome informado seja inválido, o programa deve realizar a
consistência, só prosseguindo quando o usuário informar um nome válido.
* Pedir para o usuário informar um código de produto e exibir na tela o nome do
produto e o total de unidades vendidas deste produto considerando as vendas de
todas as filiais. Se o usuário informar um código inválido, o programa deve
realizar a consistência, só prosseguindo quando o usuário informar um código
válido.
* Determinar e exibir a média de unidades vendidas de cada produto por filial,
exibindo o nome do produto, seu código, seu preço e a média vendida.
* Determinar e exibir o faturamento total de cada filial no mês, considerando o total
de produtos vendidos de cada tipo e seu preço.
* Determinar o produto que representou o maior faturamento (considerando total de
unidades vendidas em todas as lojas e os preços dos produtos) e exibir seu nome e
código e o total faturado com vendas deste produto. Caso mais de um produto
ficar empatado, seu programa deve exibir todos que atingiram esse faturamento
máximo.
Considere, por conveniência, P como 3 e F como 3 também, embora o programa deva
funcionar normalmente (e de forma consistente) caso o valor dessas constantes seja
alterado.
*/

#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define SIZENAME 51
#define NUMPROD 3
#define NUMBRANCH 3
#define NUMMONTH 1

void flushIn();

void clearscreen();

int mainMenu();

void searchById(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);
void searchByName(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD]);

void profitByBranch(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);         

void profitByBranchAndId (char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);

void mostLucrativeProd(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);

void averageUnitsByBranch(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]);

char month[12][11] = {"Janeiro", "Fevereiro", "Marco", 
                                "Abril", "Maio", "Junho", 
                                "Julho", "Agosto", "Setembro", 
                                "Outubro", "Novembro", "Dezembro"};
  
int main() {
    // Armazenar dados
    char productNames[NUMPROD][SIZENAME];
    int id[NUMPROD];
    float price[NUMPROD];
    int unitSold[NUMPROD][NUMBRANCH][NUMMONTH];
    
    // Variaveis auxiliares
    char name[SIZENAME];
    int option;
    int insertSold;
    int i, j, k;
    
    setlocale(LC_CTYPE, "");
    srand(time(NULL));
    
    printf("Deseja inserir manualmente o número de unidades vendidas por mês ou gerá-los aleatoriamente?\n");
    printf("[1] Inserir manualmente\n");
    printf("[2] Inserir aleatoriamente\n");
    do{ 
        printf("Sua opção: ");
        scanf("%d", &insertSold);
        if ((insertSold != 1 && insertSold != 2)){
            printf("Valor inválido, insira outro\n");
        }
    } while (insertSold != 1 && insertSold != 2);
    

    for (i = 0; i < NUMPROD; i ++) {
        clearscreen();
        
        printf("Insira o código do produto %d: ", i + 1);
        scanf("%d", &id[i]);
        
        flushIn();
        printf("Insira o nome do produto %d: ", i + 1);
        fgets(name, SIZENAME, stdin);
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
                if (insertSold == 1) {
                    printf("Insira a quatidade vendida do produto %d na filial %d no mês de %s: ", 
                            i + 1, j + 1, month[k]);
                    scanf("%d", &unitSold[i][j][k]);
                }
                if (insertSold == 2) {
                    unitSold[i][j][k] = ((float)rand()/RAND_MAX)*(5);
                }
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
        case 6: 
            averageUnitsByBranch(productNames, id, price, unitSold);
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
        "[6] Media de unidades por produto por filial\n"
        "[0] Encerrar Programa \n"
        "Sua opção: ");
        scanf("%d", &option);
    } while (option > 6 || option < 0);
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
            fgets(searchName, SIZENAME, stdin);
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
        printf("Filial %d \n", i+1);
        for (j = 0; j < NUMMONTH; j ++ ) {
            profitMonth = 0;
            for (k = 0; k < NUMPROD; k ++) {
                profitMonth += (price[k] * unitSold[k][i][j]); 
            }
            printf("%14s%14.2f\n", month[j], profitMonth);
            profit += profitMonth;
        }
        printf("Lucro total: R$%.2f\n\n", profit);
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

void averageUnitsByBranch(char productNames[NUMPROD][SIZENAME], 
                int id[NUMPROD], float price[NUMPROD], 
                int unitSold[NUMPROD][NUMBRANCH][NUMMONTH]) {
    int i, j, k;
    int units;
    float average;

    for (i = 0; i < NUMPROD; i ++) {
        units = 0; 
        for (j = 0; j < NUMBRANCH; j ++) {
            for (k = 0; k < NUMMONTH; k ++) {
                units += unitSold[i][j][k];
            }
        }
        average = (float)units / NUMBRANCH;
        printf("Nome do produto                                     Código  Unidades  Média\n");
        printf("%51s%8d%8d%14.2f\n\n", productNames[i], id[i], units, average);
    }

    flushIn();
    printf("Enter para continuar...\n");
    fgetc(stdin);
}

void flushIn() {
    #ifdef _WIN32
        fflush(stdin);
    #elif _POSIX_C_SOURCE >= 199309L
        __fpurge(stdin);
    #endif
}

void clearscreen() {
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #endif
}
