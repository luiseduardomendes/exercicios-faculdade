#include <stdio.h>
#include <math.h>

void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin);

void showReta(float m, float n);

typedef struct points{
    float x, y;
}points;

int main() {
    points p1, p2;
    float coefAng, coefLin;

    printf("Insira as coordenadas do primeiro ponto: ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Insira as coordenadas do segundo ponto: ");
    scanf("%f %f", &p2.x, &p2.y);

    coeficientes(p1.x, p2.x, p1.y, p2.y, &coefAng, &coefLin);

    printf("Coeficiente angular %.2f\n", coefAng);
    printf("Coeficiente Linear %.2f\n", coefLin);

    showReta(coefAng, coefLin);
    return 0;
}

void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin) {
    *coefAng = (y2 - y1) / (x2 - x1);
    *coefLin = y2 - x2 * (*coefAng);
}
void showReta(float m, float n) {
    int i, j;
    points tamanho2, tamanho1;
    printf("m: %.2f\n", m);
    printf("n: %.2f\n", n);

    tamanho1.x = -15;
    tamanho1.y = n - 15;
    tamanho2.x = 15;
    tamanho2.y = n + 15;


    for (i = tamanho2.y; i >= tamanho1.y; i --) {
        for (j = tamanho1.x; j < tamanho2.x; j ++) {
            if (fabs(round((m * j) + n) == i)) {
                printf("# ");
            }
            else if (i == 0 || j == 0) {
                printf("* ");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}
