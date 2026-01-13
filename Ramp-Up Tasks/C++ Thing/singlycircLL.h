#ifndef SINGLYCIRCLL_H
#define SINGLYCIRCLL_H

class scLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    void insertAt(int position, int value);
    bool deleteAt(int position);              
    bool isLoop() const;                  
    scLinkedList();
    void insert(int value);
    void display() const;
    ~scLinkedList();
};

#endif