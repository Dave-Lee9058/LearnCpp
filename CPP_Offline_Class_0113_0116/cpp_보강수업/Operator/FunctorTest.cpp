#include <iostream>

class Adder
{
private:
public:
    int operator() (int x, int y)
    {
        return x + y;
    }
};

class Compare
{
private:
public:
    virtual bool operator()(int x, int y)
    {
        return true;
    }
};

class Ascending : public Compare
{
private:
public:
    bool operator()(int x, int y)
    {
        return x > y;
    } 
};

class Descending : public Compare
{
private:
public:
    bool operator()(int x, int y)
    {
        return x < y;
    }
};

void bubbleSort(int* arr, int n, Compare com)
{
    int tmp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(com(arr[i], arr[j]))
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[j] = tmp;
            }
            
        }
    }
}

void printArr(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    int arr[] = {3, 5, 1, 2, 4};
    bubbleSort(arr, 5, Ascending());
    printArr(arr, 5);

    bubbleSort(arr, 5, Descending());
    printArr(arr, 5);

    return 0;
}