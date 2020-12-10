#include "Navig_win.h"

Navig_window::Navig_window(Graph_lib::Point xy, int w, int h, const std::string title)
    : Window{ xy, w, h, title },
      quit_button{ Graph_lib::Point{x_max() - 120 - 15, 15}, 120, 40, "Quit", cb_quit },
      menu_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Menu", cb_menu },
      find_way_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Find way", cb_find_way },
      add_point_button{ Graph_lib::Point{x_max() - 120 - 15, 105}, 120, 40, "Add town", cb_add_point },
      add_road_button{ Graph_lib::Point{x_max() - 120 - 15, 150}, 120, 40, "Add road", cb_add_road },
      close_menu_button{ Graph_lib::Point{x_max() - 120 - 15, 195}, 120, 40, "x", cb_close_menu },
      add_roads_mode{ Graph_lib::Point{x_max() - 120 - 20, y_max() - 50 - 15}, 120, 40, "Add roads", cb_adding_roads_mode},
      add_roads_is_active{{x_max() - 150, y_max() - 55 - 15}, add_roads_txt}

{
    add_p_win.hide();
    add_road_win.hide();
    find_way_win.hide();

    add_roads_is_active.set_color(Graph_lib::Color::invisible);


    attach(quit_button);
    attach(menu_button);
    attach(find_way_button);
    attach(add_point_button);
    attach(add_road_button);
    attach(close_menu_button);
    attach(add_roads_mode);

    find_way_button.hide();
    add_point_button.hide();
    add_road_button.hide();
    close_menu_button.hide();

    attach(X);
    attach(Y);

    map.set_color(Graph_lib::Color::black);
    map.draw_lines();
    attach(map);


}

void Navig_window::quit()
{
    //for win in windows_open hide()

    add_p_win.hide();
    add_road_win.hide();
    hide();
}

void Navig_window::menu()
{
    menu_button.hide();
    find_way_button.show();
    add_point_button.show();
    add_road_button.show();
    close_menu_button.show();
}


void Navig_window::hide_menu()
{
    find_way_button.hide();
    add_point_button.hide();
    close_menu_button.hide();
    add_road_button.hide();
    menu_button.show();
}


void Navig_window::add_point()
{

    hide_menu();
    add_p_win.show();

    int x, y;
    std::string name;
    if(add_p_win.get_point(x, y, name))
    {
        if(town_exists(name)||bad_coordinates(x, y))
        {
            //give user some notification about this
            return;
        }
        x += start_map.x;
        y += start_map.y;
        towns.push_back(new Town{{x, y}, cb_clicked, name});
        update_map();
        graph.add_vertex(name);
    }

    Graph_lib::gui_main(); // to correctly close add_p_win

}

void Navig_window::add_road()
{
    hide_menu();
    add_road_win.show();

    std::string name_a, name_b;
    if(add_road_win.get_names(name_a, name_b))
    {
        if(!town_exists(name_a)||!town_exists(name_b)||(name_b == name_a))
        {
            //give user some notification about this
            return;
        }
        double road_length = distance(get_town(name_a).center, get_town(name_b).center);
        graph.add_edge(name_a, name_b, road_length);

        roads.push_back(new Road(get_town(name_a).center, get_town(name_b).center, name_a, name_b));
        update_map();
    }

    Graph_lib::gui_main(); // to correctly close add_road_win
}




void Navig_window::find_way()
{
    hide_menu();
    update_map(true);
    find_way_win.show();

    std::string start, finish;
    if(find_way_win.get_names(start, finish))
    {
        if(!town_exists(start)||!town_exists(finish))
        {
            //give user some notification about this
            return;
        }
        //list of towns' names that is in order of following the shortest path
        std::vector<std::string> path = get_way(graph, start, finish);
        draw_way(path);
    }

    Graph_lib::gui_main(); // to correctly close find_way_win
}


void Navig_window::clicked(Graph_lib::Address widget)
{
    Fl_Widget& w = Graph_lib::reference_to<Fl_Widget>(widget);
    w.activate();

    if(Adding_mode)
    {
        update_map(true);
        //Lightning town's frame
        Town* ptr_click = get_town(w.x(), w.y());
        ptr_click->act();
        attach(*ptr_click);
        redraw();
        if(ptr_click->is_active)
        {
            cnt_cliked += 1;
            if(cnt_cliked == 1)
                ptr_last_click = ptr_click;
        }
        else
            cnt_cliked -= 1;
        if(cnt_cliked == 2)
        {
            //add_road
            std::string name_a = ptr_click->mark;
            std::string name_b = ptr_last_click->mark;

            if(!town_exists(name_a)||!town_exists(name_b)||(name_b == name_a))
            {
                //give user some notification about this
                cnt_cliked = 0;
                update_map(true);
                return;
            }

            double road_length = distance(get_town(name_a).center, get_town(name_b).center);
            graph.add_edge(name_a, name_b, road_length);

            roads.push_back(new Road(get_town(name_a).center, get_town(name_b).center, name_a, name_b));
            update_map(true);

            cnt_cliked = 0;
        }
    }

    //update_map(); // is not needed cause we need only to change 1 object

}



void Navig_window::update_map(bool dflt)
{
    if(!dflt)
    {
        for(int i = 0; i < roads.size(); ++i)
            attach(roads[i]);
        for(int i = 0; i < towns.size(); ++i)
        {
            attach(towns[i]);
            attach(towns[i].frame);
        }
    }
    else
    {
        for(int i = 0; i < roads.size(); ++i)
        {
            roads[i].set_color(Graph_lib::Color::black);
            attach(roads[i]);
        }
        for(int i = 0; i < towns.size(); ++i)
        {
            towns[i].frame.set_color(Graph_lib::Color::black);
            towns[i].is_active = false;
            attach(towns[i]);
            attach(towns[i].frame);
        }
    }

    redraw();
}


void Navig_window::draw_way(std::vector<std::string> path)
{
    //    std::cout << "graph" << std::endl;
    //    for(int i = 0; i < graph.data().size(); ++i)
    //    {
    //        for(int j = 0; j < graph.data().size(); ++j)
    //        {
    //            std::cout << graph.data()[i][j] << " ";
    //        }
    //        std::cout << std::endl;
    //    }

    if(path.size() == 0) //pass doesn't exist
    {
        //show some notification to user
        return;
    }

    //drawing highlighted lines between cur and prev town of pass
    //(its guaranteed that those roads existed)
    for(int i = 1; i < path.size(); ++i)
    {
        Town* first = get_town_ptr(path[i]);
        Town* second = get_town_ptr(path[i - 1]);
        Road* cur = get_road(first->center, second->center);
        cur->set_color(Graph_lib::Color::red);
        first->frame.set_color(Graph_lib::Color::red);
        second->frame.set_color(Graph_lib::Color::red);
    }
    redraw();

}

bool Navig_window::town_exists(std::string s) const
{
    for(int i = 0; i < towns.size(); ++i)
        if(towns[i].mark == s)
            return true;
    return false;
}

bool Navig_window::bad_coordinates(int x, int y) const
{
    if(x < 0 || y < 0 || x > map_width + town_size || y + town_size > map_height)
        return true;
    return false;
}

Town& Navig_window::get_town(std::string name)
{
    for(int i = 0; i < towns.size(); ++i)
        if(towns[i].mark == name)
            return towns[i];

    throw std::runtime_error("Trying to get not extisting Town");
}

Town* Navig_window::get_town_ptr(std::string name)
{
    for(int i = 0; i < towns.size(); ++i)
        if(towns[i].mark == name)
            return &towns[i];

    throw std::runtime_error("Trying to get not extisting Town");
}

Town* Navig_window::get_town(int x, int y)
{
    for(int i = 0; i < towns.size(); ++i)
        if(towns[i].pos.x == x && towns[i].pos.y == y )
            return &towns[i];

    throw std::runtime_error("Trying to get not extisting Town");
}


Road* Navig_window::get_road(Graph_lib::Point first, Graph_lib::Point second)
{

    for(int i = 0; i < roads.size(); ++i)
        if((roads[i].first_point == first && roads[i].second_point == second) || (roads[i].first_point == second && roads[i].second_point == first))
            return &roads[i];

    throw std::runtime_error("Trying to get not extisting Road");
}


void Navig_window::remove_point()
{
    //TO DO:
    //removing from graph & from towns & deleting all roads connected with it

}


void Navig_window::adding_roads_mode()
{
    if(Adding_mode)
    {
        Adding_mode = false;
        add_roads_is_active.set_color(Graph_lib::Color::invisible);
        //attach(add_roads_is_active);
        detach(add_roads_is_active);
    }
    else
    {
        Adding_mode = true;
        add_roads_is_active.set_color(Graph_lib::Color::red);
        attach(add_roads_is_active);
    }
    cnt_cliked = 0;
    redraw();
}
