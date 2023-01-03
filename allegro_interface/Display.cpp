#include "Display.h"

Display::Display(int w, int h){
    this->w = w;
    this->h = h;
}

Display::Display(){
    this->w = 640;
    this->h = 480;
}

bool Display::create_display(){
    this->display = al_create_display(w, h);
    return this->display != NULL;
}

void Display::clear(){
    al_clear_to_color(al_map_rgb(0,0,0));
}

void Display::show(){
    al_flip_display();
}

void Display::close(){
    al_destroy_display(this->display);
}

int Display::getW(){
    return this->w;
}

int Display::getH(){
    return this->h;
}

ALLEGRO_DISPLAY* Display::get(){
    return this->display;
}