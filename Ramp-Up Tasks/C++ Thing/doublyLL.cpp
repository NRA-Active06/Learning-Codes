#include "doublyLL.h"
#include <iostream>

dLinkedList::dLinkedList() : head(nullptr), tail(nullptr) {}

void dLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void dLinkedList::displayForward() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "null\n";
}

void dLinkedList::displayBackward() const {
    Node* temp = tail;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << "null\n";
}

dLinkedList::~dLinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = tail = nullptr;
}