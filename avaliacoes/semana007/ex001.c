#include <string.h>
#include <stdio.h>
#include <locale.h>
#define SIZENAME 51
#define NUMPROD 3
#define NUMBRANCH 3
#define NUMMONTH 12


int main() {
    char productNames[NUMPROD][SIZENAME];
    int i, j, k;
    int id[NUMPROD];
    char name[SIZENAME];
    float price[NUMPROD];
    int unitSold[NUMPROD][NUMBRANCH][NUMMONTH];

    for (i = 0; i < NUMPROD; i ++) {
        printf("Insira o código do produto %d: ", i + 1);
        scanf("%d", &id[i]);
        flushIn();
        printf("Insira o nome do produto %d: ", i + 1);
        fgets(&name, SIZENAME, stdin);
        strcpy(productNames[i], name);
        printf("Insira o preço do produto %d: ", i + 1);
        scanf("%f", price[i]);
        for (j = 0; j < NUMBRANCH; j ++) {
            for (k = 0; k < NUMMONTH; k ++) {
                printf("Insira a quatidade vendida do produto %d na filial %d no mês %d: ", 
                        i + 1, j + 1, k + 1);
                scanf("%d", &unitSold[i][j][k]);
            }
        }
    }



    return 0;
}

void flushIn() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF || ch != '\0');
}