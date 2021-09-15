/* Você deve construir um programa que lê ou recebe por aleatoriedade N valores reais 
e os armazena em um vetor de N posições. A seguir, o programa deve fazer o seguinte 
(todas as operações são realizadas sobre o mesmo vetor):
* Exibir todos os valores do vetor na mesma linha.
* Pedir para o usuário ler um novo valor e inserir este valor na primeira posição do
vetor, deslocando todos os elementos para as posições subsequentes. O último elemento 
é perdido. Exibir o vetor resultante novamente.
* Alterar todos os elementos que estão em posições ímpares do vetor pelo índice da
posição. Ou seja, o elemento que está na posição 1 é substituído por 1, e assim
sucessivamente. Exibir o vetor resultante novamente.
* Calcular e exibir a média dos valores da última versão do vetor.
* Identificar e exibir o valor da última versão do vetor que está mais próximo da
média calculada anteriormente. */

#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 10

int main() {
    setlocale(LC_CTYPE, "");
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
    for(i = N-1; i >= 0; i --) {
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
