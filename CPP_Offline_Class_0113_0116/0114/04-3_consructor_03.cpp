#include <iostream>

class Apple
{
private : 
    int *p;
    
public:
    Apple() 
    {
        printf("Call Apple() \n");
        p = new int[1000];
    }

    ~Apple()
    {
        printf("Call ~Apple() \n");
        if( p != nullptr)
        {
            printf("delete p \n");
            delete[] p;
        }
        else
        {
            printf("already delete p \n");
        }
        
        
    }

};

int main()
{

    return 0;
}