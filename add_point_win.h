#ifndef ADD_WIN_H
#define ADD_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "town.h"

//#include "Navig_win.h"  ->  cycle with no ending


struct Add_window: Graph_lib::Window
{
    Add_window();

    Graph_lib::Button close_add_button;
    Graph_lib::Button add_button;

    bool cancel_clicked = false;
    bool add_clicked = false;
    bool get_point(int& x, int& y, std::string& name);
//    bool ptr_get_point(Town* added); //, void* cb_clicked(Graph_lib::Address widget, Graph_lib::Address win));
    void wait_for_button();

    Graph_lib::In_box X;
    Graph_lib::In_box Y;
    Graph_lib::In_box Name;




private:
    static void cb_close_add (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Add_window> (addr).hide_add(); }
    static void cb_add (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Add_window> (addr).add(); }
    void hide_add();
    void add();
};



#endif
