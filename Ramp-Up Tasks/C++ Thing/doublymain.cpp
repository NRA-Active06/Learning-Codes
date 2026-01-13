#include <iostream>
#include "doublyLL.h"

int main() {
    dLinkedList d;

    d.insert(3);
    d.insert(4);
    d.insert(9);
    d.displayForward(); 
    d.displayBackward();

    d.insertAt(4, 66);     
    d.insertAt(3, 55);    
    d.displayForward(); 
    d.displayBackward();

    d.deleteAt(1);       
    d.deleteAt(0);           
    d.displayForward();
    d.displayBackward();

    std::cout << "Does this loop? " << d.hasLoop() << std::endl;
}