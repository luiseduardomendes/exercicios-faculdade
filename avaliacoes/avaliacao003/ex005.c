/*faça um programa que recebe dois números inteiros entre 0 e 19 que representam as
coordenadas x e y de um ponto em um plano bidimensional 20X20, cuja origem fica no canto
inferior esquerdo. A função deve desenhar este plano na tela, usando caracteres “#”, e
indicando a posição do ponto com o caractere “P”. Por exemplo, se o ponto informado fosse
(5,8), a função deveria desenhar o seguinte (ignore a cor diferenciada): */
#include <stdio.h>
#define TAM 20

int main() {
    int i,j;
    int x, y;
    printf("Insira a coordenada x [de 0 ate 19]:\n");
    scanf("%d", &x);
    printf("Insira a coordenada y [de 0 ate 19]:\n");
    scanf("%d", &y);

    for (i = TAM - 1; i >= 0; i --) { // LINHAS
        for (j = 0; j < TAM; j ++) { // COLUNAS
            if (i == y && j == x) {
                printf("P ");
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}