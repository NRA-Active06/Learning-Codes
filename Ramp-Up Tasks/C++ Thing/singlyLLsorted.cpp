#include <iostream>
#include "singlyLLsorted.h"

sLinkedList::sLinkedList() : head(nullptr) {}

void sLinkedList::insert(int value) {
    Node* newNode = new Node{value, nullptr};

    if(head == nullptr) {
        head = newNode;
        return;
    }

// this handles first position and intermediate position

    if (value <= head->data) { //if the value is less than the data stored in head
        newNode->next = head; //move the head over to 'next' as value is added at head / first
        head = newNode;
        return;
    }

    Node* prev = head;
    Node* current = head->next;

    //loop to get to the last node
    while (current != nullptr && current->data < value)
    {
        prev = current;
        current = current->next;
    }

    newNode->next = current;
    prev->next = newNode;
}

/*
Head & temp - > 1
newNode -> 10
insert (5)
newNode --> 5
Head -> 1 -->10 -->5
*/

// insert at a position
//return an appropriate error code which should say invalid position 
// negative position and out of range position

bool sLinkedList::insertAt(int position, int value) {
    if (position < 0) return false;

    Node* newNode = new Node{value, nullptr};

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return true;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        delete newNode;
        return false; //error handling
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
    return true;
}

// delete at a position

bool sLinkedList::deleteAt(int position) {
    if (position < 0 || head == nullptr) return false;

    //segmentation fault --- dangling pointer
    if (position == 0) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    //1-->2-->3-->4
    if (temp == nullptr || temp->next == nullptr) return false;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return true;
}

// write a logic to figure out if there is a loop in a linked-list ()

bool sLinkedList::hasloop() const {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          
        fast = fast->next->next;

        if (slow == fast) return true;
    }
    return false;
}

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