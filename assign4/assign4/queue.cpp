#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"


Queue::Queue()
{
}


Queue::Queue(const Queue& otherQueue)
{
    list=otherQueue.list;
}


Queue::~Queue()
{
    list.~LinkedList;
}


void Queue::enqueue(int item)
{
    list.insertAtintail(item);
}


int Queue::front()
{
    return (list.getHead()->data);
}


int Queue::dequeue()
{
    int b=list.getHead()->data;
    list.deleteHead();
    return (b);
}


int Queue::length()
{
    return list.length();
}


bool Queue::isEmpty()
{
    if (list.length()==0)
        return 0;
    else
        return 1;
}

void Queue::print()
{
    list.print();
}

#endif
