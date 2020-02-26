#include <iostream>
#include <cstring>
#include <string>
#include <functional>

using namespace std;

template<typename T>
struct Less
{
    bool operator() (T n1, T n2) 
    {
        return n1 < n2;
    }
};

template<typename T>
struct Greator
{
    bool operator() (T n1, T n2)
    {
        return n1 > n2;
    }
};

int main()
{
    std::cout << Less<int>()(10, 20) << '\n';
    std::cout << Greator<int>()(10, 20) << '\n';

    std::cout << std::less<int>()(10, 20) << '\n';
    std::cout << std::greater<int>()(10, 20) << '\n';
    
    return 0;
}


#if 0
template<typename T1, typename F>
void For_each(T1 *sarr, T1* earr, F f)
{
    while(sarr != earr)
    {
        f(*sarr++);
    }
    std::cout << '\n';
}

template<typename T>
class PrintFunctor
{
private:
    std::string sep;
public:
    PrintFunctor(const std::string sep = " ") : sep(sep) {}

    void operator()(T n)
    {
        std::cout << n << sep;
    }
};

template<typename T1>
void Print(T1 n)
{
    std::cout << n << " ";
}

int main()
{
    int narr[] = {10, 20, 30, 40, 50};
    For_each<int>(narr, narr+5, Print<int>);
    
    For_each<int>(narr, narr+5, PrintFunctor<int>());
    
    std::string sarr[] = {"banana", "orange", "melon"};
    For_each<std::string>(sarr, sarr+3, Print<std::string>);
    
    For_each<std::string>(sarr, sarr+3, PrintFunctor<std::string>());
    
    return 0;
}
#endif

#if 0
template<typename T>
class Data
{
private:
    T data;
public:
    Data(T t): data(t) 
    {}

    void Print()
    {
        std::cout << "Type : " << typeid(data).name() << '\n';
        std::cout << "Size : " << sizeof(data) << '\n';
        std::cout << "Value : " << data << '\n';
    }
};

template<>
class Data <char *>
{
private:
    char* data;
public:
    Data(char *t): data(new char[strlen(t)]) 
    {
        strcpy(data, t);
    }


    void Print()
    {
        std::cout << "Type : " << typeid(data).name() << '\n';
        std::cout << "Size : " << sizeof(data) << '\n';
        std::cout << "Value : " << data << "\n\n";
    }
};

int main()
{
    Data<int> intData (10);
    intData.Print();

    Data<double> doubleData (21.5);
    doubleData.Print();

    Data<char *> charData("Test");
    charData.Print();

    return 0;
}

#endif