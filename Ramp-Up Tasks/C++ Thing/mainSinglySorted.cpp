#include <iostream>
#include "singlyLL.h"

int main() {
    sLinkedList list;

    list.insert(10);
    list.insert(1);
    list.insert(5);
    list.insert(7);

    std::cout << "After sorted inserts:\n";
    list.display();  

    list.insertAt(2, 99);
    std::cout << "\nAfter insertAt(2, 99):\n";
    list.display();


    list.deleteAt(3);
    std::cout << "\nAfter deleteAt(3):\n";
    list.display();

    std::cout << "\nHas loop? " << (list.hasloop() ? "Yes" : "No") << std::endl;

    return 0;
}