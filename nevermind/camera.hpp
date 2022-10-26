#include "graphics.hpp"
#include <vector>

class Camera{
    private:
        pair<int, int> px;
        pair<int, int> pos;
        pair<int, int> disp;
        ALLEGRO_DISPLAY *display;
        double zoom;

    public:    
        Camera(int disp_w, int disp_h, int px_w, int px_h, int start_w, int start_h, double range_view, double range_render);
        bool create_display(int w, int h);
        void zoom_in();
        void zoom_out();

};