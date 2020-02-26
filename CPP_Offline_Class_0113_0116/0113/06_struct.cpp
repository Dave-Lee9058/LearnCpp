#include <iostream>

struct SA
{
    int a; 
    int *b;
};

struct SB
{
    SA a;
    SA *b;
};

struct SC
{
    SB a;
    SB *b;
};

int main()
{
    SC x, y[2], *z;

    z = new SC[2];

    z[1].b = new SB;
    z[1].b->b = new SA;
    z[1].b->b->b = new int;
    *z[1].b->b->b = 10;

    printf("%d %p \n", *z[1].b->b->b, z[1].b->b->b);

    delete z[1].b->b->b;
    delete z[1].b->b;
    delete z[1].b;
    delete z;

    return 0;
}