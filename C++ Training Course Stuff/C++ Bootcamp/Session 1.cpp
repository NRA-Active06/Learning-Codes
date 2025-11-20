// Compiler setup

/* 
VSCode setup, or use whatever editor you're comfortable using.
A C++ compiler. You can use either GCC G++ or clang++. Run the following on your terminal

  g++ --version
  clang --version
  
if either of those work, you have yourself a c++ compiler you can use for our sessions.
If this doesn't work, get in touch and we'll help you out.

*/

// How to use a C++ compiler
// C++ source files can be compiled by invoking the above compiler with

  g++ file.cpp -o exe
  
// The resulting binary can then be executed. On a typical Linux shell, this would be

  ./exe
  
// Basic C++ grammar

// The C++ entry point is defined by

  int main(int argc, char** argv)
  {
  }
  
// and this is the starting point of a C++ program.
// "argc" will contain the number of program arguments, and "argv" will contain the arguments themselves.

// C++ basic types

// We covered the "int" and "char" types.
// Other C++ types were mentioned, "short", "long", "float", "double", as well as the "unsigned" variants.

// Basic stream input and output

// Data can be printed out using the output stream:

  std::cout << "message\n";
  
// and values can also be printed out using the same syntax:

  std::cout << "This program has " << argc << " arguments\n";
  
// An input stream is also usable:

  int i;
  std::cin >> i;

// to query values from the user.
  
//Control of program execution

// Execution of your program can be controlled using "if" statements:

  if (argc > 2)
      std::cout << "This program has more than 2 arguments\n";

// Custom functions

A C++ program may contain any number of functions, defined using the same grammar as main:

  int myFunction() {
  }
  
// Enum

// An enumeration is used to define a type with a restricted set of possible values:

  enum Colour {
    Red,
    Blue,
    Yellow
  };
  
  
// Final program from session 1:

#include <iostream>

int readInt()
{
    int a;
    std::cin >> a;
    return a;
}

enum Operation
{
    Sum,
    Sub,
    Mul,
    Div
};

Operation readOp()
{
    char c;
    std::cin >> c;
    switch (c) {
    case '+' : return Sum;
    case '*' : return Mul;
    case '-' : return Sub;
    case '/' : return Div;
    }
    std::abort();
}

int main(int argc, char** argv)
{
    std::cout << "Give me the LHS:\n";
    int a = readInt();
    std::cout << "Give me the RHS:\n";
    int b = readInt();
    std::cout << "Operation?\n";
    Operation op = readOp();
    switch (op) {
    case Sum:
        std::cout << (a+b) << '\n';
        break;
    case Mul:
        std::cout << (a*b) << '\n';
        break;
    case Sub:
        std::cout << (a-b) << '\n';
        break;
    case Div:
        std::cout << (a/b) << '\n';
        break;
    }
}