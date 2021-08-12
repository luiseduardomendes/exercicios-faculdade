/* O programa a seguir analisa, a partir de medidas de referência inseridas pelo
usuário, se há ou não necessidade de monitoramento de certos indivíduos, cujos
pesos e alturas são inseridos pelo usuário durante a execução do programa.*/

#include <stdio.h>
#define NUM_PESSOAS 3

int main() {
    float peso_referencia, altura_referencia;
    float peso[NUM_PESSOAS], altura[NUM_PESSOAS];
    float soma_pesos = 0, media_pesos;
    float soma_alturas = 0, media_alturas;
    int monitorados = 0, pessoas_monitoradas[NUM_PESSOAS];
    int i;
    printf("Informe o peso de referencia: ");
    scanf("%f", &peso_referencia);
    printf("Informe a altura de referencia: ");
    scanf("%f", &altura_referencia);

    for(i = 0; i < NUM_PESSOAS; i ++) {
        printf("\nInforme o peso(kg) e a altura(m) da pessoa, respectivamente: ");
        scanf("%f %f", &peso[i], &altura[i]);
        soma_pesos += peso[i];
        soma_alturas += altura[i];
        if ((peso[i] > peso_referencia) && (altura[i] < altura_referencia)){
            pessoas_monitoradas[monitorados] = i + 1;
            monitorados += 1;
        }
    }

    media_pesos = (soma_pesos / NUM_PESSOAS);
    media_alturas = (soma_alturas / NUM_PESSOAS);

    printf("Pesos e alturas analisadas: \n\n");
    for(i = 0; i < NUM_PESSOAS; i ++) {
        printf("Individuo.....%d: \n\n", i + 1);
        printf("Peso:   %8.1f kg\n", peso[i]);
        printf("Altura:   %6.2f m\n\n", altura[i]);
    }

    printf("Media dos pesos analisados:        %.2f kg\n", media_pesos);
    printf("Media das alturas analisadas:      %.2f m\n", media_alturas);
    printf("Pessoas que deve ser monitoradas:  %d pessoa(s)\n", monitorados);
    printf("Identificacao dos monitorados:\n");
    for (i = 0; i < monitorados; i ++) {
        printf("-individuo %d\n", pessoas_monitoradas[i]);
    }

    return 0;
}
