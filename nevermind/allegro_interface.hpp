#include "allegro.hpp"
#include <vector>
#include <map>
#include <string>
#include <functional>

#include "camera.hpp"
#include "app_controller.hpp"

using namespace std;

class Allegro_interface{
    private:
        ALLEGRO_DISPLAY* Display;
        Camera* camera;
        Graphics_2d *graphics;
        map<string, ALLEGRO_TIMER*> timers;
        App_controller app_controller;
        void timer_event(ALLEGRO_EVENT event);
        void keyboard_event(ALLEGRO_EVENT event);
        void verify_event(ALLEGRO_EVENT event);
    public:
        
        Allegro_interface(int disp_w, int disp_h, int fps, double render);
        void end_app();
        void create_timer(double period, string timer_name);
        void create_map(int bitmap_size_w, int bitmap_size_h, vector<string> bitmaps_file_path, int num_bitmaps_w, int num_bitmaps_h);
        void run_app();
};