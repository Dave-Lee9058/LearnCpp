#include <iostream>
#include <memory>
#include <stdlib.h>


const int a = 10;

// a = 30; // shouldn't change the value of the const.

// int *ptr0; // can change value and address
// const int *ptr; // cannnot change value
// int * const ptr1; // cannot change address
// const int * const ptr2; // cannnot change value and address

void func06(const int * const p)
{
    // *p = 10; // cannot change value
    // p = new int; // cannot change address
}

void func71(int a, int b) // call by value
{
    int t = a;
    a = b;
    b = t;
}

void func72(int *a, int *b) // call by address
{
    // a null check nothing
    int t = *a;
    *a = *b;
    *b = t;
}

void func73(int &a, int &b) // call by reference
{
    // don't need to validation about the null.
    int t = a;
    a = b;
    b = t;
}

void func08()
{
    const int num = 20;
    // int &ref = num; 
    // ref += 10;
    const int &ref = num;
    
    printf ("num : %d \n", num);

    const int &a = 10;
}

int main()
{   
    int x = 3, y = 4;

    func71(x, y);
    printf ("%d, %d \n", x, y);

    func72(&x, &y);
    printf("%d, %d \n", x, y);

    func73(x, y);               // reference : can get the address only one times. 
    printf("%d, %d \n", x, y);

    func08();
    
    return 0;
}