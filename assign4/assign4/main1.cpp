#include <cstdlib>
#include<iostream>
#include "LinkedList.cpp"
#include "stack.cpp"
using namespace std;

int main (){
    Stack faizi;
    faizi.push(5);
    faizi.push(6);
    faizi.push(7);
    faizi.push(8);
    faizi.print();
    int j=faizi.top();
    cout<<j<<endl;
    int j1=faizi.pop();
    cout<<j1<<endl;
    faizi.print();
    int j2=faizi.length();
    cout<<j2<<endl;
    Stack faizi2(faizi);
    faizi2.print();
}
