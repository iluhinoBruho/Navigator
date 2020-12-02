#include "Matrix.h"


Matrix::Matrix(int n)
    : size{n}
{
   mat = new table(n, std::vector<int>(n, INF));
}

Matrix::Matrix(const Matrix& a)
{
    mat = new table{*(a.mat)};
    size = (*mat).size();
}


void Matrix::del_cols_rows(int *idxs, int n)
{
    if( n > size )
        throw std::runtime_error("deleting more coloumns than possible");

    //assuming that indexs coming in 0 indexation
    std::sort(idxs, idxs + n); // sorting indexes for correct work of alghoritm
    table* mat_new = new table(size - n, std::vector<int>(size - n));
    int del_rows = 0; // amount of deleted rows
    for(int i = 0; i < size; ++i)
    {
        if(del_rows < n && idxs[del_rows] == i)
        {
            del_rows += 1;
            continue;
        }
        int del_cols = 0; //amount of deleted coloumns
        for(int j = 0; j < size; ++j)
        {                                      // we copy all mat[i][j] except those on the "deleting" positions
            if(del_cols < n && idxs[del_cols] == j)
            {
                del_cols += 1;
                continue;
            }
            (*mat_new)[i - del_rows][j - del_cols] = mat->data()[i][j]; //when we skiped N elems in mat[i] we lower idx on N in new_mat[i]
                                                     //to put elements after each other
        }
    }

    delete_mat();
    mat = mat_new;
    size = size - n;

}

void Matrix::add_vertex(std::string name)
{
    towns[name] = size;
    size += 1;
    for(int i = 0; i < (*mat).size(); ++i)
        (*mat)[i].push_back(INF); //just added isnt connected with any
    (*mat).push_back(std::vector<int>(size, INF));
}

void Matrix::remove_vertex(std::string name)
{
    int pos = towns[name];
    for(auto it = towns.begin(); it != towns.end(); )
        if(it->first == name)
            it = towns.erase(it);
        else
        {
            if(it->second > pos)
                it->second--;
            it++;
        }
    int idxs[1]; // may be rebuild for more vertexes
    idxs[0] = pos;
    del_cols_rows(idxs);

}

void Matrix::add_edge(std::string a, std::string b, int weight)
{
    int idxa = get_num(a);
    int idxb = get_num(b);
    (*mat)[idxa][idxb] = (*mat)[idxb][idxa] = weight;
}

void Matrix::remove_edge(std::string a, std::string b)
{
    int idxa = get_num(a);
    int idxb = get_num(b);
    (*mat)[idxa][idxb] = (*mat)[idxb][idxa] = INF;
}

std::string Matrix::get_name(int num) const
{
    for(auto it = towns.begin(); it != towns.end(); )
    {
        if(it->second == num)
            return it->first;
        it++;
    }
}
int Matrix::get_num(std::string name) const
{
    std::cout << "Ok here" << std::endl;

    for(auto it = towns.begin(); it != towns.end(); )
    {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }

    for(auto it = towns.begin(); it != towns.end(); )
    {
        if(it->first == name)
            return it->second;
        it++;
    }
}


Matrix& Matrix::operator=(const Matrix& a)
{
    if (this == &a)
        return *this;

    //copying
    delete_mat();
    mat = new table{*(a.mat)};
    size = a.size;
    return *this;
}


