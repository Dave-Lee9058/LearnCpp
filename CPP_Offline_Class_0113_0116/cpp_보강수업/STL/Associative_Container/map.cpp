/* map
셋이 키의 집합만을 관리하는데 비해 맵은 키와 값의 쌍을 관리한다. 
연관이 있는 두 개의 값을 쌍으로 관리한다는 점에서 진정한 연관 컨테이너라고 할 수 있다.
셋과 마찬가지로 정렬된 상태로 요소를 저장하므로 키값으로 빠르게 검색할 수 있다. 
셋에 비해 값을 추가로 가진다는 차이점이 있는데 반대로 표현하면 셋은 값을 가지지 않는 맵이라고도 할 수 있다.
*/
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// 삽입, 삭제 : insert, [], erase
#if 0
int main()
{
	map<string,int> m;
	m.insert(pair<string,int>(string("서울"),1000));
	m.insert(pair<string,int>("부산",500));
	m["대전"]=400;
	m["대구"]=300;
	m["광주"]=200;
	m["인천"]=100;
	m["독도"]=1;

    map<string,int>::iterator it;
	for (it=m.begin();it!=m.end();it++) {
		cout << it->first << ":" << it->second << "만명" << endl;
	}
    std::cout << '\n';

    m["서울"]=1500;

    std::cout << m["서울"] << '\n';

    map<string,int>::iterator it1;
	for (it1=m.begin();it1!=m.end();it1++) {
		cout << it1->first << ":" << it1->second << "만명" << endl;
	}
     std::cout << '\n';

	m.erase(m.begin());
	m.erase("인천");

	map<string,int>::iterator it2;
	for (it2=m.begin();it2!=m.end();it2++) {
		cout << it2->first << ":" << it2->second << "만명" << endl;
	}
     std::cout << '\n';
}
#endif
//검색 : find
#if 0
int main()
{
	map<string,int> m;
	m["서울"]=1000;m["부산"]=500;m["대전"]=400;m["대구"]=300;
	m["광주"]=200;m["인천"]=100;m["독도"]=1;

	map<string,int>::iterator it;
	it=m.find("부산");
	if (it == m.end()) {
		cout << "맵에 없는 도시입니다." << endl;
	} else {
		cout << it->first << "의 인구는 " << it->second << "만 명이다." << endl;
	}
}
#endif
//수정 : 값(second)는 변경 가능하나, 키(first)는 변경 불가
#if 0
int main()
{
	map<string,int> m;
	m["서울"]=1000;m["부산"]=500;m["대전"]=400;m["대구"]=300;
	m["광주"]=200;m["인천"]=100;m["독도"]=1;

	map<string,int>::iterator it;
	it=m.find("부산");
	it->second = 550;  // 값 변경 가능 
	//it->first = "전주"; // 키 변경 불가능 ->  m["부산"] = 550; 와 동일함. 
}
#endif
// map 응용
#if 0
class Account {
protected:
	string id;
	string name;
	int balance;
	friend ostream& operator<<(ostream& o, const Account& a);
public:
	Account() {}
	Account(string id, string name, int money) {
		this->id=id;
		this->name=name;
		balance=money;
	}
	string getId() const { return id; }
	string getName() const { return name; }
	int getBalance() const { return balance; }
};
ostream& operator<<(ostream& o, const Account& a) {
	o<<"계좌번호:"<<a.id<<", 이름:"<<a.name<<", 잔액:"<<a.balance<<endl;
	return o;
}

int main()
{
	map<string, Account> accs;
	Account acc1("10002", "홍길동", 100000);
	Account acc2("10001", "고길동", 200000);
	Account acc3("10003", "박길동", 300000);
	accs[acc1.getId()] = acc1;
	accs[acc2.getId()] = acc2;
	accs[acc3.getId()] = acc3;

	map<string, Account>::iterator it = accs.find("10003");
	cout << it->second;
}
#endif

//multimap : count
#if 0
int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator iter;
	for (iter = mm.begin(); iter != mm.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;

	cout << "key 3의 원소의 개수는 " << mm.count(3) << endl;

	iter = mm.find(3);
	if (iter != mm.end())
		cout << "첫 번째 key 3에 매핑된 value: " << iter->second << endl;
}
#endif
// multimap : equal_range
#if 0
int main()
{
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator lower_iter;
	multimap<int, int>::iterator upper_iter;
	lower_iter = mm.lower_bound(3);
	upper_iter = mm.upper_bound(3);

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	multimap<int, int>::iterator iter;
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iter_pair;
	iter_pair = mm.equal_range(3);

	cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

    // std::cout << mm[3] << '\n';
}
#endif

#if 1
// unordered_map
#include <unordered_map>

class Account {
protected:
	string id;
	string name;
	int balance;
	friend ostream& operator<<(ostream& o, const Account& a);
public:
	Account() {}
	Account(string id, string name, int money) {
		this->id=id;
		this->name=name;
		balance=money;
	}
	string getId() const { return id; }
	string getName() const { return name; }
	int getBalance() const { return balance; }
};
ostream& operator<<(ostream& o, const Account& a) {
	o<<"계좌번호:"<<a.id<<", 이름:"<<a.name<<", 잔액:"<<a.balance<<endl;
	return o;
}


int main()
{
    unordered_map<string, Account> accs;
	Account acc1("10002", "홍길동", 100000);
	Account acc2("10001", "고길동", 200000);
	Account acc3("10003", "박길동", 300000);
	accs[acc1.getId()] = acc1;
	accs[acc2.getId()] = acc2;
	accs[acc3.getId()] = acc3;

    for(auto iter = accs.begin(); iter != accs.end(); ++iter)
    {
        std::cout << iter->first << " " << iter->second << '\n';
    }
}


#endif