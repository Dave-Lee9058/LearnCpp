#include <iostream>

class A
{
private:

public:
    A()
    {
        printf("Call A Constructor \n");
    }

    virtual ~A() // Virtual Destructor //If it is added the virtual keyword, It can be called the deconstructor of the son.
    {
        printf("Call A Destructor \n");
    }
};

class B : public A
{
private:

public:
    B()
    {
        printf("Call B Constructor \n");
    }

    ~B()
    {
        printf("Call B Destructor \n");
    }
};

int main()
{
    A * a = new B;
    delete a;

    return 0;
}