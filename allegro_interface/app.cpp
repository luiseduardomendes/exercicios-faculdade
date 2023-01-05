#include "Interface.h"
#include "Shape.h"
#include <cmath>
#include <string>
#include <iostream>
#include "linear_algebra.h"
#include "test_entity_inheritance.h"
#include "test_app_interface.h"

int main(){
    AppInterface app;
    app.create_display(640, 480, 1.0/60.0);
    app.init();
    while (app.is_running()){
        app.run();
    }
    return 0;   
}