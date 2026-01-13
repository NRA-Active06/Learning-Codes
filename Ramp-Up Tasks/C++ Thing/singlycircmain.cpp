#include <iostream>
#include "singlycircLL.h"

int main() {
    scLinkedList circ;
    circ.insert(12);
    circ.insert(19);
    circ.insert(32);
    circ.display();

    circ.insertAt(0, 9);   //inserts
    circ.insertAt(2, 23);  
    circ.display();

    circ.deleteAt(3);    //deletes  
    circ.deleteAt(4);      
    circ.display();

    std::cout << "Does this have a loop? " << circ.isLoop() << std::endl;
}