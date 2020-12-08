#ifndef LOGICS_H
#define LOGICS_H

#include "../Graph_lib/Graph.h"

#include <vector>
#include <cmath>
#include "Constants.h"
#include "Matrix.h"


using table = std::vector<std::vector<double>>;


std::vector<std::string> get_way(const Matrix& graph, std::string s, std::string f);

//Dejikstra algorithm
std::vector<int> Dejikstra(const table& graph, int start, int dest);

double distance(Graph_lib::Point a, Graph_lib::Point b);


#endif
