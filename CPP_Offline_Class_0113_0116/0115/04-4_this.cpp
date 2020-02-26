#include <iostream>

class Apple
{
private:

public:
    Apple() {}

    Apple* func01()
    {
        printf("Call func01() \n");
        return this;
    }

    Apple& func02()
    {
        return *this;
    }

    Apple* func03()
    {
        return func02().func01();
    }
};

int main()
{
    return 0;
}