#include <stdio.h>
#include <time.h>

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
        
    } while(supEsq.x > infDir.x || supEsq.y < infDir.y);

    do{
        printf("Insira a posição do ninja: ");
        scanf("%d %d", &ninja.position.x, &ninja.position.y);
    } while(ninja.position.x > infDir.x || ninja.position.y < infDir.y ||
                ninja.position.x < supEsq.x || ninja.position.y > supEsq.y);

    do{
        printf("Informe os deslocamentos do ninja em x e y: ");
        scanf("%d %d", &ninja.direction.x, &ninja.direction.y);
    }while (ninja.direction.x < -1 || ninja.direction.x > 1 ||
            ninja.direction.y < -1 || ninja.direction.y > 1);


    printf("ninja se movendo...\n");
    do{
        timer = clock();
        if ((double)(timer - timeMove) / CLOCKS_PER_SEC > 1){
            flag = moveNinja(&ninja, supEsq, infDir);
            printf("Posição do ninja: %d %d\n", ninja.position.x, ninja.position.y);
            timeMove = clock();
            if (flag == 0) {
                endOfMovement = 1;
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


    if (newPosition.x < infDir.x && newPosition.x > supEsq.x &&
        newPosition.y > infDir.y && newPosition.y < supEsq.y) {

        ninja->position.x = newPosition.x;
        ninja->position.y = newPosition.y;
        flag = 1;
    }

    return flag;
}

