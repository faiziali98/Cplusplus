#include <cstdlib>
#include<iostream>
#include "LinkedList.cpp"
using namespace std;

int main (){
    LinkedList faizi;
    faizi.insertAtHead(5);
    Node *m1=faizi.getintail();
    cout<<m1->data<<endl;
    faizi.insertAtHead(6);
    faizi.insertAtHead(7);
    faizi.insertAtHead(8);
    faizi.insertAtintail(9);
    LinkedList faizi2(faizi);
    cout << "data of faizi10 0" << endl;
    faizi.print();
    cout<<"Data Of Faizi2 "<<endl;
    faizi2.print();
    faizi.insertAtintail(11);
    faizi.insertAfter(10,8);
    faizi.insertSorted(3);
    faizi.insertSorted(10);
    faizi.insertSorted(4);
    faizi.insertSorted(12);
    cout<<"Data Of Faizi1 "<<endl;
    faizi.print();
    Node *g=faizi.getintail();
    Node *m=faizi.getHead();
    cout<<m->data<<endl;
    cout<<g->data<<endl;
    Node *k=faizi.searchFor(13);
    faizi.deleteElement(3);
    faizi.deleteHead();
    faizi.deleteintail();
    faizi.deleteintail();
    faizi.deleteintail();
    faizi.print();
    //cout<<"Search "<<k->data<<endl;
    int k1=faizi.length();
    cout<<k1<<endl;
}
