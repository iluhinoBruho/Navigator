#ifndef AXIS_H
#define AXIS_H


#include "../Graph_lib/Graph.h"

#include "Constants.h"
#include <string>



struct Axis_imp : Graph_lib::Shape
{
  // representation left public
  enum Orientation { x, y };

  Axis_imp(Orientation d, Graph_lib::Point xy, int length, int nummber_of_notches = 0, const std::string& label = "");

  void draw_lines () const override;
  void move (int dx, int dy) override;
  void draw_notches () const;

  void set_color (Graph_lib::Color c);

  Graph_lib::Text label;
  Graph_lib::Lines notches;
  Graph_lib::Vector_ref<Graph_lib::Text> marks;
};

#endif


