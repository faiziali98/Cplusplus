#ifndef __STACK_H
#define __STACK_H
#include "LinkedList.cpp"

/* This is the generic Stack class */

class Stack
{
    LinkedList list;

public:

    // Constructor
    Stack();

    // Copy Constructor
    Stack(const Stack& otherStack);

    // Destructor
    ~Stack();

    // Required Methods
    void push(int item);
    int top();
    int pop();
    int length();
    bool isEmpty();
    void print();
};

#endif
