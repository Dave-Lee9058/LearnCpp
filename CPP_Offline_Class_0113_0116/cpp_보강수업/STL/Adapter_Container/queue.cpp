/* queue
큐는 스택에 비해 먼저 들어간 값이 먼저 나오는(FIFO) 자료 구조이다. 
자료를 관리하는 기본적인 기능은 시퀀스의 것을 그대로 재사용할 수 있으며 
FIFO 원리대로 동작하기 위해 꼭 필요한 인터페이스는 다음 4가지 밖에 없다.

push, pop : 앞뒤에서 값을 추가하거나 제거한다.
front, back : 앞뒤의 값을 읽는다.
*/
#include <iostream>
#include <queue>
using namespace std;
#if 1
int main()
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}
#endif

