#include <sys/ioctl.h>
#include <stdio.h>
#include <cmath>
#include <unistd.h>

#define MAX 70
const char scale[] = "$@B%8&WM#oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?+<>i!lI;:*\"^,`-~_'. ";

int width = 64;
int height = 48;

int calc(int r);
int f(int x, int y){
    return calc(
        sqrt(x*x+y*y)*2.2
    );
}

int calc(int r){
    if (r >= MAX)
        return MAX-1;
    else if (r < 0)
        return 0;
    else
        return r;
    
}

int main(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    width = w.ws_row/2-1;
    height = w.ws_col/4;

    system("clear");
    for (int i = -width; i <= width; i ++){
        for (int j = -height; j <= height; j ++){
            printf("%c", scale[f(i, j)]);
            printf("%c", scale[f(i, j)]);
            //printf("%2d", f(i, j));
        }
        printf("\n");
    }
    return 0;
}
