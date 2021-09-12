// COLOCAR CONSISTENCIA DE VALORES, TO LOUCO DE SONO, AMANHA EU VEJO ISSO


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD 3

int menu();

int main () {
    int opcao, i, conta, conta_dest;
    float saldo[QTD], valor;
    setlocale(LC_CTYPE, "");

    for(i = 0; i < QTD; i ++) {
        printf("Insira o saldo da conta %d: R$", i);
        scanf("%f", &saldo[i]);
    }

    do {
        opcao = menu();
        switch (opcao) {
        case 0: 
            printf("Sistema encerrado!\n");
            break;
        case 1: 
            do{
                printf("Insira o código da conta: ");
                scanf("%d", &conta);
                if (conta > QTD || conta < 0) {
                    printf("Código inválido!\n");
                }
            } while (conta > QTD || conta < 0);
            printf("O saldo da conta é: R$ %.2f\n", saldo[conta]);
            break;
        case 2: 
            do{
                printf("Insira o código da conta: ");
                scanf("%d", &conta);
                if (conta > QTD || conta < 0) {
                    printf("Código inválido!\n");
                }
            } while (conta > QTD || conta < 0);
            printf("Insira o valor a ser depositado: R$");
            scanf("%f", &valor);

            saldo[conta - 1] += valor; 

            printf("Operação efetuada com sucesso!\n");
            printf("O novo saldo da conta é: R$");
            printf("%.2f", saldo[conta]);
            break;

        case 3: 
            do{
                printf("Insira o código da conta: ");
                scanf("%d", &conta);
                if (conta > QTD || conta < 0) {
                    printf("Código inválido!\n");
                }
            } while (conta > QTD || conta < 0);
            printf("Insira o valor a ser sacado: R$");
            scanf("%f", &valor);
            
            if (saldo[conta] > valor) {
                saldo[conta] -= valor;
                printf("Operação efetuada com sucesso!\n");
                printf("O novo saldo da conta é: R$");
                printf("%.2f", saldo[conta]);
            }
            else {
                printf("Saldo insuficiente!\n");
            }            
            break;
        case 4: 
            do{
                printf("Insira o código da conta de origem: ");
                scanf("%d", &conta);
                if (conta > QTD || conta < 0) {
                    printf("Código inválido!\n");
                }
            } while (conta > QTD || conta < 0);
            do{
                printf("Insira o código da conta de destino: ");
                scanf("%d", &conta_dest);
                if (conta_dest > QTD || conta_dest < 0) {
                    printf("Código inválido!\n");
                }
            } while (conta_dest > QTD || conta_dest < 0);
            printf("Insira o valor a ser transferido: R$");
            scanf("%f", &valor);
            
            if (saldo[conta] > valor) {
                saldo[conta_dest] -= valor;
                printf("Operação efetuada com sucesso!\n");
                printf("O novo saldo da conta de origem é: R$");
                printf("%.2f", saldo[conta]);
                printf("O novo saldo da conta de destino é: R$");
                printf("%.2f", saldo[conta_dest]);
            }
            else {
                printf("Saldo insuficiente!\n");
            }            
            break;
        }
    } while (opcao != 0);

    return 0;
}

int menu() {
    int option;
    do {
        printf("Escolha uma opção: \n");
        printf ("    ___________________\n\n");
        printf ("    [1] Saldo\n"
                "    [2] Depósito\n"
                "    [3] Saque\n"
                "    [4] Transferência\n"
                "    [0] Encerrar\n");
        printf ("    ___________________\n");
        printf("\nSua opção: ");
        scanf("%d", &option);
        if (option < 0 && option > 4) {
            printf("Valor inválido, insira outro [ENTER para continuar]\n");
            __fpurge(stdin);
            getchar();
        }
    } while (option < 0 && option > 4);
    return (option);
}