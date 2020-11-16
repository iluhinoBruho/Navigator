#include "Navig_win.h"

Navig_window::Navig_window(Graph_lib::Point xy, int w, int h, const std::string title)
    : Window{ xy, w, h, title },
      quit_button{ Graph_lib::Point{x_max() - 120 - 15, 15}, 120, 40, "Quit", cb_quit },
      menu_button{ Graph_lib::Point{x_max() - 120 - 15, 60}, 120, 40, "Menu", cb_menu }
{
    attach(quit_button);
    attach(menu_button);

    map.set_color(Graph_lib::Color::black);
    map.draw_lines();

    attach(map);

}

void Navig_window::menu()
{
    menu_button.hide();


}
