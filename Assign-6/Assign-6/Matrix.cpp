#include "Matrix.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
Matrix<T>::Matrix(int row, int cols){
    rows=row;
    colms=cols;
    p.resize(row);

    for (int i = 0; i < row; i++)
        p[i].resize(cols);
}

template<typename T>
Matrix<T>::Matrix(int row, int cols,const T & initvalue) {
    rows=row;
    colms=cols;
    p.resize(row);

    for (int i = 0; i < row; i++)
        p[i].resize(cols,initvalue);
}

template<typename T>
Matrix<T>::Matrix(const Matrix & m){
    p=m.p;
    rows=m.rows;
    colms=m.colms;
}

template<typename T>
Matrix<T> Matrix<T>::transpose(){
    int a=p[0][0];
    Matrix<T> temp(colms,rows,a);
    return temp;
}

template<typename T>
void Matrix<T>::print(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colms; j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

template<typename T>
int Matrix<T>::row(){
    return rows;
}

template<typename T>
int Matrix<T>::cols(){
    return colms;
}

template<typename T>
void Matrix<T>::swap_rows(int r1, int r2){
    vector<T> temp;
    temp.resize(colms);
    for(int n=0;n<colms;n++){
        temp[n]=p[r1][n];
    }
    for(int n=0;n<colms;n++){
        p[r1][n]=p[r2][n];
    }
    for(int n=0;n<colms;n++){
        p[r2][n]=temp[n];
    }

}
template<typename T>
void Matrix<T>::remove_row(int row){
    vector<vector<T> > temp;
    int a=p[0][0];
    temp.resize(rows-1);
    for (int i = 0; i < rows-1; i++)
        temp[i].resize(colms,a);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colms; j++){
            if (i!=row && i<row){
                temp[i][j]=p[i][j];
            }
            else if (i!=row && i>row){
                temp[i-1][j]=p[i][j];
            }
        }
    }
    p.resize(rows-1);
    for (int i = 0; i < rows-1; i++)
        p[i].resize(colms);
    rows=rows-1;
    p=temp;
}

template<typename T>
void Matrix<T>::remove_column(int col){
    vector<vector<T> > temp;
    int a=p[0][0];
    temp.resize(rows);
    for (int i = 0; i < rows; i++)
        temp[i].resize(colms-1,a);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < colms; j++){
            if (i!=colms && i<colms){
                temp[i][j]=p[i][j];
            }
            else if (i!=colms && i>colms){
                temp[i][j-1]=p[i][j];
            }
        }
    }
    p.resize(rows);
    for (int i = 0; i < rows; i++)
        p[i].resize(colms-1);
    colms=colms-1;
    p=temp;
}
