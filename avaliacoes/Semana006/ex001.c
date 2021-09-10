#include <stdio.h>
#include <math.h>
#define N 10

int main() {
    int i;
    float vet[N], soma = 0, media, proximo;
    printf("Insira os valores para o vetor: \n\n");
    for (i = 0; i < N; i ++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &vet[i]);
    }

    printf("\nOs itens digitados foram: \n\n");
    for (i = 0; i < N; i ++) {
        printf("%.2f \t", vet[i]);
    }

    // movendo o vetor 1 posição para a direita
    for(i = N-1; i >= 0 - 1; i --) {
        vet[i + 1] = vet[i];
    }
    printf("\n");

    printf("\nInsira um novo valor: ");
    scanf("%f", &vet[0]);

    printf("\nO vetor com os valores atualizados é \n\n");
    for (i = 0; i < N; i ++) {
        printf("%.2f \t", vet[i]);
    }

    for(i = 1; i < N; i += 2) {
        vet[i] = i;
    }
    
    printf("\n\nO vetor com as posições ímpares atualizadas é\n\n");
    for (i = 0; i < N; i ++) {
        printf("%.2f \t", vet[i]);
    }

    for (i = 0; i < N;i ++) {
        soma += vet[i];
    }
    
    media = (float)soma / N;

    printf("\n\nA media dos elementos do vetor é: %.2f\n\n", media);

    proximo = vet[0];
    for(i = 1; i < N; i ++) {
        if (fabs(media - vet[i]) < fabs(media - proximo)) {
            proximo = vet[i];
        }
    }


    printf("O valor mais próximo da média é: %.2f\n\n", proximo);


    return 0;
}