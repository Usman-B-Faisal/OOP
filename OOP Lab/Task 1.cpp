#include<iostream>
using namespace std;

int main()
{
	int size = 5, i = 0;
	int* p = new int[5];
	cout << "Enter Elements in Array: " << endl;
	for (i;; i++)
	{
		if (i < size)
		{
			cin >> *(p + i);
			if (*(p + i) == -1)
			{
				break;
			}
		}

		else
		{
			int* temp = new int[2 * size];
			for (int j = 0; j < size; j++)
			{
				*(temp + j) = *(p + j);
			}
			size = size * 2;
			delete[]p;
			p = temp;
			i--;
		}
	}
	cout<<endl<<size<<endl;
	cout << "Reversed Array Is: " << endl;
	for (int k = i - 1; k >= 0; k--)
	{
		cout << *(p + k) << "	";
	}
	delete [] p;
	return 0;
}
