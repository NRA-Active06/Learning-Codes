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
//Insert -- function should insert in sorted order
//5 - 7
//4 - 5- 7
//4 - 5- 6- 7
//4 - 5- 6- 7- 9
//1-4-5-6-7-9
//insert at position
void scLinkedList::insertAt(int position, int value) {
    if (position < 0) return;

    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    if (position == 0) {
        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        newNode->next = head;
        head = newNode;
        tail->next = head;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;

        if (temp == head) {
            delete newNode;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//delete at position
bool scLinkedList::deleteAt(int position) {
    if (position < 0 || head == nullptr) return false;

    if (position == 0) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return true;
        }

        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;

        Node* toDelete = head;
        head = head->next;
        tail->next = head;
        delete toDelete;
        return true;
    }

    Node* temp = head;
    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) return false;  //just to check if its out of range
    }

    Node* toDelete = temp->next;
    if (toDelete == head) return false; //position is out of range

    temp->next = toDelete->next;
    delete toDelete;
    return true;
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

//check for loop
bool scLinkedList::isLoop() const {
    if (head == nullptr) return true;
    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return (temp == head); 
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