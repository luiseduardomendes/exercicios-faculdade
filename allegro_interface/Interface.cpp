#include "Interface.h"
#include <iostream>

void Interface::create_display(int w, int h, double fps){
    this->width = w;
    this->height = h;
    this->fps = fps;
    this->display = Display(width, height);

    if (!al_init())
        return;
    if (!display.create_display())
        return;
    
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    this->create_timer("__timer_display__", fps);
}

Interface::Interface(){}

bool Interface::is_running(){
    return running;
}

void Interface::init_timers(){
    
    std::map<std::string, Timer*>::iterator it;

    for (it = timers.begin(); it != timers.end(); it ++){
        it->second->init(queue);
        it->second->start();
            
    }   
}