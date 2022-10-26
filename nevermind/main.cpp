#include "allegro_interface.hpp"
#include <functional>

using namespace::std;

int main(){
    Allegro_interface app(640,480,60,10);
    app.run_app();
    return 0;
}

