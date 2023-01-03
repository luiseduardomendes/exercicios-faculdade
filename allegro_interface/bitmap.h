#include "allegro_depends.h"
#include "linear_algebra.h"
#include <string>

class Bitmap{
    private:
        ALLEGRO_BITMAP* bmp;
    public:
        void load(std::string filename);
        ALLEGRO_BITMAP* get();
        void draw(Vec pos);
};