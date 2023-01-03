#include "entity.h"
#include <vector>

class Player : public Entity{
    private:
        void create_bmp(){
            ALLEGRO_DISPLAY* tmp_dsp = al_get_current_display();
            ALLEGRO_BITMAP* tmp_bmp =  al_create_bitmap(20, 20);
            al_set_target_bitmap(this->bmp.get());
            al_draw_filled_circle(5, 5, 5, al_map_rgb(0x80,0x80,0x80));
            al_draw_circle(5, 5, 5, al_map_rgb(0x40,0x40,0x40), 2);
            al_set_target_backbuffer(tmp_dsp);
        }

    public:
        Vec pos, mov, looking;
                
        Player(){
            mov = Vec(0,0,0);
            pos = Vec(0,0,0);
            looking = Vec(1,0,0);
            
            create_bmp();
        }      
        Player(Vec pos){
            this->mov = Vec(0,0,0);
            this->pos = pos;
            this->looking = Vec(1,0,0);

            create_bmp();
        }     
        
        void draw(){
            this->bmp.draw(pos);
        }
};