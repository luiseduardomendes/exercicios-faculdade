#include "background.hpp"

Background::Background(string bitmap_path, int map_w, int map_h){
    al_load_bitmap(bitmap_path.c_str());
    this->map_w = map_w;
    this->map_h = map_h;
}