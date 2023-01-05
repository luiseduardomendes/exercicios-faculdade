#pragma once
#include "Interface.h"
#include "test_entity_inheritance.h"

class AppInterface : public Interface{
    private:
        Player player;

        void timer_routine(ALLEGRO_EVENT event);
        void keyboard_routine_key_down(ALLEGRO_EVENT event);
        void keyboard_routine_key_up(ALLEGRO_EVENT event);
    public:
        void init();
        void run();
};