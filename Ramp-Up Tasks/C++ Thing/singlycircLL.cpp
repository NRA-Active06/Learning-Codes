#include "singlycircLL.h"
#include <iostream>

scLinkedList::scLinkedList() : head(nullptr) {}

void scLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // this points to itself
        return;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void scLinkedList::display() const {
    if (head == nullptr) {
        std::cout << "Empty\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    } while (temp != head);

    std::cout << "(loops from here back to the front)" << std::endl;
}

scLinkedList::~scLinkedList() {
    if (head == nullptr) return;

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;
    tail->next = nullptr;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}