#include "test.h"

void cb_test(Graph_lib::Address widget, Graph_lib::Address win) { Graph_lib::reference_to<Navig_window>(win).clicked_test(widget); }

void test(Navig_window& win)
{
    std::vector<Graph_lib::Point> test_towns = {{100, 100}, {200, 200}, {200, 400}, {150, 300}, {500, 150}, {600, 450}, {450, 450}, {500, 230}, {700, 50}, {650, 240}};
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        std::string name = std::to_string(i + 1);
        win.towns.push_back(new Town(test_towns[i], cb_test, name));
        win.graph.add_vertex(name);
        win.attach(win.towns[i]);
        win.attach(win.towns[i].frame);
    }
    win.redraw();
}
