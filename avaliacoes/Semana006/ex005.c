/*Algoritmo para o crivo de Eratóstenes */

/*
    definir o maior elemento

    definir o primeiro elemento

    criar um vetor de tamanho igual ao maior elemento menos 1

    preencher esse vetor com o valor de i + 1

    pegar o menor valor e testar a divisibilidade por 2 de cada um desses valores 
        se for divisivel por 2, recebe o valor de -1 e flag recebe verdadeiro
        senão, não sofre alteração

    flag recebe valor falso

    repete o laço

*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int max_number, divisor, i, j = 0, prime_numbers[255] = {0};
    bool stop;

    printf("Insira o maior valor para o crivo de Eratóstenes: \n");
    scanf("%d", &max_number);

    for (i = 0; i <= max_number - 2; i ++){
        prime_numbers[i] = i + 2;
    }

    divisor = 2;

    do {
        stop = true;
        for (i = divisor; i <= max_number - divisor; i ++){
            if (prime_numbers[i] % divisor == 0) {
                prime_numbers[i] = -1;
                stop = false;
            }
        }
        j++;
        while (prime_numbers [j] == -1){
            j++;
        }

        divisor = prime_numbers[j];

    }  while (!(stop));

    printf("Os números primos até %d são: \n\n", max_number);

    j=0;

    for (i = 0; i <= max_number - 2; i ++){
        
        
        if (prime_numbers[i] != -1){
            printf("%d\t", prime_numbers[i]);
            j++;  
            if (j % 10 == 0)
                printf("\n"); 
        }
    }

    printf("\n");

    return 0;
}