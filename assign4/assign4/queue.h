#ifndef __QUEUE_H
#define __QUEUE_H
#include "LinkedList.cpp"

/* This is the generic Queue class */

class Queue
{
    LinkedList list;

public:

    // Constructor
    Queue();

    // Copy Constructor
    Queue(const Queue& otherQueue);

    // Destructor
    ~Queue();

    // Required Methods
    void enqueue(int item);
    int front();
    int dequeue();
    int length();
    bool isEmpty();
    void print();
    };

#endif
