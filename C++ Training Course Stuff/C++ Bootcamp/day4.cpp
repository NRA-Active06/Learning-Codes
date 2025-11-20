#include <iostream>

template < typename MyType, unsigned M, unsigned N >

class Matrix
{
public:
private:
    MyType* data(M*N);
};

class MyFloatType
{
public:
    MyFloatType operator*(...)
    {}
};

//void AddFloatMatrix(const Matrix<float>& a, const Matrix<float>& b)
//{};

void AddIntMatrix(const Matrix<MyType, 4, 4>& a, const Matrix<MyType, 4, 4>& b)
{
};

//void AddInMatrix(const Matrix<float>& a, const Matrix<float>& b)
//{}

/*

enum ReturnCodes
{
    SUCCESS = 0,
    OUT_OF_RANGE,
    SOME_OTHER_ERROR
}

ReturnCodes other(){
}

ReturnCodes sqrt(float f, float& result)
{
    ReturnCodes result = other();
    if (result != SUCCESS){

    }

    if (f < 0.0f)
    {
        return INPUT_OUT_OF_RANGE;
    }
}

int someFN(float f, float& result)
{
    //std::sqrt
    if (f < 0.0f)
    {
        return INPUT_OUT_OF_RANGE;
    }

    result = ///;
    return SUCCESS;
}

int main(int, char**)
{
    //float f = ...;
    float result;
    ReturnCodes result = 5;
}
 */