#include<iostream>
using namespace std;

void** minRow_wise(int** Two_D, int row, int col);
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
	minRow_wise(Two_D, row, col);
	return 0;
}
void** minRow_wise(int** Two_D, int row, int col)
{
	int temp = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			for (int k = 0; k < col; k++)
			{
				if (Two_D[i][j] < Two_D[i][k])
				{
					temp = Two_D[i][j];
					Two_D[i][j] = Two_D[i][k];
					Two_D[i][k] = temp;
				}
			}
	}
	int* min = new int[row];
	for (int i = 0, j = 0; i < row; i++)
	{
		min[i] = Two_D[i][0];
	}
	for (int i = 0; i < row; i++)
	{
		cout << "Minimum Value in Row " << i + 1 << " was " << min[i] << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] Two_D[i];
	}
	delete[] Two_D;
	return 0;
}