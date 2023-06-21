#include<iostream>
using namespace std;

int NEWSIZE=0;
int* growArray(int* arr1, int size);
int main()
{
	int size = 10, * arr1 = new int[size];
	cout << "Enter array of 10 elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr1[i];
	}
	int* ptr = growArray(arr1, size);
	cout << "Enlarged array is: " << endl;
	for (int i = 0; i<NEWSIZE ; i++)
	{
		cout << ptr[i] << "\t";
	}
	delete[] arr1;
	delete[] ptr;
	return 0;
}
int* growArray(int* arr1, int size)
{
	int i = 0;
	cout << "Enter what size do you want to grow it to: ";
	cin >> NEWSIZE;
	int* temp = new int[NEWSIZE];
	for (i = 0; i < size; i++)
	{
		temp[i] = arr1[i];
	}
	cout << "Enter new elements you want to add in the array: " << endl;
	for (i; i < NEWSIZE; i++)
	{
		cin >> temp[i];
	}

	return temp;
}