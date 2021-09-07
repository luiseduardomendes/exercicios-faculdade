// Programa multiplataforma (não utiliza chamadas de sistema)

/* A persistência multiplicativa de um número inteiro é o número de vezes que os dígitos
 * deste número devem ser multiplicados, para que o resultado chegue a um único dígito
 * (um número entre 0 e 9). Você deve fazer um programa que lê um valor inteiro n. Depois
 * disso, o programa deve informar qual é a persistência multiplicativa do número n
 * informado e qual foi o dígito resultante. Note que não sabemos o número de dígitos
 * do número n informado.
 * Por exemplo, se o usuário informar o número 6423, a persistência multiplicativa é 3 e o
 * dígito resultante é 6, porque:
 * 6*4*2*3=144
 * 1*4*4=16
 * 1*6=6
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// função para definir o numero de letras de um valor
int tamanho_numero(int num);

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

int tamanho_numero(int num) {
    int tamanho_num;
    tamanho_num = 1;
    while (num >= 10) {
        tamanho_num ++;
        num = num / 10;
    }
    return tamanho_num;
}
