#include <stdio.h>

int main() {
    float saldo, valor_operado;
    int codigo, codigo_conta;

    printf("Insira o saldo inicial da conta\nR$");
    scanf("%f", &saldo);

    do{
        printf("[1] Deposito\n[2] Saque\n[3] Transferencia\n[0] Encerrar\n");
        printf("\nSua opcao:");
        scanf("%d", &codigo);

        switch (codigo) {
            case 1:
                printf("Insira o valor que deseja depositar\n");
                scanf("%f", &valor_operado);
                saldo += valor_operado;
                break;

            case 2:
                printf("Insira o valor que deseja sacar\n");
                scanf("%f", &valor_operado);

                if (saldo >= valor_operado) {
                saldo -= valor_operado;
                }
                else{
                    printf("Saldo insuficiente!\n");
                }
                break;

            case 3 :
                printf("Insira o valor que deseja transferir\nR$");
                scanf("%f", &valor_operado);

                printf("Insira o codigo da conta de destino da transferencia\nR$");
                scanf("%d", &codigo_conta);

                if (saldo >= valor_operado) {
                    saldo -= valor_operado;
                }
                else{
                    printf("Saldo insuficiente!\n");
                }
                break;
        }
        printf("\nSaldo atual: R$%.2f\n\n", saldo);
    }while (codigo != 0);
    getchar();

    return 0;
}