#include "road.h"

#include <iostream>
Road::Road(Graph_lib::Point a, Graph_lib::Point b,  std::string name_a, std::string name_b)
    : Line(get_coords(a,b).first, get_coords(a,b).second),
      first_point{a},
      second_point{b},
      name_first{name_a},
      name_second{name_b}
{

}

std::pair<Graph_lib::Point, Graph_lib::Point> Road::get_coords(Graph_lib::Point a, Graph_lib::Point b)
{



    std::pair<Graph_lib::Point, Graph_lib::Point> res{a, b};

    double dist = distance(a, b);
    double k = town_rad / dist;

    double abcos = abs(b.x - a.x) / dist;
    double absin = abs(a.y - b.y) / dist;

    int dx = static_cast<int>(double(town_size) * pow(2, 0.5) / 2 * abcos);
    int dy = static_cast<int>(double(town_size) * pow(2, 0.5)  / 2 * absin);


    if(a.x >= b.x && a.y >= b.y)
    {
        res.first.x -= dx;
        res.first.y -= dy;

        res.second.x += dx;
        res.second.y += dy;

    }
    else if(a.x >= b.x && a.y < b.y)
    {
        res.first.x -= dx;
        res.first.y += dy;

        res.second.x += dx;
        res.second.y -= dy;
    }
    else if(a.x < b.x && a.y >= b.y)
    {

        res.first.x += dx;
        res.first.y -= dy;

        res.second.x -= dx;
        res.second.y += dy;
    }
    else if(a.x < b.x && a.y < b.y)
    {
        res.first.x += dx;
        res.first.y += dy;

        res.second.x -= dx;
        res.second.y -= dy;
    }


    return res;

}


//void Road::attach (Graph_lib::Window& win)
//{
//    Button::attach (win);
//}
