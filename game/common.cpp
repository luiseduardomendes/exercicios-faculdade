#include "header.hpp"

bool pointInsideBox(t_coord point_, t_hitbox box_){
    if (point_.x >= box_.inf.x && point_.x <= box_.sup.x && point_.y >= box_.inf.y && point_.y <= box_.sup.y)
        return true;
    else
        return false;
}
bool isHitboxIn(t_hitbox HB1, t_hitbox HB2){
    t_coord aux1, aux2;

    aux1.x = HB2.inf.x;
    aux1.y = HB2.sup.y;

    aux2.x = HB2.sup.x;
    aux2.y = HB2.inf.y;

    if (pointInsideBox(aux1, HB1) || pointInsideBox(aux2, HB1) ||
            pointInsideBox(HB2.inf, HB1) || pointInsideBox(HB2.sup, HB1))
        return true;
    return false;
}