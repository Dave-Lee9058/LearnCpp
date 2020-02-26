/*
읽기 알고리즘은 컨테이너를 변경하지는 않으며 컨테이너로부터 원하는 정보를 구하기만 하는 
알고리즘이다
*/
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;
//find
#if 0
int main()
{
	string names[]={"홍길동","유재석","강호동",
		"송대한","송민국","송만세","이동국"};
	vector<string> as(&names[0],&names[7]);

	vector<string>::iterator it;
	it=find(as.begin(),as.end(),"송민국");
	if (it==as.end()) {
		cout << "없다" << endl;
	} else {
		cout << "있다" << endl;
	}
}
#endif
//find_if
#if 0
bool HasHong(string who)
{
     return (who.find("홍") != string::npos); 
	 //string::find() 함수는 찾는 문자열이 없으면 string::npos를 리턴한다.
}
void main()
{
	string names[]={"홍길동","유재석","강호동",
		"송대한","송민국","송만세","이동국"};
	vector<string> as(&names[0],&names[7]);

	vector<string>::iterator it;
	it=find(as.begin(),as.end(),"송민국");
	if (it==as.end()) {
		cout << "없다" << endl;
	} else {
		cout << "있다" << endl;
	}
}
#endif

#if 0

bool predict(int n)
{
    return n > 50;
}

int main()
{
    int arr[] = {15, 91, 34, 65, 76, 43, 31, 79};
    vector<int> arrv(&arr[0], &arr[7]);

    vector<int>::iterator it = find(arrv.begin(), arrv.end(), predict);

    if(it != arrv.end())
    {
        std::cout << "exit" << '\n';
    }
    else
    {
        std::cout << "nothing" << '\n';
    }
    
}

#endif

//adjacent_find
//adjacent_find는 구간을 순회하면서 앞뒤의 요소값이 같은 위치를 찾아 
//앞쪽 반복자의 위치를 리턴한다. 인접한 두 요소가 같은 것이 없으면 last가 리턴된다.
//다음 예제는 벡터에서 같은 값이 두 번 연속으로 나오는 위치를 검색한다.
#if 0
int main()
{
	int ari[]={1,9,3,6,7,5,5,8,1,4};
	vector<int> vi(&ari[0],&ari[9]);

	vector<int>::iterator it;
	it=adjacent_find(vi.begin(),vi.end());
	if (it != vi.end()) {
		printf("두 요소가 인접한 값은 %d입니다.\n",*it);
	}
}
#endif
#if 0
bool doublespace(char a, char b)
{
	return (a==' ' && b== ' ');
}

bool bc(char a, char b)
{
    return (a == 'b' && b == 'c');
}

int main()
{
	const char *str="기다림은  만남을 목적으로 하지 않아도  좋다.";
    const char *str2 = "abcdefg";

	const char *p,*pend=&str[strlen(str)];
	for (p=str;;p++) {
		p=adjacent_find(p,pend,doublespace);
		if (p==pend) break;
		cout << p-str << "위치에 이중 공백이 있습니다." << endl;
	}

    const char *p1,*pend1=&str2[strlen(str2)];
	for (p1=str2;;p1++) {
		p1=adjacent_find(p1,pend1,bc);
		if (p1==pend1) break;
		cout << p-str << "위치에 이중 공백이 있습니다." << endl;
	}
}
#endif
//find_first_of
//이 함수는 첫 구간의 요소에서 두 번째 구간의 값 중 하나가 발견되는 최초의 지점을 찾는다
#if 0
int main()
{
	int ar1[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3};
	int ar2[]={2,4,6,8,0};

	int *p=find_first_of(&ar1[0],&ar1[25],&ar2[0],&ar2[4]);
	if (p!=&ar1[25]) {
		cout<<"최초의 짝수는 "<<p-ar1<<"번째의 "<<*p<<"입니다."<<endl;
	}
}
#endif
//search, find_end, search_n
#if 0
int main()
{
	int ar1[]={3,1,4,1,5,9,2,6,5,3,5,8,9,9,9,3,2,3,1,5,9,2,6,4,3};
	int ar2[]={1,5,9};

	int *p;
	p=search(&ar1[0],&ar1[25],&ar2[0],&ar2[3]);
	if (p!=&ar1[25]) {
		cout<<p-ar1<<"번째에서 구간이 발견되었습니다."<<endl;
	}
	p=find_end(&ar1[0],&ar1[25],&ar2[0],&ar2[3]);
	if (p!=&ar1[25]) {
		cout<<p-ar1<<"번째에서 구간이 발견되었습니다."<<endl;
	}
	p=search_n(&ar1[0],&ar1[25],3,9);
	if (p!=&ar1[25]) {
		cout<<p-ar1<<"번째에서 3연속의 9를 발견했습니다."<<endl;
	}
}
#endif
//for_each
#if 0
void func(string str)
{
	cout << str << endl;
}

struct print : unary_function<string, void>
{
    void operator()(string str)
    {
        std::cout << str << '\n';
    }
};

int main()
{
	vector<string> vs;
	vs.push_back("로보트 태권 브이");
	vs.push_back("들장미 소녀 캔디");
	vs.push_back("바보 온달과 평강 공주");
	vs.push_back("독수리 오형제");

	// for_each(vs.begin(),vs.end(),func);
    for_each(vs.begin(),vs.end(),print());
}
#endif
//equal
#if 0
int main()
{
	int ari[]={8,9,0,6,2,9,9};
	vector<int> vi(&ari[0],&ari[7]);
    vi.push_back(1);

	if (equal(&ari[0],&ari[7],vi.begin())) {
		puts("두 구간은 동일하다");
	} else {
		puts("두 구간은 틀리다.");
	}
}
#endif
#if 0
bool compare(double a,double b)
{
	return ((int)a == (int)b);
}

struct same : binary_function<double, double, bool>
{
    bool operator()(double a, double b)
    {
        return ((int)a == (int)b);
    }
};

int main()
{
	double af1[]={ 45.34, 77.84, 96.22, 91.04, 85.24 };
	double af2[]={ 45.99, 77.25, 96.86, 91.23, 86.13 };

	if (equal(&af1[0],&af1[4],&af2[0],same())) {
		puts("지정 구간의 정수부가 모두 같다.");
	} else {
		puts("지정 구간의 정수부 중 일부가 일치하지 않는다.");
	}
}
#endif


//mismatch : 두 구간에서 최최의 다른 지점
#if 0
int main()
{
	int ari[]={8,9,0,6,2,9,9};
	vector<int> vi(&ari[0],&ari[7]);
	vi[3]=7;

	pair<int *,vector<int>::iterator> p;
	p=mismatch(&ari[0],&ari[7],vi.begin());
	if (p.first != &ari[7]) {
		printf("%d번째 자리(%d,%d)부터 다르다.\n",
			p.first-ari,*(p.first),*(p.second));
	} else {
		puts("두 컨테이너가 일치한다.");
	}
}
#endif

#if 0
int main()
{
	int ari[]={8,9,0,6,2,9,9};
    vector<int> v1(&ari[0], &ari[7]);
	vector<int> v2(&ari[0],&ari[7]);
	v2[3]=7;

	pair<vector<int>::iterator,vector<int>::iterator> p;
	p=mismatch(v1.begin(),v1.end(),v2.begin());
	if (p.first != v1.end()) {
		printf("%d번째 자리(%d,%d)부터 다르다.\n",
			p.first,*(p.first),*(p.second));
	} else {
		puts("두 컨테이너가 일치한다.");
	}
}
#endif

#if 0
int main()
{
	int answer[]={1,1,4,3,2,4,3,2,3,4,1,2,4,4,3,2,1,3,2,4};
	int paper[]= {1,1,4,3,3,4,3,1,3,4,1,2,4,4,3,4,1,3,2,2};

	pair<int *,int *> p;
	int i;
	for (i=0;;) {
		p=mismatch(&answer[i],&answer[20],&paper[i]);
		if (p.first == &answer[20]) break;
		printf("%d번 틀림, 정답=%d, 답안=%d\n",
			p.first-answer+1,*(p.first),*(p.second));
		i=p.first-answer+1;
	}
}
#endif
//count
#if 0
void main()
{
	const char *str="Oh baby baby,How was I supposed to know "
		"That something wasn't right here";
	size_t num;

	num=count(&str[0],&str[strlen(str)+1],'a');
	printf("이 문장에는 a가 %d개 있습니다.\n",num);
}
#endif

#if 1
int main()
{
    const char *str = "abcdefghijklmn";
    size_t num;

    // num=count_if(&str[0],&str[strlen(str)+1],bind2nd(greater<char>(),'k')); // ?? > 'k';
    // num=count_if(&str[0],&str[strlen(str)+1],bind1st(less<char>(),'k')); // 'k' < ??

    num=count_if(&str[0],&str[strlen(str)+1],bind1st(greater<char>(),'k')); // 'k' > ??
    // num=count_if(&str[0],&str[strlen(str)+1],bind2st(less<char>(),'k')); // ?? < 'k

    printf("이 문제에서 K보다 큰 문자는 %d 개 있음. \n", num);

}
#endif

//count_if
#if 0
void main()
{
	const char *str="Oh baby baby,How was I supposed to know "
		"That something wasn't right here";
	size_t num;

	num=count_if(&str[0],&str[strlen(str)+1],bind2nd(greater<char>(),'E'));
	printf("이 문장에는 t보다 더 큰 문자가 %d개 있습니다.\n",num);
}
#endif