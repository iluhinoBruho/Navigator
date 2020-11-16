#include "Navig_win.h"

Navig_window::Navig_window(Graph_lib::Point xy, int w, int h, const std::string title)
    : Window{ xy, w, h, title },
      quit_button{ Graph_lib::Point{x_max() - 120 - 15, 15}, 120, 40, "Quit", cb_quit },
      menu_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Menu", cb_menu },
      find_way_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Find way", cb_find_way },
      add_point_button{ Graph_lib::Point{x_max() - 120 - 15, 105}, 120, 40, "Add point", cb_add_point },
      close_menu_button{ Graph_lib::Point{x_max() - 120 - 15, 150}, 120, 40, "x", cb_close_menu }

{
    attach(quit_button);
    attach(menu_button);
    attach(find_way_button);
    attach(add_point_button);
    attach(close_menu_button);

    find_way_button.hide();
    add_point_button.hide();
    close_menu_button.hide();

    map.set_color(Graph_lib::Color::black);
    map.draw_lines();
    map.set_fill_color(Graph_lib::Color::white);

    attach(map);
}

void Navig_window::menu()
{
    menu_button.hide();
    find_way_button.show();
    add_point_button.show();
    close_menu_button.show();
}


void Navig_window::hide_menu()
{
    find_way_button.hide();
    add_point_button.hide();
    close_menu_button.hide();
    menu_button.show();
}

void Navig_window::add_point()
{
    //TO DO
    hide_menu();
}


void Navig_window::find_way()
{
    //TO DO;
    hide_menu();
}
