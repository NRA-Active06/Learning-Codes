#include <iostream>

struct coordinate{
    int x;
    int y;
    int z;
};

struct Matrix{
    int data[4*4];
};

void initialiseIdentity(Matrix& v)
{
    for (int i = 0; i < 16; i++)
    {
        if (i % 5 ==0) 
            v.data[i] = 1;
        else 
            v.data[i] = 0;
    }
}

unsigned pow2(unsigned n)
{
    return 1 << n;
}

void someF(const coordinate& xyz)
{
    //this is so that you dont have to copy and paste it in, saving stack space but also a constant because
    //you dont want to accidentally change the structure itself by accident
}

int main(int, char**){
/*
    unsigned x;
    int y = 0b11;

    std::cout << "Give me a number: ";
    std::cin >> x;
    std::cout << "Result: " << pow2(x) << "\n";

    //std::cout << "Enter a number: ";
    //std::cin >> y;
    std::cout << "Your number is " << y << '\n';

    int result = 0;
    std::cout << result << '\n';
*/

    coordinate mycoord;
    mycoord.x = 0;

    coordinate* ptr = &mycoord;
    (*ptr).z = 0;
    ptr[0].z = 0;
    ptr->z = 0;

    coordinate mycoord = {.x = 0, .y = 0, .z = 0};
}