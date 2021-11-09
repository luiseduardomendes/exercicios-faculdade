#include <stdio.h>
#include <locale.h>
#include <string.h>
#define SIZENAME 51
#define SIZEMAPX 64
#define SIZEMAPY 36
#define NUMMAXNINJAS 25

typedef struct{
    int x, y;
}t_pos;

int readMap(char mapName[], t_pos *player, t_pos ninjas[], int *numNinjas, char map[SIZEMAPY][SIZEMAPX]);
int writePositions(char fileName[],t_pos *player,t_pos ninjas[],int numNinjas,char map[SIZEMAPY][SIZEMAPX]);
void removeEnter(char str[], int strSize);

int main(){
    FILE* file;
    int flag = 0;
    setlocale(LC_ALL, "");
    char mapFileName[SIZENAME];
    char infFileName[SIZENAME] = {"inf.txt"};
    t_pos player, ninjas[NUMMAXNINJAS];
    int numNinjas = 0; 
    char map[SIZEMAPY][SIZEMAPX];
    int i, j;

    do{
        printf("Informe o nome do arquivo no qual está armazenado o mapa [enter para usar arquivo padrão]: ");
        fgets(mapFileName, SIZENAME, stdin);
        removeEnter(mapFileName, SIZENAME);
        if (!strcmp(mapFileName, ""))
            strcpy(mapFileName, "map.txt");
        file = fopen (mapFileName, "r");
        if (file != NULL){
            fclose(file);
            flag = 1;
        }
        else {
            printf("Arquivo inexistente!\n");
            flag = 0;
            }
    } while (flag != 1);
    
    printf("Informe o nome do arquivo no qual quer armazenar as posições [enter para usar arquivo padrão]: ");
    fgets(infFileName, SIZENAME, stdin);
    removeEnter(infFileName, SIZENAME);
    if (!strcmp(infFileName, "")){
        strcpy(infFileName, "inf.txt");
    }
    

    if (!readMap(mapFileName, &player, ninjas, &numNinjas, map)){
        printf("Erro na abertura do arquivo mapa\n");
    }
    else{
        fprintf(stdout, "Posicao do jogador: %d, %d\n", player.x, player.y);
        for (i = 0; i < numNinjas; i ++)
            fprintf(stdout, "Posicao do ninja %d: %d, %d\n", i+1, ninjas[i].x, ninjas[i].y);
        if(!writePositions(infFileName, &player, ninjas, numNinjas, map)){
            printf("Erro na abertura do arquivo dados\n");
        }
    }  
    return 0;
}

int readMap(char fileName[], t_pos *player, t_pos ninjas[], int *numNinjas, char map[SIZEMAPY][SIZEMAPX]){
    FILE *file;
    int flag = 1, i, j;
    int ninjasIndex = 0; 

    if(file = fopen(fileName, "r")){
        for (i = 0; i < SIZEMAPY; i ++){
            for (j = 0; j < SIZEMAPX; j ++){
                map[i][j] = fgetc(file);
                if (map[i][j] == '\n') {
                    j --;
                }
                else if (map[i][j] == 'N') {
                    ninjas[ninjasIndex].x = j;
                    ninjas[ninjasIndex].y = i;
                    ninjasIndex ++;
                }
                else if (map[i][j] == 'J'){
                    player->x = j;
                    player->y = i;
                }
            }
        }
    }
    else
        flag = 0;

    *numNinjas = ninjasIndex;
    return flag;
}

int writePositions(char fileName[],t_pos *player,t_pos ninjas[],int numNinjas,char map[SIZEMAPY][SIZEMAPX]){
    FILE* file;
    int flag = 1;
    int i;
    if (file = fopen(fileName, "w")){
        fprintf(file, "Posicao do jogador: %d, %d\n", player->x, player->y);
        for (i = 0; i < numNinjas; i ++){
            fprintf(file, "Posicao do ninja %d: %d, %d\n", i+1, ninjas[i].x, ninjas[i].y);
        }
    }
    else{
        flag = 0;
    }
    return flag;
} 

void removeEnter(char str[], int strSize) {
    int i;
    for(i = 0; i < strSize; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}
