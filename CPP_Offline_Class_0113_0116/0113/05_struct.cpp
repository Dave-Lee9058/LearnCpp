#include <iostream>

struct STRU
{
    int a;
    int b[3];
    int *c;
};

int main()
{
    STRU x, y[2], *z;

    // ex1
    x.a = 20; // . is named as chaining

    printf("%d %p \n", x.a, &x.a); // x.&a -> &x.a

    // ex2
    x.b[0] = 0;
    x.b[1] = 1;
    x.b[2] = 2;

    printf("%2d %p \n", x.b[0], &x.b[0]);
    printf("%2d %p \n", x.b[1], &x.b[1]);
    printf("%2d %p \n", x.b[2], &x.b[2]);
    
    // ex3
    // x.*c // didn't alloc the memory.
    // euqal, add = add, value = value
    x.c = &x.a; // add = add
    printf("%2d %p \n", *x.c, x.c); 

    // ex4
    x.c = new int;
    *x.c = 20;

    printf("%2d %p \n", *x.c, x.c); 

    delete x.c;

    // ex5
    x.c = new int[5];
    for(int i = 0; i < 5; i++)
    {
       x.c[i] = i; 
    }

    for(int i = 0; i < 5; i ++)
    {
        printf("%d %p \n", x.c[i], &x.c[i]);
    }

    delete[] x.c;

    // ex6
    y[0].a = 30;
    printf("%d %p \n", y[0].a, &y[0].a);

    y[1].a = 40;
    printf("%d %p \n", y[1].a, &y[1].a);

    // ex7
    int ct = 0;
    for(int i = 0;i < 2; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            y[i].b[j] = ct++;
        }
    }

    
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d %p \n", y[i].b[j], &y[i].b[j]);
        }
        printf("\n");
    }

    // ex8
    y[0].c = new int;

    *y[0].c = 50;
    printf("%d %p \n", *y[0].c, y[0].c);
    delete y[0].c;

    y[1].c = new int[3];
    for(int i = 0; i < 3; i ++)
    {
        y[1].c[i] = i;
    }
    
    for(int i = 0; i < 3; i++)
    {
        printf("%2d %p \n", y[1].c[i], &y[1].c[i]);
    }

    delete[] y[1].c;
    printf("\n");

    // ex9
    z = new STRU;
    z->a = 60;
    printf("%d %p \n", z->a, &z->a);

    for(int i = 0; i < 3; i ++)
    {
        z->b[i] = i;
    }

    for(int i = 0; i < 3; i++)
    {
        printf("%2d %p \n", z->b[i], &z->b[i]);
    }

    z->c = new int;
    *z->c = 70;
    printf("%d %p \n", *z->c, z->c);
    delete z->c;

    delete z;

    // ex10
    z = new STRU[2];

    z[0].a = 80;
    printf("%d %p \n", z[0].a, &z[0].a);
    z[1].a = 90;
    printf("%d %p \n", z[1].a, &z[1].a);

    z[0].c = new int;
    *z[0].c = 90;
    printf("%2d %p \n", *z[0].c, z[0].c);
    delete z[0].c;

    z[1].c = new int[3];
    for(int i = 0; i < 3; i ++)
    {
        z[1].c[i] = i;
    }

    for(int i = 0; i < 3;  i++)
    {
        printf("%2d %p \n", z[1].c[i], &z[1].c[i]);
    }

    delete[] z[1].c;

    delete[] z;

    return 0;
}