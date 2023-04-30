#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cstdlib>

typedef struct fPoint{
    int x,y;
}fPoint;

fPoint p[3], q;


float sign (fPoint p1, fPoint p2, fPoint p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

fPoint midpoint(fPoint p1, fPoint p2){
    fPoint point;
    point.x = (p1.x + p2.x)/2;
    point.y = (p1.y + p2.y)/2;
    return point;
}

using namespace std;

int main(){
    al_init();
    srand(time(NULL));

    ALLEGRO_DISPLAY *display = NULL;
    if (!(display = al_create_display(480,480)))
        cout << "Display nao pode ser criado" << endl;
    
    al_init_primitives_addon();

    p[0].x = 480;     p[0].y = 480;
    p[1].x = 0;       p[1].y = 480;
    p[2].x = 240;     p[2].y = 0;

    int n;
    

    q.x = 240;   
    q.y = 239;
    

    cout << q.x << " " << q.y << endl;
    n = 10;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    while(1){       
        n = n + 10;

        al_draw_pixel(p[0].x, p[0].y, al_map_rgb(0xff,0xff,0xff));
        al_draw_pixel(p[1].x, p[1].y, al_map_rgb(0xff,0xff,0xff));
        al_draw_pixel(p[2].x, p[2].y, al_map_rgb(0xff,0xff,0xff));

        for (int i = 0; i < n; i ++){
            al_draw_pixel(q.x, q.y, al_map_rgb(0xff,0xff,0xff));
            q = midpoint(q, p[rand()%3]);
        }

        al_flip_display();
        if (n > 100000){
            break;
        }

        system("sleep 2.5");
    }


    return 0;
}
