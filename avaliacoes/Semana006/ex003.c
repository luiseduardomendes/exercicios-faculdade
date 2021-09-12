#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <locale.h>
#include <time.h>
#include <sys/wait.h>

#define N 5

int main() {
    int i, j, k, dist = 50, distMax = 6;
    int horse_dist[N] = {0};
    bool end_of_race = false;
    int aposta, vencedor;

    srand(time(NULL));

    for (k = 0; k < N; k ++) {
        for (j = 0; j < dist; j ++) {
            if (horse_dist[k] == j){
                printf("C%d", k + 1);
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Faça sua aposta: Qual cavalo você acha que vencerá? [1 até %d]\n", N);
    scanf("%d", &aposta);
    getchar();
    while (!(end_of_race)) {
        i = 0;
        while (!(end_of_race) && i < N) {
            system("clear");

            horse_dist[i] += (1 + ((float)rand() / RAND_MAX) * (distMax - 1));

            for (k = 0; k < N; k ++) {
                for (j = 0; j < dist; j ++) {
                    if (horse_dist[k] == j){
                        printf("C%d", k + 1);
                    }
                    else {
                        printf("- ");
                    }
                }
                printf("\n");
            }

            
            
            if (horse_dist[i] >= dist) {
                vencedor = i + 1;
                end_of_race = true;
            }

            system("sleep 0.25");
            fflush(stdout);
            
            i++;
        } 
    }

    if (vencedor == aposta){
        printf("Você acertou o cavalo vencedor! Parabéns!!!\n\n");
    }
    else {
        printf("Você perdeu a aposta! Tente novamente na próxima!\n\n");
    }
    
    
    return 0;
}
