#include <iostream>

int readInt()
{
    int a;
    std::cin >> a;
    return a;
}

char readOp()
{
    char c;
    std::cout << "Which operation do you want to do? ";
    std::cin >> c;
    return c;
}

int main(int argc, char** argv)
{
    //bool, char, short, int, long, unsigned ____ (all can be unsigned)
    //half, float, double, long double, real
    char* str = argv[0];
    str[0];
    
    std::cout << "Give me the LHS: ";
    int a = readInt();
    std::cout << "Give me the RHS: ";
    int b = readInt();
    char op = readOp();

    if( op == '+'){
        std::cout << a+b << '\n';
    }
    else if( op == '-'){
        std::cout << a-b << '\n';
    }
    else if( op == '*'){
        std::cout << a*b << '\n';
    }
    else if( op == '/'){
        std::cout << a/b << '\n';
    }
    else {
        std::cout << "I don't recognise this operation\n";
    }

    return 0;
}