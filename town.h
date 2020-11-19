#ifndef TOWN_H
#define TOWN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"

#include <string>


class Town : public Graph_lib::Button
{
public:
    Town(Graph_lib::Point xy, Graph_lib::Callback cb, const std::string name);
    ~Town(){ };

    std::string mark;
    bool is_active = false;

    void attach(Graph_lib::Window& win) override;

private:
    void remove(std::string s);
    void clicked();
};



#endif


