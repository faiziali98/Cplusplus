#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>

class Matrix
{
    private:
        vector<vector<T> > p;
        int rows;
        int colms;
    public:
        Matrix(int row, int cols);
        Matrix(int row, int cols,const T & initvalue);
        Matrix(const Matrix & m);
        Matrix transpose();
        void print();
        int row();
        int cols();
        void swap_rows(int r1, int r2);
        void remove_row(int row);
        void remove_column(int col);
};

#endif // MATRIX_H
