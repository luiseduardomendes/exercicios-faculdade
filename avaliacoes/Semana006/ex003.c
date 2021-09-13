/* O programa a seguir é um simulador de corrida de cavalos!
O usuário pode apostar em qual cavalo ele acha que vencerá. A cada repetição do programa, 
cada cavalo recebe um acréscimo na distância percorrida igual a um valor pseudoaleatório 
gerado pelo programa. Ao final da execução do programa o usuário descobrirá se acertou ou
errou a aposta. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <locale.h>
#include <time.h>

#define N 5

void flush_in();

void sleep_ms(int milliseconds)

int main() {
    setlocale(LC_CTYPE, "");
    int i, j, k, dist = 50, distMax = 6;
    int horse_dist[N] = {0};
    bool end_of_race = false;
    int bet, winner;

    srand(time(NULL));

    for (k = 0; k < N; k ++) { // mostra na tela a disposição inicial dos cavalos
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
    scanf("%d", &bet);

    while (!(end_of_race)) {
        i = 0;
        while (!(end_of_race) && i < N) {
            system("clear");

            horse_dist[i] += (1 + ((float)rand() / RAND_MAX) * (distMax - 1));

            // mostra na tela a disposição atual dos cavalos
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
                winner = i + 1;
                end_of_race = true;
            }

            sleep_ms(250);
            flush_in();
            
            i++;
        } 
    }

    if (winner == bet){
        printf("Você acertou o cavalo vencedor! Parabéns!!!\n\n");
    }
    else {
        printf("Você perdeu a aposta! Tente novamente na próxima!\n\n");
    }
    
    
    return 0;
}

void sleep_ms(int milliseconds) {
    #ifdef WIN32
        Sleep(milliseconds);
    #elif _POSIX_C_SOURCE >= 199309L
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    #else
        usleep(milliseconds * 1000);
    #endif
}

void flush_in()
{
    int ch;
    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}