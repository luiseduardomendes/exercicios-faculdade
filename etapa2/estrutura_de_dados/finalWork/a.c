#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    printf("%d\n", strcmp("opab","opa"));
    
    return 0;
}

/*
    STRCMP:
        - returns -1 if 
            * a is smaller than b
            * a comes previously in lexicographic order
        - returns 1 if
            * a is greater than b
            * a comes after in lexicographic order
        - return 0 if
            * a is equal to b

*/