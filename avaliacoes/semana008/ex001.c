#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct cartesian
{
    double x, y;
}cartesian;
double pow2 (double x, double y);

void showCircle(cartesian centro, double raio);

int main() {
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    double raio;
    cartesian centro;

    ALLEGRO_DISPLAY * display = al_create_display(640, 480);
    ALLEGRO_FONT * font = al_load_ttf_font("YARDSALE.ttf", 64, 0);

    while (true) {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_text(font, al_map_rgb(0,0,0),0,0,0, "Hello World");
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_font(font);

    printf("Insira o raio de um círculo: ");
    scanf("%lf", &raio);
    printf("Insira as coordenadas do centro do circulo: ");
    scanf("%lf %lf", &centro.x, &centro.y);

    showCircle(centro, raio);
    return 0;
}

void showCircle(cartesian centro, double raio) {
    int i, j, escalaX = 1, escalaY = 1;
    cartesian tamanho2, tamanho1;
    tamanho1.x = centro.x - (4*raio/3);
    tamanho1.y = centro.y - (4*raio/3);
    tamanho2.x = centro.x + (4*raio/3);
    tamanho2.y = centro.y + (4*raio/3);

    for (i = tamanho2.y; i >= tamanho1.y; i -= escalaY) {
        for (j = tamanho1.x; j < tamanho2.x; j += escalaX) {
            if (fabs( round(pow((j - centro.x), 2)) + round(pow((i - centro.y), 2)) - round(pow(raio, 2)) ) <= 0.9*raio) {
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

double pow2 (double x, double y){
    int i, retorno = 1;
    for (i = 1; i < y; i ++){
        x *= x;
    }
    retorno = x;
    return retorno;
}
