/*NUMERO RUNAROUND

primeiro passo: usar uma função para descobrir o tamanho do numero e separar o numero numero em um vetor de algarismos

segundo passo realizar o teste

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int tamanho_numero(int num);


int main(){
    int numero, i, j = 0, tamanho_num;
    int algarismos[38], anterior = 0;
    bool visitado[38] = {false};

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

        while (i > tamanho_num) {
            i -= tamanho_num;
        }

        visitado[i] = true;

        j++;
    } while (j <= tamanho_num + 2 );
    printf("\n");

    for (i = 0; i< tamanho_num; i ++) {
        if (visitado[i])
            printf("verdadeiro\n");
        else
            printf("Falso\n");
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












