#include <iostream>

/*
Apply Automatically
1. Default Constructor
2. Class this (ex> Apple *this)
3. Copy Constructor
*/

class SoSimple
{
private:
    int num1;
    int num2;
    int *p;

public:
    SoSimple(int n1, int n2) : num1(n1), num2(n2), p(new int)
    {
        // p = new int;
        printf("call Construct \n");
    }

    SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2), p(new int)
    {
        printf("call Copy Constructor \n");
    }

    void ShowSimpleData()
    {
        printf("num1 : %d, num2 : %d, p address : %p \n", num1, num2, p);
    }

    ~SoSimple()
    {
        if(p != nullptr)
        {
            delete p;
        }
        
    }
};

int main()
{
    SoSimple sim1(15, 20);
    sim1.ShowSimpleData();
    printf("%d, %p \n", 1, &sim1);

    SoSimple sim2 = sim1;
    sim2.ShowSimpleData();
    printf("%d, %p\n", 2, &sim2);
    // SoSimple sim2(sim1);

    SoSimple sim3(sim1);
    sim3.ShowSimpleData();
    printf("%d, %p \n", 3, &sim3);

    
    return 0;
}