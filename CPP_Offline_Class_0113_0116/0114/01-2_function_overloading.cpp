#include <iostream>

void func01()
{
    printf("call func01() \n");
}

void func01(int a)
{
    printf("call func01(%d) \n", a);
}

void func01(int a, int b)
{
    printf("call func01(%d, %d) - int type \n", a, b);
}

void func01(short a, short b)
{
    printf("call func01(%d, %d) - short type", a, b);
}

int func02()
{
    printf("call func02() \n");
}

// short func02() // return cannot accept the function overloading.
// {
//     printf("call func02() \n");
// }

void func03(int a, int b, int c = 10)
{
    printf("call func03() \n");
}

int main()
{
    func01();
    func01(10);
    func01(10, 20);
    func01((short)10, (short)20); // function call 

    // int a, b;
    // a = (int)b;  // type casting
    // a = b;
    
    return 0;
}