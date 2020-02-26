#include <iostream>

typedef unsigned int    ROBOT;
typedef unsigned int    APPLE;
typedef unsigned char   BYTE;   // 1 BYTE
typedef int             INT;    //
typedef float           FLOAT;
typedef int *           LPBANANA;
typedef int             ORANGE;
typedef int *           LPORANGE;
typedef int             TIGER, *LPTIGER, *PTIGER;
typedef int**           LPLPLION;
typedef int             LION, *LPLION, **LPLPLION;

int main()
{
    unsigned int a{5};

    ROBOT b {10};

    APPLE c {20};

    BYTE d{'a'};

    INT e{30};

    FLOAT f{10.2f};

    // LPBANANA ba = 6;
    LPBANANA ba = new int;
    *ba = 10;

    printf("a : %d \n", a);
    printf("b : %d \n", b);
    printf("c : %d \n", c);
    printf("d : %c \n", d);
    printf("e : %d \n", e);
    printf("f : %f \n", f);
    printf("ba : %d \n", *ba);

    delete ba;

    LPLPLION ppLion;
    ppLion =  new LPLION; // new int*;
    *ppLion = new LION[10]; // new int[10];

    return 0;
}
