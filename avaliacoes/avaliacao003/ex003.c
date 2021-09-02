/* Faça um programa que tente adivinhar o número inteiro N que o usuário está pensando,
 * com base em pistas que ele oferece. As pistas, neste caso, são 4 números inteiros que
 * o usuário informa: um divisor de N, um não divisor de N, um múltiplo de N e um não
 * múltiplo de N. O programa deve mostrar todos os números que satisfazem esses critérios,
 * e mostrar para o usuário. Caso nenhum número satisfaça os critérios, o programa deve
 * informar que não há números que satisfazem esses critérios.*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int divisor, nao_divisor, multiplo, nao_multiplo;
    int i, j, k;
    bool falha, encontrou;

    printf("Pense em um numero qualquer!\n");
    printf("Digite um divisor do numero que voce pensou:\n");
    scanf("%d", &divisor);
    printf("Digite um numero que nao e divisor do seu:\n");
    scanf("%d", &nao_divisor);
    printf("Digite um multiplo do numero que voce pensou:\n");
    scanf("%d", &multiplo);
    printf("Digite um numero que nao e multiplo do seu:\n");
    scanf("%d", &nao_multiplo);

    printf("\nO valor digitados e um dos seguintes valores: \n\n");
    for (i = 1; i <= multiplo; i ++) {
        falha = false;
        for ( j = 1; j <= (int) multiplo / divisor; j ++) {
            if (i == divisor * j ) { //encontrou um valor cujo divisor pode ser o divisor do usuario
                for (k = 1; k <= multiplo / divisor; k ++) {
                    if (i == k * nao_divisor) {
                        falha = true; // o nao divisor eh divisor de i
                    }
                }
                if (!(falha)) { // se o nao divisor nao eh divisor de i
                    for (k = 1; k <= multiplo / divisor; k ++) {
                        if (k * i == nao_multiplo) {
                            falha = true; // o nao multiplo eh multiplo de i
                        }
                    }
                    if (!(falha)) { // se o nao multiplo nao eh multiplo de i
                        for (k = 1; k <= multiplo / divisor; k ++) {
                            if (k * i == multiplo) { // encontrou um valor que satisfaz todas as condicoes
                                printf("%d\n", i);
                                encontrou = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if (!(encontrou)) {
        printf("Nenhum valor corresponde aos valores inseridos!\n");
    }
    return 0;
}