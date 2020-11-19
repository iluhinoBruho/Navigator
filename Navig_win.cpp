#include "Navig_win.h"
#include "Globals.h"

Navig_window::Navig_window(Graph_lib::Point xy, int w, int h, const std::string title)
    : Window{ xy, w, h, title },
      quit_button{ Graph_lib::Point{x_max() - 120 - 15, 15}, 120, 40, "Quit", cb_quit },
      menu_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Menu", cb_menu },
      find_way_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Find way", cb_find_way },
      add_point_button{ Graph_lib::Point{x_max() - 120 - 15, 105}, 120, 40, "Add point", cb_add_point },
      close_menu_button{ Graph_lib::Point{x_max() - 120 - 15, 150}, 120, 40, "x", cb_close_menu }

{
    add_p_win.hide();

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

    Town added({600,600}, cb_clicked, "Juckovskii");
    attach(added);
}

void Navig_window::quit()
{
    //for win in windows_open hide()

    add_p_win.hide();
    hide();
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
//    if(add_active)
//    {
//        hide_menu();
//        return;
//    }
//    hide_menu();
//    add_p_win.show();

//    Town added({100,100}, cb_clicked, "Juckovskii");
//    //towns[name] = added;
//    //towns.push_back(added);
//    //attach(towns[0]);
//    attach(added);
//    added.show();
//    //Graph_lib::gui_main();
//
}

void Navig_window::find_way()
{
    //TO DO;
    hide_menu();
}


void Navig_window::clicked(Graph_lib::Address widget)
{
    Fl_Widget& w = Graph_lib::reference_to<Fl_Widget>(widget);
    //Town& c ( Graph_lib::Point { w.x(), w.y() } );
    //c.activate();
}

//void Navig_window::update_map()
//{
//    for(int i = 0; i < towns.size(); ++i)
//        attach(towns[i]);
//    redraw();
//}

//void Navig_window::add_town()
//{
//    Town added({100,100}, cb_clicked, "Juckovskii");
//    //towns[name] = added;
//    towns.push_back(added);
//    attach(added);
//}

