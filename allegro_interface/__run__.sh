#!/bin/sh
g++ app.cpp -O2 Display.cpp Interface.cpp Keyboard.cpp Shape.cpp Timer_Vector.cpp Timer.cpp $(pkg-config --libs allegro-5 allegro_font-5  allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_dialog-5 --cflags) -lm -o _out_
./_out_