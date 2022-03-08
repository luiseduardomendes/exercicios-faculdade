#include "stack.h"

void print_bin(int num){ 
    tStackNode* top;
    int i = num;

    top = stack_init();
    
    while(num != 0){
        i = num % 2;
        num = num/2;
        stack_push(&top, i);
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
        print_bin(n);
    } while(1);
    
    return 0;
}