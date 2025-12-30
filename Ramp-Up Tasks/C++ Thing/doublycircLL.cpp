#include "doublycircLL.h"
#include <iostream>

dcLinkedList::dcLinkedList() : head(nullptr) {}

void dcLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

void dcLinkedList::displayForward() const {
    if (head == nullptr) {
        std::cout << "Empty\n";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    std::cout << "(back to head)\n";
}

void dcLinkedList::displayBackward() const {
    if (head == nullptr) {
        std::cout << "Empty\n";
        return;
    }

    Node* tail = head->prev;
    Node* temp = tail;
    do {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != tail);

    std::cout << "(back to tail)\n";
}

dcLinkedList::~dcLinkedList() {
    if (head == nullptr) return;

    Node* tail = head->prev;
    tail->next = nullptr;
    head->prev = nullptr;

    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = nullptr;
}