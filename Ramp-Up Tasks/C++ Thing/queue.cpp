#include "queue.h"

Queue::Queue(int cap) {
    capacity = cap;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

Queue::~Queue() {
    delete[] arr;
}

bool Queue::IsFull() const {
    return size == capacity;
}

bool Queue::IsEmpty() const {
    return size == 0;
}

void Queue::Enqueue(int value) {
    if (IsFull()) {
        cout << "Queue is full!\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

int Queue::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    int val = arr[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

int Queue::Peek() const {
    if (IsEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return arr[front];
}

void Queue::Display() const {
    if (IsEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i < size; i++) {
        int index = (front + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;
}