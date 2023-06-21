//EXERCISE NO.4
#include<iostream>
using namespace std;

int* InputArray(int& size);
int* Intersection(int*, int&, int*, int&, int&);
void OutputArray(int* ptr, const int& size);
int main()
{
	int size1 = 0, size2 = 0, size3 = 0;
	int* setA = InputArray(size1);
	int* setB = InputArray(size2);
	int* intersection = Intersection(setA, size1, setB, size2, size3);
	OutputArray(intersection, size3);
}

int* Intersection(int* setA, int& sizeA, int* setB, int& sizeB, int& sizeI)
{
	int* temp = new int[sizeA];
	for (int i = 0; i < sizeA; i++)
	{
		for (int j = 0; j < sizeB; j++)
		{
			if (*(setA + i) == *(setB + j))
			{
				*(temp + (sizeI++)) = *(setA + i);
			}
		}
	}
	int* intersect = new int[sizeI];
	for (int i = 0; i < sizeI; i++)
	{
		*(intersect + i) = *(temp + i);
	}
	temp = 0;
	return intersect;
}
void OutputArray(int* ptr, const int& size)
{
	cout << "Output Is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(ptr + i) << endl;
	}
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