#pragma once

class Vec{
    private:
    public:
        double x, y, z;
        Vec();
        Vec(double x, double y, double z);

        double mod();
        Vec unit();
        
        Vec operator / (double d);
        Vec operator * (double d);
        Vec operator + (double d);
        Vec operator - (double d);
        bool operator==(double d);
        bool operator!=(double d);
        bool operator<=(double d);
        bool operator<(double d);
        bool operator>=(double d);
        bool operator>(double d);
};