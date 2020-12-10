#ifndef TOWN_H
#define TOWN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"

#include <string>


struct Town : Graph_lib::Button
{
public:
    Town(Graph_lib::Point xy, Graph_lib::Callback cb, const std::string name);

    Graph_lib::Point pos;
    Graph_lib::Point center;

    Graph_lib::Circle frame;


    std::string mark;
    bool is_active = false;

    void attach(Graph_lib::Window& win) override;

    void act();

};



#endif


