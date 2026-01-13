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

//insert at a position
void dLinkedList::insertAt(int position, int value) {
    if (position < 0) return;

    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    if (position == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;
    }

    Node* before = temp->prev;
    before->next = newNode;
    newNode->prev = before;

    newNode->next = temp;
    temp->prev = newNode;
}

//delete at position
bool dLinkedList::deleteAt(int position) {
    if (position < 0 || head == nullptr) return false;

    if (position == 0) {
        Node* toDelete = head;

        if (head == tail) {
            head = tail = nullptr;
            delete toDelete;
            return true;
        }

        head = head->next;
        head->prev = nullptr;
        delete toDelete;
        return true;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) return false; 

    if (temp == tail) {
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return true;
    }

    Node* before = temp->prev;
    Node* after  = temp->next;

    before->next = after;
    after->prev = before;

    delete temp;
    return true;
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

//check for loop
bool dLinkedList::hasLoop() const {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
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