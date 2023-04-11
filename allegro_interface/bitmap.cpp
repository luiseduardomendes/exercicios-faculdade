#include "bitmap.h"

void Bitmap::load(std::string filename){
    this->bmp = al_load_bitmap(filename.c_str());
}

void Bitmap::create(double w, double h){
    this->bmp = al_create_bitmap(w, h);
}

ALLEGRO_BITMAP *Bitmap::get(){
    return this->bmp;
}

void Bitmap::draw(Vec pos){
    al_draw_bitmap(this->bmp, pos.x, pos.y, 0);
}   