#include <iostream>

class A
{
public:
    A() = default;
    A(short b) : s(b) {}
    A(float a, short b) : f(a), s(b) {}

    void setF(float x)
    {
        // is f in range?
        if (x < 0.0f || x > 1.0f) return;
        f = x;
    }

    ~A() {}

private:
    float f = 0;

protected:
    short s = 3;
};

class B0 : public A
{
public:
    B0()
    {
    }

    short myFn() const
    {
        return s;
    }

    long myL() const
    {
        return l;
    }

private:
    long l = 0;
};


class B1 : public A
{
};

class C1 : public B1
{
};

class D0 : public B0, public B1
{
};

void someFn(const A& a)
{
    // ...
}

struct Mile
{
    float value;
};

class Km
{
public:
    Km() = delete;

    explicit Km(float f) : value(f)
    {
    }

    float getValue() const
    {
        return value;
    }

private:
    float value;
};

Km operator +(const Km& k0, const Km& k1)
{
    float f = k0.getValue() + k1.getValue();
    return Km(f);
}

std::ostream& operator <<(std::ostream& out,
                          const Km& km)
{
    return out << km.getValue() << "km";
}

int main(int, char**)
{
    Km k(3.0f);
    Km k2(5.0f);

    Km k3(0.0f);

    k = k + k2;

    std::cout << k3;
}