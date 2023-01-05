#include "test_entity_inheritance.h"

void Player::create_bmp(){
    ALLEGRO_DISPLAY* tmp_dsp = al_get_current_display();
    
    this->bmp.create(20,20);
    al_set_target_bitmap(this->bmp.get());
    al_draw_filled_circle(10, 10, 10, al_map_rgb(0x80,0x80,0x80));
    al_draw_circle(10, 10, 9, al_map_rgb(0x40,0x40,0x40), 2);
    al_set_target_backbuffer(tmp_dsp);
}

Player::Player(){
    spd = 2.5;
    mov = Vec(0,0,0);
    pos = Vec(0,0,0);
    looking = Vec(1,0,0);
}      

Player::Player(Vec pos){
    spd = 2.5;
    this->mov = Vec(0,0,0);
    this->pos = pos;
    this->looking = Vec(1,0,0);
}     

void Player::draw(){
    this->bmp.draw(pos);
}