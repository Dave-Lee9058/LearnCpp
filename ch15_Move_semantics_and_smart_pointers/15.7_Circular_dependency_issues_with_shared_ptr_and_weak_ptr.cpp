#include <iostream>
#include <memory>
#include <string>
 
#if 0 // std::weak_ptr

class Person
{
private:
    std::string m_name;
    std::weak_ptr<Person> m_partner;

public:
    Person(const std::string &name) : m_name(name) 
    {
        std::cout << m_name << " created. \n";
    }

    ~Person()
    {
        std::cout << m_name << " destoryed. \n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if(!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

        return true;
    }

    const std::shared_ptr<Person> getPartner() const { return m_partner.lock(); }
    const std::string getName() const { return m_name; }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucky");
    auto ricky = std::make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);

    auto partner = ricky->getPartner();
    std::cout << ricky->getName() << "'s partner is : " << partner->getName() << '\n';

    return 0;
}

#endif


#if 1  // reductive case

class Resource
{
private:
public:
    std::weak_ptr<Resource> m_ptr;

    Resource() { std::cout << "Resource acquired. \n"; }
    ~Resource() { std::cout << "Resource destroyed. \n"; }
};

int main()
{
    auto ptr1 = std::make_shared<Resource>();

    ptr1->m_ptr = ptr1;

    return 0;
}

#endif

#if 0

class Person
{
private:
    std::string m_name;
    std::shared_ptr<Person> m_partner;

public:
    Person(const std::string &name) : m_name(name) 
    {
        std::cout << m_name << " created. \n";
    }

    ~Person()
    {
        std::cout << m_name << " destoryed. \n";
    }

    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if(!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

        return true;
    }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucky");
    auto ricky = std::make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);

    return 0;
}


#endif