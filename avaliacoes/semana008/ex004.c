#include <stdio.h>
#include <math.h>

typedef struct points{
    float x, y;
}points;

int interception(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22);
void showReta(float m1, float n1, float m2, float n2);

int main() {
    float x11,y11,x12,y12,x21,y21,x22,y22;
    float m1, n1, m2, n2;
    int flag;

    printf("Digite as coordenas para o ponto 1 da reta 1: ");
    scanf("%f %f", &x11, &y11);
    printf("Digite as coordenas para o ponto 2 da reta 1: ");
    scanf("%f %f", &x12, &y12);
    printf("Digite as coordenas para o ponto 1 da reta 2: ");
    scanf("%f %f", &x21, &y21);
    printf("Digite as coordenas para o ponto 2 da reta 2: ");
    scanf("%f %f", &x22, &y22);

    flag = interception(x11,y11,x12,y12,x21,y21,x22,y22);

    return 0;
}

int interception(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22) {
    int flag;
    float coefAng1, coefLin1, coefAng2, coefLin2;

    coefAng1 = (y12 - y11) / (x12 - x11);
    coefLin1 = y12 - x12 * (coefAng1);

    coefAng2 = (y22 - y21) / (x22 - x21);
    coefLin2 = y22 - x22 * (coefAng2);

    if (coefAng1 == coefAng2 && coefLin1 != coefLin2){
        flag = 0;
    }
    else {
        flag = 1;
        showReta(coefAng1, coefLin1, coefAng2, coefLin2);
    }
    return flag;
}

void showReta(float m1, float n1, float m2, float n2) {
    int i, j;
    float intx, inty;
    points tamanho2, tamanho1;

    intx = (n2 - n1) / (m1 - m2);
    inty = m1 * intx + n1;


    printf("intx: %.2f\n", intx);
    printf("inty: %.2f\n", inty);

    tamanho1.x = intx - 15;
    tamanho1.y = inty - 15;
    tamanho2.x = intx + 15;
    tamanho2.y = inty + 15;

    for (i = tamanho2.y; i >= tamanho1.y; i --) {
        for (j = tamanho1.x; j < tamanho2.x; j ++) {
            if (i == inty && j == intx){
                printf("o ");
            }
            else if (fabs(round((m1 * j) + n1) == i)) {
                printf("# ");
            }
            else if (fabs(round((m2 * j) + n2) == i)){
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

void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin) {
    *coefAng = (y2 - y1) / (x2 - x1);
    *coefLin = y2 - x2 * (*coefAng);
}
