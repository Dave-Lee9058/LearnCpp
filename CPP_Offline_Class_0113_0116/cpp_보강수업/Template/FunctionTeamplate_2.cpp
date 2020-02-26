#include<iostream>
#include<string>
using namespace std;

template <typename T>
int compare(T x, T y)
{
	return x - y;
}

template <typename T>
void bubble_sort(T* arr, int n, int compare(T,T))
{
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (compare(arr[j], arr[j + 1])>0) {
				T t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

class Person {
	int age;
	string name;
public:
	Person(){}
	Person(int age, string name) :name(name), age(age) {}
	friend ostream& operator<<(ostream& o, const Person& p) {
		o << "ÀÌ¸§:" << p.name << ", ³ªÀÌ:" << p.age;
		return o;
	}
	//int operator-(const Person& p) {
	//	return age - p.age;
	//}
	int operator-(const Person& p) {
		return name.compare(p.name);
	}
};

template<typename IT>
void Print(IT s, IT e)
{
	IT it;
	for (it = s; it != e; it++) {
		cout << *it << endl;
	}
}

int main()
{
	Person arr[] = { Person(10, "Hong"), Person(20, "Kang") };
	bubble_sort<Person>(arr, 2, compare<Person>);
	Print(arr, &arr[2]);
	return 0;
}


#if 0
int main()
{
	int arr[] = { 2, 4, 1, 9, 8, 7 };
	bubble_sort<int>(arr, 6, compare<int>);
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
#endif
#if 0
template <typename T>
T Max(T a, T b)
{
	cout<<"T Max(T a, T b)"<<endl;
	return a>b? a:b;
}
template <>
const char* Max(const char* a,const char*b)
{
	return strcmp(a,b)>0? a:b;
}
char* Max(char* a,char*b)
{
	return strcmp(a,b)>0? a:b;
}
int Max(int a, int b)
{
	cout<<"int Max(int a, int b)"<<endl;
	return a>b? a:b;
}

void main()
{
	char str1[] = "abc";
	char str2[] = "def";
	cout<<Max(10,20)<<endl;
	cout<<Max("simple","best")<<endl;
	cout<<Max(str1,str2)<<endl;
}
#endif
