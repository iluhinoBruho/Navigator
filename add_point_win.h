#ifndef ADD_WIN_H
#define ADD_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "Globals.h"
#include "town.h"

//#include "Navig_win.h"  ->  cycle with no ending


struct Add_window: Graph_lib::Window
{
    Add_window();

    Graph_lib::Button close_add_button;


private:
    static void cb_close_add (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Add_window> (addr).hide_add(); }
    void hide_add();
};



#endif
