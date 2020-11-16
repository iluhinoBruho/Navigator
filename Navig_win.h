#ifndef NAVIG_WIN_H
#define NAVIG_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"


struct Navig_window: Graph_lib::Window
{
    Navig_window(Graph_lib::Point xy, int w, int h, const std::string title);

    Graph_lib::Button quit_button;
    Graph_lib::Button menu_button;

    Graph_lib::Rectangle map{{map_margin, map_margin}, map_width, map_height};

private:
    static void cb_quit(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).quit(); }
    static void cb_menu(Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Navig_window> (addr).menu(); }
    void quit() { hide(); }
    void menu();

};



#endif
