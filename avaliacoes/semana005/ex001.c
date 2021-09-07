// Programa desenvolvido para Linux

/* Você deve desenvolver um programa para processar vendas em um mercado. O mercado
 * possui os seguintes itens, com os respectivos valores
 *
 * Código   Produto                 Valor unitário
 * 10       Pão                     R$ 2,25
 * 23       Leite (1 L)             R$ 7,65
 * 8        Biscoito (pct 300g)     R$ 6,93
 * 90       Arroz (pct 1kg)         R$ 30,21
 * 76       Feijão (pct 1kg)        R$ 12,33
 * 0        Finaliza compra
 *
 * O mercado oferece 2% de desconto para compras acima de R$ 100,00.
 * O programa deve continuamente processar compras de múltiplos clientes. Para isso, o
 * programa deve exibir um menu de opções (0-Sair 1-Nova compra). Faça consistência
 * para garantir que o programa só prosseguirá caso o usuário informe uma dessas opções.
 * Caso o usuário selecione a opção 0, o programa deve parar de processar novas compras.
 * Caso o programa selecione 1, o programa deve processar uma nova compra. Neste caso, o
 * programa deve exibir a tabela acima para este cliente específico e continuamente pedir
 * para o usuário informar o código do produto (deve ser existente) e a respectiva
 * quantidade desejada (deve ser maior que zero). Caso o código ou a quantidade sejam
 * inválidas, o programa deve informar isso ao usuário e repetir a operação de requisitar
 * essas informações. O cliente indica que finalizou sua compra ao informar o código zero
 * para o produto. Ao fim da compra de cada cliente o programa deve informar o total da
 * compra e, caso ele tenha desconto, informar o total com desconto também (isso não deve
 * ser informado se ele não cumprir o requisito para o desconto). No fim do dia (quando o
 * usuário selecionar a opção Sair no primeiro menu), o programa deve informar as
 * seguintes estatísticas:
 *
 * -Quantidade de compras realizadas.
 * -Total faturado no dia (considere os valores pagos incluindo os descontos)
 * -Média do valor das compras.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define NUM_PRODUTOS 6
// Constantes para facilitar a eventual mudança nos preços do estabelecimento
#define VALOR10 2.25  // Pão
#define VALOR23 7.65  // Leite
#define VALOR08 6.93  // Biscoito
#define VALOR90 30.21 // Arroz
#define VALOR76 12.33 // Feijão

// Função usada para calcular o valor de um produto a partir da quantidade do item
float valor_produto (int codigo, int quantidade);
// Mostra o menu principal e retorna a resposta do usuário
int menu_principal();
// Mostra o menu de opções e retorna a resposta do usuário
int menu_opcoes();

int main()
{
    setlocale(LC_CTYPE, "");
    int opcao, continuar_programa, quantidade;
    float valor_total, valor_pedido;

    printf("Programa iniciado!\n");
    valor_total = 0;
    do { // reinicia o programa a cada compra
        printf("Pedido iniciado: \n");
        valor_pedido = 0;
        do { // continua a compra enquanto o pedido nao é finalizado
            do {
                // função menu_opcoes retorna -1 se código é inválido
                opcao = menu_opcoes();
                if (opcao < 0) {
                    printf("Código inválido\nInsira outro! [aperte enter para continuar]\n");
                    __fpurge(stdin); // trocar para fflush(stdin) em Windows
                    getchar();
                }
            } while (opcao < 0);

            if (opcao != 0){
                printf("Insira a quantidade do produto %d desejada: ", opcao);
                scanf("%d", &quantidade);
                valor_pedido += valor_produto(opcao, quantidade);
                system("clear");
                printf("%d unidade(s) do produto %d foram adicionadas ao carrinho\n\n");
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
        system("clear");
    } while (continuar_programa != 0);

    printf("Programa encerrado!\n");
    printf("Valor total obtido: R$ %.2f\n", valor_total);
}

int menu_opcoes() {
    int codigo_retorno_opcoes, i;
    int codigos_validos[NUM_PRODUTOS] = {10, 23, 8, 90, 76, 0};
    bool codigo_validado = false;

    printf("Escolha seu produto\n\n"
           "__________________________________________________\n\n");
    printf ("Código .. Produto .............. Valor unitário\n"
            " [10] ... Pão .................. R$ 2,25\n"
            " [23] ... Leite (1 L) .......... R$ 7,65\n"
            " [08] ... Biscoito (pct 300g) .. R$ 6,93\n"
            " [90] ... Arroz (pct 1kg) ...... R$ 30,21\n"
            " [76] ... Feijão (pct 1kg) ..... R$ 12,33\n"
            " [00] ... Finaliza compra\n\n"
            "__________________________________________________\n");

    printf("Sua opção: ");
    scanf("%d", &codigo_retorno_opcoes);

    for(i = 0; i < NUM_PRODUTOS; i ++) {
        if (codigo_retorno_opcoes == codigos_validos[i]){
            codigo_validado = true;
        }
    }
    if (!(codigo_validado)) {
        codigo_retorno_opcoes = -1;
    }
    return codigo_retorno_opcoes;
}

int menu_principal(){
    int codigo_retorno_principal;
    do {
        printf("________________________\n\n"
               "[0] Encerrar o programa\n"
               "[1] Realizar nova compra\n"
               "________________________\n");
        scanf("%d", &codigo_retorno_principal);
        if (codigo_retorno_principal < 0 &&
            codigo_retorno_principal > 1){
            printf("Valor inserido inválido!\nInsira outro [aperte enter para continuar]\n");
            __fpurge(stdin); // trocar para fflush(stdin) em Windows
            getchar();
        }
    } while (codigo_retorno_principal < 0 &&
             codigo_retorno_principal > 1);
    return codigo_retorno_principal;
}

float valor_produto (int codigo, int quantidade){
    float valor = 0;

    switch (codigo) {
        case 10 : valor = VALOR10 * quantidade;
            break;
        case 23 : valor = VALOR23 * quantidade;
            break;
        case 8  : valor = VALOR08 * quantidade;
            break;
        case 90 : valor = VALOR90 * quantidade;
            break;
        case 76 : valor = VALOR76 * quantidade;
            break;
    }

    return valor;
}
