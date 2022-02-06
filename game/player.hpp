#pragma once
#include "header.hpp"

class Player{
public:
    Player();
    t_coord position;
    t_coord fall_speed;
    bool jumping;
    void jump();
    void move();
    void fell();
    void set_fall_speed();
};