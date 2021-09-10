// Programa desenvolvido para Linux

/* Você deve elaborar um programa que simula o deslocamento de um objeto
 * (representado por um par de coordenadas) em um espaço retangular. O programa deve
 * inicialmente ler 4 valores reais que representam respectivamente as coordenadas
 * cartesianas dos pontos P1(x1,y1) e P2(x2,y2). Onde P1 representa o ponto do canto
 * inferior esquerdo de um retângulo e P2 representa o ponto superior direito deste
 * retângulo. Logo, as coordenadas x e y de P2 devem ser maiores que as coordenadas x e y
 * de P1, respectivamente. A seguir, o programa deve ler dois valores que representam as
 * coordenadas de um ponto P3(x3,y3), que representa a posição inicial deste objeto. A
 * seguir, o programa deve ler um valor positivo que representa o passo de deslocamento. A
 * seguir, o programa deve continuamente pedir para o usuário informar uma direção de
 * deslocamento e efetuar o deslocamento do objeto, alterando e informando a sua nova
 * posição. O programa deve finalizar quando o objeto sair do perímetro definido pelo
 * retângulo, exibindo uma mensagem que indica isso. Assuma que para sair do perímetro, o
 * objeto deve ter uma posição fora dos limites. Se estiver exatamente sobre o limite ele é
 * considerado dentro do perímetro. As direções são representadas pelas seguintes teclas:
 * - A(a): anda para a esquerda, conforme o passo definido.
 * - D(d): anda para a direita, conforme o passo definido.
 * - S(s): anda para baixo, conforme o passo definido.
 * - W(w): anda para a cima, conforme o passo definido.
 * Caso o usuário informe uma direção inválida o programa deve informar isso e continuar
 * a execução exibindo a posição atual e executando a próxima iteração.
 * Caso o usuário informe algum dos valores inciais (P1,P2,P3 e passo, inválidos, o
 * programa deve ser encerrado, com uma mensagem informando que aquela informação é
 * inválida). Não é necessário deixar o programa repetindo para coletar as informações
 * válidas.
 * Ao fim do programa, ele deve informar quantos movimentos o objeto realizou para sair
 * do perímetro.
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
    enum coordenadas {x1, y1, x2, y2, x3, y3};
    float ponto[6];
    float deslocamento;
    char movimento;
    int passos = 0;
    int i, j;


    printf("Insira o valor das coordenadas x e y do ponto 1: ");
    scanf("%f %f", &ponto[x1], &ponto[y1]);
    printf("\n");

    do {
        printf("Insira o valor das coordenadas x e y do ponto 2: ");
        scanf("%f %f", &ponto[x2], &ponto[y2]);
        printf("\n");
        if ((ponto[x1] > ponto[x2] || ponto[y1] > ponto[y2])) {
            printf("Valor inválido, \n"
                   "as coordenadas do ponto 2 devem ser maiores do que as do ponto 1");
        }

    } while (ponto[x1] > ponto[x2] || ponto[y1] > ponto[y2]);


    printf("Insira o valor das coordenadas x e y do objeto: ");
    scanf("%f %f", &ponto[x3], &ponto[y3]);
    printf("\n");

    printf("Insira o valor do deslocamento do objeto: ");
    scanf("%f", &deslocamento);
    printf("\n");

    while ((ponto[x3] >= ponto[x1] && ponto[y3] >= ponto[y1]) &&
           (ponto[x3] <= ponto[x2] && ponto[y3] <= ponto[x2])) {
        system("clear");

        // desenha um mapa na tela do usuario
        for (i = (int)ponto[x2]; i >= (int)ponto[x1]; i --) {

            for (j = (int)ponto[y1]; j <= (int)ponto[y2]; j ++) {

                if (j == (int)ponto[x3] && i == (int)ponto[y3]) {
                    printf("o ");
                }
                else {
                    printf("# ");
                }
            }
            printf("\n");
        }

        printf("Insira a direção do movimento: ");
        __fpurge(stdin);
        scanf("%c", &movimento);
        movimento = toupper(movimento);
        switch (movimento) {
            case 'A': ponto[x3] -= deslocamento;
                passos ++;
                break;
            case 'D': ponto[x3] += deslocamento;
                passos ++;
                break;
            case 'W': ponto[y3] += deslocamento;
                passos ++;
                break;
            case 'S': ponto[y3] -= deslocamento;
                passos ++;
                break;
            default : printf("Direção inválida!\n");
                break;
        }

    }
    printf("Você saiu da área delimitada em %d passos!", passos);
    return 0;
}

