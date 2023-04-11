#include <stdint.h>
#include <stdlib.h>

#define N 2


void matrix_mult_8_to_16(uint8_t A[N][N], uint8_t B[N][N], uint16_t S[N][N]){
    int i, j, k;

    for (i = 0; i < N; i ++){
        for (j = 0; j < N; j ++){
            S[i][j] = 0;
            for (k = 0; k < N; k++){
                S[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_sum_16(uint16_t A[N][N], uint16_t B[N][N], uint16_t S[N][N]){
    int i, j;

    for (i = 0; i < N; i ++){
        for (j = 0; j < N; j ++){
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void process_function(uint8_t A[N][N], uint8_t B[N][N], uint8_t C[N][N], uint8_t D[N][N], uint16_t S[N][N]){
    uint16_t S1[N][N], S2[N][N];

    matrix_mult_8_to_16(A, B, S1);
    matrix_mult_8_to_16(C, D, S2);
    matrix_sum_16(S1, S2, S);
}

void filter(uint16_t S[N][N], uint16_t boundary){
    int i, j;

    for (i = 0; i < N; i ++){
        for (j = 0; j < N; j ++){
            S[i][j] = S[i][j] * (S[i][j] > boundary);
        }
    }
}

void program(uint8_t A[N][N], uint8_t B[N][N], uint8_t C[N][N], uint8_t D[N][N], uint16_t S[N][N], uint16_t filter_value){
    process_function(A, B, C, D, S);
    filter(S, 60);
}