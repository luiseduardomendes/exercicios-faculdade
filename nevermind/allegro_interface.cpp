#include "allegro_interface.hpp"

Allegro_interface::Allegro_interface(int disp_w, int disp_h, int fps, double render){
    if (!al_init())
        return;
    if (!(this->camera->create_display(disp_w, disp_h)))
        return;
    
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    this->graphics = new Graphics_2d(render, 10);

    this->create_timer(1.0/fps, "_draw_");
}

void Allegro_interface::create_timer(double period, string timer_name){
    timers[timer_name] = al_create_timer(period);
    al_start_timer(timers[timer_name]);
}

void Allegro_interface::run_app(){
    ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();

    al_register_event_source(eventQueue, al_get_display_event_source(this->Display));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    for (auto it : this->timers)
        al_register_event_source(eventQueue, al_get_timer_event_source(it.second));
    
    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);
        
        this->verify_event(event);
        
    } while (this->app_controller.is_running());
}

void Allegro_interface::verify_event(ALLEGRO_EVENT event){
    switch (event.type){
        case (ALLEGRO_EVENT_DISPLAY_CLOSE):
            this->app_controller.end_app();
            break;  
        case (ALLEGRO_KEY_DOWN):
            this->keyboard_event(event);
            break;
        case (ALLEGRO_EVENT_TIMER):
            this->timer_event(event);
            break;
    }
}

void Allegro_interface::keyboard_event(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode){
    case ALLEGRO_KEY_ESCAPE:
        this->app_controller.end_app();
        break;
    }
}

void Allegro_interface::timer_event(ALLEGRO_EVENT event){
    ALLEGRO_TIMER* source = event.type.source;
    
}