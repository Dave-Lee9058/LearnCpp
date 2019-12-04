/**
 * @file 6.4_Sorting_an_array_using_selection_sort.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <algorithm>

void printArray(int array[], const int length)
{
    for(int count = 0; count < length; count++)
    {
        std::cout << array[count] << " ";
    }
    std::cout << '\n';
}

int main()
{
    const int length = 5;
    int array[length] = {30, 50, 20, 10, 40};

    std::sort(std::begin(array), std::end(array));

    printArray(array, std::size(array));

/*
    for(int startIdx = 0; startIdx < length-1; startIdx++)
    {
        int smallestIdx = startIdx;

        for(int currentIdx = startIdx+1; currentIdx < length; currentIdx++)
        {
            if(array[smallestIdx] > array[currentIdx])
            {
                smallestIdx = currentIdx;
            }
        }
        std::swap(array[startIdx], array[smallestIdx]);

        printArray(array, std::size(array));
    }
*/
}


/*
int main()
{
    int x = 2;
    int y = 4;
    std::cout << "Before swap: x = " << x << " y = " << y << '\n';
    std::swap(x, y);
    std::cout << "After swap: x = " << x << " y = " << y << '\n';
    
    return 0;
}
*/