#include <iostream>


// move segmentics
template<class T>
class Auto_ptr2
{
private:
    T* m_ptr;

public:
    Auto_ptr2(T *ptr = nullptr) : m_ptr(ptr) {}

    ~Auto_ptr2() 
    {
        delete m_ptr;
    }

    // A copy constructor that implements move semantics
    Auto_ptr2(Auto_ptr2& a) // note : not const
    {
        m_ptr = a.m_ptr;    // transfer out dumb pointer from the source to our local object.
        a.m_ptr = nullptr;  // make sure the source no longer owns the pointer.
    }

    // An assignment operator that implements move semantics
    Auto_ptr2& operator=(Auto_ptr2& a)
    {
        if(&a == this)
            return *this;
        
        delete m_ptr;   // make sure we deallocate any pointer the destination is already holding first.

        m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object.
        a.m_ptr = nullptr; // make sure the source no longer owns the pointer.
        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
private:
public:
    Resource() { std::cout << "Resource Acquired \n"; }
    ~Resource() { std::cout << "Resource Destroyed \n"; }
};

int main()
{
    Auto_ptr2<Resource> res1 (new Resource);
    Auto_ptr2<Resource> res2;

    std::cout << "res1 is " << (res1.isNull() ? "null \n" : "not null \n");
    std::cout << "res2 is " << (res2.isNull() ? "null \n" : "not null \n");

    res2 = res1;
    std::cout << "Ownership tranfered \n";

    std::cout << "res1 is " << (res1.isNull() ? "null \n" : "not null \n");
    std::cout << "res2 is " << (res2.isNull() ? "null \n" : "not null \n");
    
    return 0;
}

#if 0
template<class T>
class Auto_ptr1
{
private:
    T *m_ptr;

public:
    Auto_ptr1(T *ptr = nullptr) : m_ptr(ptr)
    {

    }

    ~Auto_ptr1()
    {
        delete m_ptr;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Resource
{
private:
public:
    Resource() { std::cout << "Resource acquired \n"; }
    ~Resource() { std::cout << "Resource destroyed \n"; }
    void sayHi() { std::cout << "Hi \n"; }
};

void someFunction()
{
    Auto_ptr1<Resource> ptr(new Resource);

    int x;
    std::cout << "Enter an integer : ";
    std::cin >> x;

    if(x == 0)
    {
        return;
    }

    ptr->sayHi();
}

void passByValue(Auto_ptr1<Resource> res)
{

}

int main()
{
    // Auto_ptr1<Resource> res(new Resource);

    // someFunction();

    //Auto_ptr1<Resource> res1(new Resource);
  //  Auto_ptr1<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;

    Auto_ptr1<Resource> res1(new Resource);
    passByValue(res1);


    return 0;
}
#endif