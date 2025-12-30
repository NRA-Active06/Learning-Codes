#include "singlyLL.h"
#include "singlycircLL.h"
#include "doublyLL.h"
#include "doublycircLL.h"
#include <iostream>

/*
int main() {
    sLinkedList list;

    list.insert(10);
    list.insert(25);
    list.insert(31);

    list.display();
}


int main() {
    scLinkedList list;

    list.insert(10);
    list.insert(25);
    list.insert(31);
    list.insert(47);

    list.display();
}


int main() {
    dLinkedList list;

    std::cout << "Doubly linked list forwards:" << std::endl;
    list.insert(100);
    list.insert(200);
    list.insert(300);

    list.displayForward();

    std::cout << "Doubly linked list backwards:" << std::endl;
    list.displayBackward();

    return 0;
}
*/

int main() {
    dcLinkedList list;

    std::cout << "Doubly circular linked list forwards:" << std::endl;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    list.displayForward();

    std::cout << "Doubly circular linked list backwards:" << std::endl;
    list.displayBackward();

    return 0;
}