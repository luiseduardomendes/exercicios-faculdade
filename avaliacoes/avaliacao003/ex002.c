/* O programa a seguir serve para auxiliar num processo de pesquisa. Ele recebe como entrada
 * a quantidade de pessoas a serem entrevistadas e para cada pessoa, le a idade, renda mensal
 * e localidade (U - urbana ou  R - rural). O programa informa como saida a menor renda mensal
 * informada, percentual entre entrevistados da area urbana e da area rural e a media da renda
 * mensal para moradores da cidade e para moradores da area rural. */

#include <stdio.h>
#include <ctype.h>

int main() {

    // entrada
    int idade, num_pessoas;
    float renda;
    char localidade;

    // auxiliares e de saida
    int num_urbano = 0, num_rural = 0;
    float menor_renda, maior_renda, soma_renda_urbana = 0, soma_renda_rural = 0;
    float media_renda_urbana, media_renda_rural;
    float porcentagem_urbana, porcentagem_rural;

    // contador for
    int i;

    printf("Informe a quantidade de pessoas que serao entrevistadas: \n");
    scanf("%d", &num_pessoas);

    for(i = 0; i < num_pessoas; i ++) {
        printf("Digite os dados do individuo %d:\n", i + 1);

        printf("    Renda mensal ... : ");
        scanf("%f", &renda);

        do{
            printf("    Localidade\n"
                   "        [U] Urbana\n"
                   "        [R] Rural\n"
                   "    Sua opcao ...... : ");
            fflush(stdin);
            scanf("%c", &localidade);
            localidade = toupper(localidade);

            if (localidade != 'U' && localidade != 'R') {
                printf("Caracter invalido, tente novamente\n");
            }

        } while (localidade != 'U' && localidade != 'R') ;

        if (i == 0){
            menor_renda = renda;
            maior_renda = renda;
        }
        else{
            if (renda < menor_renda) {
                menor_renda = renda;
            }
            else if(renda > maior_renda) {
                maior_renda = renda;
            }
        }

        if (localidade == 'U') {
            num_urbano ++;
            soma_renda_urbana += renda;
        }
        else if (localidade == 'R') {
            num_rural ++;
            soma_renda_rural += renda;
        }
    }
    porcentagem_urbana = ((float)num_urbano / num_pessoas) * 100;
    porcentagem_rural = ((float)num_rural / num_pessoas) * 100;
    media_renda_rural = soma_renda_rural / num_rural;
    media_renda_urbana = soma_renda_urbana / num_urbano;

    puts("");
    printf("Maior renda mensal .............................. : R$%.2f\n", maior_renda);
    printf("Menor renda mensal .............................. : R$%.2f\n", menor_renda);
    printf("Percentual de entrevistados de areas urbanas .... : %.2f%%\n", porcentagem_urbana);
    printf("Percentual de entrevistados de areas rurais ..... : %.2f%%\n", porcentagem_rural);
    printf("Media da renda nas areas urbanas ................ : R$%.2f\n", media_renda_urbana);
    printf("Media da renda nas areas rurais ................. : R$%.2f\n", media_renda_rural);
    return 0;
}


