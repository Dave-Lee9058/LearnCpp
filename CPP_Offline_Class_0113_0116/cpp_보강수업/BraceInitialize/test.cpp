#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {}
    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName() const
    {
        return this->name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge() const
    {
        return this->age;
    }

    friend ostream& operator<< (ostream &out, const Person &p)
    {
        out << p.getName() << ", " << p.getAge() << '\n'; 
        return out;
    }
};

// ostream& operator<< (ostream &out, const Person &p)
// {
//     out << p.getName() << ", " << p.getAge() << '\n'; 
//     return out;
// }

int main()
{
    Person p ("Park", 30);
    std::cout << p << '\n';
    return 0;
}
