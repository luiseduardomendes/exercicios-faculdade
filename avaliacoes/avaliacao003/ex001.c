/* Programa supermercado
 * O programa a seguir serve para processar as vendas num mercado que possui os seguintes itens
 *
 * Código__Produto_______________ Valor unitário
 *
 *   10 .. Pão .................. R$ 2,25
 *   23 .. Leite (1 L) .......... R$ 7,65
 *    8 .. Biscoito (pct 300g) .. R$ 6,93
 *   90 .. Arroz (pct 1kg) ...... R$ 30,21
 *   76 .. Feijão (pct 1kg) ..... R$ 12,33
 *
 *   Em caso de compras acima de R$100, o valor recebe um desconto de 2%
 *
 *   O programa opera a partir da entrada dos seguintes dados
 *   [1] quantidade de itens diferentes
 *   [2] código dos itens comprados
 *   [3] unidades do item referente ao código
 *
 *   O programa retorna como saída, o valor a pagar e, caso se aplique, o valor com desconto
 * */

#include <stdio.h>

void mostrar_menu();
float valor_item (int codigo, int quantidade);

int main() {
    int codigo, num_tipos_itens, quantidade;
    int i;
    float valor_a_pagar = 0;
    printf("Bem vindo ao supermercado!\n");
    mostrar_menu();

    printf("Quantos tipos distintos de itens deseja comprar?\n");
    do{
        scanf("%d", &num_tipos_itens);
        if ((num_tipos_itens <= 0) || (num_tipos_itens > 5)) {
            printf("Insira uma quantidade valida\n");
        }
    } while ((num_tipos_itens <= 0) || (num_tipos_itens > 5));

    for (i = 0; i < num_tipos_itens; i++) {
        printf("Codigo do item %d:\n", i + 1);
        scanf("%d", &codigo);
        printf("Quantidade do item %d:\n", i + 1);
        scanf("%d", &quantidade);

        valor_a_pagar += valor_item(codigo, quantidade);
    }

    printf("Total a pagar:        R$%.2f\n", valor_a_pagar);

    if (valor_a_pagar > 100) {
        printf("Promocao aplicada! Voce recebeu 2%% de desconto!\n");
        valor_a_pagar *= 0.98;
        printf("Total com desconto:   R$%.2f\n", valor_a_pagar);
    }
    return 0;
}

void mostrar_menu() {
    printf("Codigo   Produto                 Valor unitario\n"
           " [10]    Pao ................... R$ 2,25\n"
           " [23]    Leite (1 L) ........... R$ 7,65\n"
           " [08]    Biscoito (pct 300g) ... R$ 6,93\n"
           " [90]    Arroz (pct 1kg) ....... R$ 30,21\n"
           " [76]    Feijao (pct 1kg) ...... R$ 12,33\n\n");
}

float valor_item (int codigo, int quantidade) {
    float valor = 0;
    switch (codigo) {
        case 10: valor =  2.25 * quantidade;
        break;
        case 23: valor =  7.65 * quantidade;
        break;
        case  8: valor =  6.93 * quantidade;
        break;
        case 90: valor = 30.21 * quantidade;
        break;
        case 76: valor = 12.33 * quantidade;
        break;
        default: printf("Codigo inserido invalido\n");
        break;
    }
    return valor;
}