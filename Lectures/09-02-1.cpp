//DISPLAY 9.2 Basic Pointer Manipulations 
//Program to demonstrate pointers and dynamic variables.
#include <iostream>
using namespace std;

int main( )
{
    int *p1, *p2;

    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    *p2 = 53;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;

    p1 = new int;
    *p1 = 88;
    cout << "*p1 == " << *p1 << endl;
    cout << "*p2 == " << *p2 << endl;
    cout << "Hope you got the point of this example!\n";
    
    //system("PAUSE"); 
    cout << "p1 == " << p1 << endl;
    cout << "p2 == " << p2 << endl;
    
    
    delete p1;
    delete p2;
    
    cout << "p1 == " << p1 << endl;
    cout << "p2 == " << p2 << endl; 
    
    //system("PAUSE"); 
    cout << "At *p1 we have  " << *p1 << endl;
    cout << "At *p2 we have  " << *p2 << endl;
    //system("PAUSE");
    p1 = NULL;
    p2 = NULL;
    
    cout << "At p1 we have  " << p1 << endl;
    cout << "At p2 we have  " << p2 << endl;
    
    p1 = new int;
    p2 = new int;
    
    //system("PAUSE");
    return 0;
}
