#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void histogram(float v[]);

int main(){
    float v[] = {1.7, 2.1, 2.3, 1.8, 1.9, 2.4, 2.7, 2.2};
    int i, j;
    float sum = 0, mean;
    float stdDev = 0;

    for (i = 0; i < 8; i ++){
        v[i] *= 1.6;
        sum += (v[i])/8;
    }

    mean = sum;
    sum *= 8;

    for (i = 0; i < 8; i ++){
        stdDev += ((v[i] - mean) * (v[i] - mean)) / 8;
    }

    

    histogram(v);


    printf("sum: %f\nmean: %f\nstandard deviation: %f\n", sum, mean, stdDev);

    return 0;
}

void histogram(float v[]){
    int i, j, t = 1, k;
    float v2[8], buffer;

    for (i = 0 ; i < 8; i ++){
        v2[i] = v[i];
    } 

    k = 7;
    while (t){
        t = 0;
        for (i = 0; i < k; i ++){
            if (v2[i] < v2[i+1]){
                t = 1;
                buffer = v2[i];
                v2[i] = v2[i+1];
                v2[i+1] = buffer;
                
            }
        }
        k --;
    }
    
    printf("Histogram:\n");
    for (i = 0; i < 8; i ++){
        printf("%d: ", i);
        for (j = 0; j < v2[i] * 5; j ++)
            printf("#");
        printf("\n");
    }
}

