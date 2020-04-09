/**
 * @file 6.5_c_style_strings.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-19
 * 
 * @copyright Copyright (c) 2019
 * 
 * @note
 * A C-style string is simply an array of characters that uses a null terminator. 
 * A null terminator is a special character (‘\0’, ascii code 0) used to indicate the end of the string. 
 * More generically, A C-style string is called a null-terminated string.
 */
#define __STDC_WANT_LIB_EXT1__ 1
#include <iostream>
#include <iterator>
#include <cstring>

int main()
{
    char myString[] {"string"};
    const int length {static_cast<int>(std::size(myString))};
    // const int length (sizeof(myString) / sizeof(myString[0]));

    std::cout << myString << " has " << length << " charactoers. \n";

    for(int i = 0; i < length; i++)
    {
        std::cout << static_cast<int>(myString[i]) << " ";
    }

    std::cout << '\n';

    char source[] {"Copy this!"};
    char dest[50];
    char dest1[5];
    std::strcpy(dest, source);
    std::cout << dest << '\n';

    std::cout << "strlen : " << std::strlen(dest) << '\n';
    std::cout << "arrLength : " << std::size(dest) << '\n';

    // std::strcpy_s(dest1, 5, source);
    // std::cout << dest1 << '\n';


    return 0;
}