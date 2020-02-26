#include <iostream>
#include <string>

using namespace std;

enum class CHARTOR_CLASS : short 
{
    TANK,
    MARINE,
    DROPSHIP,
};

int main()
{
    CHARTOR_CLASS unit = CHARTOR_CLASS::TANK;

    // short unints = CHARTOR_CLASS::MARINE; // 불허 

    std::cout << static_cast<short>(unit) << '\n';
}