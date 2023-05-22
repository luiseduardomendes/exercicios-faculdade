#include "Vec.hpp"

Vec::Vec(){x = 0; y = 0;};

Vec::Vec(double x , double y){
    this->x = x;
    this->y = y;
}

Vec Vec::operator+(Vec v){
    Vec r;
    r.x = this->x + v.x;
    r.y = this->y + v.y;
    return r;
}

Vec Vec::operator-(Vec v){
    Vec r;
    r.x = this->x - v.x;
    r.y = this->y - v.y;
    return r;
}

Vec Vec::operator*(double v){
    Vec r;
    r.x = this->x * v;
    r.y = this->y * v;
    return r;
}

Vec Vec::operator/(double v){
    Vec r;
    r.x = this->x / v;
    r.y = this->y / v;
    return r;
}

double Vec::mod(){
    return sqrt(x*x + y*y);
}
