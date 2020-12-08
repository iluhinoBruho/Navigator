#ifndef NAVIG_WIN_H
#define NAVIG_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "Add_win.h"
#include "town.h"
#include "road.h"
#include "Logics.h"
#include "axis.h"


struct Navig_window: Graph_lib::Window
{
    Navig_window(Graph_lib::Point xy, int w, int h, const std::string title);

    Graph_lib::Button quit_button;
    Graph_lib::Button menu_button;

    Graph_lib::Button find_way_button;
    Graph_lib::Button add_point_button;
    Graph_lib::Button add_road_button;
    Graph_lib::Button close_menu_button;
    Graph_lib::Button add_roads_mode;

    Graph_lib::Text add_roads_is_active;

    Axis_imp X{Axis_imp::Orientation::x, start_map, map_width, 10, "X"};
    Axis_imp Y{Axis_imp::Orientation::y, start_map, map_height, 8, "Y"};
    Graph_lib::Rectangle map{start_map, map_width, map_height};


    Find_way_window find_way_win;
    Add_point_window add_p_win;
    Add_road_window add_road_win;
    Graph_lib::Vector_ref<Town> towns;
    Graph_lib::Vector_ref<Road> roads;
    Matrix graph;


    void update_map(bool deflt = false);

    void draw_way(std::vector<std::string> path);

    //only for testing
    void clicked_test(Graph_lib::Address widget) { clicked(widget); }
    Town* get_town_test(std::string name) { get_town_ptr(name); }
private:
    static void cb_clicked(Graph_lib::Address widget, Graph_lib::Address win) { Graph_lib::reference_to<Navig_window>(win).clicked(widget); }
    static void cb_quit(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).quit(); }
    static void cb_menu(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).menu(); }
    static void cb_close_menu (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).hide_menu(); }
    static void cb_add_point(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).add_point(); }
    static void cb_add_road(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).add_road(); }
    static void cb_find_way(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).find_way(); }
    static void cb_adding_roads_mode(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).adding_roads_mode(); }


    void clicked(Graph_lib::Address widget);
    void quit();
    void menu();
    void show_menu();
    void hide_menu();
    void add_point();
    void add_road();
    void remove_point();
    void find_way();
    void adding_roads_mode();

    bool town_exists(std::string s) const;
    bool bad_coordinates(int x, int y) const;

    Town& get_town(std::string name);
    Town* get_town(int x, int y);
    Town* get_town_ptr(std::string name);
    Road* get_road(Graph_lib::Point first, Graph_lib::Point second);

    bool Adding_mode = false;
    int cnt_cliked;
    Town* ptr_last_click;

};



#endif
