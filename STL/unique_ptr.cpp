#include <iostream>
#include <memory>

struct Capa
{
    int value;
    std::unique_ptr<int> a;

    Capa() : value(1) {} 

};


int main()
{
    std::unique_ptr<Capa> cp {std::make_unique<Capa>()};

    std::cout << cp->value << '\n';

    if(cp->a != nullptr)
    {
        std::cout << "a is not null \n";
    }
    else
    {
        std::cout << "a is null : " << cp.get() << "\n";
    }
    
    return 0;
}