/*NUMERO RUNAROUND

primeiro passo: usar uma função para descobrir o tamanho do numero e separar o numero numero em um vetor de algarismos

segundo passo realizar o teste

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void separar_numero(int num, int tamanho, int vetor[38]);
int tamanho_numero(int num);


int main(){
    int numero, i, tamanho_num;
    int algarismos[38];
    bool visitado[38] = {false};
    
    
    printf("Insira um valor: ");
    scanf("%d", &numero);

    tamanho_num = tamanho_numero(numero);
    
    separar_numero(numero, tamanho_num, algarismos);

    for (i = 0; i < tamanho_num; i ++) {
        printf("%d", algarismos[i]);
    }

    i = 0;

    while (true) {
        i += algarismos[i];
        visitado[i] = true;
        while (i > tamanho_num) {            
            if (i > tamanho_num){
                i -= tamanho_num;
            } 
        }
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

void separar_numero(int num, int tamanho, int vetor[38]) {
    int i;    

    for(i = 1; i <= tamanho; i ++) {
        vetor[i] = num / pow(10, tamanho - i);
    }
}











