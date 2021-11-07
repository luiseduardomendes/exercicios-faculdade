#include <stdio.h>

int main() {
    char str[] = {"(9*(5-3))-(4/(9*8))/(8-13)"};

    printf("%d", testaParenteses(str, 0, 0));
    
}

int testaParenteses(char str[], int i, int aberto){

    if (str[i] != '(' && str[i] != ')') 
        i++;
    aberto = 0;

    else if (str[i] == ')') 
        if (aberto) 
            return 1;
        else 
            return 0;
    
    
    else if (str[i] == '(') 
        return testaParenteses(str, i+1, 1);
    
}