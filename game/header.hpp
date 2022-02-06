#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define GRAVITY 10

typedef struct{
    int width, height;
    bool exit;
}t_scr;

typedef struct{
    float x, y;
}t_coord;

typedef struct{
    t_coord inf, sup;
}t_hitbox;

#include "player.hpp"
#include "obstacle.hpp"

bool pointInsideBox(t_coord point_, t_hitbox box_);
bool isHitboxIn(t_hitbox HB1, t_hitbox HB2);

