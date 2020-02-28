#include <iostream>
#include <string>
#include <utility>
#include <vector>

#if 1

int main()
{
    std::vector<std::string> v;
    std::string str = "Knock";

    std::cout << "Copying str \n";
    v.push_back(str);

    std::cout << "str : " << str << '\n';
    std::cout << "vector : " << v[0] << '\n';

    std::cout << "\nMoving str\n";

    v.push_back(std::move(str));
    std::cout << "str : " << str << '\n';
    std::cout << "vector : " << v[0] << " " << v[1] << '\n';

    return 0;
}

#endif

#if 0

template<class T>
void myswap(T &a, T &b)
{
    T temp {std::move(a)}; // invoke move constructor (std::move에 의해 a(l-value) 가 r value로 return이 되고, move semantics가 사용됨.)
    a = std::move(b); // invokes move assignment
    b = std::move(temp); // invokes move assignment
}

int main()
{
    std::string x{"abc"};
    std::string y {"de"};

    printf("x : %s \n", x.c_str());
    printf("y : %s \n", y.c_str());

    myswap(x, y);

    printf("x : %s \n", x.c_str());
    printf("y : %s \n", y.c_str());

    
    return 0;
}

#endif

#if 0

template<class T>
void myswap(T &a, T &b)
{
    T temp {a};
    a = b;
    b = temp;
}

int main()
{
    std::string x{"abc"};
    std::string y {"de"};

    printf("x : %s \n", x.c_str());
    printf("y : %s \n", y.c_str());

    myswap(x, y);

    printf("x : %s \n", x.c_str());
    printf("y : %s \n", y.c_str());

    
    return 0;
}

#endif