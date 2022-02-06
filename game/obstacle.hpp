#pragma once

#include "header.hpp"


class Obstacle{
public:
    Obstacle(float);
    t_hitbox hitbox;
    void set_hitbox();
    t_coord position;
    float speed;
    void move();
};