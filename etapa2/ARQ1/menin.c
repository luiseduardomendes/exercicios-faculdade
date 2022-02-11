#include <stdio.h>
#define N 15

int main()
{
    int v[N] = {1,130,2,129,3,4,143,255,0,0,0,0,0,0,0};
    int soma = 0, i = 0, j = 0, k = 0;
    int aux;
    int vi[N];
    int vn[N];

    //SEPARAÇÃO DE VETORES
    while(v[i] != 0)
    {       
        aux = v[i];
        //NO RAMSES SERÁ NEGATIVO "JN"
        if(aux > 127)
        {
            //TIRAR O BIT 7 DO NÚMERO DO INDICE
            //NO RAMSES PODE SER FEITO POR SUB 128 OU AND 127
            aux = aux - 128;
            vi[k] = aux;
            
            printf("vetor indice %d\nindice %d\n",vi[k],k);
            k++;
        }
        //NO RAMSES É SÓ DEIXAR SEGUIR
        else if(aux > 0 && aux <=127)
        {
            vn[j] = aux;
            
            printf("vetor numero %d\nindice %d\n",vn[j],j);
            j++;
        }
        i++;
    }
    printf("Vetor principal: \n\n");
    for (int cont = 0; cont < N; cont ++)
        printf("%d\t", v[cont]);
    printf("\n\n");
    printf("Vetor de indices: \n\n");
    for (int cont = 0; cont < k; cont ++)
        printf("%d\t", vi[cont]);
    printf("\n\n");
    printf("Vetor de numeros: \n\n");
    for (int cont = 0; cont < j; cont ++)
        printf("%d\t", vn[cont]);
    printf("\n\n");

    for(int cont = 0; cont < k && cont < j; cont ++)
        if(vi[cont] < j)
            soma += vn[vi[cont]];
    
    printf("\nA soma dos numeros eh: %d\n\n",soma);
    
    return 0;
}