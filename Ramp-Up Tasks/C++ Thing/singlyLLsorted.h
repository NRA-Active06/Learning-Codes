#ifndef SINGLYLLSORTED_H
#define SINGLYLLSORTED_H

class sLinkedList {
private: 

    struct Node {
        int data;
        Node* next; //
    };
    Node* head; //head is a pointer to the first node

public:
    bool insertAt(int position, int value);
    bool deleteAt(int position);
    bool hasloop() const;
    sLinkedList(); //constructor
    void insert(int value);
    void display() const;
    ~sLinkedList(); //destructor
};

#endif