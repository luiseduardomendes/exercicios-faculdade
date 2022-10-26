cmake_minimum_required(VERSION 3.10)
project(my_project VERSION 1.0.0)

add_executable(cmake-good main.cpp)
add_library(
    app-controller
    app_controller.hpp
    app_controller.cpp
)
add_library(
    allegro-interface
    allegro_interface.hpp
    allegro_interface.cpp
)
add_library(
    entity
    entity.hpp
    entity.cpp
)
add_library(
    graphics
    graphics.hpp
    graphics.cpp
)


target_link_libraries(cmake-good PRIVATE entity)
target_link_libraries(cmake-good PRIVATE graphics)
target_link_libraries(cmake-good PRIVATE app-controller)
target_link_libraries(cmake-good PRIVATE allegro-interface)
add_compile_options(allegro-5 allegro_font-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_dialog-5 --libs)


