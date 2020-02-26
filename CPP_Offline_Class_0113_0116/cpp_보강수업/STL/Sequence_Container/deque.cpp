//데크(Deque)는 양쪽 끝이 있는 큐이며 양 끝에서 자료를 삽입, 삭제할 수 있다.
#include <iostream>
#include <deque>
using namespace std;
template<typename IT>
void Print(IT s, IT e)
{
	IT it;
	for (it = s; it != e; it++) {
		cout << *it << " ";
	}
	cout << endl;
}
#if 0

int main()
{
	deque<int> dq;
	dq.push_back(8);
	dq.push_back(9);
	dq.push_front(2);
	dq.push_front(1);
	Print(dq.begin(), dq.end());
}
#endif

//반복자 : +, - 연산
#if 0
int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter;
	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	iter = dq.begin() + 2; //반복자에 +2합니다.
	cout << *iter << endl;

	iter += 2; //반복자에 +2합니다.
	cout << *iter << endl;

	iter -= 3; //반복자에 -3합니다.
	cout << *iter << endl;
}
#endif

//insert
#if 1
int main()
{
	deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);

	deque<int>::iterator iter;
	deque<int>::iterator iter2;
	Print(dq.begin(), dq.end());

	iter = dq.begin() + 2;
	iter2 = dq.insert(iter, 500);
	cout << *iter2 << endl;

	Print(dq.begin(), dq.end());
}
#endif