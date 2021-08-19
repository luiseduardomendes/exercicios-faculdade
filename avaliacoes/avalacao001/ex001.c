/*
1. Você deve desenvolver um programa para processar vendas em um mercado. O
mercado possui os seguintes itens, com os respectivos valores:

1 Pão.......................R$ 1,50
2 Leite (1 L)...............R$ 4,65
3 Biscoito (pct 300g).......R$ 6,93

O mercado oferece 2% de desconto para compras acima de R$ 50,00.
O programa deve exibir as informações da tabela acima para o usuário e pedir para
ele informar o código do produto que deseja e a quantidade. Ao final, o programa
deve informar o valor que o usuário deve pagar (já aplicando o desconto, se for o
caso). O programa só deve lidar com a compra de um único produto por execução.
*/
#include <stdio.h>
#include <stdlib.h>

void mostrar_menu();

int main (){
    int resposta, quantidade;
    float valor_pgto = 0;

    printf("Bem vindo ao Supermercado!\n");
    printf("Aproveite nossa promocao!\n");
    printf("2%% de desconto nas compras acima de R$50,00\n\n");

    do{

        mostrar_menu(); // Mostra as opcoes de produtos
        printf("\nSua opcao: ");

        do{ // Repete a leitura ate que o usuario insira um valor valido
            scanf("%d", &resposta);
            if ((resposta > 3) || (resposta < 0)){
                printf("Valor inserido invalido, insira outro: ");
            }
        } while ((resposta > 3) || (resposta < 0));

        if (resposta == 0)
            break; // Encerra o programa caso seja solicitado pelo usuario

            printf("Insira a quantidade desejada do produto: ");
            scanf("%d", &quantidade);

            switch(resposta){
                case 1: printf("%d paes foram adicionados ao seu carrinho!\n", quantidade);
                valor_pgto += (quantidade * 1.50);
                break;

                case 2: printf("%d leites foram adicionados ao seu carrinho!\n", quantidade);
                valor_pgto += (quantidade * 4.65);
                break;

                case 3: printf("%d biscoitos foram adicionados ao seu carrinho!\n", quantidade);
                valor_pgto += (quantidade * 16.93);
                break;
            }

            printf("\nContinuando pedido...\n");

    } while (resposta != 0); // Repete enquanto o usuario nao concluir o pedido

    printf("Pedido concluido!\n");
    printf("Total a pagar .........R$%.2f\n", valor_pgto);

    if (valor_pgto > 50){
        valor_pgto = valor_pgto * 0.98;
        printf("Valor com desconto.....R$%.2f\n", valor_pgto);
    }
    printf("\nVolte sempre!\n\n");
    system("pause");
    return 0;
}

void mostrar_menu(){
    printf("Digite o codigo para o produto desejado: \n");
    printf("[1] Pao ......................R$1,50\n");
    printf("[2] Leite ....................R$4,65\n");
    printf("[3] Biscoito (300g) ..........R$6,93\n");
    printf("[0] Encerrar pedido\n");
}
