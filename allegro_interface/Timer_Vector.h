#pragma once

#include "allegro_depends.h"
#include "Timer.h"
#include <vector>
#include <map>

class Timer_Vector{
    protected:
        std::map<std::string, Timer*> timers;
        

    public:
        void create_timer(std::string timer_id, double clock);
        void start_timer(std::string timer_id);
        void stop_timer(std::string timer_id);
        void remove_timer(std::string timer_id);

        virtual void timer_routine(ALLEGRO_EVENT event) = 0;

        std::string check_timer_event(ALLEGRO_EVENT event);
        std::vector<ALLEGRO_TIMER*> get_timers();
};