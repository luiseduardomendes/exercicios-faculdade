#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define SIZENAME 51
#define NUMPROD 2
#define NUMBRANCH 2
#define NUMMONTH 12


int main() {
    char productNames[NUMPROD][SIZENAME];
    int i, j, k;
    int id[NUMPROD];
    char name[SIZENAME];
    char searchName[SIZENAME];
    char month[NUMMONTH][11] = {"Janeiro", "Fevereiro", "Março", 
                                "Abril", "Maio", "Junho", 
                                "Julho", "Agosto", "Setembro", 
                                "Outubro", "Novembro", "Dezembro"};
    float price[NUMPROD];
    int unitSold[NUMPROD][NUMBRANCH][NUMMONTH];
    int searchId, index;
    int found, sumSold;
    int comparison;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    for (i = 0; i < NUMPROD; i ++) {
        
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
                unitSold[i][j][k] = (1+(float)rand()/RAND_MAX)*(50-1);

            }
        }
    }
    do{
        found = 0;
        do {
            printf("Informe o nome de um produto[0 para encerrar]: ");
            fgets(&searchName, SIZENAME, stdin);
            i = 0;
            while (strcmp(productNames[i], searchName)){
                comparison = strcmp(searchName, productNames[i]);
                if (!(comparison))
                    i ++;
                else 
                    index = i;
                    found = 1;
            } while(!(comparison));
        } while (comparison != 0);
        printf("  Código                                                Nome     Preço\n");
        printf("%8d %51s %9.2f %8d\n\n", id[index], productNames[index], price[index]);

    }while (strcmp("0", searchName) != 0);

    do {
        flushIn();
        printf("Informe um código de produto[0 para encerrar]: ");
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
        }
    } while (searchId != 0);


    return 0;
}

void flushIn() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}