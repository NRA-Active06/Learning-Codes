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

    std::cout << "Give me the LHS: ";
    int a = readInt();
    std::cout << "Give me the RHS: ";
    int b = readInt();
    char op = readOp();

    switch (op) {
        case '+': 
            std::cout << a+b << '\n';
            break;
        case '-':
            std::cout << a-b << '\n';
            break;
        case '/':
            std::cout << a/b << '\n';
            break;
        case '*':
            std::cout << a+b << '\n';
            break;
        default:
            std::cout << "I am unfamiliar with this operation\n";
            break;
    }

    return 0;
}