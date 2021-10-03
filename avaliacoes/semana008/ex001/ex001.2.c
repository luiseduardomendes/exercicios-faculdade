#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct cartesian
{
    double x, y;
}cartesian;

double distance(double x1, double x2, double y1, double y2);
void showCirclewPoints(cartesian centro, double raio, cartesian ponto);
int pointInCircle(cartesian ponto, cartesian centro, double raio);
void showCircle(cartesian centro, double raio);

int main() {
    double raio;
    int flag, pontosInseridos = 3, i;
    cartesian centro, ponto[100];

    /*al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY * display = al_create_display(640, 480);
    ALLEGRO_FONT * font = al_load_ttf_font("YARDSALE.ttf", 64, 0);

    while (true) {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_text(font, al_map_rgb(0,0,0),0,0,0, "Hello World");
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_font(font);*/

    printf("Insira o raio de um círculo: ");
    scanf("%lf", &raio);
    printf("Insira as coordenadas do centro do circulo: ");
    scanf("%lf %lf", &centro.x, &centro.y);

    showCircle(centro, raio);
    __fpurge(stdin);
    getchar();
    for (i = 0; i < pontosInseridos; i ++) {
        system("clear");
        printf("Insira um ponto no plano cartesiano: ");

        scanf("%lf %lf", &ponto[i].x, &ponto[i].y);

        flag = pointInCircle(ponto[i], centro, raio);

        showCirclewPoints(centro, raio, ponto[i]);
        switch (flag) {
            case 1: printf("O ponto está inserido na circunferencia!\n");
            break;
            case 0: printf("O ponto está no raio da circunferencia!\n");
            break;
            case -1: printf("O ponto está fora da circunferencia!\n");
            break;
        }

        __fpurge(stdin);
        getchar();
    }

    return 0;
}

void showCircle(cartesian centro, double raio) {
    int i, j, escalaX = 1, escalaY = 1;
    cartesian tamanho2, tamanho1;
    double dist;
    tamanho1.x = centro.x - (4*raio/3);
    tamanho1.y = centro.y - (4*raio/3);
    tamanho2.x = centro.x + (4*raio/3);
    tamanho2.y = centro.y + (4*raio/3);


    for (i = tamanho2.y; i >= tamanho1.y; i -= escalaY) {
        for (j = tamanho1.x; j < tamanho2.x; j += escalaX) {
            dist = distance(j, centro.x, i, centro.y);

            if (fabs(dist - raio) <= 0.5) {
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

void showCirclewPoints(cartesian centro, double raio, cartesian ponto) {
    int i, j, escalaX = 1, escalaY = 1;
    double dist;
    cartesian tamanho2, tamanho1;
    tamanho1.x = centro.x - (4*raio/3);
    tamanho1.y = centro.y - (4*raio/3);
    tamanho2.x = centro.x + (4*raio/3);
    tamanho2.y = centro.y + (4*raio/3);

    for (i = tamanho2.y; i >= tamanho1.y; i -= escalaY) {
        for (j = tamanho1.x; j < tamanho2.x; j += escalaX) {
            dist = distance(j, centro.x, i, centro.y);
            if (round(ponto.x) == j && round(ponto.y) == i){
                printf("o ");
            }
            else if (fabs(dist - raio) <= 0.5) {
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

int pointInCircle(cartesian ponto, cartesian centro, double raio) {
    int flag;

    double dist;

    dist = distance(ponto.x, centro.x, ponto.y, centro.y);

    printf("Distancia: %.2lf\n", distance);
    printf("Ponto: %.2lf %.2lf\n", ponto.x, ponto.y);
    printf("Centro: %.2lf %.2lf\n", centro.x, centro.y);

    if (dist < raio){
        flag = 1;
    }
    else if (dist > raio){
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
