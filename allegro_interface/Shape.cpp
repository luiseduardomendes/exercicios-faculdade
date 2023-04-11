#include "Shape.h"

void Shape::circle(double x, double y, double radius, ALLEGRO_COLOR color){
    al_draw_filled_circle(x, y, radius, color);
}

void Shape::circle(double x, double y, double radius, double thickness, ALLEGRO_COLOR color){
    al_draw_circle(x, y, radius, color, thickness);
}