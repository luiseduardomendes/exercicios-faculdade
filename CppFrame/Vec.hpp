#pragma once
#include <cmath>

class Vec{
public:
    double x, y;
    Vec();
    Vec(double x , double y);
    Vec operator+(Vec v);
    Vec operator-(Vec v);
    Vec operator*(double v);
    Vec operator/(double v);
    double mod();
};