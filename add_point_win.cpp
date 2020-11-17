#include "add_point_win.h"

Add_window::Add_window()
    : Window{ {win_corner.x + 150, win_corner.y + 150}, win_add_w, win_add_h, add_name },
      close_add_button{ Graph_lib::Point{x_max() - 100 - 5, 5}, 100, 35, "cancel", cb_close_add }

{
    attach(close_add_button);
}


void Add_window::hide_add()
{
    hide();
}
