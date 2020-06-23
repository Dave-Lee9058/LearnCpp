#include <iostream>

/**
 * @brief 
 * c++ supports three types of memory allocation. * 
 *
 * 1. Statc Memory Allocation : happens for static and global variables. 
 *                              Memory for these types of variables is allocated once, when your program is run and persis throughout the life of program.
 * 2. Automatic memory allocation : happens for function parameters and local variables.
 * 
 * 3. Dynamic memory allocation 
 * 
 */

#if 0

int main()
{
    int *ptr{new int};
    *ptr = 7;

    int *ptr1 {new int (5)};
    int *ptr2 {new int {6}};

    delete ptr;
    delete ptr1, ptr2;

    return 0;
}

#endif

#if 1

int main()
{
    int *ptr{new int};
    *ptr = 7;
    std::cout << *ptr  << '\n';
    delete ptr;

    std::cout << *ptr;
    delete ptr;

    return 0;
}

#endif

#if 1

#endif

#if 1

#endif

#if 1

#endif