#include <stdio.h>
#include <stdlib.h>

int main(){
    enum coordenadas {x1, y1, x2, y2, x3, y3};
    float ponto[6];
    float deslocamento;
    char movimento;
    int passos = 0;
    int i, j;


    printf("Insira o valor das coordenadas x e y do ponto 1: ");
    scanf("%f %f", &ponto[x1], &ponto[y1]);
    printf("\n");

    do {
        printf("Insira o valor das coordenadas x e y do ponto 2: ");
        scanf("%f %f", &ponto[x2], &ponto[y2]);
        printf("\n");
        if ((ponto[x1] > ponto[x2] || ponto[y1] > ponto[y2])) {
            printf("Valor inválido, \n"
                   "as coordenadas do ponto 2 devem ser maiores do que as do ponto 1");
        }

    } while (ponto[x1] > ponto[x2] || ponto[y1] > ponto[y2]);


    printf("Insira o valor das coordenadas x e y do objeto: ");
    scanf("%f %f", &ponto[x3], &ponto[y3]);
    printf("\n");

    printf("Insira o valor do deslocamento do objeto: ");
    scanf("%f", &deslocamento);
    printf("\n");

    while ((ponto[x3] >= ponto[x1] && ponto[y3] >= ponto[y1]) &&
           (ponto[x3] <= ponto[x2] && ponto[y3] <= ponto[x2])) {
        system("clear");

        for (i = (int)ponto[x2]; i >= (int)ponto[x1]; i --) {

            for (j = (int)ponto[y1]; j <= (int)ponto[y2]; j ++) {

                if (j == (int)ponto[x3] && i == (int)ponto[y3]) {
                    printf("o ");
                }
                else {
                    printf("# ");
                }
            }
            printf("\n");
        }

        printf("Insira a direção do movimento: ");
        __fpurge(stdin);
        scanf("%c", &movimento);
        movimento = toupper(movimento);
        switch (movimento) {
            case 'A': ponto[x3] -= deslocamento;
                break;
            case 'D': ponto[x3] += deslocamento;
                break;
            case 'W': ponto[y3] += deslocamento;
                break;
            case 'S': ponto[y3] -= deslocamento;
                break;
        }
        passos ++;
    }
    printf("Você saiu da área delimitada em %d passos!", passos);
    return 0;
}

