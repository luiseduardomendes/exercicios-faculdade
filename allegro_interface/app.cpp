#include "Interface.h"
#include "Shape.h"
#include <cmath>
#include <string>
#include <iostream>
#include "linear_algebra.h"


class Projectile{
    public:
        Vec pos, mov;
        Shape s;
        double spd, radius;
        ALLEGRO_COLOR color;

        Projectile(Vec pos, Vec mov){
            spd = 2.5;
            this->mov = mov * spd;
            this->pos = pos;
            radius = 3;
            color = al_map_rgb(0xff,0xff,0xff);
        }
        Projectile(){}
        void draw(){
            s.circle(pos.x, pos.y, radius, color);
        }
        void inc_pos(){
            pos.x += mov.x;
            pos.y += mov.y;
            pos.z += mov.z;
        }
};

class Circle{
    private:
    public:
        double dash_cooldown;
        bool dash_up;

        Vec pos, mov, looking;
        std::vector<Projectile> proj;

        double radius, spd;
        ALLEGRO_COLOR color, color_border;
        Shape s;
        
        Circle(){
            spd = 2.5;
            mov = Vec(0,0,0);
            pos = Vec(0,0,0);
            looking = Vec(1,0,0);
            radius = 10;
            color = al_map_rgb(0x80,0x80,0x80);
            color_border = al_map_rgb(0x40,0x40,0x40);
        }      
        Circle(Vec pos){
            spd = 2.5;
            mov = Vec(0,0,0);
            looking = Vec(1,0,0);
            this->pos = pos;
            radius = 10;
            color = al_map_rgb(0x80,0x80,0x80);
            color_border = al_map_rgb(0x40,0x40,0x40);
        }     
        void draw(){
            s.circle(pos.x, pos.y, radius, color);
            s.circle(pos.x, pos.y, radius, radius/5, color_border);
            al_draw_line(pos.x, pos.y, pos.x + looking.x*20, pos.y + looking.y*20, al_map_rgb(0x80,0,0), 3);
            for (auto it : proj)
                it.draw();
        }
        void inc_pos(){
            pos.x += mov.x;
            pos.y += mov.y;
            pos.z += mov.z;
            if (!(mov == 0)){
                looking = mov.unit();
            }
            inc_proj();
        }
        void inc_proj(){
            std::vector<std::vector<Projectile>::iterator> temp;
            std::vector<Projectile>::iterator it;
            for (it = proj.begin(); it != proj.end(); it ++){
                it->inc_pos();
                if (it->pos.x > 10000 || it->pos.y > 10000 || it->pos.x < 0 || it->pos.y < 0){
                    temp.push_back(it);
                }
            }
            for (auto i : temp)
                proj.erase(i);
        }
        void shot_proj(){
            proj.push_back(Projectile(pos, looking));
        }
};

class AppInterface : public Interface{
    private:
        Circle c;
        void timer_routine(ALLEGRO_EVENT event){
            ALLEGRO_TIMER* source = event.timer.source;
            if (source == this->timers["__timer_display__"]->get()){
                display.clear();
                this->c.draw();
                this->c.inc_pos();
                display.show();
            }
            else if (source == this->timers["dash_timer"]->get()){
                this->c.mov = c.mov/3;
                this->timers["dash_timer"]->stop();
            }
            else if (source == this->timers["dash_cooldown"]->get()){
                this->c.dash_up = true;
                this->timers["dash_cooldown"]->stop();
            }
        }
        void keyboard_routine_key_down(ALLEGRO_EVENT event){
            switch (event.keyboard.keycode){
            case ALLEGRO_KEY_W:
                this->c.mov.y = -c.spd;
                break;
            case ALLEGRO_KEY_A:
                this->c.mov.x = -c.spd;
                break;
            case ALLEGRO_KEY_S:
                this->c.mov.y = +c.spd;
                break;
            case ALLEGRO_KEY_D:
                this->c.mov.x = +c.spd;
                break;
            case ALLEGRO_KEY_SPACE:
                break;
            default:
                break;
            }
        }
        void keyboard_routine_key_up(ALLEGRO_EVENT event){
            switch (event.keyboard.keycode){
            case ALLEGRO_KEY_W:
                this->c.mov.y += c.spd;
                break;
            case ALLEGRO_KEY_A:
                this->c.mov.x += c.spd;
                break;
            case ALLEGRO_KEY_S:
                this->c.mov.y -= c.spd;
                break;
            case ALLEGRO_KEY_D:
                this->c.mov.x -= c.spd;
                break;
            case ALLEGRO_KEY_ESCAPE:
                this->running = false;
                break;
            case ALLEGRO_KEY_E:
                this->c.shot_proj();
                break;
            case ALLEGRO_KEY_SPACE:
                this->timers["dash_timer"]->start();
                this->timers["dash_cooldown"]->start();
                this->c.mov = c.mov * 3;
                this->c.dash_up = false;
                break;
            default:
                break;
            }
        }
    public:
        void init(){
            this->running = true;
            queue = al_create_event_queue();
            al_register_event_source(queue, al_get_display_event_source(display.get()));
            al_register_event_source(queue, al_get_keyboard_event_source());
            init_timers();

            c = Circle(Vec(this->width/2, this->height/2, 0));
        }
        void run(){
            al_wait_for_event(queue, &event);
            if (event.type == ALLEGRO_EVENT_TIMER)
                this->timer_routine(event);
            else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                this->running = false;
            else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
                this->keyboard_routine_key_down(event);
            else if (event.type == ALLEGRO_EVENT_KEY_UP)
                this->keyboard_routine_key_up(event);
            
        }
};

int main(){
    Circle circle;
    AppInterface app;
    app.create_display(640, 480, 1.0/60.0);
    app.create_timer("dash_timer", 1);
    app.create_timer("dash_cooldown", 5);
    app.init();
    while (app.is_running()){
        app.run();
    }
    return 0;   
}