#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_NUM 11
#define FIRST_VALIDATION_NUM 9
#define SECND_VALIDATION_NUM 10

int main() {
    int i, cpf[MAX_NUM], aux;
    int first_digit_sum = 0;
    int secnd_digit_sum = 0;
    bool valid = true;

    printf("Insira os números do seu CPF com um espaço entre cada dígito: \n\n");
    for (i = 0; i < MAX_NUM; i ++){
        scanf("%d", &cpf[i]);
    } 

    for (i = 0; i < MAX_NUM - 2; i ++) {
        first_digit_sum += ((MAX_NUM - i - 1) * cpf[i]);
    }
    aux = (first_digit_sum * 10 ) % 11;

    if (aux == 10){
        aux = 0;
    }

    if (aux != cpf[FIRST_VALIDATION_NUM]) {
        valid = false;
    }

    for (i = 0; i < MAX_NUM - 1; i ++) {
        secnd_digit_sum += ((MAX_NUM - i) * cpf[i]);
    }
    aux = (secnd_digit_sum * 10 ) % 11;

    if (aux == 10){
        aux = 0;
    }
    if (aux != cpf[SECND_VALIDATION_NUM]) {
        valid = false;
    }

    if (valid){
        printf("O cpf ");
        for(i = 0; i < MAX_NUM; i ++) {
            printf("%d", cpf[i]);
            if ((i+1) % 3 == 0 && i + 1 != 9){
                printf(".");
            }
            else if ((i + 1) % 9 == 0){
                printf("-");
            }
        }
        printf(" é um cpf válido!\n\n");
    }
    
    else{
        printf("O cpf ");
        for(i = 0; i < MAX_NUM; i ++) {
            printf("%d", cpf[i]);
            if ((i+1) % 3 == 0 && i + 1 != 9){
                printf(".");
            }
            else if ((i + 1) % 9 == 0){
                printf("-");
            }
        }
        printf(" é um cpf inválido!\n\n");
    }
    
    return 0;
}
