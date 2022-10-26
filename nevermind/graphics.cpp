#include "graphics.hpp"
#include "entity.hpp"

Graphics_2d::Graphics_2d(double range_view, double range_render){
    this->view_distance = range_view;
    this->render_distance = range_render;
    
    this->current_background_key = "";
}

void Graphics_2d::create_map(string key, int bitmaps_w, int bitmaps_h, int dim_px_w, int dim_px_h, vector<string> asset_paths){
    auto it = asset_paths.begin();
    vector<Background*> temp;
    for (int i = 0; i < bitmaps_h; i ++){
        temp.clear();
        for (int j = 0; j < bitmaps_w; j ++){
            temp.push_back(new Background(*(it++), dim_px_w, dim_px_h));
        }
        this->backgrounds[key].push_back(temp);
    }
}

void Graphics_2d::set_initial_map(string map_key, int map_index_x, int map_index_y){
    this->current_background_key = map_key;
    this->current_background_index.first = map_index_x;
    this->current_background_index.second = map_index_y;
}