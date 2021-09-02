/*
 * 4. (Desafio)A fórmula de Leibniz para calcular a constante π,envolve a seguinte
 * série infinita:
 * Quanto maior for o número de termos considerados, maior será a precisão da aproximação.
 * Faça um programa que lê um valor N que representa o número de termos e que calcula o
 * valor aproximado de π, utilizando o número de termos informado.*/
#include <stdio.h>

int main () {
    int i, j;
    int tamanho;
    double soma = 0;

    printf("Insira a quantidade de valores para a formula de Leibniz\n");
    scanf("%d", &tamanho);

    for (i = 1, j = 0; i < tamanho; i += 2, j++) {
        if (j % 2 == 0)
            soma = soma + (1.0 / i);
        else
            soma = soma - (1.0 / i);
    }
    soma = soma * 4;
    printf("O valor de pi, a partir da formula de Leibniz eh %lf\n", soma);

    return 0;
}