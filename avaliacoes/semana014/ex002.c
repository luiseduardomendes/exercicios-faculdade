#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int vet[99];
    int search, numOc, sizeVec, opc, i;
    printf("Insira o número de elementos do vetor: ");
    scanf("%d", &sizeVec);
    do{
        printf("Deseja inserir o vetor manualmente? \n"
        "[0] Manual\n"
        "[1] Aleatório\n"
        "Sua opção: ");
        scanf("%d", &opc);
    }while (opc != 0 && opc != 1);

    if(opc){
        for (i = 0; i < sizeVec; i ++) {
            vet[i] = rand() % 10;
            printf("%d\t", vet[i]);
        }
        printf("\n");
    }
    else {
        for (i = 0; i < sizeVec; i ++) 
            scanf("%d", &vet[i]);
    }

    printf("Insira um valor que deseja buscar: ");
    scanf("%d", &search);

    numOc = contaValores(vet, sizeof(vet)/sizeof(int), search);
    printf("O vetor possui %d ocorrências do valor %d\n", numOc, search);
    return 0;
}

int contaValores(int vet[], int sizeVec, int n){
    return contaValoresRec(vet, sizeVec, n, 0);
}

int contaValoresRec(int vet[], int sizeVec, int n, int index){
    if (index == sizeVec)
        return 0;
    else if (vet[index] == n)
        return 1 + contaValoresRec(vet, sizeVec, n, index + 1);
    else
        return contaValoresRec(vet, sizeVec, n, index + 1);
}