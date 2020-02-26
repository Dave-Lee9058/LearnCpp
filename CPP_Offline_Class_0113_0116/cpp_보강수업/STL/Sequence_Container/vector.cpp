/*vector
정의:벡터는 임의 타입의 동적 배열
장점:요소들의 크기가 똑같고 인접한 위치에 이웃하여 배치되므로 메모리를 적게 차지하며 임의 위치를 빠른 속도로 액세스할 수 있다.
단점:삽입, 삭제시 요소의 인접 배치 원칙을 지키기 위해 요소를 이동시켜야 하는 번거로움이 있어 삽입, 삭제 속도가 느리다.
*/
#include <iostream>
#include <vector>

using namespace std;
// max_size
#if 0
int main()
{
	vector<int> vi;
	cout<<"max_size = "<<vi.max_size()<<endl;
	/*
	최대 크기는 무려 10억개나 되는데 정수형 10억개이므로 4G까지 벡터 크기를 늘릴 수 있다. 
	이 크기는 이론상의 크기일 뿐 실제로는 운영체제의 메모리 제공 능력에 영향을 받는데 대부분의 
	환경에서 주소 공간의 부족으로 인해 절반 정도밖에 확장할 수 없다. 
	그렇다고 하더라도 5억개는 실로 엄청난 개수인데 무한하다고 표현해도 틀리지 않을 정도다.*/

    return 0;
}
#endif

//size, capacity
#if 0
int main()
{
	vector<int> v;

	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(10);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(20);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(30);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(40);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(50);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(60);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(70);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(80);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(90);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

    return 0;
}
#endif

// reserve
#if 0
int main()
{
	vector<int> v;
    // vector<int> v(20); // Size와 Capacity가 같이 늘어나고 초기화 됨.

	v.reserve(8);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(10);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(20);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(30);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(40);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(50);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(60);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(70);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(80);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
	v.push_back(90);
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

    return 0;
}
#endif

// size 지정
#if 0
int main()
{
	vector<int> v1(5, 10); //0으로 초기화된 size가 5인 컨테이너, ,뒤에 10넣으면 초기값이 10으로 변경됨
	v1.push_back(10); //10 추가
	v1.push_back(20); //20 추가
	v1.push_back(30); //30 추가
	v1.push_back(40); //40 추가
	v1.push_back(50); //50 추가

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //0으로 초기화된 size가 5인 컨테이너
	v2[0] = 10; // 0에서 10로 수정
	v2[1] = 20; // 0에서 20로 수정
	v2[2] = 30; // 0에서 30로 수정
	v2[3] = 40; // 0에서 40로 수정
	v2[4] = 50; // 0에서 50로 수정

	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

    return 0;
}
#endif

//size, 초기값 지정
#if 0
int main()
{
	vector<int> v1(5); //기본값 0으로 초기화된 size가 5인 컨테이너
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5, 0); //지정값 0으로 초기화된 size가 5인 컨테이너    
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	vector<int> v3(5, 10); //지정값 10으로 초기화된 size가 5인 컨테이너    
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

    return 0;
}
#endif

// resize
#if 0
int main()
{
	vector<int> v(5); //기본값 0으로 초기화된 size가 5인 컨테이너

	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(10); //기본값 0으로 초기화된 size가 10인 컨테이너로 확장
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(5); //size가 5인 컨테이너로 축소 capacity는 변화 없음.
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

    return 0;
}
#endif

//front, back
#if 0
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << v[0] << ", " << v.front() << endl; // 첫 번째 원소
	cout << v[4] << ", " << v.back() << endl; // 마지막 원소

	v.front() = 100; // 첫 번째 원소를 100으로
	v.back() = 500; // 마지막 원소를 500으로
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

    return 0;
}
#endif

//clear, empty
#if 0
int main()
{
	vector<int> v(5);

	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.clear(); // v를 비운다.
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	if (v.empty()) // v가 비었는가?
	{
		cout << "v에 원소가 없습니다." << endl;
	}

    return 0;
}
#endif

//at
#if 0
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v[0] = 100; //범위 점검 없는 0 index 원소의 참조
	v[4] = 500; //범위 점검 없는 4 index 원소의 참조
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.at(0) = 1000; //범위 점검 있는 0 index 원소의 참조
	v.at(4) = 5000; //범위 점검 있는 4 index 원소의 참조
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;

    return 0;
}
#endif
//at : out_of_range
#if 0
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	try
	{
		cout << v.at(0) << endl;
		cout << v.at(3) << endl;
		cout << v.at(6) << endl; //throw out_of_range 예외
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}

    return 0;
}
#endif

//assign
#if 0
int main()
{
	vector<int> v(5, 1); // 초기값 1의 5개의 원소를 갖는 컨테이너 생성

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.assign(5, 2); // 5개의 원소값을 2로 할당
	cout << v.size() << ',' << v.capacity() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

    return 0;
}
#endif

//대입 : =
#if 0
int main()
{
	vector<int> v1(5, 1); // 초기값 1의 5개의 원소를 갖는 컨테이너 생성

	vector<int>v2;
	v2 = v1; // 대입 연산자
	v1[0] = 100;

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

    return 0;
}
#endif

template<typename IT>
void Print(IT s, IT e)
{
	IT it;
	for (it=s;it!=e;it++) {
		cout<<*it<<" ";
	}
	cout<<endl;
}

//반복자 : iterator
#if 0
int main()
{
     int num;
     int i;
     printf("배열 크기를 입력하시오 : ");
	 cin>>num;
     vector<int> vi(num);
     for (i=0;i<num;i++) {
          vi[i]=i*2;
     }

	 for (vector<int>::iterator it =vi.begin(); it!=vi.end(); it++) {
		 cout << *it << " ";
     }
	 cout << endl;
	 cout<<"벡터의 크기는 "<<vi.size()<<"입니다."<<endl;

     Print(vi.begin(), vi.end());

     return 0;
}
#endif


//반복자 + 연산
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin(); // 시작 원소(10)를 가리킨다.
	cout << *iter << endl;

	iter += 2; // +2한 위치의 원소(30)를 가리킨다. 물리적인 배열만 가능함. (list는 안됨)
	cout << *iter << endl;

	iter -= 1; // -1한 위치의 원소(20)를 가리킨다. 물리적인 배열만 가능함. (list는 안됨)
	cout << *iter << endl;

    return 0;
}
#endif
//반복자 : const_iterator
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();

	cout << *iter << endl; //가리키는 원소의 참조
	cout << *citer << endl; //가리키는 원소의 상수 참조

	cout << *++iter << endl; //다음 원소로 이동한 원소의 참조
	cout << *++citer << endl; //다음 원소로 이동한 원소의 상수 참조

	*iter = 100;  // 일반 반복자는 가리키는 원소를 변경할 수 있음.
	// *citer = 100; // 상수 반복자는 가리키는 원소를 변경할 수 없음.

    Print(v.begin(), v.end());

    return 0;
}
#endif
// 역방향 반복자 : reverse_iterator
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter; //정방향 반복자
	vector<int>::reverse_iterator riter; //역방향 반복자

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	for (riter = v.rbegin(); riter != v.rend(); ++riter)
		cout << *riter << " ";
	cout << endl;

    return 0;
}
#endif

//insert
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;
	vector<int>::iterator iter2;

	// iter가 가리키는 위치에 정수 100을 삽입.
	// iter2는 삽입한 정수를 가리키는 반복자.
	iter2 = v.insert(iter, 100);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "iter2: " << *iter2 << endl;

    return 0;
}
#endif
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;

	// iter가 가리키는 위치에 정수 100을 3개 삽입.   
	v.insert(iter, 3, 100);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	/////////////////////////////////////////////////////
	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	iter = v2.begin() + 1;
	// iter가 가리키는 위치에 [v.begin(), v.end()) 구간의 원소를 삽입.   
	v2.insert(iter, v.begin(), v.end());

	for (iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
    return 0;
}
#endif
// erase
#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	vector<int>::iterator iter2;
	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	iter = v.begin() + 2;
	// iter가 가리키는 위치의 원소를 제거합니다. iter2는 다음 원소 40
	iter2 = v.erase(iter);
	cout << *iter2 << " ";
	cout << endl;

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	// [v.begin()+1, v.end()] 구간의 원소를 제거합니다.   
	iter2 = v.erase(v.begin() + 1, v.end()); // iter2는 다음 원소 v.end()

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

    return 0;
}
#endif
// 데이터 초기화
#if 0
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2(v.begin(), v.end()); // 순차열 [v.begin(), v.end()]로 v2를 초기화.

	vector<int>::iterator iter;
	for (iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " "; // v2 출력
	cout << endl;

	vector<int> v3;
	v3.assign(v.begin(), v.end());  // v3에 순차열 [v.begin(), v.end())을 할당.
	for (iter = v3.begin(); iter != v3.end(); ++iter)
		cout << *iter << " "; // v3 출력
	cout << endl;

	int ari[] = { 1,2,3,4,5 };
	vector<int> v4(&ari[0], &ari[5]);
	for (iter = v4.begin(); iter != v4.end(); ++iter)
		cout << *iter << " "; // v4 출력
	cout << endl;

    return 0;
}
#endif

//교환 : swap
#if 0
int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
    v1.push_back(40);

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << ", " << v2[i] << endl;
	cout << endl;

	v1.swap(v2); // v1과 v2를 swap합니다.
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << ", " << v2[i] << endl;
	cout << endl;

    for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v1[i] << ", " << v2[i] << endl;
	cout << endl;


    return 0;
}
#endif

// 비교 : ==, !=, >, <
#if 0
int main()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(50);

	if (v1 == v2)
		cout << "v1 == v2" << endl;

	if (v1 != v2)
		cout << "v1 != v2" << endl;

	if (v1 < v2)
		cout << "v1 < v2" << endl;

	return 0;
}
#endif

//반복자 무효화 : erase
#if 0
void main()
{
	vector<int> vi;
	vi.push_back(10);
	vi.push_back(20);
	vi.push_back(30);
	vi.push_back(40);
	vi.push_back(50);
	vector<int>::iterator it = vi.begin()+2;
	cout << *it << endl;
	vi.erase(it);  //vi.erase(it)는 it가 무효화된다.
	cout << *it << endl;
}
#endif

//다른 컨테이너와 요소 교환하기 : 생략
#include <list>
#include <algorithm>
#if 0
void main()
{
	list<int> li;
	for (int i=0;i<100;i++) {
		li.push_back(i);
	}
	vector<int> vi;
	
	vi.insert(vi.begin(), find(li.begin(),li.end(),8), find(li.begin(),li.end(),25));
	Print(vi.begin(),vi.end());
}
#endif

//사용자 정의 요소
#if 1
class Time
{
protected:
	int hour,min,sec;
	friend ostream& operator<<(ostream& o, const Time& t);
public:
	Time(int h,int m,int s) { hour=h;min=m;sec=s; }
};
ostream& operator<<(ostream& o, const Time& t) {
	o<<t.hour<<":"<<t.min<<":"<<t.sec;
	return o;
}
#endif
#if 0
int main()
{
	vector<Time> vt;
	vt.push_back(Time(1,1,1));
	vt.push_back(Time(2,2,2));
	Print(vt.begin(),vt.end());
	return 0;
}
#endif
// vector :bool 생략
#if 1
int main()
{
	vector<bool> vb(32);

	cout << vb[10] << endl;
	vb[10]=true;
	cout << vb[10] << endl;

	//vector<bool>에 포함된 reference 타입은 벡터내의 한 요소, 
	//한 비트를 표현하는 클래스이다
	vector<bool>::reference r=vb[10]; 
	cout << r << endl;
	r.flip();
	cout << r << endl;
	vector<bool>::iterator it;
	for (it=vb.begin();it!=vb.end();it++) {
		cout << *it;
	}

	return 0;
}
#endif

