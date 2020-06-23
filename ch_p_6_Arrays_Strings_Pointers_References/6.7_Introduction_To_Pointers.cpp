#include <iostream>
#include <typeinfo>

#if 1

char *chPtr{};
int *iPtr{};

struct Something
{
    int x{};
    int y{};
    int z{};
};

Something *somethingPtr{};

int main()
{
    std::cout << sizeof(chPtr) << '\n';
    std::cout << sizeof(iPtr) << '\n';
    std::cout << sizeof(somethingPtr) << '\n';
}

#endif

#if 0

void foo(int *&)
{

}

int main()
{
    int *p;
    foo(p);
    std::cout << *p << '\n';
    return 0;
}

#endif

#if 0
int main()
{
    int x{4};
    std::cout << typeid(&x).name() << '\n';

    int value{5};
    std::cout << &value << '\n';
    std::cout << value << '\n';

    int *iPtr{&value};
    std::cout << iPtr << '\n';
    std::cout << *iPtr << '\n';

    return 0;
}
#endif

#if 0

int main()
{
    int x{5};
    std::cout << x << '\n';
    std::cout << &x << '\n';
    std::cout << *(&x) << '\n';

    int *iPtr{};
    double *dPtr{};

    int v{6};
    int *ptr{&v};
    std::cout << &v << '\n';
    std::cout << ptr << '\n';
    
    return 0;
}
#endif