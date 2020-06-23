#include <iostream>
#include <cstddef> // std::size_t

#if 0
int main()
{
    std::cout << "Enter a positivie integer : ";
    std::size_t length{};
    std::cin >> length;

    int *array{new int[length]{}};

    std::cout << "Length : " << length << '\n';
    array[0] = 5;
    printf("%d \n", array[0]);
    delete[] array;

    int fixedArray[5] = {1,2,3,4,5};

    int *array1 {new int[5]{9,7,5,3,1}};

    auto *aray2 {new in[5]{1,2,3,4,5}};

    return 0;
}
#endif

#include <string>
#include <algorithm>

#if 1
int main()
{
    std::cout << "How many names would you like to enter? : ";
    std::size_t count{};
    std::cin >> count;

    auto *names{new std::string[count]};

    for(int num = 0; num < count; num++)
    {
        std::cout << "Enter name #" << num+1 << ": "; 
        std::cin >> names[num]; 
    }

    std::sort(names, names+count);

    for(int num = 0; num < count; num++)
    {
        printf("Name #%d : %s\n", num+1, names[num].c_str());
    }

    delete[] names;

    return 0;
}
#endif