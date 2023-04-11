#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mult_matrix.h"

void print_m16(uint16_t A[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%8d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_m8(uint8_t A[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%8d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    uint8_t A[N][N] = {{1, 4}, {6, 3}};
    uint8_t B[N][N] = {{2, 3}, {7, 2}};
    uint8_t C[N][N] = {{1, 5}, {3, 5}};
    uint8_t D[N][N] = {{6, 3}, {7, 4}};
    uint16_t S[N][N];

    program(A, B, C, D, S, 60);
    print_m16(S);
}
