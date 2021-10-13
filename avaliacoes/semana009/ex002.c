#include <stdio.h>
#include <math.h>
#include <locale.h>

enum pointsName {infEsq = 0, supDir = 1};
typedef struct points{
    float x, y;
}points;

void ShowRetangulo(float xe, float ye, float xd, float yd, points center) ;
int centroide(float xe, float ye, float xd, float yd, float *xc, float*yc);
    //this function returns -1 if the user enter wrong cordinates for the vertices

int main() {
    setlocale(LC_CTYPE, "");
    points rectangle[2];
    points center;
    int errorFlag;

    do {
        printf("Digite o ponto inferior direito de um retângulo: ");
        scanf("%f %f", &rectangle[infEsq].x, &rectangle[infEsq].y);
        printf("Digite o ponto superior esquerdo do retângulo: ");
        scanf("%f %f", &rectangle[supDir].x, &rectangle[supDir].y);

        errorFlag = centroide(rectangle[infEsq].x, rectangle[infEsq].y, rectangle[supDir].x, 
                    rectangle[supDir].y, &center.x, &center.y);

        if (!(errorFlag)) {
            printf("As coordenadas do ponto centroide do retângulo são: %.2f, %.2f\n", 
                    center.x, center.y);

            ShowRetangulo(rectangle[infEsq].x, rectangle[infEsq].y, rectangle[supDir].x, 
                    rectangle[supDir].y, center);
        }
        else{
            printf("As coordenadas inseridas para o retângulo estão inválidas! Insira novamente\n");
        }
    } while (errorFlag);
    return 0;
}

int centroide(float xe, float ye, float xd, float yd, float *xc, float*yc) {
    int flag;
    if (xe > xd || ye > yd){
        flag = -1;
    }
    else {
        *xc = (xe + xd)/ 2;
        *yc = (ye + yd)/ 2;
        flag = 0;
    }
    return flag;
}

void ShowRetangulo(float xe, float ye, float xd, float yd, points center) {
    int i, j;
    points tamanho2, tamanho1;
    tamanho1.x = xe - 3;
    tamanho1.y = ye - 3;
    tamanho2.x = xd + 3;
    tamanho2.y = yd + 3;


    for (i = tamanho2.y; i >= tamanho1.y; i --) {
        for (j = tamanho1.x; j < tamanho2.x; j ++) {
            if (round(center.x) == j && round(center.y) == i){
                printf("o ");
            }
            else if ((round(xe) == j || round(xd) == j) && i <= yd && i >= ye) {
                printf("# ");
            }
            else if ((round(ye) == i || round(yd) == i) && j <= xd && j >= xe) {
                printf("# ");
            }
            else if (i == 0 || j == 0) {
                printf("* ");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}
