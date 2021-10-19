#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVECTOR 5

double correlacaodePearson(double v1[], double v2[], int sizeVec);
void vectorGeneration(double v[], int n, double limInf, double limSup);
void showVector(double v[], int n);

int main(){
    double v1[SIZEVECTOR], v2[SIZEVECTOR];
    int i, aleatorio;
    srand(time(NULL));

    do{
        printf("Voce deseja escrever manualmente os elementos do vetor ou gerar vetores aleatorios?\n");
        printf("[0] Manual\n");
        printf("[1] Aleatorio\n");
        printf("Sua opcao: ");
        scanf("%d", &aleatorio);
    } while (aleatorio != 0 && aleatorio != 1);

    if (aleatorio){
        vectorGeneration(v1, SIZEVECTOR, -100, 100);
        vectorGeneration(v2, SIZEVECTOR, -100, 100);
    }

    else {
        printf("Insira os valores do vetor 1:\n");
        for (i = 0; i < SIZEVECTOR; i ++) {
            scanf("%lf", &v1[i]);
        }
        printf("Insira os valores do vetor 2:\n");
        for (i = 0; i < SIZEVECTOR; i ++) {
            scanf("%lf", &v2[i]);
        }
    }

    printf("Vetor 1:\n");
    showVector(v1, SIZEVECTOR);
    printf("Vetor 2:\n");
    showVector(v2, SIZEVECTOR);

    double r = correlacaodePearson(v1, v2, SIZEVECTOR);

    printf("Coeficiente de correlacao de Pearson: %lf\n", r);

    return 0;
}

double correlacaodePearson (double v1[], double v2[], int sizeVec) {
    struct variaveis {
        double x, y;
    }media, soma, var;
    int i;
    double cov;
    double numerador, denominador;
    double r;

    soma.x = 0;
    soma.y = 0;
    media.x = 0;
    media.y = 0;
    var.x = 0;
    var.y = 0;
    cov = 0;

    for (i = 0; i < sizeVec; i ++) {
        soma.x += v1[i];
        soma.y += v2[i];
    }

    media.x = soma.x / sizeVec;
    media.y = soma.y / sizeVec;

    for (i = 0; i < sizeVec; i ++) {
        var.x += pow((v1[i] - media.x), 2);
        var.y += pow((v2[i] - media.y), 2);
    }

    for (i = 0; i < sizeVec; i ++) {
        cov += ((v1[i] - media.x) * (v2[i] - media.y));
    }

    numerador = cov;
    denominador = sqrt(var.x * var.y);

    r = (numerador / denominador);

    return r;
}

void vectorGeneration(double v[], int n, double limInf, double limSup) {
    int i;
    for (i = 0; i < n; i ++) {
        v[i] = limInf + ((double)rand() / RAND_MAX) * (limSup - limInf);
    }
}

void showVector(double v[], int n) {
    int i;
    for (i = 0; i < n; i ++) {
        printf("%.2lf\t", v[i]);
    }
    printf("\n");
}
