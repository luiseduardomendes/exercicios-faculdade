#pragma once
#include "entity.h"
#include <vector>

class Player : public Entity{
    private:
    public:
        void create_bmp();
        Player();
        Player(Vec pos);
        void draw();
};