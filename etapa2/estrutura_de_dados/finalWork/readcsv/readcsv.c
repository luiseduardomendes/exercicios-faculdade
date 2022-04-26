#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readcsv.h"

float* read_csv(char *filename, float data[]){
    FILE* file;

    char line[2048];
    char *ch;
    int i = 0;

    if (!(file = fopen(filename, "r")))
        return NULL;

    while(!feof(file) && i < MAX_R){
        fgets(line, 2048, file);
        
        ch = strtok(line, ", ");
        
        while (ch != NULL){
            data[i] = atof(ch);
            ch = strtok(NULL, ", ");
            i++;
        }
    }

    return data;
    
}
bst_node* read_txt(char *filename, bst_node *str_bst){
    FILE* file;

    char line[2048];
    char *ch;
    int i = 0;

    if (!(file = fopen(filename, "r")))
        return NULL;

    while(!feof(file) && i < MAX_R){
        fgets(line, 2048, file);
        
        ch = strtok(line, ", \t\n;:-.()\0");
        
        while (ch != NULL){
            str_bst = bst_insert(str_bst, ch);
            ch = strtok(NULL, ", \t\n;:-.()\0");
            i++;
        }
    }

    return str_bst;
    
}

