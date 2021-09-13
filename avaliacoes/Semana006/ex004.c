/* Faça um programa que lê um número de N dígitos, armazenando cada dígito em uma posição 
do vetor. O programa deve descobrir se o número informado é “runaround”. Um número é 
runaround se ele satisfizer as seguintes condições:

* Cada dígito informa em que posição o próximo dígito ocorre. Por exemplo, no
caso do número 38241, o primeiro dígito é 3, o que quer dizer que o próximo
dígito a ser visitado está a 3 dígitos à direita dele. Ou seja, o próximo dígito é o
dígito 4, na posição 4.

* Quando a contagem chega ao último dígito da direita, ela continua no primeiro
dígito da esquerda. Por exemplo, continuando a sequência anterior, do dígito 4, o
próximo dígito seria o dígito 2, na posição 3. Porque a seguinte sequência de
visitas deveria ser feita: 1-3-8-2.

* A sequência deve retornar ao dígito inicial, depois de todos os dígitos terem sido
visitados uma vez.*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#define LIMIT_INT_RANGE 38

int tamanho_numero(int num);

int main(){
    setlocale(LC_CTYPE, "");
    int numero, i, j, tamanho_num;
    int algarismos[LIMIT_INT_RANGE], anterior = 0;
    bool visitado[LIMIT_INT_RANGE] = {false}, runaround = true;

    printf("Insira um valor: ");
    scanf("%d", &numero);

    tamanho_num = tamanho_numero(numero);

    for(i = 0; i <= tamanho_num; i ++) {
       algarismos[i] = (numero / pow(10, tamanho_num - i- 1 )) - (pow(10, 1) * anterior);
       anterior *= 10;
       anterior += algarismos[i];
    }

    for (i = 0; i < tamanho_num; i ++) {
        printf("%d ", algarismos[i]);
    }

    j=0;
    i=0;

    do {
        i += algarismos[i];

        while (i >= tamanho_num) {
            i -= tamanho_num;
        }

        visitado[i] = true;

        j++;

    } while (j <= tamanho_num + 2 );

    printf("\n");

    for (i = 0; i < tamanho_num; i ++) {
        if (!(visitado[i]))
            runaround = false;
    }

    if (runaround) {
        printf("O número %d é Runaround!\n", numero);
    }
    else {
        printf("O número %d não é Runaround!\n", numero);
    }

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
