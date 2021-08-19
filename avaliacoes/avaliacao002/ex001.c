#include <stdio.h>
#define NUM_CIDADES 3

int main(){
    struct dados {
        int identificador, populacao;
    } cidades[NUM_CIDADES];

    int i;
    int referencia;
    int soma_populacoes = 0;
    float media_populacoes;

    printf("Insira um valor de referencia para analisar as populacoes de cada cidade:");
    scanf("%d", &referencia);

    for(i = 0; i < NUM_CIDADES; i ++) {
        printf("\nInsira o identificador e a populacao da cidade %d, respectivamente\n", i + 1);
        scanf("%d %d", &cidades[i].identificador, &cidades[i].populacao);
    }

    for (i = 0; i < NUM_CIDADES; i ++) {
        soma_populacoes += cidades[i].populacao;
        if(cidades[i].populacao > referencia) {

            printf("\nA cidade de codigo %d possui populacao acima do valor de referencia\n",
                   cidades[i].identificador);
        }
        else if(cidades[i].populacao < referencia){
            printf("\nA cidade de codigo %d possui populacao abaixo do valor de referencia\n",
                   cidades[i].identificador);
        }
        else {
            printf("\nA cidade de codigo %d possui populacao igual ao valor de referencia\n",
                   cidades[i].identificador);
        }
    }

    media_populacoes = (float)(soma_populacoes / NUM_CIDADES);

    for (i = 0; i < NUM_CIDADES; i ++) {
        soma_populacoes += cidades[i].populacao;
        if(cidades[i].populacao > media_populacoes) {
            printf("\nA cidade de codigo %d possui populacao acima da media das populacoes\n",
                   cidades[i].identificador);
        }
        else if(cidades[i].populacao < media_populacoes){
            printf("\nA cidade de codigo %d possui populacao abaixo da media das populacoes\n",
                   cidades[i].identificador);
        }
        else {
            printf("\nA cidade de codigo %d possui populacao igual a media das populacoes\n",
                   cidades[i].identificador);
        }
    }
    fflush(stdin);
    getchar();
    return 0;
}