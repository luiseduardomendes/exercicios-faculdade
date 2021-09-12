#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int tamanho_numero(int num);


int main(){
    int numero, i, j, tamanho_num;
    int algarismos[38], anterior = 0;
    bool visitado[38] = {false}, runaround = true;

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

    for (i = 0; i< tamanho_num; i ++) {
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

int tamanho_numero(int num){
    int tamanho_num;
    tamanho_num = 1;
    while (num >= 10) {
        tamanho_num ++;
        num = num / 10;
    }
    return tamanho_num;
}
