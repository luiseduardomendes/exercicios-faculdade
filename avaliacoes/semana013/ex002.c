#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZENAME 51
#define NUMCARACT 4
#define MAXCLASSES 25
#define NUMANALYSED 150

FILE *dataFile;
int analysis(char fileName[], float numericData[][NUMCARACT], char className[][SIZENAME], int numAnalysed);
void showData(float numericData[][4], char className[][SIZENAME], int numAnalysed);
int removeRepetition(char className[][SIZENAME], char classNameWithoutRep[][SIZENAME], int numClasses);
void removeEnter(char str[], int strSize);
void vectorize(float matrix[][4], float v1[], float v2[], float v3[], float v4[], int numLines);
float correlacaodePearson (float v1[], float v2[], int sizeVec);

enum {sepalLenght, sepalWidht, petalLenght, petalWidht};

int main() {
    const int numAnalysed = 150;
    int numWithoutRep = 0;
    float numericData[numAnalysed][NUMCARACT];
    char className[numAnalysed][SIZENAME];
    char classNameWithoutRep[numAnalysed][SIZENAME];
    int i, j;
    float rplpw, rplsl, rplsw, rpwsl, rpwsw, rslsw;
    float dataSepalLenght[NUMANALYSED] = {0}, dataSepalWidth[NUMANALYSED] = {0};
    float dataPetalLenght[NUMANALYSED] = {0}, dataPetalWidth[NUMANALYSED] = {0};
    float mediaData[3][NUMCARACT] = {0};
    float standardDeviat[3][NUMCARACT] = {0};

    analysis("iris.arff", numericData, className, numAnalysed);

    showData(numericData, className, numAnalysed);

    numWithoutRep = removeRepetition(className, classNameWithoutRep, numAnalysed);

    printf("\nClasses: \n");
    for (i = 0; i < numWithoutRep; i ++)
        printf("%s\n", classNameWithoutRep[i]);

    standardDeviation(numericData, className, classNameWithoutRep, numAnalysed, numWithoutRep, mediaData, standardDeviat);
    for (i = 0; i < numWithoutRep; i ++) {
        printf("\nMedia da Classe: %s\n", classNameWithoutRep);
        for (j = 0; j < 4; j ++){
            switch (j){
                case sepalLenght: printf("Comprimento da sépala: ");
                    break;
                case sepalWidht:  printf("Largura da sépala:     ");
                    break;
                case petalLenght: printf("Comprimento da pétala: ");
                    break;
                case petalWidht:  printf("Largura da pétala:     ");
                    break;
            }
            printf(" %.4fcm\n", mediaData[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < numWithoutRep; i ++) {
        printf("\nDesvio Padrão da Classe: %s \n\n", classNameWithoutRep);
        for (j = 0; j < 4; j ++){
            switch (j){
                case sepalLenght: printf("Comprimento da sépala: ");
                    break;
                case sepalWidht:  printf("Largura da sépala:     ");
                    break;
                case petalLenght: printf("Comprimento da pétala: ");
                    break;
                case petalWidht:  printf("Largura da pétala:     ");
                    break;
            }
            printf("%.4f\n", standardDeviat[i][j]);
        }

        printf("\n");
    }
    printf("\n");

    vectorize(numericData, dataSepalLenght, dataSepalWidth, dataPetalLenght, dataPetalWidth, 150);

    rplpw = correlacaodePearson(dataPetalLenght, dataPetalWidth, 150);
    rplsl = correlacaodePearson(dataPetalLenght, dataSepalLenght, 150);
    rplsw = correlacaodePearson(dataPetalLenght, dataSepalWidth, 150);
    rpwsl = correlacaodePearson(dataPetalWidth, dataSepalLenght, 150);
    rpwsw = correlacaodePearson(dataPetalWidth, dataSepalWidth, 150);
    rslsw = correlacaodePearson(dataSepalLenght, dataSepalWidth, 150);

    printf("\nCoeficientes de correlação de Pearson: \n");
    printf("Comprimento da pétala x Largura da pétala:      %.4f\n"
           "Comprimento da pétala x Comprimento da sépala:  %.4f\n"
           "Comprimento da pétala x Largura da sépala:      %.4f\n"
           "Largura da pétala x Comprimento da sépala:      %.4f\n"
           "Largura da pétala x Largura da sépala:          %.4f\n"
           "Comprimento da sépala x Largura da sépala:      %.4f\n", rplpw, rplsl, rplsw, rpwsl, rpwsw, rslsw);

    return 0;
}

int analysis(char fileName[], float numericData[][NUMCARACT], char className[][SIZENAME], int numAnalysed){
    int flag, error = 0, indexData = 0;
    char buffer[255], chTest;

    if (dataFile = fopen(fileName, "rb")) {
        while(!feof(dataFile) && !error){
            if (fgets(buffer, sizeof(buffer), dataFile)){
                if (buffer[0] != '%' && buffer[0] != '@' && buffer[0] != '\n' && buffer[0] != '\0'){
                    numericData[indexData][sepalLenght] = atof(strtok(buffer, ","));
                    numericData[indexData][sepalWidht] = atof(strtok(NULL, ","));
                    numericData[indexData][petalLenght] = atof(strtok(NULL, ","));
                    numericData[indexData][petalWidht] = atof(strtok(NULL, ","));
                    strcpy(className[indexData], strtok(NULL, ","));
                    removeEnter(className[indexData], SIZENAME);
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

void showData(float numericData[][NUMCARACT], char className[][SIZENAME], int numAnalysed){
    int i, j;
    enum {sepalLenght, sepalWidht, petalLenght, petalWidht};
    for(i = 0; i < numAnalysed; i ++){
        for(j = 0; j <= petalWidht; j ++) {
            printf("%6.2fcm", numericData[i][j]);
        }
        printf("%25s\n", className[i]);
    }
}

int removeRepetition(char className[][SIZENAME], char classNameWithoutRep[][SIZENAME], int numClasses){
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
    return numWithoutRep;
}

void standardDeviation(float numericData[][NUMCARACT], char className[][SIZENAME], char classNameWithoutRep[][SIZENAME], int numData, int numClasses, float mediaData[numData][NUMCARACT], float standardDeviat[][NUMCARACT]){
    int i, j, classAnalysed = 0, caract;

    int sizeClass[MAXCLASSES] = {0};

    //calculo da media
    for(classAnalysed = 0; classAnalysed < numClasses; classAnalysed ++) {

        for(i = 0; i < numData; i ++)
            if(strcmp(classNameWithoutRep[classAnalysed], className[i]) == 0){
                for (caract = 0; caract < NUMCARACT; caract ++)
                    mediaData[classAnalysed][caract] += numericData[i][caract];
                sizeClass[classAnalysed] ++;
            }

        for (caract = 0; caract < NUMCARACT; caract ++)
            mediaData[classAnalysed][caract] /= sizeClass[classAnalysed];
    }

    for (classAnalysed = 0; classAnalysed < numClasses; classAnalysed ++) {
        for (i = 0; i < numData; i ++)
            if(strcmp(classNameWithoutRep[classAnalysed], className[i]) == 0)
                for (caract = 0; caract < NUMCARACT; caract ++)
                    standardDeviat[classAnalysed][caract] += pow((numericData[i][caract] - mediaData    [classAnalysed][caract]), 2);


        for (caract = 0; caract < NUMCARACT; caract ++)
            standardDeviat[classAnalysed][caract] /= sizeClass[classAnalysed];
    }
}

void vectorize(float matrix[][NUMCARACT], float v1[], float v2[], float v3[], float v4[], int numLines){
    int i;
    for (i = 0; i < numLines; i ++){
        v1[i] = matrix[i][sepalLenght];
        v2[i] = matrix[i][sepalWidht];
        v3[i] = matrix[i][petalLenght];
        v4[i] = matrix[i][petalWidht];
    }
}

float correlacaodePearson (float v1[], float v2[], int sizeVec) {
    struct variaveis {
        double x, y;
    }media, soma, var;
    int i;
    double cov;
    double numerador, denominador;
    double r;

    soma.x = 0;
    soma.y = 0;
    media.x = 0;
    media.y = 0;
    var.x = 0;
    var.y = 0;
    cov = 0;

    for (i = 0; i < sizeVec; i ++) {
        soma.x += v1[i];
        soma.y += v2[i];
    }

    media.x = soma.x / sizeVec;
    media.y = soma.y / sizeVec;

    for (i = 0; i < sizeVec; i ++) {
        var.x += pow((v1[i] - media.x), 2);
        var.y += pow((v2[i] - media.y), 2);
    }

    for (i = 0; i < sizeVec; i ++) {
        cov += ((v1[i] - media.x) * (v2[i] - media.y));
    }

    numerador = cov;
    denominador = sqrt(var.x * var.y);

    r = (numerador / denominador);

    return r;
}

void removeEnter(char str[], int strSize) {
    int i;
    for(i = 0; i < strSize; i++)
        if (str[i] == '\n')
            str[i] = '\0';
}

