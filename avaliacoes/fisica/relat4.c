#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define NUMQUADROS 20
#include <string.h>
#include <math.h>

float angularPosition(float x, float y, int n, int q);
float angularDegrees(float angle);

int main() {
    char buffer[101];
    float centerOfMass[NUMQUADROS], auxRadiusx[NUMQUADROS], auxRadiusy[NUMQUADROS];
    float timeCurrent[NUMQUADROS];
    int round[NUMQUADROS], quadrant[NUMQUADROS];
    int i;
    float angularPosRad[NUMQUADROS], angularPosDeg[NUMQUADROS];
    float timeCurrentMedio[NUMQUADROS] = {0};
    float speedAngularDeg[NUMQUADROS] = {0}, speedAngularRad[NUMQUADROS] = {0};
    float speedLinear[NUMQUADROS] = {0};
    FILE *file;

    setlocale(LC_ALL, "");

    if (file = fopen("data.txt", "r")){
        rewind(file);
        for (i = 0; i < NUMQUADROS; i ++){
            fgets(buffer, 101, file);
            centerOfMass[i] = atof(strtok(buffer, ", \t"));
            auxRadiusy[i] = atof(strtok(NULL, ", \t"));
            auxRadiusx[i] = atof(strtok(NULL, ", \t"));
            timeCurrent[i] = atof(strtok(NULL, ", \t"));
            round[i] = atoi(strtok(NULL, ", \t"));
            quadrant[i] = atoi(strtok(NULL, ", \t"));
        }
        fclose(file);

        for (i = 0; i < NUMQUADROS; i ++) {
            angularPosRad[i] = angularPosition(auxRadiusx[i] - centerOfMass[i], auxRadiusy[i], round[i], quadrant[i]);
            angularPosDeg[i] = angularDegrees(angularPosRad[i]);
        }

        for (i = 1; i < NUMQUADROS-1; i ++) {
            timeCurrentMedio[i] = (timeCurrent[i-1] + timeCurrent[i+1]) / 2.0;
            speedLinear[i] = ((centerOfMass[i + 1] - centerOfMass[i-1]) / (timeCurrent[i+1] - timeCurrent[i-1]));
            speedAngularDeg[i] = ((angularPosDeg[i+1] - angularPosDeg[i-1]) / (timeCurrent[i+1] - timeCurrent[i-1]));
            speedAngularRad[i] =  ((angularPosRad[i+1] - angularPosRad[i-1]) / (timeCurrent[i+1] - timeCurrent[i-1]));
        }





        if (file = fopen("C:\\Users\\dudup\\OneDrive\\Área de Trabalho\\dataoutput.txt", "w")){
            for(i = 0; i < NUMQUADROS; i ++) {
                fprintf(file, "%3.3f\t", centerOfMass[i]);
                fprintf(file, "%3.3f\t", auxRadiusx[i]);
                fprintf(file, "%3.3f\t", auxRadiusy[i]);
                fprintf(file, "%3.3f\t", timeCurrent[i]);
                fprintf(file, "%3d\t", round[i]);
                fprintf(file, "%3d\t", quadrant[i]);
                fprintf(file, "%3.3f\t", angularPosRad[i]);
                fprintf(file, "%3.3f\t", angularPosDeg[i]);
                fprintf(file, "%3.3f\t", timeCurrentMedio[i]);
                fprintf(file, "%3.3f\t", speedLinear[i]);
                fprintf(file, "%3.3f\t", speedAngularRad[i]);
                fprintf(file, "%3.3f\t", speedAngularDeg[i]);
                fprintf(file, "\n");
            }
            fclose(file);
        }
        else {
            printf("Erro na abertura do segundo arquivo\n");
            return -1;
        }
    }
    else {
        printf("Erro na abertura do segundo arquivo\n");
        return -1;
    }
    return 0;
}

float angularPosition(float x, float y, int n, int q){
    return atan(y/x) + ((q - 1.0) * M_PI / 2.0) + (2.0 * M_PI * n);
}

float angularDegrees(float angle){
    return (angle * 180.0 / M_PI);
}



