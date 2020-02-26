#include <iostream>

class Apple
{
private:
    int num1;
    int num2;
public:
    Apple()
    {
        printf("Call Apple() \n");
        num1 = 0;
        num2 = 0;
    }

    Apple(int num1, int num2)
    {
        printf("Call Apple(int num1, int num2) \n");
        this->num1 = num1;
        this->num2 = num2;
    }

    void showValue()
    {
        printf("num1 : %d, num2 : %d \n", num1, num2);
    }

    ~Apple()
    {
        printf("Call ~Apple(), num1 : %d, num2 : %d \n", num1, num2);
    }
};

int main()
{
    {
        Apple a;
    }
    printf("1 \n");

    Apple *a3 = new Apple(30, 40); 
    printf("2 \n");

    delete a3;
    printf("3 \n");

    // Apple a1;
    // a1.showValue();

    // Apple a2(10, 20);
    // a2.showValue();

    // Apple *a3 = new Apple(30, 40); 
    // a3->showValue();
    // delete a3;

    return 0;
}
