#include <iostream>

const char* getName()
{
    return "Alex";  // String literals have static duration ranther than automatic duration.
}

int main()
{
    char myName[] {"Alex"};
    std::cout << myName << '\n';

    const char *myName2 {"Alex2"};
    std::cout << myName2 << '\n';

    char c{'Q'};
    std::cout << &c << '\n';

    return 0;
}