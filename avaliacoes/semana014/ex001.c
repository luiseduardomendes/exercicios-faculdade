#include <stdio.h>
#include <math.h>
#include <locale.h>

int somaDigitos(int num);
int somaDigitosRec(int num, int index, int size);
int numDigits(int num);

int main() {
    setlocale(LC_ALL, "");
    int num, sum;
    printf("Insira um número não negativo: ");
    scanf("%d", &num);
    sum = somaDigitos(num);
    if (sum >= 0)
        printf("A soma dos algarismos é: %d\n", sum);
    else
        printf("Núumero negativo\n");
    return 0;
}

int somaDigitos(int num){
    if (num < 0)
        return -1;
    else if (num == 0)
        return 0;
    else
        return somaDigitosRec(num, 0, numDigits(num));
}

int somaDigitosRec(int num, int index, int size){
    int digit, aux;
    if (index == size){
        return 0;
    }
    else {
        aux = num / pow(10, size - index);
        digit = (num / (pow(10, size - index - 1))) - aux * 10;
        return digit + somaDigitosRec(num, index+1, size);
    }
}

int numDigits(int num){
    return (int)log10(num)+1;
}
