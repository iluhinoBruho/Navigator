#include "add_point_win.h"

Add_window::Add_window(const std::string& confirm_button_name, const std::string& win_name)
    : Window{ {win_corner.x + 150, win_corner.y + 150}, win_add_w, win_add_h, win_name },
      close_add_button{ Graph_lib::Point{x_max() - 100 - 10, 50}, 100, 35, "cancel", cb_close_add },
      add_button{ Graph_lib::Point{x_max() - 100 - 10, 10}, 100, 35, confirm_button_name, cb_add }

{
    attach(add_button);
    attach(close_add_button);
}


void Add_window::hide_add()
{
    cancel_clicked = true;
    hide();
}

void Add_window::add()
{
    add_clicked = true;
    hide();
}

void Add_window::wait_for_button()
{
    while(!cancel_clicked && !add_clicked)
        Fl::wait();

}




Add_road_window::Add_road_window()
    : Add_window("Add", add_r_win_name),
      Name_a{Graph_lib::Point{95,40}, 160, 30, "Depature    : "},
      Name_b{Graph_lib::Point{95,80}, 160, 30, "Destination : "}
{
    attach(Name_a);
    attach(Name_b);
}


Add_point_window::Add_point_window(std:: string win_name)
    : Add_window("Add", add_t_win_name),
      X{Graph_lib::Point{60,75}, 60, 30, "X : "},
      Y{Graph_lib::Point{160,75}, 60, 30, "Y : "},
      Name{Graph_lib::Point{60,40}, 160, 30, "Town : "}

{
    attach(Name);
    attach(X);
    attach(Y);

}

Find_way_window::Find_way_window()
    : Add_window("Find", find_w_win_name),
      Name_a{Graph_lib::Point{95,40}, 160, 30, "Depature    : "},
      Name_b{Graph_lib::Point{95,80}, 160, 30, "Destination : "}
{
    attach(Name_a);
    attach(Name_b);
}


bool Add_point_window::get_point(int& x, int& y, std::string& name)
{
    show();
    wait_for_button();

    if(add_clicked)
    {
        //Town
        x = X.get_int();
        y = Y.get_int();
        name = Name.get_string();

        add_clicked = false;
        return true;
    }


    cancel_clicked = false;
    return false;

}

bool Add_road_window::get_names(std::string& name_a, std::string& name_b)
{
    show();
    wait_for_button();

    if(add_clicked)
    {
        //Towns names
        name_a = Name_a.get_string();
        name_b = Name_b.get_string();

        add_clicked = false;
        return true;
    }


    cancel_clicked = false;
    return false;

}

bool Find_way_window::get_names(std::string& name_a, std::string& name_b)
{
    show();
    wait_for_button();

    if(add_clicked)
    {
        //Towns names
        name_a = Name_a.get_string();
        name_b = Name_b.get_string();

        add_clicked = false;
        return true;
    }


    cancel_clicked = false;
    return false;

}


