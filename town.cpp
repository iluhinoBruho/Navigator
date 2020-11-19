#include "town.h"


Town::Town(Graph_lib::Point xy, Graph_lib::Callback cb, std::string name)
    :Graph_lib::Button{xy, town_size, town_size, "", cb}, mark{ name } {}

//Town::Town(Graph_lib::Point xy, const std::string name)
//    : Graph_lib::Button{xy, town_size, town_size, ""}, mark{ name }
//{

//}

void Town::remove(std::string s)
{
    //TO DO:
    //removing from graph & from towns

//    for(: towns)
//    {
//        if(el.name == s)
//            delete el
//    }
//    delete towns[s];

    hide();
}


void Town::clicked()
{
    //Showing mark of button  ( name  of town )
}



void Town::attach (Graph_lib::Window& win)
{
    Button::attach (win);
}
