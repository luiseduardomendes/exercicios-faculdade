#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUMNINJAS 10
#define VELOCITY 0.5

typedef struct POSICAO{
    int x, y;
}POSICAO;

typedef struct DIRECAO{
    int x, y;
}DIRECAO;

typedef struct NINJA{
    POSICAO position;
    DIRECAO direction;
    int passos;
    int id;
}NINJA;

int moveNinja (NINJA* ninja, POSICAO supEsq, POSICAO infDir);
void ninjaPosition (NINJA *ninja, POSICAO supEsq, POSICAO infDir);
void sleep_ms(int milliseconds);

int main() {
    NINJA ninjas[NUMNINJAS], ninjasOrdenado[NUMNINJAS];
    POSICAO supEsq, infDir;
    clock_t timer, timeMove;
    int i, j, k, flag, moves = 0, numMoves, ninjasParados = 0, ninjaFound;

    srand(time(NULL));
    timer = clock();
    timeMove = clock();

    for (i = 0; i < NUMNINJAS; i ++) {
        ninjas[i].passos = 0;
        ninjas[i].id = i + 1;
    }

    // leitura do mapa
    do{
        printf("Insira a posição do canto superior esquerdo: ");
        scanf("%d %d", &supEsq.x, &supEsq.y);

        printf("Insira a posição do canto inferior direito: ");
        scanf("%d %d", &infDir.x, &infDir.y);

    } while(supEsq.x > infDir.x || supEsq.y > infDir.y);

    printf("Insira o numero de movimentos: ");
    scanf("%d", &numMoves);

    for(i = 0; i < NUMNINJAS; i ++) {
        ninjaPosition(&ninjas[i], supEsq, infDir);
    }

    printf("ninja se movendo...\n");
    do{
        timer = clock();
        if ((double)(timer - timeMove) / CLOCKS_PER_SEC > VELOCITY){
            for (i = 0; i < NUMNINJAS; i ++){
                flag = moveNinja (&ninjas[i], supEsq, infDir);
                while (flag == 0){
                    setDirection(&ninjas[i]);
                    flag = moveNinja (&ninjas[i], supEsq, infDir);
                }
            }
            timeMove = clock();
            moves ++;
            system("clear");
            showMap(ninjas, NUMNINJAS, supEsq, infDir);
        }
        

    } while (moves < numMoves);

    return 0;
}

int moveNinja (NINJA* ninja, POSICAO supEsq, POSICAO infDir) {
    int flag = 0;
    POSICAO newPosition;
    newPosition.x = ninja->position.x + ninja->direction.x;
    newPosition.y = ninja->position.y + ninja->direction.y;

    if (newPosition.x <= infDir.x && newPosition.x >= supEsq.x &&
        newPosition.y <= infDir.y && newPosition.y >= supEsq.y) {

        ninja->position.x = newPosition.x;
        ninja->position.y = newPosition.y;

        flag = 1;
    }

    return flag;
}

void ninjaPosition (NINJA *ninja, POSICAO supEsq, POSICAO infDir) {
    int i, flagMove;

    ninja->position.x = supEsq.x + (((float)rand() / RAND_MAX) * (infDir.x - supEsq.x));
    ninja->position.y = supEsq.y + (((float)rand() / RAND_MAX) * (infDir.y - supEsq.y));
    flagMove = 1 + (((float)rand() / RAND_MAX) * (3));
    switch (flagMove) {
        case 1:
            ninja->direction.x = 1;
            ninja->direction.y = 0;
            break;
        case 2:
            ninja->direction.x = -1;
            ninja->direction.y = 0;
            break;
        case 3:
            ninja->direction.x = 0;
            ninja->direction.y = 1;
            break;
        case 4:
            ninja->direction.x = 0;
            ninja->direction.y = -1;
            break;
    }

}

void setDirection(NINJA *ninja){
    int flagMove;
    flagMove = 1 + (((float)rand() / RAND_MAX) * (3));
    switch (flagMove) {
        case 1:
            ninja->direction.x = 1;
            ninja->direction.y = 0;
            break;
        case 2:
            ninja->direction.x = -1;
            ninja->direction.y = 0;
            break;
        case 3:
            ninja->direction.x = 0;
            ninja->direction.y = 1;
            break;
        case 4:
            ninja->direction.x = 0;
            ninja->direction.y = -1;
            break;
    }
}

void showMap(NINJA ninjas[], int n, POSICAO supEsq, POSICAO infDir){
    int i, j, k;
    int ninjaFound;

    for (i = supEsq.y; i <= infDir.y; i ++){
        for (j = supEsq.x; j <= infDir.x; j ++){
            ninjaFound = 0;
            k = 0;
            while (k < n && !ninjaFound) {
                if (ninjas[k].position.x == j && ninjas[k].position.y == i){
                    ninjaFound = 1;
                }
                k++;
            }
            if (ninjaFound){
                printf("N ");
            }
            else{
                printf("- ");
            }
        }
        printf("\n");
    }
}

void clearscreen() {
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #endif
}
