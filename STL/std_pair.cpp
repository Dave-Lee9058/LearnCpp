#include <iostream>
#include <utility>

int main()
{
    std::pair<int, int> foo;
    std::pair<int, int> bar {30, 40};

    foo = std::make_pair<int,int>(10, 20);

    std::cout << foo.first << " " << foo.second << '\n';
    std::cout << bar.first << " " << bar.second << '\n';

    return 0;
}