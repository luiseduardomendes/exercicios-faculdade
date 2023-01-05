#include "test_app_interface.h"

void AppInterface::timer_routine(ALLEGRO_EVENT event){
    ALLEGRO_TIMER* source = event.timer.source;
    if (source == this->timers["__timer_display__"]->get()){
        display.clear();
        this->player.draw();
        this->player.move();
        display.show();
    }
}
void AppInterface::keyboard_routine_key_down(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode){
    case ALLEGRO_KEY_W:
        this->player.mov.y += -player.spd;
        break;
    case ALLEGRO_KEY_A:
        this->player.mov.x += -player.spd;
        break;
    case ALLEGRO_KEY_S:
        this->player.mov.y += +player.spd;
        break;
    case ALLEGRO_KEY_D:
        this->player.mov.x += +player.spd;
        break;
    case ALLEGRO_KEY_SPACE:
        break;
    default:
        break;
    }
}
void AppInterface::keyboard_routine_key_up(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode){
    case ALLEGRO_KEY_W:
        this->player.mov.y += player.spd;
        break;
    case ALLEGRO_KEY_A:
        this->player.mov.x += player.spd;
        break;
    case ALLEGRO_KEY_S:
        this->player.mov.y -= player.spd;
        break;
    case ALLEGRO_KEY_D:
        this->player.mov.x -= player.spd;
        break;
    case ALLEGRO_KEY_ESCAPE:
        this->running = false;
        break;
    default:
        break;
    }
}

void AppInterface::init(){
    this->running = true;
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_display_event_source(display.get()));
    al_register_event_source(queue, al_get_keyboard_event_source());
    init_timers();

    player = Player(Vec(this->width/2, this->height/2, 0));
    player.create_bmp();
}
void AppInterface::run(){
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
