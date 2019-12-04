/**
 * @file 6.6_an_introduction_to_std::string_view.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

std::string_view askForName()
{
    std::cout << "What's your name? \n";
    std::string str{};
    std::cin >> str;

    std::string_view view{str};
    std::cout << "Hello " << view << '\n';
    return view;
}

void print(std::string s)
{
    std::cout << s << '\n';
}

int main()
{
    char arr[] {"Gold"};
    std::string_view str{arr};
    std::cout << str << '\n';

    arr[3] = 'f';
    std::cout << str << '\n';

    std::string_view str1 {"Peach"};
    std::cout << str1 << '\n';

    str1.remove_prefix(1);
    std::cout << str1 << '\n';

    str1.remove_suffix(2);
    std::cout << str1 << '\n';

    char vowels[] {'a', 'e', 'i', 'o', 'u'};
    std::string_view str2 {vowels, sizeof(vowels) / sizeof(vowels[0])};
    std::cout << str2 << '\n';

    // std::string_view view {askForName()};
    // std::cout << "Your name is " << view << '\n';

    std::string str3 {"Test"};
    std::string_view strv3 {str3};
    std::cout << strv3 << '\n';
    str3 = "Golf";
    std::cout << strv3 << '\n';

    std::string_view sv {"bolloon"};
    sv.remove_suffix(3);
    // print(sv);

    std::string str4 {sv};

    print(str4);
    print(static_cast<std::string>(sv));
    
    auto szNullTerminated{ str4.c_str()};

    std::cout << "Length : " << std::strlen(szNullTerminated) << '\n';

    std::string_view str5 {"balloon"};
    std::cout << str5 << '\n';

    std::cout << std::strlen(str5.data()) << '\n';

    /**
    char text[] {"hello"};
    std::string str {text};
    std::string more {str};
    std::cout << text << " " << str << " " << more << '\n';

    std::string_view str_view{text};
    std::string_view more_view{text};

    std::cout << text << " " << str_view << " " << more_view << '\n';

    std::string_view strv { "Trains are fast!" };
    std::cout << strv.length() << '\n';
    std::cout << strv.substr(0, strv.find(' ')) << '\n';
    std::cout << (strv == "Trains are fast!") << '\n';
    **/
    

    return 0;
}