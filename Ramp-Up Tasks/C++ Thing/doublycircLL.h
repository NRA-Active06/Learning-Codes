#ifndef DOUBLYCIRCLL_H
#define DOUBLYCIRCLL_H

class dcLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;

public:
    dcLinkedList();
    void insert(int value);     // insert at end
    void displayForward() const;
    void displayBackward() const;
    ~dcLinkedList();
};

#endif