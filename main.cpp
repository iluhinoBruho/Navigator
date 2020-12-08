#include <iostream>

#include "../Graph_lib/Graph.h"
#include "Navig_win.h"
#include "add_point_win.h"
#include "Constants.h"
#include "town.h"
#include "Logics.h"
#include "Matrix.h"
#include "test.h"


int main()
{
    try
    {
        Navig_window win(win_corner, win_width, win_height, main_name);
        test(win);
        return Graph_lib::gui_main();

    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    } catch(...)
    {
        std::cerr << "Unknown error" << std::endl;
    }
}
