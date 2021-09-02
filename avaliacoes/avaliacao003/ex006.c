/* Dado um número real x entre 0.0 e 1.0, que representa fração da quantidade informação
 * processada, e um número inteiro N entre 5 e 50, que representa o tamanho da barra
 * (em caracteres), faça um programa que leia x e N, e imprima a barra de progresso.*/

#include <stdio.h>

int main() {
    int tamanho;
    float progresso;
    int i;
    printf("Digite o tamanho da barra de progresso:\n");
    scanf("%d", &tamanho);
    printf("Digite o progresso atual:\n");
    scanf("%f", &progresso);

    for (i = -1; i < tamanho + 1; i ++) {
        if (i == -1) {
            printf("<");
        }
        else if (i == tamanho) {
            printf(">");
        }
        else if (i < (int)(progresso * (float)tamanho)){
            printf("#");
        }
        else {
            printf("-");
        }
    }
    printf("\n");
    return 0;
}