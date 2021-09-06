#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, r, repeticoes = 0;

    do{
        printf("Digite um valor n [maior do que 1]: ");
        scanf("%d", &num);
        if (num < 1) {
            printf("Insira um número maior que 1\n");
        }
    } while (num < 1);

    do{
        printf("Digite o número de repetições: ");
        scanf("%d", &r);
        if (r < 1) {
            printf("Insira um número maior que 1\n");
        }
    } while (r < 1);

    while (num != 1 && repeticoes <= r) {
        if (num % 2 == 0) {
            num = num / 2;
        }
        else {
            num = (3 * num) + 1;
        }
        printf("%d\n", num);
        repeticoes ++;
    }
    if (num == 1){
        printf("O numero de repetições usadas para chegar até 1 foi %d\n", repeticoes);
    }
    else {
        printf("Não foi possível chegar em 1 com o número de repetições estipulado!\n");
    }
}
