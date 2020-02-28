#include <iostream>

#if 0 // r-value reference as function parameters

void fun(const int &lref) // l-value arguments will select this function
{
    std::cout << "l-value reference to const \n";
}

void fun(const int &&ref) // r-value arguments will select this function
{
    std::cout << "r-value rference to const \n";
}

void fun(int &&ref) // r-value arguments will select this function
{
    std::cout << "r-value rference \n";
}

int main()
{
    int x{5};
    fun(x); // l-value argument calls l-value version of function
    fun(5); // r-value argument calls r-value version of function

    int &&rref {10};
    fun(rref);

    const int &&rref1 {10};
    fun(rref1);

    return 0;
}

#endif

#if 0 // r-value reference can be initialized with literal.
int main()
{
    int &&rref {5}; // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
    std::cout << rref << '\n';
    rref = 10;
    std::cout << rref << '\n';
    return 0;
}

#endif


#if 1

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int nemerator = 0, int denomenator = 0) : m_numerator{nemerator}, m_denominator{denomenator} {}

    friend std::ostream& operator<<(std::ostream &out, const Fraction &f1)
    {
        out << f1.m_numerator << " / " << f1.m_denominator;
        return out;
    } 
};

int main()
{
    auto &&rref { Fraction{3, 5}};
    std::cout << rref << '\n';

    return 0;
}

#endif


#if 0 // l-value reference, r-value Reference
int main()
{
    int x{5};
    int &lref{x};
    int &&rref{5};
    return 0;
}
#endif