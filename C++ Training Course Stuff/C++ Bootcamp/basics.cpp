#include <iostream>

//Stack, automatic store
//Heap, free store
// if you were to input ./a.out hi i am
// [./a.out] 5 (mem. address)
// [hi] 32
// [i] 50
// [am] 46
// argv [5, 32, 50, 46] <-- the argv points to the pointers

int main(int argc, char** argv) //argc = argument count, argv = argument vector
{
    int b;
    int* ptr;

    //std::cer
    //std::clog
    //std::cin

    std::cout << "You've given me " << argc << " arguments!\n";
    std::cout << argv[0] << argv[1] << argv[2] << '\n';

    if(argc > 2)
        std::cout << argv[1] << " is the second argument!" << "\n";
}