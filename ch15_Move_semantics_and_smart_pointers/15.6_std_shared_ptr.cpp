#include <iostream>
#include <memory>

#if 1
class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
    auto ptr1 = std::make_shared<Resource>();
    {
        auto ptr2 = ptr1;
        std::cout << "Killing one shared pointer. \n";
    }

    std::cout << "Killing another shared pointer. \n";
    
    return 0;
}

# endif


#if 0

class Resource
{
private:
public:
    Resource() { printf("Resource acquired. \n"); }
    ~Resource() { printf("Resource deployed. \n"); }
    
};

int main()
{
    Resource *res = new Resource;
    std::shared_ptr<Resource> ptr1(res);
    {
        std::shared_ptr<Resource> ptr2(res); // create ptr2 directly from res (instead of ptr1)
        std::cout << "Killing one shared pointer \n";
    } // ptr2 goes out of scope here, and the allocated Resource is destroyed

    std::cout << "killing another shared pointer \n";
    
    return 0;
} // ptr1 goes out of scope here, and the allocated Resource is destroyed again

#endif

#if 0

class Resource
{
private:
public:
    Resource() { printf("Resource acquired. \n"); }
    ~Resource() { printf("Resource deployed. \n"); }
    
};

int main()
{
    Resource *res = new Resource;
    std::shared_ptr<Resource> ptr1(res);
    {
        std::shared_ptr<Resource> ptr2(ptr1);
        std::cout << "Killing one shared pointer \n";
    }

    std::cout << "killing another shared pointer \n";

    return 0;
}

#endif