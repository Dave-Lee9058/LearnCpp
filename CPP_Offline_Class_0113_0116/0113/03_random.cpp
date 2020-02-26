#include <iostream>
#include <time.h>

int main()
{
    std::srand((unsigned)time(nullptr));

    // for(int i = 0; i < 100; i++)
    // {
    //     int num = rand();
    //     printf("%d %d \n",num, rand() % 100);
    // }

    // for(int i = 0; i < 100; i++)
    // {
    //     int num = rand();
    //     printf("%d %d \n",(rand() % 10) +1, (-5 + rand()) % 6);
    // }

    int **arr;

    int h = (rand() % 10) + 1 ;
    int v = (rand() % 10) + 1 ;

    printf("h : %d, v : %d \n", h, v);

    int exH = h + 1;
    int exV = v + 1;

    printf("exH : %d, exV : %d \n", exH, exV);

    arr = new int* [exV];

    for(int i = 0; i < exV; i ++)
    {
        arr[i] = new int[exH];
    }

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < h; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    int hSum = 0;

    for(int i = 0; i < v; i++)
    {
        for (int j = 0; j < h; j++)
        {
            hSum  +=  arr[i][j];
        }
        arr[i][exH-1] = hSum;
        hSum = 0;
    }

    int vSum = 0;
    for( int i = 0; i < h; i++)
    {
        for( int j = 0; j < v; j++)
        {
            vSum += arr[j][i];
        }

        arr[exV-1][i] = vSum;
        vSum = 0;
    }

    for(int i = 0; i < exV; i++)
    {
        for(int j = 0; j < exH; j++)
        {
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < exV; i ++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}