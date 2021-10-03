#include <stdio.h>
void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin);
typedef struct points{
    float x, y;
}points;
int main() {
    points p1, p2;
    float coefAng, coefLin;
    
    printf("Insira as coordenadas do primeiro ponto: ");
    scanf("%f %f", p1.x, p1.y);
    printf("Insira as coordenadas do segundo ponto: ");
    scanf("%f %f", p2.x, p2.y);

    coeficientes(p1.x, p2.x, p1.y, p2.y, &coefAng, &coefLin);

    printf("Coeficiente angular %.2f", coefAng);
    printf("Coeficiente Linear %.2f", coefLin);
    return 0;
}

void coeficientes(float x1, float x2, float y1, float y2, float *coefAng, float *coefLin) {
    *coefAng = (y2 - y1) / (x2 - x1);  
    *coefLin = (*coefAng) * x2 + y2;
}