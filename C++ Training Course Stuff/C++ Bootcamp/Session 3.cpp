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

class Factory
{
    Factory() {}
public:
    static std::unique_ptr<Factory> create() {
        return std::make_unique<Factory>();
    }
};

void fn()
{
    Factory::create();
}

class Temp
{
public:
    float faren() const {}
    float celcius() const {}
private:
    // temperature in Kevin
    float val;
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

class HasLegs
{
public:
    virtual int getNumLegs() = 0;
};

class CanSpeak
{
public:
    virtual void speak() = 0;
};

class Animal : public HasLegs, public CanSpeak
{
public:
    Animal() {}

    virtual void speak() override
    {
        std::cout << "this animal does not speak\n";
    }

    virtual int getNumLegs() override {return 0;}

    int i;

    virtual ~Animal() = default;
};


class Dog final : public Animal
{
public:
    void speak() override
    {
        std::cout << "wooof\n";
    }

    int getNumLegs() override
    {
        return 4;
    }
};

void myfn()
{
    // only initialised once at first call.
    static int i = 0;
    // effectively counts number of times
    // function was called.
    // Dagerous with threading.
    i++;
}

class String
{
    char * data;
    String()
    {
        data = new char[32];
    }

    char& operator[](int index)
    {
        return data[index];
    }

    ~String()
    {
        delete[] data;
    }
};

int main(int, char**)
{
    Animal a;
    Dog d;

    Animal* ptrToA = &d;
    Animal* ptr = &a;
    Dog* ptrToD = static_cast<Dog*>(ptrToA);

    Animal* aptr = new Dog;
    delete aptr;

    Km k(3.0f);
    Km k2(5.0f);

    Km k3(0.0f);

    k = k + k2;

    std::cout << k3;
}