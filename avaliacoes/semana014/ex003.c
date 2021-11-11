#include <stdio.h>

int main() {
    char str[] = {"(9*(5-3)-(4/(9*8))/(8-13"};
    int num = 0;
    printf("%d\n", testaParenteses(str, 0, 0));
    
}

int testaParenteses(char str[], int i, int aberto){

    if ((str[i] == '\0' || str[i] == '\n') && aberto == 0)
        return 1;
    else if (str[i] != '(' && str[i] != ')') 
        testaParenteses(str, i+1, aberto);

    else if (str[i] == ')') {
        if (aberto > 0) {
            return 1 * testaParenteses(str, i+1, aberto-1);
        }
        else 
            return 0;
    }
    
    else if (str[i] == '(') {   
        return 1 * testaParenteses(str, i+1, aberto + 1);
    }
}