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

// struct DOG
// {
//     int a, b;
// };

// typedef struct DOG
// {

// } DOGDOG, *LPDOG;

typedef struct tagDOG
{
    int a, b;
} DOG, * LPDOG, *PDOG, **LPLPDOG;

typedef struct tagTIGER
{
    int a, b;
} TIGER, * LPTIGER, *PTIGER, **LPLPTIGER;

int main()
{
    DOG f;
    f.a = 10;
    f.b = 20;
    
    LPDOG g = new DOG;
    g->a = 30;
    g->b = 40;

    return 0;
}