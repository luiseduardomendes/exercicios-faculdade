#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVEC 10

void vectorGeneration(int v[], int n, int limInf, int limSup);
int removeRepetition(int v1[], int v2[], int v3[], int sizeV);

int main() {
    int v1[SIZEVEC], v2[SIZEVEC], v3[SIZEVEC];
    int sizeV3;
    int i, aleatorio;
    srand(time(NULL));

    do{
        printf("Voce deseja escrever manualmente os vetores ou gerar vetores aleatorios?\n");
        printf("[0] Manual\n");
        printf("[1] Aleatorio\n");
        printf("Sua opcao: ");
        scanf("%d", &aleatorio);
    } while (aleatorio != 0 && aleatorio != 1);


    if (aleatorio){
        vectorGeneration(v1, SIZEVEC, 0, 10);
        vectorGeneration(v2, SIZEVEC, 0, 10);

        printf("vetor 1: \n");
        showVector(v1, SIZEVEC);

        printf("vetor 2: \n");
        showVector(v2, SIZEVEC);
    }

    else{
        printf("Insira os elementos do vetor 1: ");
        for (i = 0; i < SIZEVEC; i ++) {
            do {
                scanf("%d", &v1[i]);
                if (v1[i] > 100 || v1[i] < 0){
                    printf("Valor invalido, insira outro");
                }
            } while (v1[i] > 100 || v1[i] < 0);
        }
        printf("Insira os elementos do vetor 2: ");

        for (i = 0; i < SIZEVEC; i ++) {
            do {
                scanf("%d", &v2[i]);
                if (v2[i] > 100 || v2[i] < 0){
                    printf("Valor invalido, insira outro");
                }
            } while (v2[i] > 100 || v2[i] < 0);
        }
    }

    sizeV3 = removeRepetition(v1, v2, v3, SIZEVEC);

    printf("vetor 3: \n");
    showVector(v3, sizeV3);

    return 0;
}

int removeRepetition(int v1[], int v2[], int v3[], int sizeV){
    int i, j, k;
    int numElem = 0;
    int flag;

    // compara todos os numeros de v1 com todos os de v2 e guarda todos os que aparecem em ambos em v3
    // caso ja esteja em v3, o numero e desconsiderado
    for (i = 0; i < sizeV; i ++) {
        for (j = 0; j < sizeV; j ++) {

            //procura valores iguais em v1 e v2
            if (v1[i] == v2[j]){

                //caso encontre, procura se esse elemento ja esta em v3
                flag = 1;
                for (k = 0 ; k < numElem; k ++) {
                    if (v2[j] == v3[k]) {
                        flag = 0;
                    }
                }

                if (flag) {
                    v3[numElem] = v1[i];
                    numElem ++;
                }
            }
        }
    }
    return numElem;
}

void vectorGeneration(int v[], int n, int limInf, int limSup) {
    int i;
    for (i = 0; i < n; i ++) {
        v[i] = limInf + ((float)rand() / RAND_MAX) * (limSup - limInf);
    }
}

void showVector(int v[], int n) {
    int i;
    for (i = 0; i < n; i ++) {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

