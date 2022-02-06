#include "header.hpp"

Player::Player(){
    position.x = 496;
    position.y = 500;
    jumping = false;
}

void Player::jump(){
    fall_speed.y = -10;
    jumping = true;
}

void Player::fell(){
    jumping = false;
    fall_speed.y = 0;
}

void Player::set_fall_speed(){
    fall_speed.y += 1/2.0; 
}

void Player::move(){
    position.y += fall_speed.y;
}

void Player::set_hitbox(){
    hitbox.inf = position;
    hitbox.sup.x = position.x + 40;
    hitbox.sup.y = position.y + 40;
}