/**
 * @file 6.1_array_2.cpp
 * @author ds9058.lee@gmail.com
 * @brief 
 * @version 0.1
 * @date 2019-11-18
 * 
 * @copyright Copyright (c) 2019
 * 
 * @note
 * 
 * 
 */

#include <iostream>
#include <iterator>

enum class StudentNames
{
    KENNY,
    KYLE,
    STAN,
    BUTTERS,
    CARTMAN,
    MAX_STUDENTS
};

void printSize(int array[])
{
    std::cout << sizeof(array) << '\n';
    // std::cout << std::size(array) << '\n';
}

int main()
{
    // initialize list 
    int prime[5] = {2,3,5,7,11};

    // zero initialization 
    int array[5] = { };

    // Initialize all elements to 0.0
    double darray[5] = { };

    // Omitted length
    int array1[5] = { 0, 1, 2, 3, 4 }; // explicitly define length of the array
    int array2[] = { 0, 1, 2, 3, 4 }; // let initializer list set length of the array

    int testScores[static_cast<int>(StudentNames::MAX_STUDENTS)];
    testScores[static_cast<int>(StudentNames::STAN)] = 76;

    int array3[] = {1,1,2,3,5,8,13,21,23};
    // std::cout << sizeof(array3) << '\n';
    // std::cout << sizeof(array3) / sizeof(array3[0]) << '\n';
    std::cout << std::size(array3) << '\n';

    printSize(array3);
    return 0;



}