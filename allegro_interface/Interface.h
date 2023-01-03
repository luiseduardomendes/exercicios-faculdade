#pragma once
#include "allegro_depends.h"
#include "Keyboard.h"
#include "Display.h"
#include "Timer.h"
#include "Timer_Vector.h"
#include <stdarg.h>

class Interface : public Timer_Vector{
    protected:
        Display display;
        //Keyboard Keyboard;

        int width, height;
        double fps;

        bool running;

        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE *queue;

    public:
        Interface();
        virtual void run() = 0; 
        virtual void init() = 0; 
        void create_display(int w, int h, double fps);
        void init_timers();

        bool is_running();
        
};