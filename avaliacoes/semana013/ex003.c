#include <stdio.h>
#include <math.h>

int main(){
    char value[15];
    scanf("%c", value);
    printf("%d", atoi2(value));
    return 0;
}

int atoi2(char number[]){
    int sizeStr = 15;
    int i;
    int numberEquiv = 0, buffer;
    i = 0;
    while (number[i] < 0x30 || number[i] > 0x39){
        buffer = number[i] - 0x30;
        numberEquiv += buffer * pow(10, i);
        i++;
    }
    return numberEquiv;
}