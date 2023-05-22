g++ orbit.cpp Frame.cpp Entity.cpp Particle.cpp Vec.cpp $(pkg-config --libs allegro-5 allegro_font-5 allegro_primitives-5 --cflags)
./a.out