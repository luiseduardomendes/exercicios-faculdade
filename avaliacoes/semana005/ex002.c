#include <stdio.h>
#include <stdlib.h>

int main(){
    enum coordenadas {x = 1, y};
    float p1[2], p2[2], p3[3];
    float deslocamento;
    char movimento;
    int passos = 0;

    printf("Insira o valor das coordenadas x e y do ponto 1: ");
    scanf("%f %f", &p1[x], &p1[y]);
    printf("\n");

    do {
        printf("Insira o valor das coordenadas x e y do ponto 2: ");
        scanf("%f %f", &p2[x], &p2[y]);
        printf("\n");
        if ((p1[x] > p2[x] || p1 [y] > p2[y])) {
            printf("Valor inválido, \n"
                   "as coordenadas do ponto 2 devem ser maiores do que as do ponto 1");
        }

    } while (p1[x] > p2[x] || p1 [y] > p2[y]);


    printf("Insira o valor das coordenadas x e y do objeto: ");
    scanf("%f %f", &p3[x], &p3[y]);
    printf("\n");

    printf("Insira o valor do deslocamento do objeto: ");
    scanf("%f", &deslocamento);

    while ((p3[x] > p1[x] && p3[y] > p1[x]) || (p2[x] < p1[x] && p2[y] < p1[x])) {
        printf("Insira a direção do movimento: ");
        scanf("%c", &movimento);
        movimento = toupper(movimento);
        switch (movimento) {
            case 'A': p3[x] -= deslocamento;
                break;
            case 'D': p3[x] += deslocamento;
                break;
            case 'W': p3[y] += deslocamento;
                break;
            case 'S': p3[y] -= deslocamento;
                break;
        }
        passos ++;
    }
    printf("Você saiu da área delimitada em %d passos!", passos);
    return 0;
}

