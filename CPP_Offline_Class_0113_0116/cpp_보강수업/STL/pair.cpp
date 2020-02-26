/*
연관 컨테이너(Associative Container)는 키와 값처럼 관련이 있는 데이터를 하나의 쌍으로 
저장하는 컨테이너이다. 
맵은 키와 값의 쌍을 저장하며 셋은 키만 저장하고 값은 저장하지 않는다. 
데이터를 저장할 때 아무 곳에나 저장하지 않고 검색을 고려하여 최대한 빠른 속도로 키를 
찾을 수 있는 위치에 저장하므로 검색 속도가 굉장히 빠르다.

연관 컨테이너의 반복자는 모두 양방향 반복자이다. 
자료들이 항상 정렬된 상태를 유지하므로 다시 정렬할 필요가 없으며 
검색이 워낙 빠르기 때문에 이분 검색을 할 필요도 없다. 
언제든지 순서대로 순회하면 정렬된 결과를 얻을 수 있고 검색은 
원래부터 초고속이므로 굳이 임의 접근 반복자가 필요하지도 않다.
*/
#include <iostream>
#include <string>
#include <utility>
using namespace std;
// pair
#if 1


// template<class T1, class T2>
// struct pair {
//      typedef T1 first_type;
//      typedef T2 second_type;
//      T1 first;
//      T2 second;
//      pair() : first(T1()), second(T2()) {}
//      pair(const T1& v1, const T2& v2) : first(v1), second(v2) {}
// };

// template <class T1,class T2>
// pair<T1,T2> make_pair (T1 x, T2 y)
// {
//     return ( pair<T1,T2>(x,y) );
// }



typedef pair<string,double> sdpair;
sdpair GetPair()
{
	// sdpair temp;
	// temp.first="문자열";
	// temp.second=1.234;
	// return temp;
	return make_pair<string,double>("문자열",1.234);
}

int main()
{
	sdpair sd1;
	sd1 =GetPair();
	std::cout << sd1.first << ":" << sd1.second << std::endl;

	sdpair sd2("홍길동",178.3);
	std::cout << sd2.first << ":" << sd2.second << std::endl;

	sdpair sd3 = make_pair("김길동", 170.2);
	std::cout << sd3.first << ":" << sd3.second << std::endl;

	pair<string, double> sd4("고길동",180.2);
	std::cout << sd4.first << ":" << sd4.second << std::endl;
}
#endif