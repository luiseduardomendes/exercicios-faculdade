#pragma once
#include "allegro_depends.h"
#include "linear_algebra.h"
#include "bitmap.h"

class Entity{
    protected:
        Bitmap bmp;
    public:
        Vec pos, mov, looking;
        double spd;
        Vec get_pos();
        Vec get_spd();
        Vec get_looking();

        void move();
};

