/* list
리스트(list) 컨테이너는 이중 연결 리스트를 템플릿으로 추상화한 버전이다. 
동일한 자료의 집합을 관리한다는 용도면에서는 벡터와 같고 실제로 서로 대체도 가능하다. 
용도가 같기 때문에 인터페이스도 거의 유사하다. 
생성자는 완전히 똑같고 삽입, 삭제 등 주요 멤버 함수의 원형도 벡터와 일치하며 대입, 비교 
등의 연산자도 동일하게 제공된다.

반복자가+n 연산을 지원하지 않으므로 순서값으로 요소를 액세스하는 [ ] 연산자를 지원하지 않으며 
at 함수도 당연히 지원되지 않는다. 
임의 위치를 상수 시간에 액세스할 수 없으며 반드시 순회를 해야만 원하는 요소를 찾을 수 있다. 
임의 접근 반복자를 요구하는 sort나 binary_search 알고리즘은 리스트에는 사용할 수 없다.
*/
#include <iostream>
#include <list>
using namespace std;
template<typename IT>
void Print(IT s, IT e)
{
	IT it;
	for (it=s;it!=e;it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
}
//push_back, push_front
#if 0
int main()
{
	list<int> li;

	li.push_back(8);
	li.push_back(9);
	li.push_front(2);
	li.push_front(1);

	Print(li.begin(), li.end());

    return 0;
}
#endif
// 삽입, 삭제 : insert, erase
#if 0
void main()
{
	const char *str="abcdefghij";
	list<char> lc(&str[0],&str[10]);
	list<char>::iterator it;

	Print(lc.begin(), lc.end());
	it=lc.begin();it++;it++;it++;it++;it++;
	lc.insert(it,'Z');
	Print(lc.begin(), lc.end());
	it=lc.end();it--;it--;it--;
	lc.erase(it);
	Print(lc.begin(), lc.end());
}
#endif
// remove
#if 0
void main()
{
	const char *str="double linked list class";
	list<char> li(&str[0],&str[strlen(str)]);

	Print(li.begin(), li.end());
	li.remove('l');
	Print(li.begin(), li.end());
}
#endif

//remove_if
#if 0
bool Predicate(int n) // 단항 조건자
{
	return 10 <= n && n <= 30;
}

struct Predicate
{
	bool operator()(int n)
	{
		return 10 <= n && n <= 30;
	}
};
void main()
{
	list<int> li;

	li.push_back(10);
	li.push_back(20);
	li.push_back(30);
	li.push_back(40);
	li.push_back(50);

	Print(li.begin(), li.end());
	li.remove_if(Predicate);
	Print(li.begin(), li.end());
}
#endif
//정렬 : unique(연속적 중복만 삭제)
#if 0
int main()
{
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.unique(); // 연속된 데이터 같은것 만 삭제할 경우 사용
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
#endif
//unique
#if 0
// Function for binary_predicate 
bool compare(double a, double b)
{
	return ((int)a == (int)b);
}
int main()
{
	list<double> list = { 2.55, 3.15, 4.16, 4.16,
						  4.77, 12.65, 12.65, 13.59 };

	cout << "List is: ";

	// unique operation on list with no parameters 
	list.unique();

	// starts from the first element 
	// of the list to the last 
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << *it << " ";

	// unique operation on list with parameter 
	list.unique(compare);

	cout << "\nList is: ";

	// starts from the first element 
	// of the list to the last 
	for (auto it = list.begin(); it != list.end(); ++it)
		cout << *it << " ";

	return 0;
}
#endif

//sort
#if 0
int main()
{
	list<int> lt;

	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);
	lt.push_back(40);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(); // 오름차순( less, < 연산) 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
#endif
#if 0
struct Greater
{
	bool operator () (int left, int right) const
	{
		return left > right;
	}
};
int main()
{
	list<int> lt;

	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);
	lt.push_back(40);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(greater<int>()); // 조건자 greater를 사용하여 내림차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(less<int>()); // 조건자 less를 사용하여 다시 오름차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(Greater()); // 사용자 정의 조건자를 사용하여 내림차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
#endif
//merge : 두 리스트 정렬 방식이 같아야 한다.
#if 0
int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(25);
	lt2.push_back(35);
	lt2.push_back(60);


	list<int>::iterator iter;
	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << "===============" << endl;

	lt1.merge(lt2); // lt2를 lt1으로 합병 정렬합니다. 정렬 기준은 less, merge되는 t2의 data는 삭제됨.

	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
#endif
#if 0
int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(50);
	lt1.push_back(40);
	lt1.push_back(30);
	lt1.push_back(20);
	lt1.push_back(10);

	// lt2.push_back(25); //lt1과 lt2의 정렬 방식이 다르므로 오류
	// lt2.push_back(35);
	// lt2.push_back(60);

	// lt1과 lt2는 정렬 방식이 같다.
	// greater 조건자( > 연산 ) 정렬 기준을 사용함
	lt2.push_back(60);
	lt2.push_back(35);
	lt2.push_back(25);


	list<int>::iterator iter;
	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << "===============" << endl;

	// lt2를 lt1으로 합병 정렬합니다. 
	// 두 list의 정렬 기준이 > 연산인 greater라는 것을 predicate로 지정합니다.
	lt1.merge(lt2, greater<int>());
	// lt1.merge(lt2);

	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	return 0;
}
#endif
// 링크의 재배치 : splice -- 생략
// splice는 새끼줄같은 것을 꼬아서 서로 잇는다는 의미인데 뜻 
// 그대로 두 개의 리스트를 서로 잇거나 한쪽 요소들을 뽑아서 다른쪽으로 이동시킨다. 
#if 0
int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(100);
	lt2.push_back(200);
	lt2.push_back(300);
	lt2.push_back(400);
	lt2.push_back(500);

	list<int>::iterator iter;
	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());

	iter = lt1.begin();
	++iter;
	++iter; // 30 원소의 위치를 가리킴

	lt1.splice(iter, lt2); //iter가 가리키는 위치에 lt2의 모든 원소를 잘라 붙임

	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());
}
#endif
#if 0
int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(100);
	lt2.push_back(200);
	lt2.push_back(300);
	lt2.push_back(400);
	lt2.push_back(500);

	list<int>::iterator iter1, iter2;
	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());

	iter1 = lt1.begin();
	++iter1;
	++iter1; // 30 원소의 위치를 가리킴

	iter2 = lt2.begin();
	++iter2;
	++iter2; // 300 원소의 위치를 가리킴

	lt1.splice(iter1, lt2, iter2); //iter가 가리키는 위치에 lt2의 하나의 원소를 잘라 붙임

	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());
}
#endif
#if 0
int main()
{
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(100);
	lt2.push_back(200);
	lt2.push_back(300);
	lt2.push_back(400);
	lt2.push_back(500);

	list<int>::iterator iter1, iter2;
	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());

	iter1 = lt1.begin();
	++iter1;
	++iter1; // 30 원소의 위치를 가리킴

	iter2 = lt2.end();
	--iter2;

	lt1.splice(iter1, lt2, lt2.begin(), iter2); //iter가 가리키는 위치에 lt2의 구간 잘라 붙임

	cout << "lt1: ";
	Print(lt1.begin(), lt1.end());

	cout << "lt2: ";
	Print(lt2.begin(), lt2.end());
}
#endif

