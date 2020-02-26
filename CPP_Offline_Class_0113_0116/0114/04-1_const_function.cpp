#include <iostream>

class Apple
{
public:
    int x;

    void func01() const 
    {
        // x = 10; // cannot change the memeber variable.
    }
};

int main()
{
    return 0;
}