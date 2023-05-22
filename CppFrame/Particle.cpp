#include "Particle.hpp"


void Particle::set_q( double q){
    this->q = q;
}

void Particle::draw(){
    drawing.draw_circle(p.x, p.y, 3, al_map_rgb(0xff, 0xff, 0xff));
}


void Electron::draw() {
    drawing.draw_circle(p.x, p.y, 3, al_map_rgb(0, 0, 0xff));
}

void Positron::draw() {
    drawing.draw_circle(p.x, p.y, 3, al_map_rgb(0xff, 0, 0));
}
