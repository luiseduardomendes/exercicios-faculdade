#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

typedef struct cartesian
{
    double x, y;
}cartesian;

void flushIn();
void clearscreen();
double distance(double x1, double x2, double y1, double y2);
int pointInCircle(cartesian ponto, cartesian centro, double raio);
void showCircle(cartesian centro, double raio, cartesian ponto, bool pnts);

int main() {
    setlocale(LC_CTYPE, "");
    double radius;
    int flag, numPoints, i;
    cartesian center, points[100];

    printf("Insira o raio de um círculo: ");
    scanf("%lf", &radius);
    printf("Insira as coordenadas do centro do circulo: ");
    scanf("%lf %lf", &center.x, &center.y);

    do {
        printf("Digite o número de pontos que deseja inserir: ");
        scanf("%d", &numPoints);
        if (numPoints > 100 || numPoints < 0) {
            printf("Número de pontos inválido, insira novamente!\n");
        }
    } while (numPoints > 100 || numPoints < 0);

    showCircle(center, radius, points[0], false);
    printf("Enter para continuar!\n");
    flushIn();
    getchar();
    for (i = 0; i < numPoints; i ++) {
        clearscreen();
        printf("Insira um ponto no plano cartesiano: ");

        scanf("%lf %lf", &points[i].x, &points[i].y);

        flag = pointInCircle(points[i], center, radius);

        showCircle(center, radius, points[i], true);
        switch (flag) {
            case 1: printf("O ponto está inserido na circunferencia!\n");
            break;
            case 0: printf("O ponto está no raio da circunferencia!\n");
            break;
            case -1: printf("O ponto está fora da circunferencia!\n");
            break;
        }
        printf("Enter para continuar!\n");
        flushIn();
        getchar();
    }

    return 0;
}

void showCircle(cartesian center, double radius, cartesian point, bool pnts) {
    int i, j, escalaX = 1, escalaY = 1;
    double dist;
    cartesian size2, size1;
    size1.x = center.x - (4*radius/3);
    size1.y = center.y - (4*radius/3);
    size2.x = center.x + (4*radius/3);
    size2.y = center.y + (4*radius/3);

    for (i = size2.y; i >= size1.y; i -= escalaY) {
        for (j = size1.x; j < size2.x; j += escalaX) {
            dist = distance(j, center.x, i, center.y);
            if (round(point.x) == j && round(point.y) == i && pnts == true){
                printf("o ");
            }
            else if (fabs(dist - radius) <= 0.5) {
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

int pointInCircle(cartesian point, cartesian center, double radius) {
    int flag;
    double dist;

    dist = distance(point.x, center.x, point.y, center.y);

    if (dist < radius){
        flag = 1;
    }
    else if (dist > radius){
        flag = -1;
    }
    else{
        flag = 0;
    }
    return flag;
}

double distance(double x1, double x2, double y1, double y2) {
    double dist;

    dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

    return dist;
}

void flushIn() {
    #ifdef _WIN32
        fflush(stdin);
    #elif _POSIX_C_SOURCE >= 199309L
        __fpurge(stdin);
    #endif
}

void clearscreen() {
    #ifdef _WIN32
        system("cls");
    #elif _POSIX_C_SOURCE >= 199309L
        system("clear");
    #endif
}
