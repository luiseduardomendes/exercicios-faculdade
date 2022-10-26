#include "camera.hpp"

Camera::Camera(int disp_w, int disp_h, int px_w, int px_h, int start_w, int start_h, double range_view, double range_render){
    this->zoom = 1;
    this->px.first = px_w;
    this->px.second = px_h;
    this->disp.first = disp_w;
    this->disp.second = disp_h;
    this->pos.first = start_w;
    this->pos.second = start_h;    
}

bool Camera::create_display(int w, int h){
    this->display = al_create_display(w, h);
    return this->display != NULL;
}

void Camera::zoom_in(){
    this->zoom /= 0.1;
}

void Camera::zoom_out(){
    this->zoom *= 0.1;
}