#include <iostream>
#include <memory>
using namespace std;

#if 0
int main()
{
    std::shared_ptr<int> sp (new int(4));
    std::cout << sp.get() << '\n';
    std::cout << sp.use_count() << '\n'; // 1
    std::shared_ptr<int> sp1 = sp;
    std::cout << sp.use_count() << '\n'; // 2

    std::weak_ptr<int> wp = sp; // std::weak_ptr은 std::shared_ptr로만 받아서 사용할 수 있음.
    std::cout << sp.use_count() << '\n'; // 2
    {
        std::shared_ptr<int> ts = wp.lock(); // lock()을 이용하여 shared_ptr 기능을 사용 할 수 있음.
        std::cout << sp.use_count() << '\n'; // 3
        if(ts)
        {
            std::cout << "use shared_ptr from weak_ptr \n";
        }
    }
    std::cout << sp.use_count() << '\n'; // 2

    sp1.reset();
    std::cout << sp.use_count() << '\n'; // 1

    sp.reset();
    std::cout << sp.use_count() << '\n'; // 0

}
#endif

#if 1
// shared_ptr circular reference


struct B;

struct A
{
    std::weak_ptr<B> b; // struct A에 member를 weak_ptr로 선언하여 circular reference를 해결할 수 있음.

    ~A()
    {
        std::cout << "A Descructor \n";
    }
};

struct B
{
    std::shared_ptr<A> a;

    ~B()
    {
        std::cout << "B Descructor \n";
    }
};

int main()
{
    auto a = std::make_shared<A> ();

    auto b = std::make_shared<B> ();

    a->b = b;
    b->a = a;    
}

#endif