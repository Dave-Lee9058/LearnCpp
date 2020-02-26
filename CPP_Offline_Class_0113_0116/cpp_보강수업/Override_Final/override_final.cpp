#include <iostream>

class A
{
public:
    virtual void func() {}

    virtual void func2() final {}

private:

};

class B : public A
{
public:
    virtual void func(int a) {} // overload

    virtual void func() override {}

    // virtual void func2() {}; // final로 Override 금지  

private:

};



int main()
{

}