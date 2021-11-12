#include <stdio.h>

int calcMDC (int, int);

int main(){
    int a, b;
    do{
        do{
            printf("Insira dois valores: ");
            scanf("%d %d", &a, &b);
        }while (a < 0 && b < 0);
        if (a != 0 && b != 0)
            printf("calcMDC: %d\n\n", calcMDC(a, b));
    } while (a != 0 && b != 0);
    printf("programa encerrado!\n");
    return 0;
}

int calcMDC (int x, int y){
    if (x > y){
        return calcMDC(x - y, y);
    }
    else {
        if (x < y){
            return calcMDC (y - x, x);
        }
        else{
            return x;
        }
    }
}