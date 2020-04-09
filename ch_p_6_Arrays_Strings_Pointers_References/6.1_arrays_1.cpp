/**
 * @file 6.1_arrays_1.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 * @note
 * 1. When declaring a fixed array, the length of the array (between the square brackets) must be a compile-time constant.
 */
#include <iostream>

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    int prime[5];
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;

    for(int i = 0; i < 5; i++)
    {
        std::cout << prime[i] << '\t';
    }

    std::cout << '\n';

    Rectangle rects[5];
    for(int i = 0; i < 5; i++)
    {
        rects[i].length = i;
        rects[i].width = i;
    }

    for(int i = 0; i < 5; i ++)
    {
        std::cout << "rect[" << i << "].length = " <<  rects[i].length << ", rect[" << i << "].width = " << rects[i].width << '\n';
    }
    
    // using a literal constant
    int array[5]; // Ok
    
    // using a macro symbolic constant
    #define ARRAY_LENGTH 5
    int array[ARRAY_LENGTH]; // Syntactically okay, but don't do this
    
    // using a symbolic constant
    const int arrayLength = 5;
    int array[arrayLength]; // Ok
    
    // using an enumerator
    enum ArrayElements
    {
        MAX_ARRAY_LENGTH = 5
    };
    int array[MAX_ARRAY_LENGTH]; // Ok

    // using a non-const variable
    int length;
    std::cin >> length;
    int array[length]; // Not ok -- length is not a compile-time constant!
    
    // using a runtime const variable
    int temp = 5;
    const int length = temp; // the value of length isn't known until runtime, so this is a runtime constant, not a compile-time constant!
    int array[length]; // Not ok

    return 0;
}

