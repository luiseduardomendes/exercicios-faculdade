#include "linear_algebra.h"
#include <cmath>

Vec::Vec(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vec Vec::unit(){
    double m = mod();
    return Vec(x/m, y/m, z/m);
}
Vec::Vec(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
double Vec::mod(){
    return sqrt(x*x + y*y + z*z);
}
Vec Vec::operator / (double d){
    return Vec(x/d, y/d, z/d);
}
Vec Vec::operator * (double d){
    return Vec(x*d, y*d, z*d);
}
Vec Vec::operator + (double d){
    return Vec(x+d, y+d, z+d);
}
Vec Vec::operator - (double d){
    return Vec(x-d, y-d, z-d);
}
bool Vec::operator==(double d){
    return d == this->mod();
}
bool Vec::operator!=(double d){
    return d != this->mod();
}
bool Vec::operator<=(double d){
    return d <= this->mod();
}
bool Vec::operator<(double d){
    return d < this->mod();
}
bool Vec::operator>=(double d){
    return d >= this->mod();
}
bool Vec::operator>(double d){
    return d > this->mod();
}

