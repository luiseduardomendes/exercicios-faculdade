#include "header.hpp"

using namespace std;

int main(){
    t_scr scr = {1024,576, false};

    Obstacle obs = Obstacle(5);

    Player player = Player();

    if(!al_init())
        cout << "Allegro nao pode ser inicializada" << endl;

    ALLEGRO_DISPLAY *display = NULL;
    if (!(display = al_create_display(scr.width, scr.height)))
        cout << "Display nao pode ser criado" << endl;

    ALLEGRO_TIMER *timer_frame = al_create_timer(1.00/60.0);
    al_start_timer(timer_frame);      

    float speed = 5;  
    
    al_install_keyboard();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_EVENT_QUEUE* eventQueue = al_create_event_queue();

    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer_frame));

    do{
        ALLEGRO_EVENT event;
        al_wait_for_event(eventQueue, &event);

        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            scr.exit = true;

        else if(event.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_SPACE:
                    if(!player.jumping)
                        player.jump();
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    scr.exit = true;
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_TIMER){
            if (event.timer.source == timer_frame){
                if(player.jumping){
                    player.set_fall_speed();
                    if (player.position.y >= 500 && player.fall_speed.y > 0)
                        player.fell();
                }
                if(obs.position.x < 0){
                    speed += 0.5;
                    obs = Obstacle(speed);
                }
                if(abs(player.position.x - obs.position.x) < 5 && abs(player.position.y - obs.position.y) < 5)
                    scr.exit = true;

                obs.move();
                player.move();

                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_filled_rectangle(player.position.x, player.position.y,
                                        player.position.x + 40, player.position.y + 40,
                                        al_map_rgb(255,255,255));
                al_draw_filled_triangle(obs.position.x, obs.position.y + 40,
                                        obs.position.x + 40, obs.position.y + 40,
                                        obs.position.x + 20, obs.position.y,
                                        al_map_rgb(255,255,255));
                al_flip_display();
            }
        }

    } while(!scr.exit);



    return 0;
}