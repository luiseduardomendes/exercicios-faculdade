#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVECTOR 5
double correlacaodePearson(double v1[], double v2[], int sizeVec);

int main(){
    double v1[SIZEVECTOR] = {12, 34, -12, 56, 43}, v2[SIZEVECTOR] = {23, 45, 0, 72, 59};
    srand(time(NULL));
    /*int i;
    for (i = 0; i < SIZEVECTOR; i ++) {
        v1[i] = -10 + ((double)rand() / RAND_MAX) * (20);
        v2[i] = -10 + ((double)rand() / RAND_MAX) * (20);
    }
    for (i = 0; i < SIZEVECTOR; i ++) {
        printf("%.2lf\t", v1[i]);
    }
    printf("\n");
    for (i = 0; i < SIZEVECTOR; i ++) {
        printf("%.2lf\t", v2[i]);
    }
    printf("\n");*/
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
    printf("Media x: %.2lf\t\tMedia y: %.2lf\n\n", media.x, media.y);

    for (i = 0; i < sizeVec; i ++) {
        var.x += pow((v1[i] - media.x), 2);
        var.y += pow((v2[i] - media.y), 2);
    }

    printf("(x - Mx)2: %.2lf\t(x - my)2: %.2lf\n\n", var.x, var.y);

    for (i = 0; i < sizeVec; i ++) {
        cov += ((v1[i] - media.x) * (v2[i] - media.y));
    }
    printf("(x - Mx)(y - My): %.2lf\n\n", cov);

    numerador = cov;
    denominador = sqrt(var.x * var.y);
    printf("numerador: %.2lf\t\tdenominador: %.2lf\n\n", numerador, denominador);
    r = (numerador / denominador);
    printf("coeficiente de correlacao de Pearson: %.2lf\n\n", r);
    return r;
}
