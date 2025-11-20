#include <iostream>

struct Matrix
{
    Matrix()
    {
        std::cout << "Constructor!" << '\n';
    }

    Matrix(int i)
    {
        std::cout << "Constructor with an integer " << i << '\n';
    }

    ~Matrix()
    {
        std::cout << "destructor!" << '\n';
    }

};

Matrix* getMeAMatrix()
{
    Matrix* m = new Matrix; //this is a pointer to the heap and allocates memory in the heap
    //...
    return m;
}

int main(){

    std::cout << "Strart of Program!\n";
    
    /*
    {
        Matrix m(8);
        //Matrix o(m);
    }
    */

    Matrix* m = new Matrix[3];

    std::cout << "End of Program!\n";
}