#include <iostream>

class Apple 
{
private:
    int m_a;
    int m_b;

public:
    // Constructor
    Apple() 
    {
        printf("Call Apple Default Consructor \n");
        m_a = 0;
        m_b = 0;
    }

    Apple(int m_a, int m_b)
    {
        printf("Call  Apple(int a, int b) Consructor \n");
        this->m_a = m_a;
        this->m_b = m_b;
    }

    void printValue()
    {
        printf("a : %d, b : %d \n", m_a, m_b);
    }

    ~Apple()
    {
        printf("Call Apple Deconsructor (a:%d, b:%d) \n", m_a, m_b);
    }
    // Insert the following at the class Automatically
    // 1. default Constructor
    // 2. Apple *this
    // this = &a
    // 3. copy consructor 
};

int main()
{
    Apple a1;
    a1.printValue();

    Apple a2(10 , 20);
    a2.printValue();    

    return 0;
}