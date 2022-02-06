#pragma once
#include "header.hpp"

class Player{
public:
    Player();
    t_coord position;
    t_coord fall_speed;
    t_hitbox hitbox;
    void set_hitbox();
    bool jumping;
    void jump();
    void move();
    void fell();
    void set_fall_speed();
};