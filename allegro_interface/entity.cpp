#include "entity.h"

void Entity::move(){
    pos.x += spd.x;
    pos.y += spd.y;
    pos.z += spd.z;

    if (spd != 0)
        looking = spd.unit();
}

Vec Entity::get_pos(){
    return pos;
}

Vec Entity::get_spd(){
    return spd;
}

Vec Entity::get_looking(){
    return looking;
}