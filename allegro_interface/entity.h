#include "allegro_depends.h"
#include "linear_algebra.h"
#include "bitmap.h"

class Entity{
    protected:
        Vec pos, spd, looking;
        Bitmap bmp;
    public:
        virtual void set_spd();
        Vec get_pos();
        Vec get_spd();
        Vec get_looking();

        void move();
};

