#ifndef NAVIG_WIN_H
#define NAVIG_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "add_point_win.h"


struct Navig_window: Graph_lib::Window
{
    Navig_window(Graph_lib::Point xy, int w, int h, const std::string title);

    Graph_lib::Button quit_button;
    Graph_lib::Button menu_button;

    Graph_lib::Button find_way_button;
    Graph_lib::Button add_point_button;
    Graph_lib::Button close_menu_button;

    Graph_lib::Rectangle map{{map_margin, map_margin}, map_width, map_height};

    bool add_active = false;

    Add_window add_p_win;

private:
    static void cb_quit(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).quit(); }
    static void cb_menu(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).menu(); }
    static void cb_close_menu (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).hide_menu(); }
    static void cb_add_point(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).add_point(); }
    static void cb_find_way(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).find_way(); }
    void quit();
    void menu();
    void show_menu();
    void hide_menu();
    void add_point();
    void find_way();

};



#endif
