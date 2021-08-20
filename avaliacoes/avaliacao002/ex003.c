#include <stdio.h>

int main() {
    int horas_entrada, min_entrada, min_saida, horas_saida;
    float valor;

    printf("TABELA DE PRECOS\n");
    printf("1 hora ................................. R$25.00\n");
    printf("2 horas ................................ R$45.00\n");
    printf("hora adicional (a partir de 2 horas) ... R$15.00\n\n");

    printf("Informe a hora e o minuto de entrada: ");
    scanf("%d %d", &horas_entrada, &min_entrada);
    printf("Informe a hora e o minuto de saida: ");
    scanf("%d %d", &horas_saida, &min_saida);

    if ((horas_saida == horas_entrada) && (min_entrada > min_saida)) { // 24 horas
        valor = (float)45 + (22 * 15);
    }

    else if (horas_saida >= horas_entrada) { // mesmo dia
        
        if ((horas_saida == horas_entrada) && (min_saida > min_entrada)) { // mesma hora do mesmo dia
            valor = 25;
        }

        else if ((horas_saida == horas_entrada + 1) && (min_saida <= min_entrada)) { // menos de 1 hora
            valor = 25;
        }

        else if ((horas_saida == horas_entrada + 1) && (min_saida > min_entrada)){ // mais de 1 hora
            valor = 45;
        }

        else if ((horas_saida == horas_entrada + 2) && (min_saida <= min_entrada)) { // menos de 2 horas
            valor = 45;
        }

        else if (min_saida > min_entrada) {
            valor = (float)45 + ((horas_saida - horas_entrada) - 1) * 15;
        }

        else {
            valor = (float)45 + ((horas_saida - horas_entrada) - 2) * 15;
        }
    }

    else { // outro dia
        if (min_saida > min_entrada) {
            valor = (float)45 + (23 - (horas_entrada - horas_saida)) * 15;
        }

        else {
            valor = (float)45 + (22 - (horas_entrada - horas_saida)) * 15;
        }
    }

    printf("\nValor a ser pago %8.2f\n", valor);

    getchar();

    return 0;
}

void tabela_precos() {
    printf("1 hora ................................. R$25.00\n");
    printf("2 horas ................................ R$45.00\n");
    printf("hora adicional (a partir de 2 horas) ... R$45.00 + R$15.00 por hora\n");
};