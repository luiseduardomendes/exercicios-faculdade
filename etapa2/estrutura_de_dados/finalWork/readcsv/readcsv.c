#include <stdlib.h>
#include <stdio.h>
#include "readcsv.h"

float* read_csv(char *filename, int rows){
    FILE* file;
    float data[MAX_R][MAX_C];
    char line[2048];
    char *ch;
    int i = 0, j = 0;

    if (!(file = fopen(filename, "r")))
        return NULL;

    while(!feof(file) && i < MAX_R){
        fgets(line, 2048, file);
        
        ch = strtok(line, ", ");
        
        while (!ch){
            data[i][j] = atof(ch);
            ch = strtok(NULL, ", ");
            printf("%.2f\t", data[i][j]);
            j++;
        }
        printf("\n");
        
        i++;
    }

    return data;
    
}