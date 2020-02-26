/* priority_queue
우선 순위 큐는 벡터와 유사하되 값을 빼 낼 때 가장 큰 값을 리턴한다는 점이 다르다.
필요한 동작은 push, pop, top 세가지밖에 없다.
*/
#include <iostream>
#include <queue>
using namespace std;
#if 1
int main()
{
	priority_queue<int> pq1; // 기본컨테이너 vector<int>, 기본정렬기준 less
	pq1.push(40);
	pq1.push(20);
	pq1.push(30);
	pq1.push(50);
	pq1.push(10);

	cout << "priority_queue[less]:" << endl;
	while (!pq1.empty())
	{
		cout << pq1.top() << endl;
		pq1.pop();
	}
	cout << "================" << endl;

	priority_queue<int, vector<int>, greater<int> > pq2;
	pq2.push(40);
	pq2.push(20);
	pq2.push(30);
	pq2.push(50);
	pq2.push(10);

	cout << "priority_queue[greater]:" << endl;
	while (!pq2.empty())
	{
		cout << pq2.top() << endl;
		pq2.pop();
	}
}
#endif