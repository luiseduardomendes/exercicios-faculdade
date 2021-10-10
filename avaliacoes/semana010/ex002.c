#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVEC 10
int main() {
    int v1[SIZEVEC], v2[SIZEVEC], v3[SIZEVEC];
    int sizeV3;
    int i;
    srand(time(NULL));
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

    /*for (i = 0; i < SIZEVEC; i ++) {
        v1[i] = ((float)rand() / RAND_MAX) * (10);
        v2[i] = ((float)rand() / RAND_MAX) * (10);
    }*/
    printf("vetor 1: \n");
    for (i = 0; i < SIZEVEC; i ++) {
        printf("%d\t", v1[i]);
    }
    printf("\n");
    printf("vetor 2: \n");
    for (i = 0; i < SIZEVEC; i ++) {
        printf("%d\t", v2[i]);
    }
    printf("\n");

    sizeV3 = funcao(v1, v2, v3, SIZEVEC);
    printf("vetor 3: \n");
    for (i = 0; i < sizeV3; i ++) {
        printf("%d\t", v3[i]);
    }
    printf("\n");

    return 0;
}

int funcao (int v1[], int v2[], int v3[], int sizeV){
    int i, j, k;
    int numElem = 0;
    int flag;
    for (i = 0; i < sizeV; i ++) {
        for (j = 0; j < sizeV; j ++) {
            flag = 1;
            for (k = 0 ; k < numElem; k ++) {
                if (v1[i] == v2[j] && v2[j] == v3[k]) {
                    flag = 0;
                }
            }
            if (v1[i] == v2[j] && flag) {
                v3[numElem] = v1[i];
                numElem ++;
            }
        }
    }
    return numElem;
}

