/*stack
스택이라는 자료 구조는 선형적인 기억 공간에 자료를 저장하되 
반드시 넣은 역순으로 빼기(LIFO)를 할 수 있다. 
그래서 기억 공간을 관리하는 능력과 넣기와 빼기 정도의 동작만 제공하면 
쉽게 만들 수 있다. 
임의 위치를 액세스한다거나 중간에서 삽입, 삭제하는 동작은 필요하지 않으며 
스택이 이를 요구하지도 않는다.
*/
#include <iostream>
#include <stack>
// #include <vector>
using namespace std;
#if 1
int main()
{
	stack<int> s;

	s.push(4);
	s.push(7);
	s.push(2);

	while (!s.empty()) { 
		cout << s.top() << endl;
		s.pop();
	}

    // cout << s.top() << endl; // empty인 경우 top을 하면 segment falt가 발생함.
}
#endif