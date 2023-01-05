#include "entity.h"

void Entity::move(){
    pos.x += mov.x;
    pos.y += mov.y;
    pos.z += mov.z;

    if (mov != 0)
        looking = mov.unit();
}

Vec Entity::get_pos(){
    return pos;
}

Vec Entity::get_spd(){
    return mov;
}

Vec Entity::get_looking(){
    return looking;
}