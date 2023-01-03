#include "Timer.h"

Timer::Timer(){
    this->timer = al_create_timer(1.0/60.0);
}

Timer::Timer(double clock){
    this->timer = al_create_timer(clock);
}

bool Timer::check(ALLEGRO_EVENT event){
    return event.timer.source == this->timer;
}

void Timer::init(ALLEGRO_EVENT_QUEUE *queue){
    al_register_event_source(queue, al_get_timer_event_source(this->timer));
}

void Timer::start(){
    al_start_timer(this->timer);
}

void Timer::stop(){
    al_stop_timer(this->timer);
}

ALLEGRO_TIMER* Timer::get(){
    return timer;
}