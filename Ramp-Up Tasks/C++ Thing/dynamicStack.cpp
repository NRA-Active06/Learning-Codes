#include "dynamicStack.h"

DynamicStack::DynamicStack(int size) {
    iSize = size;
    STACK = new int[iSize];
    iTop = -1;
}

DynamicStack::~DynamicStack() {
    delete[] STACK;
}

bool DynamicStack::IsFull() const {
    return iTop == iSize - 1;
}

bool DynamicStack::IsEmpty() const {
    return iTop == -1;
}

void DynamicStack::Push(int data) {
    if (IsFull()) {
        cout << "Stack is full!\n";
        return;
    }
    STACK[++iTop] = data;
}

int DynamicStack::Pop() {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return STACK[iTop--];
}

int DynamicStack::Peep() const {
    if (IsEmpty()) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return STACK[iTop];
}