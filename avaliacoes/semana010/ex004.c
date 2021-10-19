#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZEV1 10

int main() {
    float v1[SIZEV1] = {2, 8, 15, 9, 1, 10, 7, 16, 1, 19}, v2[SIZEV1/2] ={0};
    int i, j, sizev2;

    printf("Insira o numero de colunas do histograma: ");
    scanf("%d", &sizev2);

    printf("Insira os valores do vetor 1:\n");
    for (i = 0; i < SIZEV1; i ++) {
        scanf("%f", &v1[i]);
    }

    histograma(v1,v2,SIZEV1,sizev2);

    printf("Histograma: \n");
    for (i = 0; i < sizev2; i ++){
        printf("Faixa %d: |", i+1);
        for (j = 0; j < v2[i]; j ++){
            printf("=====");
        }
        printf("|\n");
    }
    return 0;
}

void histograma (float v1[], float v2[], int n1, int n2) {
    float maior, menor;
    float intervalo;
    int i, j;
    float v1_ordenado[n1];
    for (i = 0; i < n1; i ++){
        v1_ordenado[i] = v1[i];
    }

    ordenaVetor(v1_ordenado, n1);

    maior = v1_ordenado[n1-1];
    menor = v1_ordenado[0];

    intervalo = (maior - menor) / n2;
    j = 0;
    for ( i = 0; i < n1; i ++) {
        if (v1_ordenado[i] <= (intervalo*(j+1)) + menor) {
            v2[j] ++;
        }
        else {
            j ++;
            v2[j] ++;
        }
    }
}

void ordenaVetor (float v[], int n) {
    int i;
    int troca;
    float aux;
    do {
        troca = 0;
        for (i = 0; i < n-1; i ++) {
            if (v[i] > v[i + 1]){
                aux = v[i+1];
                v[i+1] = v[i];
                v[i] = aux;
                troca = 1;
            }
        }
        n --;
    } while (troca);
}
