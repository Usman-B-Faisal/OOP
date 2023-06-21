#include<iostream>
using namespace std;

int* secondLargest(int& size);
int main()
{
	int size = 0;
	int* ptr = secondLargest(size);
	cout << "Second largest number in the array is " << *(ptr + 1);
	delete[] ptr;
	return 0;
}

int* secondLargest(int& size)
{
	cout << "Enter Size Of Array: ";
	cin >> size;
	cout << "Enter Array: " << endl;
	int* p = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> *(p + i);
	}
	int temp = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	return p;
}