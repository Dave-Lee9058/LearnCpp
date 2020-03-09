#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class MyClass
{
public:
    MyClass() { printf("Called default constructor.. \n"); }

    MyClass(int num, string name) : m_Number{num}, m_Name{name} 
    {
        printf("Called Consructor which has a parameter \n");
    } 

    MyClass(const MyClass &mc) : m_Number{mc.m_Number}, m_Name{mc.m_Name} 
    {
        printf("Called Copy Consructor.. \n");
    }

    // MyClass(MyClass &&right) : m_Number{right.m_Number}, m_Name{right.m_Name}
    // {
    //     printf("Called Move Consructor.. \n");
    // }

    ~MyClass()
    {
        printf("%s, Called Destructor.. \n", m_Name.c_str());
    }

    const int getNumber() const { return m_Number; }

private:
    int m_Number;
    string m_Name;
};


std::unique_ptr<MyClass> createMyClass()
{
    return std::make_unique<MyClass>(4, "Test4");
}

int main()
{
    std::vector<MyClass> vecTest;

    printf("## 1 ## \n");

    // vecTest.push_back(MyClass(1, "Test1"));

    vecTest.emplace_back(2, "Test2");

    // std::unique_ptr<MyClass> mcPtr {std::make_unique<MyClass>(3, "Test3")};
    // vecTest.emplace_back(*(mcPtr.release()));

    // std::unique_ptr<MyClass> mc4Ptr = createMyClass();
    // vecTest.emplace_back(*(mc4Ptr.get()));

    printf("## 2 ## \n");
    
    return 0;
}
