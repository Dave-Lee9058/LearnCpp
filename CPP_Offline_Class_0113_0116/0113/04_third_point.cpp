#include <iostream>

int main()
{

    // array 2 * 3 * 4
    // arr[2][3][4];
    
    // int ** *arr

    // 이중 포인터 
    // 1. 2원배열 가변적
	// 2. 메모리 할당을 함수에 위탁시킬 경우 사용


    int ***arr;

    arr = new int**[2]; 

    for(int i = 0; i < 2; i++)
    {
         arr[i] = new int*[3];
    }
   
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arr[i][j] = new int[4];
        }        
        
    }

    int ct = 0;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 4; k++, ct++)
            {
                arr[i][j][k] = ct;
            }            
        }        
        
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 4; k++, ct++)
            {
                printf("%02d ", arr[i][j][k]);
            }          
            printf("\n");  
        }        
        printf("\n\n");
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            delete[] arr[i][j];
        }        
        
    }

    for(int i = 0; i < 2; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}