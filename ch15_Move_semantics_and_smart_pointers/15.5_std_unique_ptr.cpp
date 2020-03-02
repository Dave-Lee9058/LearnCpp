#include <iostream>
#include <memory>

#if 1 

#include <iostream>
 
class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };
 
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}
 
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << "/" << f1.m_denominator;
		return out;
	}
};
 
void printFraction(const Fraction* const ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
}
 
int main()
{
	// Fraction *ptr{ new Fraction{ 3, 5 } };

    std::unique_ptr<Fraction> ptr {std::make_unique<Fraction>(3, 5) };
 
	printFraction(ptr.get());
 
	// delete ptr;
 
	return 0;
}

#endif

#if 0

class Resource
{
private:

public:
    Resource() { std::cout << "Resource Acquired. \n"; }
    ~Resource() { std::cout << "Resource destroyed. \n"; }

    friend std::ostream& operator<<(std::ostream &out, const Resource &res)
    {
        out << "I am a resource \n";
        return out;
    }
    
};

void takeOwnership(std::unique_ptr<Resource> res)
{
    if(res)
        std::cout << *res << '\n';
}

void useResource(Resource *res)
{
    if(res)
        std::cout << *res << '\n';
    else
    {
        std::cout << "res is null \n";
    }
    
}

int main()
{
    auto ptr { std::make_unique<Resource>() };

    takeOwnership(std::move(ptr));

    std::cout << "Ending Program \n";

    auto ptr1 { std::make_unique<Resource>() };
    useResource(ptr1.get());
    std::cout << "Ending Program2 \n";
    return 0;
}

#endif

#if 0

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};
public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator} {}

    friend std::ostream& operator<<(std::ostream &out, const Fraction &f1)
    {
        out << f1.m_numerator << " / " << f1.m_denominator << '\n';
        return out;
    }

};

std::unique_ptr<Fraction> createFraction()
{
    return std::make_unique<Fraction>();
}


int main()
{
    std::unique_ptr<Fraction> f1 {std::make_unique<Fraction>(3, 5)};
    std::cout << *f1 << '\n';

    auto f2 {std::make_unique<Fraction[]> (4) };
    std::cout << f2[0] << '\n';

    std::unique_ptr<Fraction> f3 { createFraction() };
    if(f3) 
    {
        printf("f3 is not null \n");
    } 
    else
    {
        printf("f3 is null \n");
    }
    
    return 0;
}

#endif


#if 0

class Resource
{
private:

public:
    Resource() { printf("Resource Acquired. \n"); }
    ~Resource() { printf("Resource destroyed. \n"); }

    friend std::ostream& operator<<(std::ostream &out, const Resource &res)
    {
        out << "I am a resource\n";
        return out;
    }
};

int main()
{
    std::unique_ptr<Resource> res1 { new Resource{} };
    std::unique_ptr<Resource> res2{};

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null \n" : "null \n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null \n" : "null \n");

    res2 = std::move(res1);
    std::cout << "Ownership transferred \n";

    std::cout << "res1 is " << (static_cast<bool>(res1) ? "not null \n" : "null \n");
    std::cout << "res2 is " << (static_cast<bool>(res2) ? "not null \n" : "null \n");

    if (res2)
        std::cout << *res2 << '\n';

    return 0;
}

#endif