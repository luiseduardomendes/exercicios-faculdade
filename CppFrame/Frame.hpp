#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <bits/stdc++.h>

namespace graph{
    class Frame{
    private:
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *queue;
        ALLEGRO_COLOR bg_color;
        ALLEGRO_TIMER *timer;
        
        int w, h;
        bool __is_running__;
        void init_allegro();

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
        void event_active(); 
    };
    class Draw{
    public:
        void draw_point(float x, float y, ALLEGRO_COLOR color){
            al_draw_pixel(x, y, color);
        }
    };
    class Color{
    public:
        ALLEGRO_COLOR light_blue = al_map_rgb(52, 152, 219);
        ALLEGRO_COLOR green_water = al_map_rgb(72, 201, 176);
        ALLEGRO_COLOR green = al_map_rgb(46, 124, 113);
        ALLEGRO_COLOR ocean_blue = al_map_rgb(21, 67, 96);
        ALLEGRO_COLOR dark_red = al_map_rgb(176, 58, 46);
        ALLEGRO_COLOR white = al_map_rgb(255,255,255);
        ALLEGRO_COLOR black = al_map_rgb(0,0,0);
        
        ALLEGRO_COLOR color(int r, int g, int b){
            return al_map_rgb(r, g, b);
        }
    };
    float randf(float min, float max);
    int randi(int min, int max);

} // namespace Frame
