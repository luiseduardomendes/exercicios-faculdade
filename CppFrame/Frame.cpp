#include "Frame.hpp"
#define dbg() std::cout << "hello" << std::endl

graph::Frame::Frame(int w, int h){
    this->w = w;
    this->h = h;

    create_frame();
}

graph::Frame::Frame(){
    this->w = 480;
    this->h = 480;

    create_frame();
}

void graph::Frame::create_frame(){
    this->__is_running__ = true;

    al_init();
    this->display = al_create_display(w, h);
    this->init_allegro();
}

void graph::Frame::set_bg_color(ALLEGRO_COLOR color){
    this->bg_color = color;
}

void graph::Frame::reset_display(){
    al_clear_to_color(this->bg_color);
}

void graph::Frame::set_display(){
    al_flip_display();
}

void graph::Frame::sleep(float seconds){
    sleep(seconds);

}

void graph::Frame::init_allegro(){
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(this->display));
}


bool graph::Frame::is_running(){
    return this->__is_running__;
}

void graph::Frame::destroy_display(){
    al_destroy_display(this->display);
    this->__is_running__ = false;
}

void graph::Frame::run(){
    al_wait_for_event(this->queue, &ev);
    event_active();
}

void graph::Frame::set_update_time(float time){
    this->timer = al_create_timer(time);
    al_start_timer(this->timer);
    al_register_event_source(this->queue, al_get_timer_event_source(this->timer));
}

void  graph::Frame::event_active(){
    
    if (this->ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
        this->destroy_display();
    }
    else if (this->ev.type == ALLEGRO_EVENT_TIMER){
        if (this->ev.timer.source == this->timer){
            
        }
    }
}

float graph::randf(float min, float max){
    
    return float(rand()/RAND_MAX) * (max - min) + min;
}

int graph::randi(int min, int max){
    
    return rand() % (max - min) + min;
}