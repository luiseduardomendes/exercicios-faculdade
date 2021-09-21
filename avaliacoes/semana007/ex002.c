/*
Considere N cidades . Faça um programa que utilize uma matriz para representar as 
distâncias entre essas cidades, de tal modo que a célula (i,j) da matriz representa a 
distância entre a cidade i e a cidade j. Nesta matriz, se uma célula contém o valor 0 
(zero), isso indica que é uma rota para a própria cidade, se ela contém o valor -1, 
indica que não há via direta que conecta duas cidades, qualquer outro valor positivo 
indica que há uma via e este valor indica a distância entre as duas cidades.
A seguir, o programa deve ler uma sequência de valores (cada valor entre 0 e N-1), onde
cada valor indica uma cidade, e a sequência indica um trajeto (ordem de visitação) que
alguém gostaria de realizar para visitar um conjunto dessas cidades. O programa deve
parar de ler valores quando for informado um valor negativo, ou quando for constatado
que o trajeto é impossível, visto que o usuário informou uma cidade que não pode ser
acessada a partir da última. O programa deve informar a distância do trajeto válido (até o
usuário informar -1). Quando o usuário informar uma cidade que não pode ser acessada
a partir da última, ele deve informar isso.

Para o preenchimento da matriz, foi usado números pseudoaleatórios, que vão de 50 até
500, entretanto, os números gerados que forem menores que 100 ou maiores que 400 serão
modificados para -1, para ser usados como exemplo de cidades que não tem uma ligação entre
elas.
*/
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
