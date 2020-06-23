#include <iostream>

#if 0

int main()
{
    int value{ 7 };
    int *ptr{ &value };
 
    std::cout << ptr << '\n';
    std::cout << ptr+1 << '\n';
    std::cout << ptr+2 << '\n';
    std::cout << ptr+3 << '\n';
 
    return 0;
}

#endif

#if 0
int main()
{
    short value{ 7 };
    short *ptr{ &value };
 
    std::cout << ptr << '\n';
    std::cout << ptr+1 << '\n';
    std::cout << ptr+2 << '\n';
    std::cout << ptr+3 << '\n';
 
    return 0;
}
#endif

#if 0
int main()
{
    int array[]{ 9, 7, 5, 3, 1 };
 
    std::cout << "Element 0 is at address: " << &array[0] << '\n';
    std::cout << "Element 1 is at address: " << &array[1] << '\n';
    std::cout << "Element 2 is at address: " << &array[2] << '\n';
    std::cout << "Element 3 is at address: " << &array[3] << '\n';
 
    return 0;
}
#endif

#if 0

int main()
{
     int array []{ 9, 7, 5, 3, 1 };
 
     std::cout << &array[1] << '\n'; // print memory address of array element 1
     std::cout << array+1 << '\n'; // print memory address of array pointer + 1 
 
     std::cout << array[1] << '\n'; // prints 7
     std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)
 
    return 0;
}

#endif

#if 0

#include <iterator>
#include <algorithm>

bool isVowel(char ch)
{
    switch(ch)
    {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return true;

        default:
            return false;

    }
}

int main()
{
    char name[]{"Mollie"};
/*
    int arrayLength{ static_cast<int>(std::size(name)) };

    int numVowels{0};

    for(char *ptr{name}; ptr < (name + arrayLength); ++ptr)
    {
        if(isVowel(*ptr))
        {
            numVowels++;
        }
    }
*/

    auto numVowels {std::count_if(std::begin(name), std::end(name), isVowel)};
    std::cout << numVowels << '\n';

    int arr[]{ 1, 2, 3 };
 
    std::cout << 2[arr] << '\n';

    return 0;
}

#endif

#if 1

int* find(int *start, int *end, int value)
{
    /*
    while(start != end)
    {
        if(*start == value)
        {
            return start;
        }        

        start++;
    }

    return start;
    */

   for (int *p{start}; p != end; p++)
   {
       if(*p == value)
        {
            return p;
        }

   }

   return end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
 
    // Search for the first element with value 20.
    int *found{ find(std::begin(arr), std::end(arr), 20) };
 
    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }
 
    return 0;
}

#endif