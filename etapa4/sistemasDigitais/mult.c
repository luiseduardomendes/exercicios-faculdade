#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char a, b, a_, b_, s;

int main(int argv, char** argc){
    unsigned char mod;

    if(argv != 3)
        return 0;
    
    a = atoi(argc[1]);
    b = atoi(argc[2]);
    a_ = a;
    b_ = b;
    s = 0;

    while(b_ != 0){
        mod = b_ % 2;
        b_ = b_ >> 1;
        if (mod == 1)
            s += a_;
        a_ = a_ << 1;
    }
    printf("%d x %d = %d\n", a, b, s);

}