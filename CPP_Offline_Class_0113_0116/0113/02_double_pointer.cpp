#include <iostream>

int main()
{
    // int* *arr
    
	int **arr4;

	int cnt4 = 0;

	arr4 = new int*[3]; // *arr4[3]

	for (int i = 0; i < 3; i++)
	{
		arr4[i] = new int[4];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr4[i][j] = cnt4++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("arr4[%d][%d] = %d \n", i, j, arr4[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete[] arr4[i];
	}

	delete[] arr4;

    return 0;
}