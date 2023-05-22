#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <bits/stdc++.h>

namespace graph{
    class Frame{
    private:
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *queue;
        bool __is_running__;
        int w, h;
        void init_allegro();

    protected:
        ALLEGRO_TIMER *timer;
        ALLEGRO_COLOR bg_color;
        double dt;    

    public:
        ALLEGRO_EVENT ev;
        Frame();
        Frame(int w, int h);

        void set_update_time(float time);
        void set_bg_color(ALLEGRO_COLOR color);
        void reset_display();
        void set_display();
        void create_frame();
        void sleep(float);
        bool is_running();
        void destroy_display();
        void run();
        virtual void event_active(); 
        virtual void timer_update();
    };
    class Draw{
    public:
        void draw_point(float x, float y, ALLEGRO_COLOR color){
            al_draw_pixel(x, y, color);
        }
        void draw_circle(float x, float y, float r, ALLEGRO_COLOR color){
            al_draw_filled_circle(x, y, r, color);
        }
    };
    
    float randf(float min, float max);
    int randi(int min, int max);

} // namespace Frame
