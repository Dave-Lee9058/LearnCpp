#include <iostream>
#include "orange.h"

class Apple // the first char
{
private:
    int a;

public:
    int b;

private:
    void func01() 
    {
        printf("call func01() \n");
        a = 10;
        b = 20; 

        // func02();
    }

public:
    void func02() 
    {
        printf("call func02() \n");

        func01();
    }
};

/*
Header File
1.define 
2. typdef
3. enum
4. function declration
5. inline / macro function
6. struct
*/

// class Orange 
// {
// public:
//     int a, b;

//     void func01();

// };

// void Orange::func01()
// {
//     printf("call Orange::func01() \n");
// }

int main()
{
    Apple apple;

    apple.func02();

    Orange orange;
    orange.func01();

    return 0;
}