#include <iostream>
#include <string>
using namespace std; 

class class_c {
public:
	class_c() = delete;
	class_c(string x) : m_string{ x } {}
	string m_string;
};

int main()
{
	class_c cf{ "hello" };
	//class_c cf1{}; // compiler error C2280: attempting to reference a deleted function
}

#if 0
class class_b {
public:
	class_b() {}
	class_b(string str) : m_string(str) {}
	class_b(string str, double dbl) : m_string{ str }, m_double{ dbl } {}
	double m_double;
	string m_string;
};

int main()
{
	class_b b1{}; //Uninitialized
	class_b b1_1; //Uninitialized
	class_b b2{ "ww" };
	class_b b2_1("xx");

	// order of parameters is the same as the constructor
	class_b b3{ "yy", 4.4 };
	class_b b3_1("zz", 5.5);
}
#endif


#if 0
/**
 * new 연산자
 * 1. 메모리 생성 
 * 2. 자동으로 Casting하여 return해줌. (malloc 인 경우에는 void* 이므로 명시적으로 casting을 해야 함.)
 * 
 */

// 묵시적 기본 생성자만 있음
class class_a {
public:
    float m_float;
	string m_string;
	char m_char;
};

int main()
{
    class_a a1(); // Uninitialized
	class_a a1{}; //Default initialization
	class_a a1_1; //Uninitialized

	class_a a2{ 4.5 }; 
	class_a a3{ 4.5, "string" };
	class_a a4{ 4.5, "string", 'c' };

	//class_a a5{ "string", 'c' }; // compiler error
	//class_a a6{ "string", 'c', 2.0 }; // compiler error

	return 0;
}
#endif
