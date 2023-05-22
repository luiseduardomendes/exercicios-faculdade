#include "Vec.hpp"

class Entity{
public:
    Vec p, s, a;
    Entity(Vec p, Vec s){
        this->p = p;
        this->s = s;
        this->a = {0,0};
    }
};
