#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class A
{
public:
    void show()
    {
        std::cout << "A show() \n";
    }

private:

};

#if 0 
int main()
{
    std::unique_ptr<A> p1(new A);

    p1->show();
    std::cout << p1.get() << '\n';

    // std::unique_ptr<A> p2(p1); // unique_ptr은 복사생성자를 사용 할 수 없음

    std::unique_ptr<A> p2 = std::move(p1); // 소유권을 p2에 명확히 넘김.
    p2->show();
    std::cout << p1.get() << '\n';
    std::cout << p2.get() << '\n';

    std::unique_ptr<A> p3 = std::move(p2);
    p3->show();
    std::cout << p1.get() << '\n';
    std::cout << p2.get() << '\n';
    std::cout << p3.get() << '\n';

    p1.reset(); // 강제로 p1의 객체를 해제하는 interface. 하지만, out of brace 이후 자동 소멸되기 때문에 호출 필요 없음.
    p2.reset(new A); // reset을 하면서 객체를 다시 할당 할 수도 있음.
    std::cout << "p2.reset(new A) : " << p2.get() << '\n'; // 0x1609c20
    p3.reset(new A);
}
#endif

#if 0

/**
 *  vector에 넣을 때, move함수를 이용하여 넣음.
 */

int main()
{

    std::vector<unique_ptr<A>> v;
    std::unique_ptr<A> ua1(new A);
    // v.push_back(ua1); // Copy simentic이 호출되므로 빌드 에러가 발생함.
    v.push_back(std::move(ua1));
    std::cout << ua1.get() << '\n';

    std::cout << "vector size : " << v.size() << '\n';

    v[0]->show();

    std::unique_ptr<A>& aa = v[0];
    aa->show();
    
    // std::unique_ptr<A> getua = std::move(v[0]); 
    // getua->show();
    // std::cout << "vector size : " << v.size() << '\n';

    // if(v[0] == nullptr)
    // {
    //     std::cout << "v[0] is null \n";
    // }
    // else
    // {
    //    std::cout << "v[0] is  not null \n";
    // }


    

}

#endif

#if 0

class Test
{
public:
    Test()
    {
        std::cout << "Call Constructor. \n";
    }

    ~Test()
    {
        std::cout << "Desructor \n";
    }
};

int main()
{
    std::unique_ptr<Test> p1;
    p1.reset(new Test); // p1은 기존 Test객체의 소유권 획득
    p1.reset(new Test); // p1은 기존 객체는 소멸하고 새로 생성한 Test객체의 소유권 획득
    p1.reset();
}

#endif

#if 0
// release

class Test
{
public:
    Test()
    {
        std::cout << "Call Constructor. \n";
    }

    ~Test()
    {
        std::cout << "Desructor \n";
    }
};

int main()
{
    std::unique_ptr<Test> p1;
    Test *tp = p1.release();

    if(tp)
    {
        std::cout << "own \n";
    }
    else
    {
        std::cout << "nothing \n";
    }

    p1.reset(new Test);
    tp = p1.release(); // p1이 소용하고 있던 객체를 넘겨줌.

    if(p1)
    {
        std::cout << "p1 own \n";
    }
    else
    {
        std::cout << "p1 nothing \n";
    }
    
    if(tp)
    {
        std::cout << "own \n";
    }
    else
    {
        std::cout << "nothing \n";
    }

    std::cout << p1.get() << '\n';
}

#endif

#if 0
// swap

class Test
{
public:
    Test()
    {
        std::cout << "Call Constructor. \n";
    }

    ~Test()
    {
        std::cout << "Destructor \n";
    }
};

int main()
{
    std::unique_ptr<Test> p1 = std::make_unique<Test>();
    std::unique_ptr<Test> p2 = std::make_unique<Test>();

    std::cout << p1.get() << '\n';
    std::cout << p2.get() << '\n';

    p1.swap(p2);

    std::cout << p1.get() << '\n';
    std::cout << p2.get() << '\n';       
}
#endif

#if 0

class Test
{
public:
    int a, b;

    Test() : Test(1, 2)
    {
        std::cout << "Call Constructor. \n";
    }

    Test(int a, int b) : a(a), b(b) {}

    ~Test()
    {
        std::cout << "Destructor \n";
    }
};

int main()
{
    std::unique_ptr<Test> p1 = std::make_unique<Test>(10, 20);

    std::unique_ptr<Test[]> p2 = std::make_unique<Test[]>(4);
    std::cout << p2[0].a  << " " << p2[0].b << '\n';
}
#endif

#if 1

class B
{
public:
    void show()
    {
        std::cout << "B show() \n";
    }

    ~B()
    {
        std::cout << "B Desctructor \n";
    }

private:

};

struct UserDeleter
{
    template<typename T>
    void operator()(T* p)
    {
        std::cout << "User Deleter Fuctor \n";
        delete[] p;
    }
};

int main()
{
    std::unique_ptr<B[], UserDeleter>  pb (new B[4]); 
}

#endif

