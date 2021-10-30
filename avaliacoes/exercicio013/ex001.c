#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZENAME 51

FILE *dataFile;
int analysis(char fileName[], float numericData[][4], char className[][SIZENAME], int numAnalysed);
void showData(float numericData[][4], char className[][SIZENAME], int numAnalysed);
void removeRepetition(char className[][SIZENAME], char classNameWithoutRep[][SIZENAME], int numClasses);

int main() {
    const int numAnalysed = 150;
    int numWithoutRep = 0;
    float numericData[150][4];
    char className[150][SIZENAME];
    char classNameWithoutRep[150][SIZENAME];

    analysis("iris.arff", numericData, className, numAnalysed);
    showData(numericData, className, numAnalysed);
    for(int i = 0; i < numAnalysed;i ++){
        printf("%s\n", className[i]);
    }
    removeRepetition(className, classNameWithoutRep, numAnalysed);
    printf("Classes: \n");
    for (int i = 0; i < 10; i ++){
        printf("%s\n", classNameWithoutRep[i]);
    }
    return 0;
}

int analysis(char fileName[], float numericData[][4], char className[][SIZENAME], int numAnalysed){
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
        }
    }
    else{
        flag = -1;
    }
    return flag;
}

void showData(float numericData[][4], char className[][SIZENAME], int numAnalysed){
    int i, j;
    enum {sepalLenght, sepalWidht, petalLenght, petalWidht};
    for(i = 0; i < numAnalysed; i ++){
        for(j = 0; j <= petalWidht; j ++) {
            printf("%6.2fcm", numericData[i][j]);
        }
        printf("%25s\n", className[i]);
    }
}

void removeRepetition(char className[][SIZENAME], char classNameWithoutRep[][SIZENAME], int numClasses){
    int i, j, newName;
    int numWithoutRep = 0;
    for (i = 0; i < numClasses; i ++){
        newName = 1;
        for (j = 0; j < numWithoutRep; j++){
            if (strcmp(className[i], classNameWithoutRep[j]) == 0){
                newName = 0;
            }
        }
        if (newName){
            strcpy(classNameWithoutRep[numWithoutRep], className[i]);
            numWithoutRep ++;
        }
    }
}
