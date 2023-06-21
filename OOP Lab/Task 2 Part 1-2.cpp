// EXERCISE NO.1
#include<iostream>
using namespace std;

int* InputArray(int& size);
void OutputArray(int* myArray, const int& size);
int main()
{
	int Size = 0;
	int* ptr = InputArray(Size);
	OutputArray(ptr, Size);
}
int* InputArray(int& size)
{
	cout << "Enter Size: ";
	cin >> size;
	int* p = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> *(p + i);
	}
	return p;
}
// EXERCISE NO.2
void OutputArray(int* ptr, const int& size)
{
	cout << "Output Is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << endl;
	}
}