#ifndef ROAD_H
#define ROAD_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "Logics.h"
#include <cmath>
#include <string>

struct Road : Graph_lib::Line
{
    Road(Graph_lib::Point a, Graph_lib::Point b,  std::string name_a, std::string name_b);

    Graph_lib::Point first_point;
    Graph_lib::Point second_point;

    std::string name_first;
    std::string name_second;

private:
    std::pair<Graph_lib::Point, Graph_lib::Point> get_coords(Graph_lib::Point a, Graph_lib::Point b);

};



#endif


