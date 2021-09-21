#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define MINDIST 50
#define MAXDIST 500

int main() {
    setlocale(LC_CTYPE, "");
    srand(time(NULL));

    int citiesDist[N][N] = {0};
    int city, lastCity;
    int totalDistance;

    int i, j;

    for (i = 0; i < N; i ++) {
        for (j = i + 1; j < N; j ++) {
            citiesDist[i][j] = MINDIST + ((float)rand() / RAND_MAX) * (MAXDIST - MINDIST);
            if (citiesDist[i][j] < 100 || citiesDist[i][j] > 400) {
                citiesDist[i][j] = -1;
            }
        }
    }

    for (i = 0; i < N; i ++) {
        for (j = i + 1; j < N; j ++) {
            citiesDist[j][i] = citiesDist[i][j];
        }
    }

    for(i = 0; i < N; i ++) {
        for (j = 0; j < N; j ++) {
            printf("%d\t", citiesDist[i][j]);
        }
        printf("\n");
    }
    
    totalDistance = 0;

    printf("Insira uma cidade: ");
    scanf("%d", &lastCity);

    do {
        printf("Insira uma cidade: ");
        scanf("%d", &city);
        if(city != -1){
            if (citiesDist[city][lastCity] > 0){
                totalDistance += citiesDist[city][lastCity];
                lastCity = city;
            }
            else{
                printf("Não existe uma rota para ir da cidade %d até a %d\n", lastCity, city);
            }
        }
        else{
            printf("A distância total do percurso é de %d\n", totalDistance);
        }

    } while (city != -1);

    return 0;
}
