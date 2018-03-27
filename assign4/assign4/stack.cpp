#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"


Stack::Stack()
{
}


Stack::Stack(const Stack& otherStack)
{
    list=otherStack.list;
}


Stack::~Stack()
{
    list.~LinkedList();
}


void Stack::push(int item)
{
    list.insertAtHead(item);
}


int Stack::top()
{
    return (list.getHead()->data);
}


int Stack::pop()
{
    int b=list.getHead()->data;
    list.deleteHead();
    return (b);
}


int Stack::length()
{
    return list.length();
}


bool Stack::isEmpty()
{
    if (list.length()==0)
        return 0;
    else
        return 1;
}

void Stack::print()
{
    list.print();
}
#endif
