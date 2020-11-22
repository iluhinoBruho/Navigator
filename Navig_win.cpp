#include "Navig_win.h"

Navig_window::Navig_window(Graph_lib::Point xy, int w, int h, const std::string title)
    : Window{ xy, w, h, title },
      quit_button{ Graph_lib::Point{x_max() - 120 - 15, 15}, 120, 40, "Quit", cb_quit },
      menu_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Menu", cb_menu },
      find_way_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Find way", cb_find_way },
      add_point_button{ Graph_lib::Point{x_max() - 120 - 15, 105}, 120, 40, "Add town", cb_add_point },
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

    //to implement: map should be under everything
    //now it covers everything so you see nothing located on the sq of map
    //map.set_fill_color(Graph_lib::Color::white);

    attach(map);

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



#include <iostream>
void Navig_window::add_point()
{

    hide_menu();
    add_p_win.show();

    //new Town{{0,0},cb_clicked, "Default"};

    //Town* test = &added;
//    std::cerr << "Town default " << &added << " " << added.pos.x << " " << added.pos.y <<std::endl;

    int x, y;
    std::string name;
    if(add_p_win.get_point(x, y, name))
    {
        towns.push_back(new Town{{x,y}, cb_clicked, name});

        if(towns.size())
            std::cerr << "Last town in towns " << towns[towns.size() - 1].mark << " " << towns[towns.size() - 1].pos.x << " " << towns[towns.size() - 1].pos.y <<std::endl;
//        std::cerr << "Town added " << added.mark << " " << added.pos.x << " " << added.pos.y <<std::endl;
//        towns.push_back(added);
//        std::cerr << "Town in towns" << added.mark << " " << added.pos.x << " " << added.pos.y <<std::endl;
        update_map();
//        return;
    }
}

void Navig_window::find_way()
{
    //TO DO;
    hide_menu();
}


//now in development
void Navig_window::clicked(Graph_lib::Address widget)
{
    //    //Showing mark of button  ( name  of town )


//    Fl_Widget& w = Graph_lib::reference_to<Fl_Widget>(widget);

//    std::cerr << "Coords if click: (" << w.x() << "," << w.y() <<")" << std::endl;

//    Graph_lib::Text click{{w.x(), w.y()}, "SOME"};
//    attach(click);
//    redraw();
    //Town& c ( Graph_lib::Point { w.x(), w.y() } );
    //c.activate();
}



void Navig_window::update_map()
{
    for(int i = 0; i < towns.size(); ++i)
    {
        attach(towns[i]);

        std::cerr << "Town " << i << towns[i].mark << " " << towns[i].pos.x << " " << towns[i].pos.y <<std::endl;

    }
    redraw();
}

void Navig_window::remove_point(std::string s)
{
    //TO DO:
    //removing from graph & from towns

//    for(: towns)
//    {
//        if(el.name == s)
//            delete el
//    }
//    delete towns[s];
}
