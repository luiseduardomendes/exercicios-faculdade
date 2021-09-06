#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int tamanho_numero(int num);

int main() {
    int n1, n2;
    int tam_n1, tam_n2;
    int aux, i, j, a1, a2,aux2;
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

    aux = 0;
    for (i = 0; i < tam_n2 - 2; i ++) {
        aux = 0;
        for (j = 0; j < tam_n1; j ++) {
            a1 = (n2 / pow(10, tam_n2 - i - j - 1)) - (aux * 10);
            aux = aux * 10  + a1;

        }
        aux2 = (int)n2 / pow(10, tam_n2 - i -1);
        aux2 = aux2 * pow(10, tam_n2 - i -1);

        n2 = n2 - aux2;
        if (n1 == aux){
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
