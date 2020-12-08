#include "town.h"

Town::Town(Graph_lib::Point xy, Graph_lib::Callback cb, std::string name)
    : Graph_lib::Button{xy, town_size, town_size, name, cb}, pos{xy}, mark{ name },
      center{xy.x + town_size/2, xy.y + town_size/2},
      frame{center, town_rad}
      {}


void Town::act()
{
    if(is_active)
    {
        frame.set_color(Graph_lib::Color::black);
        is_active = false;
    }
    else
    {
        frame.set_color(Graph_lib::Color::red);
        is_active = true;
    }

}

void Town::attach (Graph_lib::Window& win)
{
    Button::attach (win);
}
