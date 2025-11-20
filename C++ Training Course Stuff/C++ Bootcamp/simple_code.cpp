#include <iostream>
#include <charconv>
#include <cstring>

int main (int argc, char** argv)
{
    int a;
    int b;

    if (argc < 4){
        std::cerr << "Not enough arguments!\n";
        return EXIT_FAILURE;
    }
    
    std::from_chars(argv[1], argv[1] + strlen(argv[1]), a);
    std::from_chars(argv[3], argv[3] + strlen(argv[3]), b);
    
    if (argv[2][0] == '+'){
        std::cout << a+b << '\n';
    }
}