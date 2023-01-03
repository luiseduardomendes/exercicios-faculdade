#include "bitmap.h"

void Bitmap::load(std::string filename){
    this->bmp = al_load_bitmap(filename.c_str());
}

ALLEGRO_BITMAP *Bitmap::get(){
    return this->bmp;
}

void Bitmap::draw(Vec pos){
    al_draw_bitmap(this->bmp, pos.x, pos.y, 0);
}   