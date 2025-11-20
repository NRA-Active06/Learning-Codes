#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H
#include <iostream>
using namespace std;

class DynamicStack {

private:
    int* STACK;
    int iTop;
    int iSize;

public:
    DynamicStack(int size);
    ~DynamicStack();
    void Push(int data);
    int Pop();
    int Peep() const;
    bool IsFull() const;
    bool IsEmpty() const;
};

#endif