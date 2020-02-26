#include <iostream>
#include <memory> // need to include memory for smartpoint

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

int main()
{
    std::auto_ptr<A> p1(new A);
    p1->show();

    std::cout << p1.get() << '\n'; // 0x650c20

    std::auto_ptr<A> p2(p1); // ++11 부터 auto_ptr deprecate 됩 ++17에서는 제외가 됨.
    std::cout << p1.get() << '\n'; // 0
    std::cout << p2.get() << '\n'; // 0x650c20

}

/**
 *  auto_ptr의 복사생성자와 대입연산자는 가지고 있는 객체를 복사하지 않고 이동하는 개념으로 기존의 것을 비운다.
 *  Copy simentic 이 요구되는 곳에서 문제가 될 수 있음.
 * 
 */
