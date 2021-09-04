/* Programa desenvolvido para Linux */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define VALOR10 2.25 // pão
#define VALOR23 7.65 // leite
#define VALOR08 6.93 // biscoito
#define VALOR90 30.21 // arroz
#define VALOR76 12.33 // feijão

float valor_produto (int codigo, int quantidade);
int menu_principal();
int menu_opcoes();


int main()
{
    setlocale(LC_CTYPE, "");
    int opcao, continuar_programa, quantidade;
    float valor_total, valor_pedido;

    valor_pedido = 0;
    valor_total = 0;

    printf("Programa iniciado!\n");

    do { // reinicia o programa a cada compra
        printf("Pedido iniciado: \n");
        do { // continua a compra enquanto o pedido nao é finalizado
            do {
                opcao = menu_opcoes();
                if (opcao < 0) {
                    printf("Código inválido\nInsira outro! [aperte enter para continuar]\n");
                    __fpurge(stdin);
                    getchar();
                }
            } while (opcao < 0); // função retorna -1 se código é inválido

            if (opcao != 0){
                printf("Insira a quantidade do produto %d desejada: ", opcao);
                scanf("%d", &quantidade);
                valor_pedido += valor_produto(opcao, quantidade);
            }
        } while (opcao != 0);

        printf("Pedido encerrado!\n");
        printf("Valor do pedido R$ %.2f\n", valor_pedido);

        if (valor_pedido > 100){
            printf("Desconto de 2%% aplicado!\n");
            valor_pedido = valor_pedido * 0.98;
            printf("Valor com desconto R$ %.2f\n", valor_pedido);
        }


        valor_total += valor_pedido;
        continuar_programa = menu_principal();
    } while (continuar_programa != 0);

    printf("Programa encerrado!\n");
    printf("Valor total obtido: R$ %.2f\n", valor_total);
}

int menu_opcoes() {
    int codigo_retorno_opcoes;
    printf("Escolha seu produto\n\n");
    printf ("Código .. Produto .............. Valor unitário\n"
            " [10] ... Pão .................. R$ 2,25\n"
            " [23] ... Leite (1 L) .......... R$ 7,65\n"
            " [08] ... Biscoito (pct 300g) .. R$ 6,93\n"
            " [90] ... Arroz (pct 1kg) ...... R$ 30,21\n"
            " [76] ... Feijão (pct 1kg) ..... R$ 12,33\n"
            " [00] ... Finaliza compra\n\n");
    printf("Sua opção: ");
    scanf("%d", &codigo_retorno_opcoes);
    if (codigo_retorno_opcoes != 10 &&
        codigo_retorno_opcoes != 23 &&
        codigo_retorno_opcoes !=  8 &&
        codigo_retorno_opcoes != 90 &&
        codigo_retorno_opcoes != 76 &&
        codigo_retorno_opcoes !=  0){
            codigo_retorno_opcoes = -1;
        }
    return codigo_retorno_opcoes;
}

int menu_principal(){
    int codigo_retorno_principal;
    do {
        printf("[0] Encerrar o programa\n"
               "[1] Realizar nova compra\n");
        scanf("%d", &codigo_retorno_principal);
        if (codigo_retorno_principal < 0 &&
            codigo_retorno_principal > 1){
            printf("Valor inserido inválido!\nInsira outro [aperte enter para continuar]\n");
            __fpurge(stdin);
            getchar();
        }
    } while (codigo_retorno_principal < 0 &&
             codigo_retorno_principal > 1);
    return codigo_retorno_principal;
}

float valor_produto (int codigo, int quantidade){
    float valor = 0;

    switch (codigo) {
        case 10 : valor = 2.25 * quantidade;
            break;
        case 23 : valor = 7.65 * quantidade;
            break;
        case 8  : valor = 6.93 * quantidade;
            break;
        case 90 : valor = 30.21 * quantidade;
            break;
        case 76 : valor = 12.33 * quantidade;
            break;
    }

    return valor;
}
