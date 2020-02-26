#include <iostream>

class A
{
private:
public:
    virtual void AAA()
    {
        std::cout << "AAA" << std::endl;
    }
};

class B : public A
{
private:
public:
    void AAA()
    {
        
    }
};

int main()
{

    return 0;
}