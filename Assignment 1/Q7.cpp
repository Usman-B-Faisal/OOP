#include<iostream>
using namespace std;

int* Union(int* arr1, int* arr2, int a, int b);
int main()
{
	int size1 = 0, size2 = 0, * arr1 = new int[size1], * arr2 = new int[size2];
	cout << "Enter size of array 1: ";
	cin >> size1;
	cout << "Enter size of array 2: ";
	cin >> size2;
	cout << "Enter elements of array 1: ";
	for (int i = 0; i < size1; i++)
		cin >> arr1[i];
	cout << "Enter elements of array 2: ";
	for (int i = 0; i < size2; i++)
		cin >> arr2[i];
	int* all = Union(arr1, arr2, size1, size2);
	delete[] all;
	delete[] arr1;
	delete[] arr2;
}
int* Union(int* arr1, int* arr2, int size1, int size2)
{
	int uni[size1 + size2] = { 0 }, count = 0, count1=0;
	for (int i = 0; i < size1; i++)
	{
		uni[i] = arr1[i];
		count1++;
	}
	for (int i = 0; i < size2; i++)
	{
		count = 0;
		for (int j = 0; j < size1; j++)
		{
			if (arr1[j] == arr2[i])
			{
				count = 1;
				break;
			}

		}
		if (count != 1)
		{
			uni[size1 + i] = arr2[i];
			count1++;
		}
	}
	
	for (int i = 0; i < count1; i++)
	{
		cout << uni[i] << "\t";
	}
	delete [] arr1;
	delete [] arr2;
	return 0;
}