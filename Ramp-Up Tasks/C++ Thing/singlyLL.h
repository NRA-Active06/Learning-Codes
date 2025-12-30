#ifndef SINGLYLL_H
#define SINGLYLL_H

class sLinkedList {
private: 

    struct Node {
        int data;
        Node* next; //
    };
    Node* head; //head is a pointer to the first node

public:
    sLinkedList(); //constructor
    void insert(int value);
    void display() const;
    ~sLinkedList(); //destructor
};

#endif