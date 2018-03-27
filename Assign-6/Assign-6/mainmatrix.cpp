#include "Matrix.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    Matrix<int> m(3,4,9);
    Matrix<int> m1=m.transpose();
    m.print();
    cout<<endl;
    m1.print();
    m1.swap_rows(2,3);
    m1.remove_row(2);
    cout<<endl;
    m1.print();
    m1.remove_column(2);
    cout<<endl;
    m1.print();
}
