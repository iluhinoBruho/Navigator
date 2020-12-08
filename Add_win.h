#ifndef ADD_WIN_H
#define ADD_WIN_H


#include "../Graph_lib/Simple_window.h"
#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include "town.h"

#include <string>


struct Add_window: Graph_lib::Window
{
    Add_window(const std::string& confirm_button_name = "confirm", const std::string& win_name = "");
    
    
    Graph_lib::Button close_add_button;
    Graph_lib::Button add_button;

    bool cancel_clicked = false;
    bool add_clicked = false;

    void wait_for_button();


private:
    static void cb_close_add (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Add_window> (addr).hide_add(); }
    static void cb_add (Graph_lib::Address, Graph_lib::Address addr) { Graph_lib::reference_to<Add_window> (addr).add(); }
    void hide_add();
    void add();
};


struct Add_road_window: Add_window
{
    Add_road_window();

    Graph_lib::In_box Name_a;
    Graph_lib::In_box Name_b;


    bool get_names(std::string& a, std::string& b);
};

struct Add_point_window: Add_window
{
    Add_point_window(std::string win_name = "Add town");

    //std::string win_name = "Add town";

    Graph_lib::In_box X;
    Graph_lib::In_box Y;
    Graph_lib::In_box Name;

    bool get_point(int& x, int& y, std::string& name);

};

struct Find_way_window : Add_window
{
    Find_way_window();

    Graph_lib::In_box Name_a;
    Graph_lib::In_box Name_b;

    bool get_names(std::string& a, std::string& b);
};

#endif
