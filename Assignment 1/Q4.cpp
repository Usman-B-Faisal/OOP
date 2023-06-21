#include<iostream>
using namespace std;

void** minCol_wise(int** Two_D, int row, int col);
int main()
{
	int row = 0, col = 0, ** Two_D = new int* [row];
	cout << "Enter no. of rows: ";
	cin >> row;
	cout << "Enter no. of cols: ";
	cin >> col;
	for (int i = 0; i < row; i++)
	{
		Two_D[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cout << "Value of Row " << i + 1 << " Col " << j + 1 << " : ";
			cin >> Two_D[i][j];
		}
	minCol_wise(Two_D, row, col);
	return 0;
}
void** minCol_wise(int** Two_D, int row, int col)
{
	cout << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Two_D[i][j] << "\t";
		}
		cout << endl;
	}
	int temp = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			for (int k = 0; k < col; k++)
			{
				if (Two_D[j][i] < Two_D[k][i])
				{
					temp = Two_D[j][i];
					Two_D[j][i] = Two_D[k][i];
					Two_D[k][i] = temp;
				}
			}
	}
	cout << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << Two_D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	int* min = new int[row];
	for (int i = 0, j = 0; i < row; i++)
	{
		min[i] = Two_D[i][0];
	}
	for (int i = 0; i < row; i++)
	{
		cout << "Minimum Value in Col " << i + 1 << " was " << min[i] << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] Two_D[i];
	}
	delete[] Two_D;
	return 0;
}