/*
변경 알고리즘은 읽기 알고리즘과는 달리 컨테이너의 요소를 바꿀 수 있는 알고리즘이다. 
그러나 요소의 값만 변경할 수 있을 뿐이지 컨테이너 자체에 대해서는 
어떠한 조작도 하지 못한다는 점을 주의하자. 
요소를 제거한다거나 새로운 요소를 삽입한다거나 컨테이너의 크기를 변경하는 것도 불가능하다. 
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator> // back, insert
#include <functional> // bind2nd, bind1st
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::
#include <cstring>

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
//copy
#if 0
int main()
{
	char src[]="1234567890";
	char dest[]="abcdefghij";

	copy(&src[3],&src[7],&dest[5]);
	puts(dest);
    return 0;
}
#endif
#if 0
int main()
{
	char src[]="1234567890";
	list<char> li;

	copy(&src[3],&src[7],back_inserter(li));
	// back_inserter 반복자가 대입 동작을 push_back 삽입 동작
	Print(li.begin(),li.end());
    
}
#endif
//copy_backward : list
//list에서 src와 dest가 겹칠 경우의 copy
#if 0
int main()
{
	int i;
	list<int> li,li2;
	list<int>::iterator first,last,result,it;

	for (i=0;i<10;i++) li.push_back(i);
	li2=li;

	Print(li.begin(),li.end());
	first=find(li.begin(),li.end(),2);
	last=find(li.begin(),li.end(),7);
	result=find(li.begin(),li.end(),3);
	copy(first,last,result);
	Print(li.begin(),li.end());

	first=find(li2.begin(),li2.end(),2);
	last=find(li2.begin(),li2.end(),7);
	result=find(li2.begin(),li2.end(),8);
	copy_backward(first,last,result);
	Print(li2.begin(),li2.end());
}
#endif
//copy_backward : vector
//vector에서 src와 dest가 겹칠 경우의 copy
#if 0
int main()
{
	int i;
	vector<int> vi,vi2;
	for (i=0;i<10;i++) vi.push_back(i);
	vi2=vi;

	Print(vi.begin(), vi.end());
	copy(vi.begin()+2,vi.begin()+7,vi.begin()+3);
	Print(vi.begin(), vi.end());
	copy_backward(vi2.begin()+2,vi2.begin()+7,vi2.begin()+8);
	Print(vi2.begin(), vi2.end());
}
#endif
//fill :반복자 구간을 특정 값으로 채운다.
#if 0
int main()
{
	int ari[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	vector<int> vi(&ari[0],&ari[16]);

	// fill(vi.begin()+2,vi.end()-5,99);
	fill_n(vi.begin()+2,9,99);  //vi.begin() 부터 9개를 99로 채운다.
	Print(vi.begin(),vi.end());
}
#endif
//random_shuffle
//이 함수는 난수로 요소를 생성해서 대입하는 것이 아니라 
//이미 존재하는 값들의 순서를 난수로 변경함으로서 섞는다.
#if 0
int main()
{
	char str[]="abcdefghijklmnopqrstuvwxyz";
	srand(unsigned (time(0)));
	puts(str);
	random_shuffle(&str[0],&str[strlen(str)]);puts(str);
	random_shuffle(&str[0],&str[strlen(str)]);puts(str);
	random_shuffle(&str[0],&str[strlen(str)]);puts(str);
}
#endif
#if 0
int fibo() 
{
	static int i1=1,i2=1;
	int t;
	t=i1+i2;
	i1=i2;
	i2=t;
	return t; 
}

int main()
{
	vector<int> vi(10);

	generate(vi.begin(),vi.end(),fibo);
	Print(vi.begin(),vi.end());
}
#endif
//remove
//remove는 실제로 요소를 제거하지는 않으며 제거 대상이 아닌 요소들을 골라 
//구간의 앞쪽으로 이동시키고 남은 요소의 시작을 가리키는 반복자를 리턴한다. 
//요소가 실제로 제거되지 않고 위치만 바뀌므로 remove 호출 후에도 컨테이너의 
//크기는 변하지 않는다. 
//요소를 실제로 제거하려면 컨테이너의 erase 멤버 함수를 호출해야 한다.
#if 0
int main()
{
	int ari[]={3,1,4,1,5,9,2,6,5};
	vector<int> vi(&ari[0],&ari[sizeof(ari)/sizeof(ari[0])]);
	vector<int>::iterator it;
	cout<<"원본:";
	Print(vi.begin(),vi.end());
	it=remove(vi.begin(),vi.end(),1); //남의 요소의 시작을 가리키는 반복자 리턴
	cout<<"remove:";
	Print(vi.begin(),vi.end());
	vi.erase(it,vi.end());  // 남은 요소들 삭제
	cout<<"erase:";
	Print(vi.begin(),vi.end());
}
#endif
//remove_copy
//제거 대상을 제외한 요소들을 새로운 반복자 구간에 대입한다.
#if 0
int main()
{
	int ari[]={3,1,4,1,5,9,2,6,5};
	vector<int> vi(&ari[0],&ari[sizeof(ari)/sizeof(ari[0])]);
	vector<int> vi2;

	remove_copy(vi.begin(),vi.end(),back_inserter(vi2),1); //vi에서 1을 제거하여 vi2에 복사
	Print(vi.begin(),vi.end());
	Print(vi2.begin(),vi2.end());
}
#endif
//unique
//반복자 구간에서 연속된 중복 요소를 제거한다.
#if 0
int main()
{
	char str[]="abcccaddefggghi";
	char *p;
	
	puts(str);
	p=unique(&str[0],&str[strlen(str)]);
	*p=0;
	puts(str);
}
#endif
//replace
//replace: first ~ last 사이의 Old값을 모조리 뒤져 New로 대체한다.
//rotate: middle 위치에 있던 요소가 first의 자리로 온다.
//reverse: 요소의 순서를 반대로 뒤집는다.
#if 0
int main()
{
	const char *str="Notebook Computer";
	vector<char> vc(&str[0],&str[strlen(str)]);
	cout<<"원본:";
	Print(vc.begin(),vc.end());
	replace(vc.begin(),vc.end(),'o','a');
	cout<<"replace:";
	Print(vc.begin(),vc.end());
	rotate(vc.begin(),vc.begin()+2,vc.end());
	cout<<"rotate:";
	Print(vc.begin(),vc.end());
	reverse(vc.begin(),vc.end());
	cout<<"reverse:";
	Print(vc.begin(),vc.end());
}
#endif
//partition: 앞~ 뒤~ 비교하여 특정 값을 기준으로 교환
//stable_partition: 뒤~ 특정 값을 비교하여 앞으로 이동
#if 0
int main()
{
	int ari[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8};
	vector<int> vi(&ari[0],&ari[sizeof(ari)/sizeof(ari[0])]);

    for(int i = 0; i < sizeof(ari)/sizeof(ari[0]); ++i)
    {
        std::cout << ari[i] << " ";
    }
    std::cout << '\n';

	cout<<"원본:";
	Print(vi.begin(), vi.end());
	partition(vi.begin(),vi.end(),bind2nd(greater<int>(),5));
	cout<<"partition:";
	Print(vi.begin(), vi.end());

    for(int i = 0; i < sizeof(ari)/sizeof(ari[0]); ++i)
    {
        std::cout << ari[i] << " ";
    }
    std::cout << '\n';

	vector<int> ar2(&ari[0],&ari[sizeof(ari)/sizeof(ari[0])]);
	stable_partition(ar2.begin(),ar2.end(),bind2nd(greater<int>(),5));
	cout<<"stable:";
	Print(ar2.begin(), ar2.end());
}
#endif
//transform:  반복자 구간에 대해 함수 객체를 적용한 후 그 결과를 다른 구간에 복사한다.
#if 1
int multi2(int a)
{
	return a*2;
}

int add(int a, int b)
{
	return a+b;
}

int main()
{
	vector<int> src(5), dest(5), sum;
	int i;

	for (i=0;i<5;i++) src[i]=i;
	transform(src.begin(),src.end(),dest.begin(),multi2);
	cout<<"src:";
	Print(src.begin(),src.end());
	cout<<"dest:";
	Print(dest.begin(),dest.end());
	transform(src.begin(),src.end(),dest.begin(),back_inserter(sum),add);
	cout<<"sum:";
	Print(sum.begin(),sum.end());
}
#endif