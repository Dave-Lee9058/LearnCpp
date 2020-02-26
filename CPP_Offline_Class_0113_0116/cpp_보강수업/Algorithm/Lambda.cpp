/*
lambda함수 또는 무명함수 라고 부르기도 한다.
lambda는 함수 오브젝트이다.
c++ 표현력을 증가시켜 준다.
STL 알로리즘을 더 간편하게 사용할 수 있다.
규격에서는 labda는 특별한 타입을 가지고 있다고 한다.
단, decltype 나 sizeof에서 사용 할 수 없다. 
int main()
{
    [] // Labda Capture
    () // Parameter
    {} // Body
    () // call lambda.
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>

#if 0 
template<typename F>
void func(F fn)
{
    fn();
}


int main()
{
    int a;
    decltype(a) b;

    []() { std::cout << "Hello Lambda \n"; }();

    [](int a, int b) { std::cout << "a + b = " << a + b << '\n'; }(10, 20);

    auto f1 = []{ std::cout << "Test \n"; };
    f1();

    std::function<void(void)> f2 = [] { std::cout << "Function Test \n"; };
    f2();

    func(f1);

    func([] { std::cout << "## Function Test ##\n"; });

    func(f2);

}
#endif

#if 0

int main()
{
    [](int n){ std::cout << "I have " << n << '\n'; }(20);

    auto f1 = [](int a, int b){ std::cout << "a + b = " << a + b << '\n'; };
    f1(10, 20);

    std::function<void(int, int)> f2 = [](int a, int b){ std::cout << "funtion a + b = " << a +  b << '\n'; };
    f2(30, 40);
}

#endif

#if 0

int main()
{
    int ret = [](int x, int y) -> int { return x + y; }(10, 20);
    std::cout << "ret : " << ret << '\n';

    int ret1 = [](int x, int y) { return x + y; }(30, 40);
    std::cout << "ret1 : " << ret1 << '\n';

    std::function<int(int, int)> f1 = [](int x, int y) { return x + y; };
    std::cout << "f1 function ret : " << f1(40, 50) << '\n';


    std::vector<int> v;
    v.push_back(12);
    v.push_back(34);
    v.push_back(23);
    v.push_back(38);

    std::for_each(v.begin(), v.end(), [](int n) { 
        if( n < 30) 
        {
            std::cout << n << " ";
        } 
        });

}

#endif

#if 0
// Lambda Return

std::function<int(int, int)> adder()
{
    std::function<int(int, int)> f = [](int x, int y) { return x + y; };
    return f;
}

int main()
{
    auto f = adder();
    std::cout << f(10, 20) << '\n';

    std::cout << adder()(30, 40) << '\n';

}

#endif

#if 0

int main()
{
    int x = 10;

    // 참조
    [&]() { 
        std::cout << x << '\n'; 
        x = 20;
        }();

    std::cout << x << '\n';

    int y = 100;

    [=]() { 
        std::cout << y << '\n'; 
        // y = 200; // 값 변경 못함.
        }();

    int z = 200;

    [=]() mutable { 
        std::cout << "z: " << z << '\n'; 
        z = 300; // 안에서만 사용, 원본은 변경하지 않음.
        std::cout << "z: " << z << '\n';
        }();
    std::cout << "z: " << z << '\n';
}

#endif

#if 0

int main()
{
    int n1, n2, n3, n4, n5;

    [&, n1, n2]{}; // n1, n2는 값 복사, 나머지는 reference

    [=, &n1, &n2]{}; // n1, n2는 reference, 나머지는 값만 사용 가능

    // [&n1, n1]{};  // n1을 권한을 중복 사용 안됨, error

    // [&, &n1]{}; // 권한 중복 사용 안됨., error

    // [=, n1]{}; // error


}

#endif

#if 0

class Person
{
public:
    Person(std::string name, int age) : name(name), age(age) {}

    std::function<void(void)> info = [=](){ std::cout << "Name : " << name << " " << "Age  : " << age << '\n'; };

private:
    std::string name;
    int age;

};

int main()
{
    Person p ("Hong", 20);
    p.info();
}

#endif

#if 1
using namespace std;

bool HasHong(string who)
{
     return (who.find("홍") != string::npos); 
	 //string::find() 함수는 찾는 문자열이 없으면 string::npos를 리턴한다.
}

int main()
{
	string names[]={"홍길동","유재석","강호동",
		"송대한","송민국","송만세","이동국"};
	vector<string> as(&names[0],&names[7]);
	vector<string>::iterator it;
	// it=find_if(as.begin(), as.end(), HasHong);
    it=find_if(as.begin(), as.end(), [](std::string who){ return (who.find("홍") != string::npos);} );

	if (it==as.end()) {
		cout << "없다" << endl;
	} else {
		cout << *it << endl;
	}
}

#endif