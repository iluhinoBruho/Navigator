#include "axis.h"

Axis_imp::Axis_imp(Axis_imp::Orientation d, Graph_lib::Point xy, int length, int n, const std::string& lab)
  : label{ Graph_lib::Point{xy.x,xy.y}, lab }
{
  switch (d)
  {
  case Axis_imp::x:
  {
    Shape::add (xy);                            // axis line
    Shape::add (Graph_lib::Point{ xy.x + length, xy.y });  // axis line
    if (1 < n)
    {
      int dist = length / n;
      int x = xy.x + dist;
      marks.push_back(new Graph_lib::Text{{xy.x + 5, xy.y-5}, std::to_string(0)});
      for (int i = 0; i < n; ++i)
      {
        notches.add (Graph_lib::Point{x, xy.y}, Graph_lib::Point{x, xy.y-5});
        marks.push_back(new Graph_lib::Text{{x + 5, xy.y-5}, std::to_string(x)});
        x += dist;
      }
    }
    // label under the line
    label.move (length + 10, xy.y - 10);
    break;
  }
  case Axis_imp::y:
  {
    Shape::add (xy);                            // axis line
    Shape::add (Graph_lib::Point{ xy.x, xy.y + length });  // axis line
    if (1 < n)
    {
      int dist = length / n;
      int y = xy.y + dist;
      marks.push_back(new Graph_lib::Text{{xy.x - 20, xy.y + 10}, std::to_string(0)});
      for (int i = 0; i < n; ++i)
      {
        notches.add (Graph_lib::Point{xy.x, y}, Graph_lib::Point{xy.x-5, y});
        marks.push_back(new Graph_lib::Text{{xy.x -30, y - 5}, std::to_string(y)});
        y += dist;
      }
    }
    // label under the line
    label.move (-10, length + 15);
    break;
  }
  }
}


void Axis_imp::draw_lines () const
{
  Shape::draw_lines();  // the line
  notches.draw();       // the notches may have a different color from the line
  label.draw();         // the label may have a different color from the line
  for(int i = 0; i < marks.size(); ++i)
      marks[i].draw();
}


void Axis_imp::set_color (Graph_lib::Color c)
{
  Shape::set_color (c);
  notches.set_color (c);
  label.set_color (c);
  for(int i = 0; i < marks.size(); ++i)
      marks[i].set_color(c);
}

void Axis_imp::move (int dx, int dy)
{
  Shape::move (dx, dy);
  notches.move (dx, dy);
  label.move (dx, dy);
  for(int i = 0; i < marks.size(); ++i)
      marks[i].move(dx, dy);
}

