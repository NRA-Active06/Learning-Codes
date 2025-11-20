#include <iostream>

void incrementCounter3(int &c){ //SECOND example of call by REFERENCE
    c++; //a LOT easier and less complicated than the other Reference code
}

void incrementCounter2(int *counterPointer){ //call by REFERENCE
    *counterPointer = *counterPointer + 1;
}

void incrementCounter(int counter){ //call by VALUE
    counter = counter + 1;
}

int main() {
    int x = 10;

    std::cout << &x << std::endl; //this will print out the ADDRESS of x

    int *xptr = &x; //made a pointer TO the memory address of var. X

    std::cout << xptr << std::endl; //prints out the MEMORY ADDRESS of x
    std::cout << *xptr << std::endl; //prints out the VALUE stored in x (deref)

    incrementCounter(x); //pass the variable itself
    std::cout << x << std::endl; //values ISN'T changed in main
    
    incrementCounter2(&x); //pass the ADDRESS of the variable
    std::cout << x << std::endl; //values IS changed in main

    //reference variables

    int a = 20;
    int &b = a; //this is a reference variable to 'a'

    b = 25;
    std::cout << a << " is the value in a! " << b << " is the value in b!\n"; //both values 'changed' as they share the same value

    incrementCounter3(a); //passing a into the function
    std::cout << a << " is the value in a! " << b << " is the value in b!\n";//both are changed

    return(0);
}