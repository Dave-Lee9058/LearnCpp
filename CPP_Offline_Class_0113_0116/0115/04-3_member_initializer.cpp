#include <iostream>

class SoSimple
{
private:
public:
    int x, y;
    int &aa;

    int bb;
    int cc;

    SoSimple(int &a, int n1, int n2) : aa{a}, x(n1), y(n2)
    {
        // aa = a;
        
                

    }

    void test()
    {
        int a1 = 5, b2 = 6; // copy initialization
        int c( 7 ), d( 8 ); // direct initialization
        int e{ 9 }, f{ 10 }; // brace initialization (preferred)
    }
};

int main()
{

}