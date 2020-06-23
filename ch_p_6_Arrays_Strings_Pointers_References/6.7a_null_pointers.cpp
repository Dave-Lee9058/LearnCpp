#include <iostream>
#include <cstddef>

#if 1

void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}
 
void print(int *x)
{
	if (!x)
		std::cout << "print(int*): null\n";
	else
		std::cout << "print(int*): " << *x << '\n';
}

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething() \n";
}

int main()
{
    int*x{nullptr};

    print(x);
    print(0);
    print(nullptr);

    doSomething(nullptr);
    
    return 0;
}
#endif

#if 0
int main()
{
    double *ptr {0};

    if(ptr)
        std::cout << "Not null" << '\n';
    else
    {
        std::cout << "NULL" << '\n';
    }
    
    return 0;
}

#endif