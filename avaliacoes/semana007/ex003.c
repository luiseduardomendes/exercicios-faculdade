#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 2
#define M 2
#define BOMB -1

int main(){
    int matriz[M][N] = {0};
    int interface[M][N] = {0};
    int numx, numy, endOfGame = 0;
    int total, i, j, score = 0;

    srand(time(NULL));   

    scanf("%d",&total);

    for (i = 0; i < total; i ++){
        numx = ((float)rand()/RAND_MAX)*(N - 1);
        numy = ((float)rand()/RAND_MAX)*(M - 1);
        if(matriz[numy][numx] != BOMB) {
            matriz[numy][numx] = BOMB;
        }
        else {
            i --;
        }
    }
    

    for (i = 0; i < M; i ++) {
        for (j = 0; j < N; j ++) {
            if (matriz[i][j] != BOMB){
                if(matriz [i - 1][j] == BOMB)
                    matriz[i][j] ++;
                if(matriz [i - 1][j - 1] == BOMB)
                    matriz[i][j] ++;
                if(matriz [i - 1][j + 1] == BOMB)
                    matriz[i][j] ++;

                if(matriz [i][j - 1] == BOMB)
                    matriz[i][j] ++;
                if(matriz [i][j + 1] == BOMB)
                    matriz[i][j] ++;

                if(matriz [i + 1][j] == BOMB)
                    matriz[i][j] ++;
                if(matriz [i + 1][j - 1] == BOMB)
                    matriz[i][j] ++;
                if(matriz [i + 1][j + 1] == BOMB)
                    matriz[i][j] ++;
            }
        }
    }
    do {
        for (i = 0; i < M; i ++) {
            for (j = 0; j < N; j ++) {
                if (interface[i][j] == 1)
                    printf("%2d", matriz[i][j]);
                else 
                    printf(" #");
            }
            printf("\n");
        }
        scanf("%d %d", &numx, &numy);
        interface[numy][numx] = 1;
        if (matriz[numy][numx] != -1) {
            
            score ++;
        }
        else {
            endOfGame = 1;
        }

        
        
        if (matriz[numy][numx] == 0) {
            if (matriz[numy - 1][numx] == 0){
                interface [numy - 1][numx] = 1;
            }
            if (matriz[numy + 1][numx] == 0){
                interface [numy + 1][numx] = 1;
            }
            if (matriz[numy][numx - 1] == 0){
                interface [numy][numx - 1] = 1;
            }
            if (matriz[numy][numx + 1] == 0){
                interface [numy][numx + 1] = 1;
            }
        }
        if (score == (M) * (N) - total){
            endOfGame = 1;
            printf("Voce venceu!\n");
        }
    } while (!(endOfGame));
    return 0;
}