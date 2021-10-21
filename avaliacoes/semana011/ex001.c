#include <stdio.h>
#include <time.h>
#include <locale.h>
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
}NINJA;

int moveNinja (NINJA* ninja, POSICAO supEsq, POSICAO infDir);

int main() {
    setlocale(LC_ALL, "");
    NINJA ninja;
    POSICAO supEsq, infDir;
    clock_t timer, timeMove;
    int endOfMovement = 0;
    int flag;

    timer = clock();
    timeMove = clock();

    do{
        printf("Insira a posição do canto superior esquerdo: ");
        scanf("%d %d", &supEsq.x, &supEsq.y);

        printf("Insira a posição do canto inferior direito: ");
        scanf("%d %d", &infDir.x, &infDir.y);
        if (supEsq.x > infDir.x || supEsq.y > infDir.y){
            printf("Valores inseridos inválidos, insira novamente\n");
        }
    } while(supEsq.x > infDir.x || supEsq.y > infDir.y);

    do{
        printf("Insira a posição do ninja: ");
        scanf("%d %d", &ninja.position.x, &ninja.position.y);
        if (ninja.position.x > infDir.x || ninja.position.y > infDir.y ||
                ninja.position.x < supEsq.x || ninja.position.y < supEsq.y)
            printf("Valores inseridos inválidos, insira novamente\n");
    } while(ninja.position.x > infDir.x || ninja.position.y > infDir.y ||
                ninja.position.x < supEsq.x || ninja.position.y < supEsq.y);

    do{
        printf("Informe os deslocamentos do ninja em x e y: ");
        scanf("%d %d", &ninja.direction.x, &ninja.direction.y);
        if ((ninja.direction.x < -1 || ninja.direction.x > 1 ||
                ninja.direction.y < -1 || ninja.direction.y > 1) ||
                (ninja.direction.x == 0 && ninja.direction.y == 0))
            printf("Valores inseridos inválidos, insira novamente\n");
    }while (ninja.direction.x < -1 || ninja.direction.x > 1 ||
            ninja.direction.y < -1 || ninja.direction.y > 1 || 
            (ninja.direction.x == 0 && ninja.direction.y == 0));


    printf("ninja se movendo...\n");
    do{
        timer = clock();
        if ((double)(timer - timeMove) / CLOCKS_PER_SEC > VELOCITY){
            flag = moveNinja(&ninja, supEsq, infDir);
            
            timeMove = clock();
            if (flag == 0) {
                endOfMovement = 1;
            }
            else {
                clearscreen();
                printf("Posição do ninja: %d %d\n", ninja.position.x, ninja.position.y);
                showMap(ninja, supEsq, infDir);
            }
        }
    } while (!endOfMovement);

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

void showMap(NINJA ninja, POSICAO supEsq, POSICAO infDir){
    int i, j;

    for (i = supEsq.y; i <= infDir.y; i ++){
        for (j = supEsq.x; j <= infDir.x; j ++){
            if (ninja.position.x == j && ninja.position.y == i){
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

