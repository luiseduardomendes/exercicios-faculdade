#include "header.hpp"

Obstacle::Obstacle(float speed_){
    speed = speed_;
    position.x = 1024;
    position.y = 500;
}

void Obstacle::move(){
    position.x -= speed;
}
