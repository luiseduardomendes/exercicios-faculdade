#include <stdio.h>
#include <math.h>
#define NUM_PONTOS 3 //numero de pontos que sera lido

struct par_ordenado{
    float x, y;
};

float sqr(float num); // funcao usada para elevar ao quadrado
float area_triangulo(struct par_ordenado coord[]); // funcao que calcula a area do triangulo

int main() {
    float distancia_1_2, distancia_1_3, distancia_2_3; // distancia entre cada um dos pontos
    struct par_ordenado coord[NUM_PONTOS]; // estrutura para armazenar os valores em variaveis x e y em um vetor

    printf("Insira o valor de 3 coordenadas de um ponto no plano cartesiando\n");
    printf("obs: Inserir numeros decimais usando ponto para separa a parte inteira da decimal\n\n");
    for(int i = 0; i < NUM_PONTOS; i ++) { // realiza a leitura dos valores
        printf("\nPonto %d: \n", i + 1);
        printf("valor de x: ");
        scanf("%f", &coord[i].x);
        printf("Valor de y: ");
        scanf("%f", &coord[i].y);
    }

        // calcula a distancia entre os pontos digitados

    distancia_1_2 = sqrt( sqr( coord[0].x - coord[1].x) +
                        sqr( coord[0].y - coord[1].y ) );
    distancia_1_3 = sqrt( sqr( coord[0].x - coord[2].x) +
                        sqr( coord[0].y - coord[2].y ) );
    distancia_2_3 = sqrt( sqr( coord[1].x - coord[2].x) +
                        sqr( coord[1].y - coord[2].y ) );

        // confere a possibilidade de criar um triangulo

    if ((distancia_1_2 < distancia_1_3 + distancia_2_3) &&
        (distancia_1_3 < distancia_2_3 + distancia_1_2) &&
        (distancia_2_3 < distancia_1_2 + distancia_1_3)){
        printf("Eh possivel formar um triangulo com os valores inseridos!\n");
        printf("A area desse triangulo eh : %.2f", area_triangulo(coord));
    }
    else{
        printf("Nao eh possivel formar um triangulo com os valores inseridos\n");
    }

    return 0;
}

float sqr(float num){
    return (num * num);
}

float area_triangulo(struct par_ordenado coord[]){
    float determinante =
            ((coord[0].x * coord[1].y) +
            (coord[2].x * coord[0].y) +
            (coord[1].x * coord[2].y) -
            (coord[2].x * coord[1].y) -
            (coord[0].x * coord[2].y) -
            (coord[1].x * coord[0].y));
    return abs(determinante / 2);
}