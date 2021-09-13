/* Algoritmo para o crivo de Eratóstenes 



*/

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "");
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