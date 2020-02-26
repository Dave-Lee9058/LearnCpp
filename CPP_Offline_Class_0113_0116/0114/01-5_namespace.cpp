#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "BestComImpl SimpleFunc() \n";
    }
} // namespace BestComImpl

namespace ProgComImpl
{
    void SimpleFunc()
    {
        std::cout << "ProgComImpl SimpleFunc() \n";
    }
} // namespace ProgComImpl

#define RED     0
#define BLUE    1
#define GREEN   2

enum 
{
    RED1 = 0, 
    BLUE1, 
    GREEN1
};

using namespace BestComImpl;
using namespace std;

int main()
{

    std::cout << "Hello world!!" << std::endl;

    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    SimpleFunc();

    return 0;
}