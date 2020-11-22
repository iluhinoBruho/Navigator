#include "town.h"

#include <iostream>
Town::Town(Graph_lib::Point xy, Graph_lib::Callback cb, std::string name)
    :Graph_lib::Button{xy, town_size, town_size, /*"click"*/ name, cb}, pos{xy}, mark{ name }
{
    std::cerr << name << " got the name" << std::endl;
}


void Town::attach (Graph_lib::Window& win)
{
    Button::attach (win);
}
