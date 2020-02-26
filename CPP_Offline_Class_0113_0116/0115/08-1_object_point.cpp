#include <iostream>

class A
{
public:
    A()
    {
        //printf("call A construct \n");
    }

    void funcA()
    {
        printf("Call funcA() \n");
    }

    virtual void funcB()
    {
        printf("call funcB_1() \n");
    }
};

class B : public A
{

public:
    B()
    {
        //printf("call B construct \n");
    }
    
    void funcB()
    {
        printf("call funcB_2() \n");
    }

    void funcB1()
    {
        printf("call funcB1() \n");
    }
};

int main()
{
    A *t1 = new A;
    t1->funcA();
    delete t1;

    A *t2 = new B;
    t2->funcA();
    t2->funcB();
    delete t2;

    B* t3 = (B*)new A;
    t3->funcA();
    t3->funcB1();
    t3->funcB();
    delete t3;


    return 0;
}