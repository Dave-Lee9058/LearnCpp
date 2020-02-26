#include <iostream>
using namespace std;

/**
 * What is the class?
 * 1. constructor
 * 
 * 2. field
 * 
 * 3. function(Method) 
 *  
 */

void func09()
{
    struct STRU
    {
        int a, b;
    };

/**
 * 1. struct / class difference
 *  1. initialize as the following
 *  2. Default Struct -> public, class -> private
 * 
 */
    STRU stru {10, 20}; // It cannot initialize at the class. It is different with the class.

    printf("a : %d, b : %d \n", stru.a, stru.b);
}

class STRU
{
    int a;

public:
    void func_01()
    {
        printf("call STRU::func_01() \n");
    }

    void func_02();

    enum 
    {
        RED = 10,
        BLUE = 20,
    };
};

void STRU::func_02() // implement the method of the struct. Because it can be separate with header and cpp file.
{
    printf("call STRU::func_02() \n");
    printf("RED : %d \n", RED);
}

int main()
{
    STRU stru;
    stru.func_02();

    return 0;
}