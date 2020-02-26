#include <iostream>

#define SQUARE(x) ((x) * (x)) // values variable should be braced with ()

#define FUNC05(x) x + x

#define FUNC06(x) (x + x)


int main()
{

    printf("%d \n", SQUARE(5));
    printf("%d \n", FUNC05(3));
    printf("%d \n", FUNC05(3) * FUNC05(3));
    printf("%d \n", FUNC06(3) * FUNC06(3));

    printf("%d", std::abs(-3));


    
    return 0;
}