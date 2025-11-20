#include "staticStack.h"

StaticStack::StaticStack() {
    iTop = -1;
    iSize = 100;
}

bool StaticStack::IsFull() const {
    return iTop == iSize - 1;
}

bool StaticStack::IsEmpty() const {
    return iTop == -1;
}

void StaticStack::Push(int data) {
    if (IsFull()) {
        cout << "Stack is full!\n";
        return;
    }
    STACK[++iTop] = data;
}

int StaticStack::Pop() {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return STACK[iTop--];
}

int StaticStack::Peep() const {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return STACK[iTop];
}