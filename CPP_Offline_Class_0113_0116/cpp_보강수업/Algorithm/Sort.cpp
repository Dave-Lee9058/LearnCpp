/*
모든 정렬 함수들은 바른 정렬을 위해 임의 접근 반복자를 요구하므로 
임의 접근이 가능한 컨테이너에 대해서만 사용할 수 있다. 
주로 벡터에 대해 정렬을 수행하며 C의 단순 배열에 대해서도 정렬을 수행할 수 있다. 
정렬 대상을 지정하는 first ~ last 반복자 구간을 인수로 취하며 마지막 인수로 
정렬의 기준으로 사용될 이항 조건자를 전달할 수 있다. 
별도의 조건자가 지정되지 않을 경우 < 연산자로 요소의 대소를 비교한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
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
//sort:퀵소트 알고리즘
//stable_sort:같은 값의 상대적인 순서가 정렬 후에도 유지.
//partial_sort:두 번째 인수로 지정한 SortEnd 부분 직전까지만 정렬하고 나머지 뒷부분은 정렬되지 않은 채로 내버려 둔다. 
//                최상위 n 번까지만 골라내고 싶을 때 이 함수를 사용.
//nth_element:두 번째 인수로 지정한 n에 n번째 값을 놓고 그 왼쪽에 n보다 작은 값을, 
//                  오른쪽에 n 이상의 값으로 구간을 분할한다.
//                  n의 위치만 정확하며 나머지 좌우 구간의 정렬 상태는 보증되지 않는다. 
//                  특정값을 기준으로 미만 그룹, 이상 그룹을 분류할 때 유용하다. 
#if 0
int main()
{
	int ari[]={49,26,19,77,34,52,84,34,92,69};

	vector<int> vi(&ari[0],&ari[10]);
	cout<<"원본:";
	Print(vi.begin(), vi.end());

	sort(vi.begin(),vi.end());
	cout<<"sort:";
	Print(vi.begin(), vi.end());
	vector<int> vi2(&ari[0],&ari[10]);
	stable_sort(vi2.begin(),vi2.end());
	cout<<"stable_sort:";
	Print(vi2.begin(), vi2.end());
	
	vector<int> vi3(&ari[0],&ari[10]);
	partial_sort(vi3.begin(),vi3.begin()+5,vi3.end());
	cout<<"partial_sort:";
	Print(vi3.begin(), vi3.end());

	vector<int> vi4(&ari[0],&ari[10]);
	nth_element(vi4.begin(),vi4.begin()+3,vi4.end());
	cout<<"nth_element:";
	Print(vi4.begin(), vi4.end());
}
#endif
//lower_bound
//값이 있는 첫 번째 위치를 리턴하며 만약 없다면 이 값이 삽입될 수 있는 위치를 조사한다. 
//upper_bound는 반대로 마지막 위치의 다음 위치를 리턴하는데 이는 검색값보다 큰 최초의 값 위치이다.
#if 0
int main()
{
	int ari[]={49,26,19,77,34,52,84,34,92,69};
	vector<int> vi(&ari[0],&ari[10]);
	vector<int>::iterator it;
	cout<<"원본:";
	Print(vi.begin(),vi.end());
	sort(vi.begin(),vi.end());
	it=lower_bound(vi.begin(),vi.end(),50);
	if (*it == 50) {
		cout << "찾는 값이 존재합니다." << endl;
	} else {
		vi.insert(it,50);
		cout<<"삽입 후:";
		Print(vi.begin(),vi.end());
	}
}
#endif
//merge :두 반복자 구간의 요소를 병합한다. 
//          두 구간은 정렬되어 있어야 하며 합쳐진 결과도 정렬된다. 
//inplace_merge: 한 컨테이너의 정렬된 두 연속 구간을 합쳐 원래 구간에 써 넣는다.
//                      frist ~ middle과 middle ~ last를 병합하여 first ~ last 구간을 다시 작성한다
#if 0
int main()
{
	int i;
	vector<int> vi1,vi2,vi3;
	for (i=1;i<5;i++) vi1.push_back(i);
	for (i=3;i<9;i++) vi2.push_back(i);
	merge(vi1.begin(),vi1.end(),vi2.begin(),vi2.end(),back_inserter(vi3));
	cout<<"merge:";
	Print(vi3.begin(),vi3.end());

	vector<int> vi4;
	for (i=1;i<5;i++) vi4.push_back(i);
	for (i=3;i<9;i++) vi4.push_back(i);
    Print(vi4.begin(),vi4.end());
	inplace_merge(vi4.begin(),vi4.begin()+4,vi4.end());
	cout<<"inplace_merge:";
	Print(vi4.begin(),vi4.end());
}
#endif
//min, max: 두 값 중 큰 값과 작은 값을 조사한다
//min_element, max_element: 반복자 구간에서 가장 큰 요소, 가장 작은 요소를 찾아 반복자를 리턴한다.
#if 1
int main()
{
	int i=3,j=5;
	printf("둘 중 작은 값은 %d이고 큰 값은 %d이다.\n",min(i,j),max(i,j));

	int ari[]={49,26,19,77,34,52,84,34,92,69};
	vector<int> vi(&ari[0],&ari[10]);
	printf("벡터에서 가장 작은 값은 %d이고 가장 큰 값은 %d이다.\n",
		*min_element(vi.begin(),vi.end()),*max_element(vi.begin(),vi.end()));
}
#endif
