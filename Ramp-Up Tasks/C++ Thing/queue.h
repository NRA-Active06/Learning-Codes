#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue {

private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int cap);
    ~Queue();
    bool IsFull() const;
    bool IsEmpty() const;
    void Enqueue(int value);
    int Dequeue();
    int Peek() const;
    void Display() const;
};

#endif