#ifndef LOGICS_H
#define LOGICS_H


#include <vector>
#include "Constants.h"
#include "Matrix.h"

using table = std::vector<std::vector<int>>;


std::vector<std::string> get_way(const Matrix& graph, std::string s, std::string f);

//Dejikstra algorithm
std::vector<int> Dejikstra(const table& graph, int start, int dest);


#endif
