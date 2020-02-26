
#include <iostream>

void func04();
int adder(int num1 =1, int num2 = 2); // function declaration should be set the default value.

void func03(int a, int b = 20, int c = 10) // it can be set the default arguement from the last.
{
    printf("call func03(%d, %d, %d) \n", a, b, c);
}

int main()
{
    func03(10);
    func03(10, 20);
    func03(10,20,30);
    func04();
    adder();

    int a;
    a++;
    ++a;
    a = a +1;
    a += 1;     

    for(int i = 0; i < 10; ++i) // ++i more than i++ // At STL, ++i is more 30 times high speed than i++.s
    {

    }

    return 0;
}

void func04()
{
    printf("call func04()");
}

int adder(int num1, int num2)
{
    printf("call adder()");
    return num1 + num2;
}