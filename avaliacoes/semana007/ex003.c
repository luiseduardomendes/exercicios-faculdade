/* Você deve elaborar um jogo parecido com o jogo clássico “campo minado”. O seu campo
tem dimensões N X M (definir como constantes). O programa deve inicialmente pedir para
o usuário informar um valor m que define quantas minas ele deve distribuir no campo. [O 
programa foi adaptado para facilitar a seleção do número de bombas pelo usuário: o usuário
escolhe entre as dificuldades fácil, médio, difícil e mestre do campo minado, que possuem
10%, 20%, 30% e 50% do mapa composto por minas, respectivamente] A seguir, o programa 
deve distribuir aleatoriamente pelo campo essas m minas. Você pode assumir que seu campo 
é uma matriz de inteiros de N X M (inicialmente inicializada com zero) e definir como -1 
o valor das células que vão receber minas. A seguir, o programa deve calcular para cada 
célula da matriz que representa o campo, quantas minas existem na vizinhança e atribuir 
esse número como valor da célula. Em uma outra matriz de N X M (visitados), que inicial-
mente é inicializada em 0, você deve representar quais células o usuário já visitou. 
Quando o usuário visita uma célula, esta célula recebe 1. A seguir, o programa deve 
continuamente pedir para o usuário qual célula ele deseja visitar (linha e coluna da 
matriz). Caso o usuário indique uma célula com mina, o jogo termina e o usuário perde. 
Caso o usuário visite uma posição sem mina, deve-se mostrar para o usuário a quantidade 
de minas na vizinhança daquela célula. Se o usuário visitar todas as posições sem mina, 
o jogo termina e ele ganha. Quando o jogo termina (com o jogador ganhando ou perdendo),
exibir todas as posições que possuem minas. O programa deve informar quando o
usuário informar uma célula já visitada também. Alternativamente, você pode exibir uma
representação do estado atual do campo, cada vez que pedir para o usuário informar a
célula a ser visitada. Por exemplo, uma representação poderia exibir o caractere "#" para
células ainda não visitadas e, no caso de uma célula já visitada, exibir o dígito que
representa quantas minas existem na vizinhança. */

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 4
#define M 4
#define MINE -1

int open_zeros (int mat[M][N], int inter[M][N], int x, int y);
void display_table(int matriz[M][N], int interface [M][N]);
void clearscreen();
int main_menu();
void flush_in();
float difficult_menu();
int gScore;


int main(){
    setlocale(LC_CTYPE, "");
    int matriz[M][N] = {0};
    int interface[M][N] = {0};
    int openmap[M][N];
    int numx, numy, endOfGame = 0;
    int i, j, aux;
    float mines_percentage = 0.1, num_mines;
    int size_table = 8;
    int main_opt;
    char nome[32];
    int players = 0; 
    int highscores[32];

    srand(time(NULL));   

    for (i = 0; i < M; i ++) {
        for (j = 0; j < N; j ++) {
            openmap[i][j] = 1;
        }
    }
    do {

        clearscreen();
        main_opt = main_menu();

        switch(main_opt){
        case 1:
            printf("Insira seu nome: ");
            flush_in();
            fgets(&nome, 32, stdin);
            players ++;
            gScore = 0;
            endOfGame = 0;
            
            num_mines = M * N * mines_percentage;

            for(i = 0; i < M; i ++){
                for(j = 0; j < N; j ++) {
                    interface[i][j] = 0;
                }
            }

            for(i = 0; i < M; i ++){
                for(j = 0; j < N; j ++) {
                    matriz[i][j] = 0;
                }
            }

            for (i = 0; i < (int)(num_mines); i ++){
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
                if (matriz[numy][numx] == 0 && interface[numy][numx] == 0) {
                    gScore += open_zeros(matriz, interface, numx, numy);
                }
                interface[numy][numx] = 1;
                if (matriz[numy][numx] != -1 && interface[numy][numx]) {
                    
                    gScore ++;
                }
                else {
                    endOfGame = 1;
                    display_table(matriz, openmap);
                    printf("Voce perdeu!\n");
                    printf("Sua pontuação foi: %d\n", gScore);
                    highscores[players] = gScore;
                    
                    flush_in();
                    printf("Enter para continuar\n");
                    getchar();
                }

                
                
                
                aux = 0;
                for (i = 0; i < M; i ++) {
                    for (j = 0; j < N; j ++) {
                        if (interface[i][j] != 0)
                            aux ++;
                    }
                }
                if (aux >= (int)M * N - num_mines) {
                    endOfGame = 1;
                    display_table(matriz, openmap);
                    printf("Voce venceu!\n");
                    printf("Sua pontuação foi: %d\n", gScore);

                    flush_in();
                    printf("Enter para continuar\n");
                    getchar();

                }
            } while (!(endOfGame));
            break;
        

        case 2 : mines_percentage = difficult_menu();
        break;

        case 0 : printf("Aplicativo encerrado!\n");
        break;
        }
    } while (main_opt != 0);
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
    printf("Pontuação: %d\n\n", gScore);

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

int main_menu() {
    int option;
    do{
        clearscreen();
        printf("*-*-*-*-Campo Minado-*-*-*-*\n");
        printf("[1] Iniciar um novo jogo\n");
        printf("[2] Alterar dificuldade\n");
        printf("[3] Alterar tamanho do mapa [OPÇÃO INDISPONÍVEL NO MOMENTO]\n");
        printf("[0] Encerrar o jogo\n");
        printf("Sua opção: ");
        scanf("%d", &option);
    } while (option < 0 || option > 2); 
    return option;
}

float difficult_menu(){
    int option; 
    float mines_percentage = 0.1;
    clearscreen();
    do {
        printf("[1] Fácil\n"
        "[2] Médio\n"
        "[3] Difícil\n"
        "[4] Mestre do campo minado\n"
        "[0] Retornar ao menu principal\n");
        
        printf("Sua opção: ");
        scanf("%d", &option);

    }while (option < 0 || option > 4);
    switch (option)
    {
    case 1 :
        mines_percentage = 0.1;
        break;
    case 2 :
        mines_percentage = 0.2;
        break;
    case 3 : 
        mines_percentage = 0.3;
        break;
    case 4 :
        mines_percentage = 0.5; 
        break;
    }
    return(mines_percentage);
}

int dimensions(){
    int option, size_table;
    do {
        printf("[1] 8 x 8\n"
        "[2] 16 x 16\n"
        "[3] 32 x 32\n"
        "[0] Voltar ao menu principal\n"
        "Sua opção: ");
        scanf("%d", &option);
    } while (option < 0 || option > 3);
    switch (option) {
        case 1: size_table = 8;
        break;
        case 2: size_table = 16;
        break;
        case 3: size_table = 32;
        break;
    }
    return (size_table); 
}
void flush_in(){
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');

}