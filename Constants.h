#ifndef CONST_H
#define CONST_H

#include "../Graph_lib/Graph.h"
#include <string>

#include <cmath>
#include <map>

//main_win
const Graph_lib::Point win_corner{100, 100};
constexpr int win_width = 1024;
constexpr int win_height = 600;
const std::string main_name = "Navigator";

//add_win
constexpr int win_add_w = 400;
constexpr int win_add_h = 260;
const std::string add_r_win_name = "Add road";
const std::string add_t_win_name = "Add town";
const std::string find_w_win_name = "Find way";


//map
constexpr int map_margin = 20;
constexpr int map_width = 800;//int(win_width*0.8);
constexpr int map_height = 560;//int(win_height * 0.93);
const Graph_lib::Point start_map{map_margin + 20, map_margin};

//town
const int town_size = 50;
const int town_rad = static_cast<int>(pow(2, 0.5) * town_size / 2);

//logics
const int INF = win_height * win_width;  //INTMAX_MAX;

#endif
