#include <string.h>
#include <stdio.h>
#include <locale.h>
#define SIZENAME 51
#define NUMPROD 3
#define NUMBRANCH 3


int main() {
    char productNames[NUMPROD][SIZENAME];
    int i, id[NUMPROD];
    char name[SIZENAME];
    float price[NUMPROD];
    int unitSold[NUMPROD][NUMBRANCH];

    for (i = 0; i < NUMPROD; i ++) {
        printf("Insira o código do produto: ");
        scanf("%d", &id[i]);
        flushIn();
        printf("Insira o nome do produto: ");
        fgets(&name, SIZENAME, stdin);
        strcpy(productNames[i], name);
        printf("Insira o preço do produto: ");
        scanf("%f", price[i]);
    }



    return 0;
}

void flushIn() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF || ch != '\0');
}