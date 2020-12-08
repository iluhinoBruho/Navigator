#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "Constants.h"


using table = std::vector<std::vector<double>>;

//graph with fast removing/adding cols/rows
class Matrix
{
public:
    Matrix()
        : mat{new table}, size{0} {}

    Matrix(int n);

    Matrix(const Matrix& a);

    ~Matrix(){ delete_mat(); }


    void add_vertex(std::string s);
    void add_edge(std::string a, std::string b, double w);
    void remove_vertex(std::string s);
    void remove_edge(std::string a, std::string b);


    std::string get_name(int num) const;
    int get_num(std::string name) const;

    const table& data() const { return *mat; }

    Matrix& operator=(const Matrix& a);

    void set_mat(table& a) { *mat = a; size = a.size();}

private:
    table* mat;
    int size; //squared matrix only
    std::map<std::string, int> towns; //keeps coorelation between names of towns and theirs' vertexes numbers

    void del_cols_rows(int* idxs, int n = 1);
    void delete_mat(){ delete mat; }

};









#endif
