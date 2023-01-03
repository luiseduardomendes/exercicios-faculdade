#pragma once

#include "allegro_depends.h"

class Timer{
    private:
        ALLEGRO_TIMER* timer;
    
    public:
        Timer();
        Timer(double clock);

        void init(ALLEGRO_EVENT_QUEUE* queue);
        void start();
        void stop();

        bool check(ALLEGRO_EVENT event);
        ALLEGRO_TIMER* get();
};