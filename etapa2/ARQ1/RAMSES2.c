#include <stdio.h>
#define N 15

int main()
{
    unsigned char v[N] = {0x01, 0x82, 0x02, 0x81, 0x03, 0x04, 0x8f, 0xff};
    unsigned char soma = 0, i = 0, size_number_vec = 0, size_index_vec = 0;
    unsigned char aux;
    unsigned char vi[N];
    unsigned char vn[N];

    //SEPARAÇÃO DE VETORES
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

    unsigned char min_value_size;

    if (size_number_vec < size_index_vec)
        min_value_size = size_number_vec;
    else
        min_value_size = size_index_vec;

    for(int cont = 0; cont < min_value_size; cont ++)
        if(aux < size_index_vec)
            soma += vn[vi[cont]];
    
    return 0;
}