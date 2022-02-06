#include "header.hpp"

Obstacle::Obstacle(float speed_){
    speed = speed_;
    position.x = 1024;
    position.y = 500;
}

void Obstacle::move(){
    position.x -= speed;
}

void Obstacle::set_hitbox(){
    hitbox.inf = position;
    hitbox.sup.x = position.x + 40;
    hitbox.sup.y = position.y + 40;
}