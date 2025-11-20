#ifndef STATICSTACK_H
#define STATICSTACK_H
#include <iostream>
using namespace std; //saves time

class StaticStack {

private:
    int STACK[100];
    int iTop;
    int iSize;

public:
    StaticStack(); 
    void Push(int data);
    int Pop();
    int Peep() const;
    bool IsFull() const;
    bool IsEmpty() const;
};

#endif