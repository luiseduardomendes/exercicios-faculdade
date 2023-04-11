#pragma once

#include "allegro_depends.h"

class Display{
    private:
        ALLEGRO_DISPLAY* display;
        int w, h;
    public:
        Display();
        Display(int w, int h);

        bool create_display();
        void clear();
        void show();
        void close();
        ALLEGRO_DISPLAY* get();
        int getW();
        int getH();

};