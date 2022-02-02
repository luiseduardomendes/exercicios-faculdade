#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DIV 10

int main(){
    double bar_length = 10 * pow(10, -3);
    double charge = 1 * pow (10, -9);
    double distViewPoint = 1 * pow(10, -3);
    double k = 9 * pow(10, 9);
    double dist;
    struct{
        double x, y;
    }unitaryVect;

    double e = 0;

    int i;

    for (i = 0; i < DIV; i ++){
        dist = sqrt(pow(distViewPoint, 2) + pow((i*bar_length/DIV)-(bar_length/2), 2));
        e += k*(charge/DIV)/pow(dist, 3);
        unitaryVect = 
    }

    

    return 0;
}