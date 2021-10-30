#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *arq;

int main() {
    char buffer[255];
    if(arq = fopen("teste.txt", "r")){
        while(!feof(arq)){
            if (fgets(buffer, sizeof(buffer), arq)){
                printf("nome: %s", buffer);
            }
            if (fgets(buffer, sizeof(buffer), arq)){
                printf("Salário: R$%.2f\n\n", atof(buffer));
            }
        }
    }

    return 0;
}