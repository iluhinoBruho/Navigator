#include "add_point_win.h"

Add_window::Add_window()
    : Window{ {win_corner.x + 150, win_corner.y + 150}, win_add_w, win_add_h, add_name },
      close_add_button{ Graph_lib::Point{x_max() - 100 - 5, 45}, 100, 35, "cancel", cb_close_add },
      add_button{ Graph_lib::Point{x_max() - 100 - 5, 5}, 100, 35, "add", cb_add },
      X{Graph_lib::Point{60,75}, 60, 30, "X : "},
      Y{Graph_lib::Point{160,75}, 60, 30, "Y : "},
      Name{Graph_lib::Point{60,40}, 160, 30, "Town : "}

{
    attach(Name);
    attach(add_button);
    attach(close_add_button);
    attach(X);
    attach(Y);

//    Doesn't work for some reason
//    Graph_lib::Text descr{{15, 15}, "DESCRIPTION"};
//    attach(descr);
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


bool Add_window::get_point(int& x, int& y, std::string& name)
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

//bool Add_window::ptr_get_point(Town* added) //,  void* cb(Graph_lib::Address widget, Graph_lib::Address win))
//{
//    show();
//    wait_for_button();

//    if(add_clicked)
//    {
//        //Town
//        int x = X.get_int();
//        int y = Y.get_int();
//        std:: string name = Name.get_string();

//        added->pos.x = x;
//        added->pos.y = x;
//        added->mark = name;
//        added->move(x, y)

//        //added = new Town{{x, y}, *cb, name };

//        add_clicked = false;
//        return true;
//    }


//    cancel_clicked = false;
//    return false;
//}


void Add_window::wait_for_button()
{
    while(!cancel_clicked && !add_clicked)
        Fl::wait();

}
