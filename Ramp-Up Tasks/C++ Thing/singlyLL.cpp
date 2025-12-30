#include <iostream>
#include "singlyLL.h"

sLinkedList::sLinkedList() : head(nullptr) {}

void sLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};

    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    //loop to get to the last node
    while (temp->next != nullptr)
        temp = temp->next;
    
    temp->next = newNode;
}

// insert a position
// delete a position
// write a logic to figure out if there is a loop in a linked-list ()

void sLinkedList::display() const {
    Node* temp = head;
    while( temp != nullptr) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << "null" << std::endl;
}

sLinkedList::~sLinkedList() {
    Node* temp;
    while(head!= nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}