#include "Frame.hpp"
#include "Vec.hpp"
#include "Entity.hpp"
#include "Particle.hpp"
#include <vector>
#include <cmath>
#include <ctime>

#define NUM_PARTS 10
#define dbg_v(a) std::cout << a.x << ", " << a.y << std::endl
#define dbg(a) std::cout << a << std::endl

using namespace std;

Vec calculate_forces(vector<Particle*> particles, Particle *p);
Vec electric_force(Particle p1, Particle p2);
Vec rand_vec(float x0, float x1, float y0, float y1);

class System : public graph::Frame{
    using graph::Frame::Frame;

    void timer_update() override {
        reset_display();
        update_system();
        draw_particles();
        set_display();
    }
private:
    vector<Particle*> particles;
    void update_system(){
        for (auto p : particles){
            p->a = calculate_forces(particles, p);
            p->s = p->s + p->a / dt;
            p->p = p->p + p->s / dt;
        }
    }
    void draw_particles(){
        for (auto p : particles){
            p->draw();
            
        }
    }
public:

    void generate_particles(){
        for (int i = 0; i < NUM_PARTS; i ++){
            auto p = new Electron(rand_vec(0., 480.,0., 480.), Vec());
            
            auto q = new Positron(rand_vec(0., 480.,0., 480.), Vec());
            
            particles.push_back(p);
        }
    }
};

Vec calculate_forces(vector<Particle*> particles, Particle *p){
    Vec forces = {0,0};
    for (auto q : particles){
        if (q != p){
            forces = forces + electric_force(*(p), *(q));
        }
    }
    return forces;
}

Vec electric_force(Particle p1, Particle p2){
    double k = 1;
    if ((p1.p-p2.p).mod() > 5)
        return ((p1.p-p2.p) * p1.q * p2.q  * k) / pow((p1.p-p2.p).mod(), 3);
    return Vec();
}

Vec rand_vec(float x0, float x1, float y0, float y1){
    return Vec (graph::randf(x0, x1), graph::randf(y0, y1));
}

int main(){
    srand(time(NULL));
    System frame(480,480);
    frame.set_update_time(1./10.);
    frame.set_bg_color(al_map_rgb(0,0,0));
    frame.generate_particles();

    frame.run();
    return 0;
}