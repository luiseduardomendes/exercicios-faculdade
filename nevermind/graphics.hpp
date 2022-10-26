#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>

#include "entity.hpp"
#include "background.hpp"
#include "allegro.hpp"

using namespace std;

class Graphics_2d{
    private:
        double view_distance;
        double render_distance;
        map<string, vector<vector<Background*>>> backgrounds;
        vector<Entity> entities;
        string current_background_key;
        pair<int, int> current_background_index;

    public:
        Graphics_2d(double range_view, double range_render);
        void set_initial_map(string map_key, int map_index_x, int map_index_y);
        void create_map(string key, int bitmaps_w, int bitmaps_h, int dim_px_w, int dim_px_h, vector<string> asset_paths);


};
