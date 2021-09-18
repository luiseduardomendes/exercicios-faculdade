#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define M 10
#define MINE -1

int open_zeros (int mat[M][N], int inter[M][N], int x, int y);
void display_table(int matriz[M][N], int interface [M][N]);
void clearscreen();
int gScore;

int main(){
    int matriz[M][N] = {0};
    int interface[M][N] = {0};
    int numx, numy, endOfGame = 0;
    int num_mines, i, j;

    srand(time(NULL));   

    clearscreen();
    printf("*-*-*-*-Campo Minado-*-*-*-*\n");
    printf("Insira o número de minas: ");
    scanf("%d",&num_mines);

    for (i = 0; i < num_mines; i ++){
        numx = ((float)rand()/RAND_MAX)*(N - 1);
        numy = ((float)rand()/RAND_MAX)*(M - 1);
        if(matriz[numy][numx] != MINE) {
            matriz[numy][numx] = MINE;
        }
        else {
            i --;
        }
    }
    

    for (i = 0; i < M; i ++) {
        for (j = 0; j < N; j ++) {
            if (matriz[i][j] != MINE){
                if(matriz [i - 1][j] == MINE)
                    matriz[i][j] ++;
                if(matriz [i - 1][j - 1] == MINE)
                    matriz[i][j] ++;
                if(matriz [i - 1][j + 1] == MINE)
                    matriz[i][j] ++;

                if(matriz [i][j - 1] == MINE)
                    matriz[i][j] ++;
                if(matriz [i][j + 1] == MINE)
                    matriz[i][j] ++;

                if(matriz [i + 1][j] == MINE)
                    matriz[i][j] ++;
                if(matriz [i + 1][j - 1] == MINE)
                    matriz[i][j] ++;
                if(matriz [i + 1][j + 1] == MINE)
                    matriz[i][j] ++;
            }
        }
    }

    do {
        display_table(matriz, interface);
        scanf("%d %d", &numx, &numy);
        interface[numy][numx] = 1;
        if (matriz[numy][numx] != -1) {
            
            gScore ++;
        }
        else {
            endOfGame = 1;
            display_table(matriz, interface);
            printf("Voce perdeu!\n");
            printf("Sua pontuação foi: %d\n", gScore);
        }

        
        
        if (matriz[numy][numx] == 0) {
            gScore += open_zeros(matriz, interface, numx, numy);
        }
        if (gScore == (M) * (N) - num_mines+1){
            endOfGame = 1;
            display_table(matriz, interface);
            printf("Voce venceu!\n");
            printf("Sua pontuação foi: %d\n", gScore);
        }
    } while (!(endOfGame));
    return 0;
}

int open_zeros (int mat[M][N], int inter[M][N], int x, int y) {

    if (y-1 >= 0 && inter [y - 1][x] == 0) {
        inter [y - 1][x] = 1;
        gScore ++;
        if(mat[y - 1][x] == 0) 
            y--;
        open_zeros(mat, inter, x, y);
    }

    if (y+1 < N && inter [y + 1][x] == 0) {
        inter[y + 1][x] = 1;
        gScore ++;
        if (mat[y + 1][x] == 0)
            y++;
        open_zeros(mat, inter, x, y);
    }

    if (x-1 >= 0 && inter [y][x - 1] == 0) {
        inter [y][x - 1] = 1;
        gScore ++;
        if (mat[y][x - 1] == 0)
            x--;
        open_zeros(mat, inter, x, y);
    }

    if (x+1 < M && inter [y][x + 1] == 0) {
        inter [y][x + 1] = 1;
        gScore ++;
        if (mat[y][x + 1] == 0)
            x++;
        open_zeros(mat, inter, x, y);
    }
    return 0;
}

void display_table(int matriz[M][N], int interface [M][N]) {
    int i, j;
    clearscreen();

    for (i = 0; i < M; i ++) {
        for (j = 0; j < N; j ++) {
            if (interface[i][j] == 1)
                printf("%2d", matriz[i][j]);
            else 
                printf(" #");
        }
        printf("\n");
    }
}
void clearscreen(){
    #ifdef WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #else
        system("cls");
    #endif
}