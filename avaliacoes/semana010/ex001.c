#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SIZEVET 10

void distanceAnalisys(float x[], float y[], int size, float *p1x, float *p1y, float *p2x, float *p2y, float *dist);
float distance(float x1, float y1, float x2, float y2);
void vectorGeneration(float v[], int n, float limInf, float limSup);
void showVector(float v[], int n);

int main(){
    float x[SIZEVET], y[SIZEVET];
    int i;
    float p1x, p1y, p2x, p2y, dist;
    int aleatorio;
    srand(time(NULL));

    do{
        printf("Voce deseja escrever manualmente os pontos ou gerar pontos aleatorios?\n");
        printf("[0] Manual\n");
        printf("[1] Aleatorio\n");
        printf("Sua opcao: ");
        scanf("%d", &aleatorio);
    } while (aleatorio != 0 && aleatorio != 1);

    // Geracao aleatoria de numeros
    if(aleatorio){
        vectorGeneration(x, SIZEVET, -25, 25);
        vectorGeneration(y, SIZEVET, -25, 25);
        for (i = 0; i < SIZEVET; i ++){
            printf("ponto %d: ", i + 1);
            printf("%.2f %.2f\n", x[i], y[i]);
        }
    }

    // leitura de dados
    else{
        printf("Insira as coordenadas x e y para os pontos\n");
        for (i = 0; i < SIZEVET; i ++){
            printf("ponto %d: ", i + 1);
            scanf("%f %f", &x[i], &y[i]);
        }
    }


    distanceAnalisys(x, y, SIZEVET, &p1x, &p1y, &p2x, &p2y, &dist);

    // apresentacao dos dados obtidos
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

void vectorGeneration(float v[], int n, float limInf, float limSup) {
    int i;
    for (i = 0; i < n; i ++) {
        v[i] = limInf + ((float)rand() / RAND_MAX) * (limSup - limInf);
    }
}

void showVector(float v[], int n) {
    int i;
    for (i = 0; i < n; i ++) {
        printf("%f\t", v[i]);
    }
    printf("\n");
}

