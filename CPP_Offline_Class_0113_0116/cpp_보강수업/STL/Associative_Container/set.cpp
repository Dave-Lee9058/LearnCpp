/* set
셋(Set)은 영어 단어 뜻 그대로 집합을 의미하는데 동일한 타입의 데이터를 모아 놓은 것이다. 
저장하는 데이터 자체가 키로 사용되며 값은 저장되지 않는다. 
동일 타입의 집합이라는 면에서는 벡터와 같지만 아무 위치에나 삽입되는 것이 아니라 
정렬된 위치에 삽입된다는 점이 다르며 그래서 검색 속도가 아주 빠르다. 

셋은 키의 중복을 허용하지 않으므로 같은 키를 두 번 넣을 수 없는 반면 
멀티셋은 키의 중복을 허용하므로 같은 키를 여러 번 넣을 수 있다. 
중복을 허용하는 집합인가 아닌가에 따라 두 컨테이너 중 하나를 선택해서 사용하면 된다. 
*/

#include <iostream>
#include <set>
#include <algorithm>
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
#if 0
int main()
{
	set<int> s; // 정수 원소를 저장하는 기본 정렬 기준이 less인 빈 컨테이너 생성

	s.insert(50); //랜덤으로 원소(key)를 삽입한다.
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter; // 기본 정렬 기준이 less인 set의 양방향 반복자

	// inorder 2진 트리 탐색 순서로 출력된다.
	Print(s.begin(), s.end());

	s.insert(50); //중복된 원소(key)를 삽입한다. 실패!!
	s.insert(50);

	Print(s.begin(), s.end());
}
#endif
//pair 이용하여 삽입 성공여부 확인
#if 0
int main()
{
	set<int> s;
	pair<set<int>::iterator, bool> pr;

	pr = s.insert(50); // 50 원소의 첫 번째 삽입
	if (true == pr.second)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

	Print(s.begin(), s.end());

	pr = s.insert(50); // 50 원소의 두 번째 삽입. 실패!!

	if (true == pr.second)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

	Print(s.begin(), s.end());
}
#endif
#if 0
int main()
{
	set<int> s; // set<int, less<int>> s;
	pair<set<int>::iterator, bool> pr;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	pr = s.insert(90); //pr.first는 90원소의 반복자

	Print(s.begin(), s.end());

	s.insert(pr.first, 85); //90원소의 반복자에서 검색 시작 후 삽입한다. 

	Print(s.begin(), s.end());
}
#endif
//정렬기준
#if 0
int main()
{
	set<int, greater<int>> s; // 정렬 기준으로 greater<int> 조건자를 사용.

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);


	// greater<int> 조건자를 사용하는 반복자 생성
	set<int, greater<int> >::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}
#endif
//count
#if 0
int main()
{
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "원소 50의 개수: " << s.count(50) << endl; // data의 존재 여부를 확인할 때 사용 가능함.
	cout << "원소 100의 개수: " << s.count(100) << endl;
}
#endif
//검색 : find
#if 0
int main()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);

	set<int>::iterator it;
	it=s.find(2);
	if (it != s.end()) {
		cout << *it << endl;
	} else {
		cout << "찾는 키가 없습니다." << endl;
	}
}
#endif
#include <string>
//객체의 집합
class Person {
protected:
	string name;
	int age;
	friend ostream& operator<<(ostream& o, const Person& p);
	friend struct PersonComp;
public:
	Person(string name, int age) {
		this->name=name;
		this->age=age;
	}
	bool operator<(const Person& p) const { // class 경우에는 operator<() 항상 재정의 해야 한다.
		return name <= p.name;
        // return age < p.age;
	}
	bool operator==(const Person& p) const {
		return name == p.name && age == p.age;
	}
};
ostream& operator<<(ostream& o, const Person& p) {
	o<<p.name<<":"<<p.age<<endl;
	return o;
}
#if 0
int main()
{
	set<Person> pers;
	pers.insert(Person("나길동", 20));
	pers.insert(Person("홍길동", 10));
	pers.insert(Person("고길동", 30));

	set<Person>::iterator it = pers.begin();
	for(;it!=pers.end(); it++) {
		cout<<*it;
	}
}
#endif

//함수 객체 사용
class PersonComp : public binary_function<Person, Person, bool> {
public:
	bool operator()(Person p1, Person p2) {
		return p1.age < p2.age;
	}
};

#if 0
int main()
{
	set<Person, PersonComp> pers;
	pers.insert(Person("나길동", 20));
	pers.insert(Person("홍길동", 10));
	pers.insert(Person("고길동", 30));
	Print(pers.begin(), pers.end());
}
#endif
#if 0
int main()
{
	set<Person> pers;
	pers.insert(Person("나길동", 20));
	pers.insert(Person("홍길동", 10));
	pers.insert(Person("고길동", 30));

	Person p("고길동",10);
    pers.insert(p);

    Print(pers.begin(), pers.end());

	set<Person>::iterator it= pers.find(p); // set의 find 함수는 operator< 적용
	if(it==pers.end()) {
		cout<<"없음"<<endl;
	} else {
		cout<<*it;
	}
	it = find(pers.begin(),pers.end(),p); //전역 find 함수는 operator== 적용
	if(it==pers.end()) {
		cout<<"없음"<<endl;
	} else {
		cout<<*it;
	}
}
#endif
//키 변경 불가
#if 0
int main()
{
	int ar[]={1,3,2,6,4,5};
	int i;
	set<int> s;
	for (i=0;i<sizeof(ar)/sizeof(ar[0]);i++) {
		s.insert(ar[i]);
	}
	Print(s.begin(),s.end());
	set<int>::iterator it;
	it=s.begin();it++;it++;it++;
	// *it=99;  //set 의 키는 변경 불가능, 이미 키로 정렬되어 있기 때문/
}
#endif
// 집합 연산
#include <vector>
#include <iterator>  //back_inserter

#if 0
int main()
{
	int i;
	int ar1[]={7,0,0,6,2,9,1,9,1,4,9,2,0};
	int ar2[]={9,1,7,6,0,0,4,0,5,1,8};
	set<int> s1;
	for (i=0;i<sizeof(ar1)/sizeof(ar1[0]);i++) {
		s1.insert(ar1[i]);
	}
	set<int> s2;
	for (i=0;i<sizeof(ar2)/sizeof(ar2[0]);i++) {
		s2.insert(ar2[i]);
	}
	cout<<"s1:";
	Print(s1.begin(),s1.end());
	cout<<"s2:";
	Print(s2.begin(),s2.end());

	cout<<"set_union:";
	vector<int> vu;
	set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(vu)); //합집합
	Print(vu.begin(),vu.end());

	cout<<"set_intersection:";
	vector<int> vi;
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(vi)); //교집합
	Print(vi.begin(),vi.end());

	cout<<"set_difference:";
	vector<int> vd;
	set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(vd)); //차집합
	Print(vd.begin(),vd.end());

	cout<<"set_symmetric_difference:";
	vector<int> vd2;
	set_symmetric_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),back_inserter(vd2)); //대칭적 차집합
	Print(vd2.begin(),vd2.end());
}
#endif

//multiset
#if 0
int main()
{
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	iter = ms.insert(10);

	cout << "iter의 원소: " << *iter << endl;

	Print(ms.begin(), ms.end());
}
#endif
//multiset : lower_iter, upper_bound
#if 0
int main()
{
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "30 원소의 개수: " << ms.count(30) << endl; // 30 원소의 개수

	iter = ms.find(30); // 30 첫 번째 원소의 반복자
	cout << "iter: " << *iter << endl;

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;

	lower_iter = ms.lower_bound(30); // 30 순차열의 시작 반복자
	upper_iter = ms.upper_bound(30); // 30 순차열의 끝 표시 반복자, 마지막 데이터의 그 다음 iter를 넘겨 받음.
	cout << "lower_iter: " << *lower_iter << ",  " << "upper_iter: " << *upper_iter << endl;

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	Print(lower_iter, upper_iter);
}
#endif
//multiset : equal_range
#if 1
int main()
{
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//multiset의 반복자 쌍(pair) 객체 생성
	pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
	iter_pair = ms.equal_range(30);

	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << *iter << " "; //[iter_pair.first, iter_pair.second) 구간의 순차열
	cout << endl;
}
#endif