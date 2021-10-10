#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVET 10
void distanceAnalisys(float x[], float y[], int size, float *p1x, float *p1y, float *p2x, float *p2y, float *dist);
float distance(float x1, float y1, float x2, float y2);
int main(){
    float x[SIZEVET], y[SIZEVET];
    int i;
    float p1x, p1y, p2x, p2y, dist;
    srand(time(NULL));
    for (i = 0; i < SIZEVET; i ++) {
        x[i] = -5 + ((float)rand() / RAND_MAX) * (10);
        y[i] = -5 + ((float)rand() / RAND_MAX) * (10);
    }
    for (i = 0; i < SIZEVET; i ++) {
        printf("%.2f\t", x[i]);
    }
    printf("\n");
    for (i = 0; i < SIZEVET; i ++) {
        printf("%.2f\t", y[i]);
    }
    printf("\n");
    distanceAnalisys(x, y, SIZEVET, &p1x, &p1y, &p2x, &p2y, &dist);
    printf("Pontos com maior distancia entre si: \n\n");
    printf("p1: %.2f, %.2f\n", p1x, p1y);
    printf("p2: %.2f, %.2f\n", p2x, p2y);
    printf("distancia entre eles: %.2f\n", dist);
    return 0;
}

void distanceAnalisys(float x[], float y[], int size, float *p1x, float *p1y, float *p2x, float *p2y, float *dist) {
    int i, j;
    float maior = distance(x[0], y[0], x[1], y[1]);
    *p1x = x[0];
    *p1y = y[0];
    *p2x = x[1];
    *p2y = y[1];

    printf("\n");
    for (i = 0; i < size; i ++){
        for (j = 0; j < size; j ++){
            if (j != i){
                *dist = distance(x[i], y[i], x[j], y[j]);
                if (*dist > maior){
                    maior = *dist;
                    *p1x = x[i];
                    *p1y = y[i];
                    *p2x = x[j];
                    *p2y = y[j];
                }
            }
        }
    }
    *dist = maior;
}

float distance(float x1, float y1, float x2, float y2){
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2- y1, 2));
    return dist;
}

