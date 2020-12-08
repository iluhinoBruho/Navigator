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

//    std::string name_a, name_b;
//    name_a = "4";
//    for(int i = 0; i < 3; ++i)
//    {
//        name_b = std::to_string(i + 1);
//        std::cout << win.get_town_test(name_a) << std::endl;
//        //std::cout << win.get_town_test(name_a)->center.x << std::endl;
//        //double road_length = distance(win.get_town_test(name_a).center, win.get_town_test(name_b).center);
//        win.graph.add_edge(name_a, name_b, 11);//road_length);
//        //win.roads.push_back(new Road((, (win.get_town_test(name_b))->center, name_a, name_b));
//    }

    win.redraw();
}
