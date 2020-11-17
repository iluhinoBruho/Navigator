#include <iostream>

#include "Navig_win.h"
#include "Constants.h"



int main()
{
    try
    {
        Navig_window win(win_corner, win_width, win_height, main_name);

        return Graph_lib::gui_main();

    } catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    } catch(...)
    {
        std::cerr << "Unknown error" << std::endl;
    }
}
