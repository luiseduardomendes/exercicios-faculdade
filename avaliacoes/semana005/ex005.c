// Programa multiplataforma (não utiliza chamadas de sistema

/* A conjectura de Collatz diz que se escolhermos qualquer número X, se ele for par,
 * dividimos X por 2; se X for ímpar multiplicamos X por 3 e adicionamos 1, realizando o
 * processo repetidamente, em algum momento obtemos o número 1. Note que se trata de
 * uma conjectura, e que portanto ainda não foi provada, apesar dos esforços dos
 * matemáticos. Faça um programa que lê um número x e um número r que indica o
 * máximo de repetições que devem ser feitas. O programa deve informar quantas
 * repetições foram realizadas para chegar a 1, realizando o processo acima, caso o número
 * de repetições seja menor que r. Caso contrário, o programa deve informar que não foi
 * possível chegar a 1 com r repetições. */

#include <stdio.h>

int main()
{
    int num, r, repeticoes = 0;

    do{
        printf("Digite um valor n [maior do que 1]: ");
        scanf("%d", &num);
        if (num < 1) {
            printf("Insira um número maior que 1\n");
        }
    } while (num < 1);

    do{
        printf("Digite o número de repetições: ");
        scanf("%d", &r);
        if (r < 1) {
            printf("Insira um número maior que 1\n");
        }
    } while (r < 1);

    while (num != 1 && repeticoes <= r) {
        if (num % 2 == 0) {
            num = num / 2;
        }
        else {
            num = (3 * num) + 1;
        }
        printf("%d\n", num);
        repeticoes ++;
    }
    if (num == 1){
        printf("O numero de repetições usadas para chegar até 1 foi %d\n", repeticoes);
    }
    else {
        printf("Não foi possível chegar em 1 com o número de repetições estipulado!\n");
    }
}
