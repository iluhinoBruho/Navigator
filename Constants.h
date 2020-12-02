#ifndef CONST_H
#define CONST_H

#include "../Graph_lib/Graph.h"
#include <string>
#include <map>

//main_win
const Graph_lib::Point win_corner{100, 100};
constexpr int win_width = 1000;
constexpr int win_height = 600;
const std::string main_name = "Navigator";

//add_win
constexpr int win_add_w = 400;
constexpr int win_add_h = 260;
const std::string add_name = "Add point";

//map
constexpr int map_margin = 20;
constexpr int map_width = int(win_width*0.8);
constexpr int map_height = int(win_height * 0.93);

//town
const int town_size = 50;

//logics
const int INF = win_height * win_width;  //INTMAX_MAX;

#endif
