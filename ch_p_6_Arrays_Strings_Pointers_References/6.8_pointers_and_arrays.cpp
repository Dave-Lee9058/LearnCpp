#include <iostream>

#if 1

void changeArray(int *ptr)
{
    *ptr = 5;
}

int main()
{
    int array[] {1,1,2,3,5,8,13,21};
    std::cout << array[0] << '\n';

    changeArray(array);

    std::cout << array[0] << '\n';

    return 0;
}

#endif


#if 0

void printSize(int array[])
{
    std::cout << sizeof(array) << '\n';
}

int main()
{
    int array[]{1,1,2,3,5,8,13,21};
    std::cout << sizeof(array) << '\n';
    std::cout << sizeof(array) / sizeof(array[0]) << '\n';
    printSize(array);
    return 0;
}


#endif

#if 0

void printSize(int *array)
{
    std::cout << sizeof(array) << '\n';
}

int main()
{
    int array[]{1,1,2,3,5,8,13,21};
    std::cout << sizeof(array) << '\n';
    std::cout << sizeof(array) / sizeof(array[0]) << '\n';
    printSize(array);
    return 0;
}

#endif

#if 0
int main()
{
    int array[5] {9,7,5,3,1};

    std::cout << &array[0] << '\n';
    std::cout << array << '\n';
    std::cout << *array << '\n';

    char name[] {"Jason"};
    std::cout << name << '\n';
    std::cout << *name << '\n';

    std::cout << sizeof(array) << '\n';

    int *ptr{array};
    std::cout << sizeof(ptr) << '\n';

    return 0;
}
#endif