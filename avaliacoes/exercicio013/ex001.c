#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *dataFile;
int analysis(char fileName[], float numericData[][4], char className[][51], int numAnalysed);
void showData(float numericData[][4], char className[][51], int numAnalysed);


int main() {
    const int numAnalysed = 150;
    float numericData[numAnalysed][4];
    char className[numAnalysed][51];

    analysis("iris.arff", numericData, className, numAnalysed);
    showData(numericData, className, numAnalysed);
    return 0;
}

int analysis(char fileName[], float numericData[][4], char className[][51], int numAnalysed){
    int flag, error = 0, indexData = 0;
    char buffer[255], chTest;
    enum {sepalLenght, sepalWidht, petalLenght, petalWidht};

    if (dataFile = fopen(fileName, "rb")) {
        while(!feof(dataFile) && !error){
            if (fgets(buffer, sizeof(buffer), dataFile)){
                if (buffer[0] != '%' && buffer[0] != '@' && buffer[0] != '\n' && buffer[0] != '\0'){
                    numericData[indexData][sepalLenght] = atof(strtok(buffer, ","));
                    numericData[indexData][sepalWidht] = atof(strtok(NULL, ","));
                    numericData[indexData][petalLenght] = atof(strtok(NULL, ","));
                    numericData[indexData][petalWidht] = atof(strtok(NULL, ","));
                    strcpy(className[indexData], strtok(NULL, ","));
                    indexData ++;
                }
            }
            else {
                error = 1;
                flag = -2;
            }
        }
    }
    else{
        flag = -1;
    }
    return flag;
}

void showData(float numericData[][4], char className[][51], int numAnalysed){
    int i, j;
    enum {sepalLenght, sepalWidht, petalLenght, petalWidht};
    for(i = 0; i < numAnalysed; i ++){
        for(j = 0; j <= petalWidht; j ++) {
            printf("%6.2fcm", numericData[i][j]);
        }
        printf("%25s\n", className[i]);
    }
}
