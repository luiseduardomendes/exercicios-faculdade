#include "two_dim_array.h"

int main(){
    Matrix A;

    Matrix_init(&A, 2, 3, 
                1.5, 3.0, 4.5, 
                1.0, 2.0, 3.0
                );
    
    Matrix_print(A);
    
    return 0;
}