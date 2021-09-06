#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int num, tamanho, num_auxiliar, i, resposta = 0, aux =1;
    printf("Insira um valor N qualquer: ");
    scanf("%d", &num);

    while (num >= 10) {

        tamanho = tamanho_numero(num);
        aux = 1;

        for (i = 0; i < tamanho; i ++) {
            num_auxiliar = num / pow(10, tamanho -1 -i);
            num = num - (num_auxiliar * (pow(10, tamanho -1 -i)));
            aux = aux * num_auxiliar;
        }
        num = aux;
        resposta ++;

    }
    printf("resposta: %d\n", resposta);
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
