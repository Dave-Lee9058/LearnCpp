#include <iostream>
#include <string>
#include <cstring>

template<typename T, int size>
void printArr(T* arr)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}


int main()
{
    int arr[] = {1,2,3,4,5};
    double darr[] = {1.23, 2.34};
    printArr<int, 5>(arr);
    printArr<double, 2>(darr);

    return 0;
}

#if 0
template <typename T>
T Max(T n1, T n2)
{
    return n1 > n2 ? n1 : n2;
}

// template 특수화
template<>
const std::string& Max(const std::string &s1, const std::string &s2)
{
    return (s1.length() > s2.length()) ? s1 : s2;
}


template<>
const char* Max(const char* s1, const char* s2)
{
    return strlen(s1) > strlen(s2) ? s1 : s2;
}


int main()
{
    std::cout << Max(3, 5) << '\n';
    std::cout << Max(10.3, 21.9) << '\n';
    std::cout << Max("hong", "gildong") << '\n';
    std::cout << Max(std::string("hong"), std::string("gildong")) << '\n';
    return 0;
}
#endif

#if 0
template <typename T1, typename T2>
void change(double n)
{
    std::cout << (T1)n << ", " << (T2)n << '\n';
}

int main()
{
    change<int, char>(3.14); // type casting인 경우에는 type생략을 하지 못함.
    return 0;
}
#endif

#if 0
template<typename T1, typename T2> 
void Print(T1 n1, T2 n2)
{
    std::cout << n1 << " , " << n2 << '\n';
}

int main()
{
    Print(10, 3.14);
    Print(5.15, "Hong");

    Print<int, double>(10, 3.14);
    Print<double, char*>(5.15, "Hong");

    return 0;
}
#endif

#if 0
template<typename T>
void Print(T t1, T t2)
{   
    std::cout << t1 << " , " << t2 << "\n";
}

int main()
{
    Print(10, 10);
    Print(3.14, 3.14);
    Print("Hong", "Park");

    Print<int>(10, 10);
    Print<double>(3.14, 3.14);
    Print<char*>("Hong", "Park");
    return 0;
}
# endif