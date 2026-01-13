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
    void insertAt(int position, int value);  
    bool deleteAt(int position);            
    bool hasLoop() const;                   
    dLinkedList();
    void insert(int value);
    void displayForward() const;
    void displayBackward() const;
    ~dLinkedList();
};

#endif