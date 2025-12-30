#ifndef DOUBLYLL_H
#define DOUBLYLL_H

class dLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    dLinkedList();
    void insert(int value);
    void displayForward() const;
    void displayBackward() const;
    ~dLinkedList();
};

#endif