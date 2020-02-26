#include <iostream>
using namespace std;
//https://tastyprogramming.tistory.com/71?category=590635

#if 0
//wrapper function°ú ravlue/lvalue passing
void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }

template<typename F, typename A>
void logTime(F f, A& arg)
{
	clock_t begin, end;
	begin = clock();
	f(arg);
	end = clock();
	cout << "time : " << ((end - begin) / CLOCKS_PER_SEC) << endl;
}
int main()
{
	int x = 0;
	logTime<void(*)(int &), int>(goo, x); // goo(x)?. ±×³É ³Ñ±â¸é º¹»çº»ÀÌ ³Ñ¾î°¨. ¹Þ¾ÆÁÖ´Â À§Ä¡¿¡¼­ reference·Î ¹Þ¾ÆÁà¾ßµÊ!
	logTime(goo, x);
	logTime(foo, 10); // foo(10). rvalue°¡ lvalue reference·Î ³Ñ¾î°¥¼ö¾ø´Ù..
	cout << x << endl;
	return 0;
}
#endif
#if 0
void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) {}
template<typename F>void logTime(F f, int& arg)
{
	//¡¦
	f(arg);
	//¡¦
}

template<typename F>void logTime(F f, int&& arg)
{
	//¡¦
	f(arg);
	//¡¦
}
int main()
{
	int x = 0;
	logTime(foo, 10);
	logTime(goo, x);
	logTime(hoo, 10); //error
	//10À» rvalueÀÌ¹Ç·Î void logTime(F f, int&& arg)¸¦ È£ÃâÇÑ´Ù.
	//±×·±µ¥ int && rag = 10 ÇüÅÂ·Î ÀÎÀÚ°¡ Àü´ÞµÉ °æ¿ì arg´Â rvalue referenceÀÌ¹Ç·Î
	//°á±¹ arg°¡ lvalue°¡ µÇ´Â »óÈ²ÀÌ ¹ú¾îÁø´Ù. ±×·± µÚ¿¡, logTime ÇÔ¼ö ³»¿¡¼­
	//f(arg); ÇüÅÂ·Î arg¸¦ ¿øº»ÇÔ¼ö hoo¿¡ ³Ñ°ÜÁÙ °æ¿ì, rvalue¸¦ ÀÎÀÚ·Î ¹Þ´Â
	//hoo¿¡ lvalue¸¦ ³Ñ°ÜÁÖ°Ô µÇ¾î perfect forwarding¿¡ ½ÇÆÐÇÏ°Ô µÈ´Ù.
	cout << x << endl;
}
#endif
//==>ÇØ°áÃ¥
#if 0
template<typename F>void logTime(F f, int&& arg)
{
	// hoo(10) ==> 10Àº rvalueÁö¸¸ arg´Â lvalueÀÌ´Ù. hoo(int&) Ã£´Âµ¥ ¾ø³×?
	//f(arg); // ±×·¡¼­ ÀÌ·¸°Ô ÇÏ¸é ¾ÈµÇ°í..
	//
	// ¿ø·¡ 10Àº rvalue ¿´´Âµ¥ arg·Î ¹ÞÀ¸¸é¼­ lvalue°¡ µÇ¾ú´Ù ¤Ð
	// ´Ù½Ã rvalue·Î Ä³½ºÆÃÇØÁÖÀÚ
	f(static_cast<int&&>(arg));
}
#endif

#if 1
//forwarding reference
void foo(int n) { n = 10; }
void goo(int& n) { n = 10; }
void hoo(int&& n) {}
// int&     : lvalue reference
// int&&    : rvalue reference
// T&       : lvalue reference
// T&&      : ? ¾Ë¼ö¾ø´Ù.. ±×·¡¼­ ÀÌ°Ç forwording reference¶ó´Â »õ·Î¿î ÀÌ¸§.
//            ÀÚ·áÇü °áÁ¤ ±ÔÄ¢
//            ÀÎÀÚ·Î lvalue°¡ ¿À¸é T´Â lvalue ÂüÁ¶Å¸ÀÔ(int&)
//            ÀÎÀÚ·Î rvalue°¡ ¿À¸é T´Â rvalue °ª Å¸ÀÔ(int)
template<typename F, typename T>void logTime(F f, T&& arg)
{
	//f(static_cast<T&&>(arg)); // casting
	f(forward<T>(arg));  //ÀÌ¹Ì ±¸ÇöµÇ¾î ÀÖ´Â ÄÚµåÀÓ
}

int main()
{
	int x = 0;
	logTime(foo, 10); // 10Àº rvalue. T : int, arg : T&& => int&&
	logTime(goo, x);  // x´Â lvalue.  T : int&, arg : T&& => int& && => int&
	logTime(hoo, 10); // 10Àº rvalue. T : int, arg : T&& => int&&.... ±×·±µ¥ 10Àº rvalueÁö¸¸ arg´Â lvalue°¡ µÇ³×.. castingÇÏÀÚ    
	cout << x << endl;
}
/*
T& ÀÏ°æ¿ì
T:int, T&:int & --> int&
T:int&, T&:int& & --> int&
T:int&&, T&:int&& & --> int&

T&& ÀÏ °æ¿ì
T:int, T&&:int && --> int&&
T:int&, T&&:int& && --> int&
T:int&&, T&&:int&& && --> int&&
*/
#endif