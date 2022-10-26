#pragma once
#include "allegro.hpp"
#include <string>

using namespace std;

class Background{
    private:
        ALLEGRO_BITMAP *bitmap;
        int map_w;
        int map_h;
    public:
        Background(string bitmap_path, int map_w, int map_h);

};