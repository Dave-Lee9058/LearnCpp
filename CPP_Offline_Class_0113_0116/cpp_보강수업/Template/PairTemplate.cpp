#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair(T1 first, T2 second) : first(first), second(second) {}
};

int main()
{
    Pair<int, std::string> p1 (100, "hong");
    Pair<std::string, std::string> p2 ("100", "Kang");

    std::cout << p1.first << ", " << p1.second << '\n';
    std::cout << p2.first << ", " << p2.second << '\n';

    std::pair<int, int> p3 (100, 200);
    std::cout << p3.first << ", " << p3.second << '\n';

    return 0;
}