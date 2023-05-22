#include "Frame.hpp"
#define print(x) std::cout << x
#define dbg(x) std::cout << x << std::endl

using namespace graph;

typedef struct fPoint{
    float x,y;
}fPoint;

float sign (fPoint p1, fPoint p2, fPoint p3);
bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3);
fPoint midpoint(fPoint p1, fPoint p2);

class MyFrame : public Frame{
private:   
    Draw draw;
    void timer_update() override {
        for (int i = 0; i < 50; i ++){
            p = midpoint(p, q[randi(0,3)]);
            draw.draw_point(p.x, p.y, al_map_rgb(0, 0, 0));
        }
        std::cout << "r: " << this->bg_color.r << " ";
        std::cout << "g: " << this->bg_color.g << " ";
        std::cout << "b: " << this->bg_color.b << std::endl;

        this->set_display();
    }
public:
    fPoint q[3], p;
    using Frame::Frame;
};

int main(){
    srand(time(NULL));
    MyFrame frame(480, 480);
    
    frame.q[0].x = 480;   frame.q[0].y = 415.69; 
    frame.q[1].x = 0;     frame.q[1].y = 415.69; 
    frame.q[2].x = 240;   frame.q[2].y = 0; 

    frame.set_update_time(1./2.);
    
    frame.set_bg_color(al_map_rgb(72, 201, 176));
    
    frame.p.x = randi(0, 416); frame.p.y = randi(0, 416);
    
    frame.reset_display();
    frame.run();
    
}

float sign (fPoint p1, fPoint p2, fPoint p3){
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