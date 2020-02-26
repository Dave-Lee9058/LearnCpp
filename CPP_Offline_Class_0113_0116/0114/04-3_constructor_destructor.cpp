/**

생성자(Constructor) 함수의 특징
1. 멤버 변수 초기화 목적
2. 생성자 함수는 객체가 생성될 시 자동 Call됨.
3. 임의로 Constructor를 Call할 수 없음.
4. 함수 재정의가 가능함.
5. Return Type이 없음. (Return이 없음.)
6. Constructor는 만들지 않으면, 자동으로 만들어짐. (Constructor를 하나라도 만들면, Default를 만들어 주지 않음.)
7. Constructor는 반드시 class 이름과 동일함.
8. Constructor와 쌍을 이루는 함수는 Destructor 이다.

 */
#include <iostream>

class Apple 
{
private:
    int m_num = 0;

public:
    // Constructor
    Apple() 
    {
        printf("Call Apple Default Consructor \n");
        m_num = 0;
    }

    Apple(int num) 
    {
        printf("Call Apple(int num) Consructor \n");
        m_num = num;
        printf("num : %d \n", m_num);
    }


    ~Apple()
    {
        printf("Call Apple Deconsructor \n");
    }
};

int main()
{
    printf("1 \n");
    Apple a; // Apple a{}; 
    printf("2 \n");    
    Apple *b = new Apple;
    printf("3 \n");
    delete b;
    printf("4 \n");

    Apple c{10};

    return 0;
}   