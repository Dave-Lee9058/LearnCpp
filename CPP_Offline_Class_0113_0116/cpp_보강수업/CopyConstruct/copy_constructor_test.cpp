#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

class Person
{
public:
    char *name;
    int age;

public:
    Person(char *name_, int age_) : age(age_) 
    {
        name = new char[20];
        strcpy(name, name_);
    }

    Person(const Person &p)
    {
        delete[] name;
        name = new char[20];
        strcpy(name, p.name);
        age = p.age;
    }

    ~Person()
    {
        if(name)
        {
            delete[] name;
        }
    }

    void show()
    {
        std::cout << name << " : " << age << std::endl;
    }
};

int main()
{
    int n(10);
    Person p1("LDS", 20);
    Person p2 = p1; // p2(p1);
    // p2.name = "HGD";
    p1.show();
    p2.show();
    return 0;
}