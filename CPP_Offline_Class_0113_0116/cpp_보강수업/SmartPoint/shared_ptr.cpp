#include <iostream>
#include <memory>

using namespace std;

// class A
// {
// public:
//     void show()
//     {
//         std::cout << "A show() \n";
//     }

//     ~A()
//     {
//         std::cout << "A Desctructor \n";
//     }

// private:

// };

#if 0

int main()
{
    std::shared_ptr<A> p1 (new A);
    std::shared_ptr<A> p2(p1);

    std::cout << p1.get() << '\n';
    std::cout << p2.get() << "\n";

    std::cout << "User Count : " << p2.use_count() << '\n'; 

    p1.reset();

    std::cout << "User Count : " << p2.use_count() << '\n'; 

}

#endif

#if 1
// shared_ptr circular reference

struct B;

struct A
{
    std::shared_ptr<B> b;

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