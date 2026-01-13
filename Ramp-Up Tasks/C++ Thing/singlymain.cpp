#include <iostream>
#include "singlyLL.h"

int main() {
    sLinkedList list;

    list.insert(1);
    list.insert(3);
    list.insert(7);

    list.insertAt(2, 5);
    list.insertAt(4, 9);

    list.display();

    std::cout << "Does this have a loop? " << list.hasloop() << std::endl;

    return 0;
}