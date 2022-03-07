#include "stack.h"

void print_bin(int num){ 
    tStackNode* top;
    int i;

    top = stack_init();
    
    while(num != 0){
        num = num % 2;
        stack_push(&top, num);
    }

    while(!stack_isEmpty(top)){
        stack_pop(&top, &i);
        printf("%d\t", i);
    }
}

int main(){
    int n;

    do {
    scanf("%d", &n);
    pritn(n);
    } while(1);
    
    return 0;
}