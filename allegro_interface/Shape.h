#pragma once

#include "allegro_depends.h"
#include <string>

class Shape{
    public:
        void circle(double x, double y, double radius, ALLEGRO_COLOR color);
        void circle(double x, double y, double radius, double thickness, ALLEGRO_COLOR color);

        void square(double x, double y, double length, double rot, ALLEGRO_COLOR color);
        void square(double x, double y, double length, double rot, double thickness, ALLEGRO_COLOR color);

        void rectangle(double x, double y, double length_w, double length_h, double rot, ALLEGRO_COLOR color);
        void rectangle(double x, double y, double length_w, double length_h, double rot, double thickness, ALLEGRO_COLOR color);
};