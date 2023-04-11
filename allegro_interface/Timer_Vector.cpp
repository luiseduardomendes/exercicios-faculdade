#include "Timer_Vector.h"

void Timer_Vector::create_timer(std::string timer_id, double clock){
    timers[timer_id] = new Timer(clock);
}

void Timer_Vector::start_timer(std::string timer_id){
    timers[timer_id]->start();
}

void Timer_Vector::stop_timer(std::string timer_id){
    timers[timer_id]->stop();
}

void Timer_Vector::remove_timer(std::string timer_id){
    timers.erase(timer_id);
}

std::string Timer_Vector::check_timer_event(ALLEGRO_EVENT event){
    std::map<std::string, Timer*>::iterator it;

    for (it = this->timers.begin(); it != this->timers.end(); it++){
        if (it->second->check(event)){
            return it->first;
        }
    }
    return "\0";
}

std::vector<ALLEGRO_TIMER*> Timer_Vector::get_timers(){
    std::map<std::string, Timer*>::iterator it;
    std::vector<ALLEGRO_TIMER*> t;

    for (it = this->timers.begin(); it != this->timers.end(); it++){
        t.push_back(it->second->get());
    }
    return t;
}

