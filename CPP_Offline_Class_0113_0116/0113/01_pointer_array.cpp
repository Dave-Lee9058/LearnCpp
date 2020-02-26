// Cpp_1013.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	// *(a+b) == a[b]

    std::cout << "Hello World!\n";

	int *a1 = new int;
	*a1 = 10;
	printf("a1 = %d \n", *a1);
	delete a1;
	
	int *arr = new int[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 5; i++) 
	{
		printf("arr[%d] = %d \n", i, arr[i]);
	}

	delete[] arr;

	int *b = (int*)malloc(sizeof(int) * 5);
	for (int i = 0; i < 5; i++)
	{
		b[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("b[%d] = %d \n", i,b[i]);
	}

	free(b);	

	int ar[3][4]{};
	int count = 0;

	// ar[i] == *(ar + i)
	// ar[i][j] == *(ar[i] + j) == *(*(ar+i)+j)

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//ar[i][j] = count++;
			*(ar[i] + j) = count++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("ar[%d][%d] = %d \n", i, j, ar[i][j]);
			printf("ar[%d][%d] = %d \n", i, j, *(ar[i] + j));
			printf("ar[%d][%d] = %d \n", i, j, *(*(ar+i) + j));
		}
	}

	// new의 객수 만큼 delete
	// int *a, *b, *c, *d;
	int *arr1[4];

	arr1[0] = new int[4];
	arr1[1] = new int[5];
	arr1[2] = new int[6];
	arr1[3] = new int[7];

	//delete[] arr1[0];
	//delete[] arr1[1];
	//delete[] arr1[2];
	//delete[] arr1[3];

	for (int i = 0; i < 4; i++)
	{
		delete[] arr1[i];
	}

	int *arr2[3];

	for (int i = 0; i < 3; i++)
	{
		arr2[i] = new int[4];
	}

	int count1 = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			*(arr2[i] + j) = count1++;
			// arr2[i][j] = count1++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("*(*(arr + %d) + %d) = %d \n", i, j, *(*(arr2+i)+j));
			printf("*(arr[%d] + %d) = %d \n ", i, j, *(arr2[i] + j));
			printf("arr[%d][%d] = %d \n", i, j, arr2[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		delete[] arr2[i];
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
