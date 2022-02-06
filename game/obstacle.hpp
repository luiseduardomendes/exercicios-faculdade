#pragma once

#include "header.hpp"


class Obstacle{
public:
    Obstacle(float);
    t_coord position;
    float speed;
    void move();
};