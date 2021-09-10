/* Dizemos que um número inteiro n2 está contido literalmente em outro número inteiro n1,
 * quando a sequência de dígitos que forma o número n2 é uma subsequência da sequência de
 * dígitos que forma o número n1. Por exemplo: 123 está contido literalmente em 1234, 234
 * está contido literalmente em 1234, 23 está contido literalmente em 1234, 456 está contido
 * literalmente em 321456987, etc. Faça um programa que lê os números inteiros n1 e n2, tal
 * que n1 deve ser maior ou igual a n2 e que informe se n2 está contido literalmente em n1
 * ou não. */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Função utilizada para determinar o número de algarismos de um valor.
int tamanho_numero(int num);

int main() {
    int n1, n2;
    int tam_n1, tam_n2;
    int aux1, i, j, a1, aux2;
    bool contido_literalmente = false;

    printf("Insira um valor n1: ");
    scanf("%d", &n1);
    do {
        printf("Insira um valor n2: ");
        scanf("%d", &n2);
        if (n2 <= n1) {
            printf("Insira um valor maior que n1\n");
        }
    } while (n2 <= n1);

    tam_n1 = tamanho_numero(n1);
    tam_n2 = tamanho_numero(n2);

    printf("Tamanho n1: %d\n", tam_n1);
    printf("Tamanho n2: %d\n", tam_n2);

    /*
        Os laços de repetição a seguir separam o numero maior em pedaços de tamanho igual
        ao numero menor, por exemplo:
        - 23456 (para n1 = 345) é dividido em 234, 345 e 456 e armazenado em aux1
        Nisso, esses numeros sao comparados a n1
    */
    for (i = 0; i < tam_n2 - 2; i ++) {
        aux1 = 0;
        for (j = 0; j < tam_n1; j ++) {
            a1 = (n2 / pow(10, tam_n2 - i - j - 1)) - (aux1 * 10);
            aux1 = aux1 * 10  + a1;

        }
        aux2 = (int)n2 / pow(10, tam_n2 - i -1);
        aux2 = aux2 * pow(10, tam_n2 - i -1);

        n2 = n2 - aux2;
        if (n1 == aux1){
            contido_literalmente = true;
        }

    }
    if(contido_literalmente){
        printf("Verdadeiro \n");
    }

    return 0;
}

int tamanho_numero(int num){
    int tamanho_num;
    tamanho_num = 1;
    while (num >= 10) {
        tamanho_num ++;
        num = num / 10;
    }
    return tamanho_num;
}
