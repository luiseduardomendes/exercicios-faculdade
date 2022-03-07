#include <stdlib.h>
#include <stdio.h>

typedef struct s_TipoPtNo{
       int info;
       struct s_TipoPtNo* prox;
       }TipoPtNo;

int fun (TipoPtNo *L)
{
    if (L != NULL)
        while (L->prox)
        {
            if (L->info > L->prox->info)
                return 0;
            L = L->prox;
        }
    return 1;
}

int main(){
    TipoPtNo *a[5], *ant = NULL;
    for (int i = 0; i < 5; i ++){
        a[i] = malloc(sizeof(TipoPtNo));
        a[i]->prox = NULL;
        if (ant != NULL)
            ant->prox = a[i];
    }
    
    a[0]->info = 1;
    a[1]->info = 5;
    a[2]->info = 6;
    a[3]->info = 8;
    a[4]->info = 3;

    printf("%d\n", fun(a[0]));
    return 0;

}