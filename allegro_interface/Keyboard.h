#pragma once

#include "allegro_depends.h"

class Keyboard{
    private:
    public:
        virtual void pressed_w()=0;
        virtual void pressed_a()=0;
        virtual void pressed_s()=0;
        virtual void pressed_d()=0;
        virtual void pressed_space()=0;
        virtual void pressed_escape()=0;
        virtual void pressed_enter()=0;
};