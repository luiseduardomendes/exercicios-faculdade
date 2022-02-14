#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15

int main()
{
    srand(time(NULL));
    unsigned char v[N];
    unsigned char soma = 0, i = 0, size_number_vec = 0, size_index_vec = 0;
    unsigned char aux;
    unsigned char vi[N];
    unsigned char vn[N];

    v[7 + rand() % 8] = 0xFF;

    while(v[i] != 0xFF){
        v[i] = (rand() % 0x10) + ((rand() % 2) * 0x80);
        i ++;
    }

    i = 0;
    printf("Vetor original: \n");
    while(v[i] != 0xFF){
        printf("%d  ", v[i]);
        i ++;
    }
    printf("\n\n");

    //SEPARAÇÃO DE VETORES
    i = 0;
    while(v[i] != 0xff)
    {       
        aux = v[i];
        //NO RAMSES SERÁ NEGATIVO "JN"
        if(aux >= 0x80)
        {
            //TIRAR O BIT 7 DO NÚMERO DO INDICE
            //NO RAMSES PODE SER FEITO POR SUB 128 OU AND 127
            aux = aux - 0x80;
            vi[size_index_vec] = aux;
            size_index_vec ++;
        }
        else if(aux > 0 && aux <= 0x80)
        {
            vn[size_number_vec] = aux;
            size_number_vec ++;
        }
        i++;
    }

    printf("Vetor de indices: \n");
    for(int j = 0; j < size_index_vec; j ++)
        printf("%d  ", vi[j]);
    printf("\n\n");

    printf("Vetor de numeros: \n");
    for(int j = 0; j < size_number_vec; j ++)
        printf("%d  ", vn[j]);
    printf("\n\n");

    unsigned char min_value_size;

    if (size_number_vec < size_index_vec)
        min_value_size = size_number_vec;
    else
        min_value_size = size_index_vec;

    for(int cont = 0; cont < min_value_size; cont ++)
        if(vi[cont] < size_number_vec)
            soma += vn[vi[cont]];
    
    printf("soma final: %d\n\n", soma);

    return 0;
}